// #include "Storage.h"

// /*
//  * Connect the SD card to the following pins:
//  *
//  * SD Card | ESP32
//  *    D2       -
//  *    D3       SS
//  *    CMD      MOSI
//  *    VSS      GND
//  *    VDD      3.3V
//  *    CLK      SCK
//  *    VSS      GND
//  *    D0       MISO
//  *    D1       -
//  */

// Storage::Storage(fs::FS *fileSystem){
//     fs = fileSystem;
// }

// void Storage::listDir( const char * dirname, uint8_t levels){
//     ESP_LOGV(TAG, "Listing directory: %s\n", dirname);

//     File root = fs->open(dirname);
//     if(!root){
//         ESP_LOGV(TAG, "Failed to open directory");
//         return;
//     }
//     if(!root.isDirectory()){
//         ESP_LOGV(TAG, "Not a directory");
//         return;
//     }

//     File file = root.openNextFile();
//     while(file){
//         if(file.isDirectory()){
//             ESP_LOGV(TAG, "DIR %s \n", file.name());
//             if(levels){
//                 listDir( file.name(), levels -1);
//             }
//         } else {
//             ESP_LOGV(TAG, "FILE: %s SIZE: %s \n", file.name(), file.size());
//         }
//         file = root.openNextFile();
//     }
// }

// void Storage::createDir( const char * path){
//     ESP_LOGV(TAG, "Creating Dir: %s\n", path);
//     if(fs->mkdir(path)){
//         ESP_LOGV(TAG, "Dir created\n");
//     } else {
//         ESP_LOGV(TAG, "mkdir failed\n");
//     }
// }

// void Storage::removeDir( const char * path){
//     ESP_LOGV(TAG, "Removing Dir: %s\n", path);
//     if(fs->rmdir(path)){
//         ESP_LOGV(TAG, "Dir removed");
//     } else {
//         ESP_LOGV(TAG, "rmdir failed");
//     }
// }

// void Storage::readFile( const char * path){
//     ESP_LOGV(TAG, "Reading file: %s\n", path);

//     File file = fs->open(path);
//     if(!file){
//         ESP_LOGV(TAG, "Failed to open file for reading");
//         return;
//     }

//     // ESP_LOGV( tag, "Read from file: ");
//     // while(file.available()){
//     //     Serial.write(file.read());
//     // }
//     file.close();
// }

// void Storage::writeFile( const char * path, const char * message){
//     ESP_LOGV(TAG, "Writing file: %s\n", path);

//     File file = fs->open(path, FILE_WRITE);
//     if(!file){
//         ESP_LOGV(TAG, "Failed to open file for writing");
//         return;
//     }
//     if(file.print(message)){
//         ESP_LOGV(TAG, "File written");
//     } else {
//         ESP_LOGV(TAG, "Write failed");
//     }
//     file.close();
// }

// void Storage::appendFile( const char * path, const char * message){
//     ESP_LOGV(TAG, "Appending to file: %s\n", path);

//     File file = fs->open(path, FILE_APPEND);
//     if(!file){
//         ESP_LOGV(TAG, "Failed to open file for appending");
//         return;
//     }
//     if(file.print(message)){
//         ESP_LOGV(TAG, "Message appended");
//     } else {
//         ESP_LOGV(TAG, "Append failed");
//     }
//     file.close();
// }

// void Storage::renameFile( const char * path1, const char * path2){
//     ESP_LOGV(TAG, "Renaming file %s to %s\n", path1, path2);
//     if (fs->rename(path1, path2)) {
//         ESP_LOGV(TAG, "File renamed");
//     } else {
//         ESP_LOGV(TAG, "Rename failed");
//     }
// }

// void Storage::deleteFile( const char * path){
//     ESP_LOGV(TAG, "Deleting file: %s\n", path);
//     if(fs->remove(path)){
//         ESP_LOGV(TAG, "File deleted");
//     } else {
//         ESP_LOGV(TAG, "Delete failed");
//     }
// }

// void Storage::testFileIO( const char * path){
//     File file = fs->open(path);
//     static uint8_t buf[512];
//     size_t len = 0;
//     uint32_t start = millis();
//     uint32_t end = start;
//     if(file){
//         len = file.size();
//         size_t flen = len;
//         start = millis();
//         while(len){
//             size_t toRead = len;
//             if(toRead > 512){
//                 toRead = 512;
//             }
//             file.read(buf, toRead);
//             len -= toRead;
//         }
//         end = millis() - start;
//         ESP_LOGV(TAG, "%u bytes read for %u ms\n", flen, end);
//         file.close();
//     } else {
//         ESP_LOGV(TAG, "Failed to open file for reading");
//     }


//     file = fs->open(path, FILE_WRITE);
//     if(!file){
//         ESP_LOGV(TAG, "Failed to open file for writing");
//         return;
//     }

//     size_t i;
//     start = millis();
//     for(i=0; i<2048; i++){
//         file.write(buf, 512);
//     }
//     end = millis() - start;
//     ESP_LOGV(TAG, "%u bytes written for %u ms\n", 2048 * 512, end);
//     file.close();
// }

// void Storage::store(){
//   //tm local;
// //  getLocalTime(&local);
//   char * fileName = "/store.txt";
//   // sprintf(fileName, "/1234.txt", 2001, 11);
//   File file = fs->open(fileName, FILE_APPEND);
//   if(!file){
//       ESP_LOGV(TAG, "Failed to open file for appending %s \n", fileName);
//       return;
//   }
//   if(file.print("stuff\n")){
//       ESP_LOGV(TAG, "Message appended");
//   } else {
//       ESP_LOGV(TAG, "Append failed");
//   }
//   file.close();
// }

// void Storage::test(){

//   listDir("/", 0);
//   createDir( "/mydir");
//   listDir( "/", 0);
//   removeDir( "/mydir");
//   listDir( "/", 2);
//   writeFile( "/hello.txt", "Hello ");
//   appendFile( "/hello.txt", "World!\n");
//   readFile( "/hello.txt");
//   deleteFile( "/foo.txt");
//   renameFile( "/hello.txt", "/foo.txt");
//   readFile( "/foo.txt");

//   ESP_LOGV(TAG, "Total space: %lluMB\n", SD.totalBytes() / (1024 * 1024));
//   ESP_LOGV(TAG, "Used space: %lluMB\n", SD.usedBytes() / (1024 * 1024));
//   SD.end();
// }
