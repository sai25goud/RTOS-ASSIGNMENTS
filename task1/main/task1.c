#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t xHandleTaskLog1;
TaskHandle_t xHandleTaskLog2;

void TaskLog1(void *pvParameters)
{
  while(1)
  {
  printf("TaskLog1\n");
  vTaskDelete(xHandleTaskLog1);
  }
}

void TaskLog2(void *pvParameters)
{
  while(1)
  {
  printf("TaskLog2\n");
  vTaskDelete(xHandleTaskLog2);
  }
}

void app_main()
{

 BaseType_t result1,result2;
 result1 = xTaskCreate(TaskLog1,"TaskLog1",2048,NULL,5, &xHandleTaskLog1);
 result2 = xTaskCreate(TaskLog2,"TaskLog2",2048,NULL,10, &xHandleTaskLog2);
 
    if(result1 == pdPASS)
    {
        printf("TaskLog1 created\n");
    }
    
    if(result2 == pdPASS)
    {
        printf("TaskLog2 created\n");
    }
}
