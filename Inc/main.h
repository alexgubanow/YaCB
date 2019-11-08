/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define IRQ1_Pin GPIO_PIN_2
#define IRQ1_GPIO_Port GPIOE
#define IRQ2_Pin GPIO_PIN_3
#define IRQ2_GPIO_Port GPIOE
#define IRQ3_Pin GPIO_PIN_4
#define IRQ3_GPIO_Port GPIOE
#define IRQ4_Pin GPIO_PIN_5
#define IRQ4_GPIO_Port GPIOE
#define IRQ5_Pin GPIO_PIN_6
#define IRQ5_GPIO_Port GPIOE
#define IRQ6_Pin GPIO_PIN_13
#define IRQ6_GPIO_Port GPIOC
#define DRV1_DIR_Pin GPIO_PIN_0
#define DRV1_DIR_GPIO_Port GPIOC
#define DRV2_DIR_Pin GPIO_PIN_1
#define DRV2_DIR_GPIO_Port GPIOC
#define DRV3_DIR_Pin GPIO_PIN_2
#define DRV3_DIR_GPIO_Port GPIOC
#define DRV4_DIR_Pin GPIO_PIN_3
#define DRV4_DIR_GPIO_Port GPIOC
#define DRV5_DIR_Pin GPIO_PIN_4
#define DRV5_DIR_GPIO_Port GPIOC
#define DRV6_DIR_Pin GPIO_PIN_5
#define DRV6_DIR_GPIO_Port GPIOC
#define IRQ8_Pin GPIO_PIN_7
#define IRQ8_GPIO_Port GPIOE
#define IRQ9_Pin GPIO_PIN_8
#define IRQ9_GPIO_Port GPIOE
#define RST_IRQ_Pin GPIO_PIN_10
#define RST_IRQ_GPIO_Port GPIOE
#define PS_ON_Pin GPIO_PIN_12
#define PS_ON_GPIO_Port GPIOE
#define IRQ7_Pin GPIO_PIN_15
#define IRQ7_GPIO_Port GPIOE
#define DRV1_EN_Pin GPIO_PIN_0
#define DRV1_EN_GPIO_Port GPIOD
#define DRV2_EN_Pin GPIO_PIN_1
#define DRV2_EN_GPIO_Port GPIOD
#define DRV3_EN_Pin GPIO_PIN_2
#define DRV3_EN_GPIO_Port GPIOD
#define DRV4_EN_Pin GPIO_PIN_3
#define DRV4_EN_GPIO_Port GPIOD
#define DRV6_EN_Pin GPIO_PIN_7
#define DRV6_EN_GPIO_Port GPIOD
#define DRV2_STP_Pin GPIO_PIN_3
#define DRV2_STP_GPIO_Port GPIOB
#define DRV3_STP_Pin GPIO_PIN_4
#define DRV3_STP_GPIO_Port GPIOB
#define DRV4_STP_Pin GPIO_PIN_5
#define DRV4_STP_GPIO_Port GPIOB
#define DRV5_STP_Pin GPIO_PIN_8
#define DRV5_STP_GPIO_Port GPIOB
#define DRV6_STP_Pin GPIO_PIN_9
#define DRV6_STP_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
