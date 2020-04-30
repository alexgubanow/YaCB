/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
osThreadId defaultTaskHandle;
osThreadId heaterTaskHandle;
osThreadId motionTaskHandle;
osThreadId cmdParserTaskHandle;
osThreadId tsenseTaskHandle;
osThreadId respondTaskHandle;
osMessageQId motionQueueHandle;
osMessageQId heaterQueueHandle;
osMessageQId cmdParserQueueHandle;
osMessageQId respondQueueHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const* argument);
void heaterTask_Handle(void const* argument);
void motionTask_Handle(void const* argument);
void cmdParserTask_Handle(void const* argument);
void tsenseTask_Handle(void const* argument);
void respondTask_Handle(void const* argument);

extern void MX_USB_DEVICE_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory(StaticTask_t** ppxIdleTaskTCBBuffer, StackType_t** ppxIdleTaskStackBuffer, uint32_t* pulIdleTaskStackSize);

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory(StaticTask_t** ppxIdleTaskTCBBuffer, StackType_t** ppxIdleTaskStackBuffer, uint32_t* pulIdleTaskStackSize)
{
	*ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
	*ppxIdleTaskStackBuffer = &xIdleStack[0];
	*pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
	/* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

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
	osMessageQDef(motionQueue, 16, uint16_t);
	motionQueueHandle = osMessageCreate(osMessageQ(motionQueue), NULL);

	/* definition and creation of heaterQueue */
	osMessageQDef(heaterQueue, 16, uint16_t);
	heaterQueueHandle = osMessageCreate(osMessageQ(heaterQueue), NULL);

	/* definition and creation of cmdParserQueue */
	osMessageQDef(cmdParserQueue, 16, uint16_t);
	cmdParserQueueHandle = osMessageCreate(osMessageQ(cmdParserQueue), NULL);

	/* definition and creation of respondQueue */
	osMessageQDef(respondQueue, 16, uint16_t);
	respondQueueHandle = osMessageCreate(osMessageQ(respondQueue), NULL);

	/* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
	/* USER CODE END RTOS_QUEUES */

	/* Create the thread(s) */
	/* definition and creation of defaultTask */
	osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
	defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

	/* definition and creation of heaterTask */
	osThreadDef(heaterTask, heaterTask_Handle, osPriorityLow, 0, 128);
	heaterTaskHandle = osThreadCreate(osThread(heaterTask), NULL);

	/* definition and creation of motionTask */
	osThreadDef(motionTask, motionTask_Handle, osPriorityRealtime, 0, 128);
	motionTaskHandle = osThreadCreate(osThread(motionTask), NULL);

	/* definition and creation of cmdParserTask */
	osThreadDef(cmdParserTask, cmdParserTask_Handle, osPriorityRealtime, 0, 128);
	cmdParserTaskHandle = osThreadCreate(osThread(cmdParserTask), NULL);

	/* definition and creation of tsenseTask */
	osThreadDef(tsenseTask, tsenseTask_Handle, osPriorityLow, 0, 128);
	tsenseTaskHandle = osThreadCreate(osThread(tsenseTask), NULL);

	/* definition and creation of respondTask */
	osThreadDef(respondTask, respondTask_Handle, osPriorityLow, 0, 128);
	respondTaskHandle = osThreadCreate(osThread(respondTask), NULL);

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
void StartDefaultTask(void const* argument)
{


	/* init code for USB_DEVICE */
	MX_USB_DEVICE_Init();

	/* USER CODE BEGIN StartDefaultTask */
	/* Infinite loop */
	for (;;)
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
void heaterTask_Handle(void const* argument)
{
	/* USER CODE BEGIN heaterTask_Handle */
	/* Infinite loop */
	for (;;)
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
void motionTask_Handle(void const* argument)
{
	/* USER CODE BEGIN motionTask_Handle */
	/* Infinite loop */
	for (;;)
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
void cmdParserTask_Handle(void const* argument)
{
	/* USER CODE BEGIN cmdParserTask_Handle */
	/* Infinite loop */
	for (;;)
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
void tsenseTask_Handle(void const* argument)
{
	/* USER CODE BEGIN tsenseTask_Handle */
	/* Infinite loop */
	for (;;)
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
void respondTask_Handle(void const* argument)
{
	/* USER CODE BEGIN respondTask_Handle */
	/* Infinite loop */
	for (;;)
	{
		if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) || HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14) || HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15))
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_RESET);
			uint8_t report[12] = { 2, 13,15 };
			USBD_CUSTOM_HID_SendReport_FS(report, sizeof(report));
		}
		osDelay(1000);
	}
	/* USER CODE END respondTask_Handle */
}