# ESP SOLAR CHARGER Logger

A device that logs the solar panel output, playing with freertos while building a small tool



## Lessons Learned,

1. <strike> Wire lib is not working in tasks with low priority.</strike> because of #2.
2. CPP variables don't outlive the block scopes; that is why setup has a while(true) {noop();} at the end
3. QueueHandle_t is a pointer already, no nead to convert it to a pointer 