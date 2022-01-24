#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define ALARM_PIN 15

void SensorTask(void *pv)
{
  int count = 0;
  while(1)
  {
    count++;
    //printf("sensor Task\n");
    printf("Sensor Task:%d\n",uxTaskGetStackHighWaterMark(NULL));
    printf("Sensor Task: CPU ID %d\n",xTaskGetAffinity(NULL));
     printf("Sensor Task: priority %d\n",uxTaskPriorityGet(NULL));
    //vTaskDelay(1000 / portTICK_PERIOD_MS);
    if (count == 1000)
    {
      vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
  }
}

void alarmTask(void *pv)
{
  //gpio_pad_select_gpio(ALARM_PIN);
  //gpio_set_direction(ALARM_PIN,GPIO_MODE_OUTPUT);

  while(1)
  {
    /* gpio_set_level(ALARM_PIN,0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    gpio_set_level(ALARM_PIN,1); */
    //sensing temperature
    printf("Stack Mark:%d\n",uxTaskGetStackHighWaterMark(NULL));
    printf("Alarm Task: CPU ID %d\n",xTaskGetAffinity(NULL));
     printf("Alarm Task: Priority %d\n",uxTaskPriorityGet(NULL));
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void app_main()
{
  xTaskCreate(SensorTask,"SensorTask",2048,NULL,5,NULL); // in one case 5 for high
  xTaskCreate(AlarmTask,"AlarmTask",2048,NULL,5,NULL); // in one case we have to take 3
}
