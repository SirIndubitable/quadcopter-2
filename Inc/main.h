/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern I2C_HandleTypeDef hi2c1;
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
void InitHardware(void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_NW_Pin GPIO_PIN_8
#define LED_NW_GPIO_Port GPIOE
#define LED_N_Pin GPIO_PIN_9
#define LED_N_GPIO_Port GPIOE
#define LED_NE_Pin GPIO_PIN_10
#define LED_NE_GPIO_Port GPIOE
#define LED_E_Pin GPIO_PIN_11
#define LED_E_GPIO_Port GPIOE
#define LED_SE_Pin GPIO_PIN_12
#define LED_SE_GPIO_Port GPIOE
#define LED_S_Pin GPIO_PIN_13
#define LED_S_GPIO_Port GPIOE
#define LED_SW_Pin GPIO_PIN_14
#define LED_SW_GPIO_Port GPIOE
#define LED_W_Pin GPIO_PIN_15
#define LED_W_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
