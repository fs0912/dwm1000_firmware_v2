/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c
  * @author  MCD Application Team
  * @version V3.4.0
  * @date    10/15/2010
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "deca_device_api.h"
#include "stm32f10x.h"
#include "port.h"

/* Tick timer count. */
volatile unsigned long time32_incr;

void SysTick_Handler(void)
{
    time32_incr++;
}

void EXTI0_IRQHandler(void) {
  // printf2("int\r\n");
  do{
    dwt_isr();
  }while(GPIO_ReadInputDataBit(DECAIRQ_GPIO, DECAIRQ) == 1);
  EXTI_ClearITPendingBit(DECAIRQ_EXTI);
  // printf2("int out\r\n");
}

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
