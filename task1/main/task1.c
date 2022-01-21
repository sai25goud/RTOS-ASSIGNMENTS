#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t xHandleTaskLog;

void TaskLog(void *pvParameters)
{
  while(1)
  printf("TaskLog1\n");
  vTaskDelete(xHandleTaskLog);
  printf("TaskLog2\n");
  vTaskDelete(xHandleTaskLog);
}

void app_main()
{
 BaseType_t result;
 result = xTaskCreate(TaskLog,"TaskLog1",2048,NULL,5, &xHandleTaskLog);
 result = xTaskCreate(TaskLog,"TaskLog2",2048,NULL,10, &xHandleTaskLog);
    if(result == pdPASS)
    {
        printf("TaskLog created\n");

    }
}