#include "./Logger.h"

Logger::Logger(LoggerParameters *loggerParameters)
{
    parameters = loggerParameters;
}

void Logger::computeFileName(char *filename, int category)
{
    struct tm  timeinfo;
    struct tm * tmp = &timeinfo;
    if (!getLocalTime(tmp))
    {
        time_t t;
        time(&t);
        tmp = gmtime( &t );
    }
    
    strftime(filename, sizeof(filename), "%Y-%m-%d", tmp);
    sprintf(filename, "/%s.%d.yaml", filename, category);

}

void Logger::store(LoggerEntry *entry)
{
    char filename[20];
    computeFileName(filename, entry->category);
    ESP_LOGW(TAG, "Atempting to open file [%s] for appending", filename);

    if (parameters->fileSystem)
    {

        File file;
        char openMode;
        if (parameters->fileSystem->exists(filename))
        {
            file = parameters->fileSystem->open(filename, FILE_APPEND);
        }
        else
        {
            file = parameters->fileSystem->open(filename, FILE_WRITE);
        }
        if (!file)
        {
            ESP_LOGW(TAG, "Failed to open file for appending %s", filename);
            return;
        }
        if (file.printf("- [%d, %s]\n", entry->timestamp, entry->data))
        {
            ESP_LOGW(TAG, "Message appended");
        }
        else
        {
            ESP_LOGW(TAG, "Append failed");
        }
        file.close();
    }
    else
    {
        ESP_LOGW(TAG, "Cannot store log entry no fs provided");
    }
}