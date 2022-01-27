// What is the mechanism used to make a task periodic for the RTOS you are using? Write a program to make a task periodic with periodicity of 500ms.



#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>


void sensor_task(void *pv)
 {
     while (1)
     {
        printf("sensor task \n"); 
        printf("stack remaining:%d",uxTaskPriorityGet(NULL)); // gives priority
        vTaskDelay(500/portTICK_PERIOD_MS);
     }
}


int app_main()
{
  BaseType_t result;
  TaskHandle_t xHandle;

    result = xTaskCreate(sensor_task,"Sensor",2048,NULL,5,&xHandle);
    return 0;
}
