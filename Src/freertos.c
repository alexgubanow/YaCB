/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */     

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId_t defaultTaskHandle;
osThreadId_t heaterTaskHandle;
osThreadId_t motionTaskHandle;
osThreadId_t cmdParserTaskHandle;
osThreadId_t tsenseTaskHandle;
osThreadId_t respondTaskHandle;
osMessageQueueId_t motionQueueHandle;
osMessageQueueId_t heaterQueueHandle;
osMessageQueueId_t cmdParserQueueHandle;
osMessageQueueId_t respondQueueHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void heaterTask_Handle(void *argument);
void motionTask_Handle(void *argument);
void cmdParserTask_Handle(void *argument);
void tsenseTask_Handle(void *argument);
void respondTask_Handle(void *argument);

extern void MX_USB_DEVICE_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */
osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* definition and creation of motionQueue */
  const osMessageQueueAttr_t motionQueue_attributes = {
    .name = "motionQueue"
  };
  motionQueueHandle = osMessageQueueNew (16, sizeof(uint16_t), &motionQueue_attributes);

  /* definition and creation of heaterQueue */
  const osMessageQueueAttr_t heaterQueue_attributes = {
    .name = "heaterQueue"
  };
  heaterQueueHandle = osMessageQueueNew (16, sizeof(uint16_t), &heaterQueue_attributes);

  /* definition and creation of cmdParserQueue */
  const osMessageQueueAttr_t cmdParserQueue_attributes = {
    .name = "cmdParserQueue"
  };
  cmdParserQueueHandle = osMessageQueueNew (16, sizeof(uint16_t), &cmdParserQueue_attributes);

  /* definition and creation of respondQueue */
  const osMessageQueueAttr_t respondQueue_attributes = {
    .name = "respondQueue"
  };
  respondQueueHandle = osMessageQueueNew (16, sizeof(uint16_t), &respondQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  const osThreadAttr_t defaultTask_attributes = {
    .name = "defaultTask",
    .priority = (osPriority_t) osPriorityNormal,
    .stack_size = 128
  };
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* definition and creation of heaterTask */
  const osThreadAttr_t heaterTask_attributes = {
    .name = "heaterTask",
    .priority = (osPriority_t) osPriorityLow,
    .stack_size = 128
  };
  heaterTaskHandle = osThreadNew(heaterTask_Handle, NULL, &heaterTask_attributes);

  /* definition and creation of motionTask */
  const osThreadAttr_t motionTask_attributes = {
    .name = "motionTask",
    .priority = (osPriority_t) osPriorityRealtime,
    .stack_size = 128
  };
  motionTaskHandle = osThreadNew(motionTask_Handle, NULL, &motionTask_attributes);

  /* definition and creation of cmdParserTask */
  const osThreadAttr_t cmdParserTask_attributes = {
    .name = "cmdParserTask",
    .priority = (osPriority_t) osPriorityRealtime,
    .stack_size = 128
  };
  cmdParserTaskHandle = osThreadNew(cmdParserTask_Handle, NULL, &cmdParserTask_attributes);

  /* definition and creation of tsenseTask */
  const osThreadAttr_t tsenseTask_attributes = {
    .name = "tsenseTask",
    .priority = (osPriority_t) osPriorityLow,
    .stack_size = 128
  };
  tsenseTaskHandle = osThreadNew(tsenseTask_Handle, NULL, &tsenseTask_attributes);

  /* definition and creation of respondTask */
  const osThreadAttr_t respondTask_attributes = {
    .name = "respondTask",
    .priority = (osPriority_t) osPriorityLow,
    .stack_size = 128
  };
  respondTaskHandle = osThreadNew(respondTask_Handle, NULL, &respondTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
    
                 
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();

  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_heaterTask_Handle */
/**
* @brief Function implementing the heaterTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_heaterTask_Handle */
void heaterTask_Handle(void *argument)
{
  /* USER CODE BEGIN heaterTask_Handle */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END heaterTask_Handle */
}

/* USER CODE BEGIN Header_motionTask_Handle */
/**
* @brief Function implementing the motionTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_motionTask_Handle */
void motionTask_Handle(void *argument)
{
  /* USER CODE BEGIN motionTask_Handle */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END motionTask_Handle */
}

/* USER CODE BEGIN Header_cmdParserTask_Handle */
/**
* @brief Function implementing the cmdParserTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_cmdParserTask_Handle */
void cmdParserTask_Handle(void *argument)
{
  /* USER CODE BEGIN cmdParserTask_Handle */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END cmdParserTask_Handle */
}

/* USER CODE BEGIN Header_tsenseTask_Handle */
/**
* @brief Function implementing the tsenseTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_tsenseTask_Handle */
void tsenseTask_Handle(void *argument)
{
  /* USER CODE BEGIN tsenseTask_Handle */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END tsenseTask_Handle */
}

/* USER CODE BEGIN Header_respondTask_Handle */
/**
* @brief Function implementing the respondTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_respondTask_Handle */
void respondTask_Handle(void *argument)
{
  /* USER CODE BEGIN respondTask_Handle */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END respondTask_Handle */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
