#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include <freertos/semphr.h>

//SemaphoreHandle_t sem;
TaskHandle_t sensorHandle;
TaskHandle_t processHandle;

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
    vTaskResume(processHandle)
    // xSemaphoreGive(sem,portMAX_DELAY);
    printf("Sensor Task : sensor_data %d\n",sensor_data);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
     
  }
}

void ProcessingTask(void *pv)
{ 
  int recv_data = 0;
  while(1)
  { 
    vTaskSuspend(NULL);
    //xSemaphoreTake(sem,portMAX_DELAY);
    printf("Processing Task : recv_data %d\n",recv_data);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
  
  
}

void app_main()
{
  //sem = xSemaphoreCreateBinary();
  xTaskCreate(sensorTask,"SensorTask",2048,NULL,5, &sensorHandle);
  xTaskCreate(processingTask,"ProcessingTask",2048,NULL,10, &processHandle);
 // xSemaphoreTake(sem,portMAX_DELAY);
 
}
