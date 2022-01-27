// Find what is the task priority numbering for the RTOS you are using. eg. Higher the number higher the priority or vice-versa. Find the range of priority that can be assigned to a task for your RTOS. 



#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>


void sensor_task(void *pv)
 {
     while (1)
     {
        printf("sensor task \n"); 
        printf("stack remaining:%d",uxTaskPriorityGet(NULL)); // gives priority
        vTaskDelay(1000/portTICK_PERIOD_MS);
     }
}

void buzzer_task(void *pv)
 {
 while (1)
     {
        printf("sensor task \n"); 
        printf("stack remaining:%d",uxTaskPriorityGet(NULL)); // gives priority
        vTaskDelay(1000/portTICK_PERIOD_MS);
     }
}

int app_main()
{
  BaseType_t result;
  TaskHandle_t xHandle,xHandle2;

    result = xTaskCreate(sensor_task,"Sensor",2048,NULL,5,&xHandle);
    result = xTaskCreate(buzzer_task,"buzzer",2048,NULL,4,&xHandle2);
    return 0;
}
