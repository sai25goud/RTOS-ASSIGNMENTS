#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

QueueHandle_t sensor_queue;

void SensorTask(void *pv)
{
int sensor_data = 0;
while(1)
  {
  sesnor_data++;
  printf("Sensor Task : sensor_data %d\n",sensor_data);
  xQueueSend(sensor_queue,&sensor_data,portMAX_DELAY);
  vTaskDelay(1000 / portTICK_PERIOD_MS);

  if(sensor_data==10)
  {
    printf("Sensor Task : sensor_data %d\n",sensor_data);
    vTaskDelay(15000 / portTICK_PERIOD_MS);
  }
     
  }
}

void ProcessingTask(void *pv)
{ 
  int recv_data = 10;
  while(1)
  {
    xQueueReceive(sensor_queue,&sensor_data,portMAX_DELAY);
    printf("Processing Task : recv_data %d\n",recv_data);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
  
  
}

void app_main()
{
  sensor_queue = xQueueCreate(10,sizeof(int));
  xTaskCreate(TaskLog1,"TaskLog1",2048,NULL,5, &xHandleTaskLog1);
  xTaskCreate(TaskLog2,"TaskLog2",2048,NULL,10, &xHandleTaskLog2);
 
}
