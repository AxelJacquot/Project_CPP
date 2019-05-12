/*
 * configuration.h
 *
 *  Created on: 21 mars 2019
 *      Author: axel
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "stm32f4xx_hal.h"

#define LED_PORT	GPIOD
#define GREEN		GPIO_PIN_12
#define ORANGE		GPIO_PIN_13
#define RED			GPIO_PIN_14
#define BLUE 		GPIO_PIN_15
#define LED_ALL		GREEN | ORANGE | RED | BLUE
#define GRE_ORA		GREEN | ORANGE
#define BLU_RED		RED | BLUE


void ENABLE_CLK_TIMER_PORT(TIM_TypeDef * timer);
void ENABLE_CLK_GPIO_PORT(GPIO_TypeDef * GPIO);
void GPIO_Configuration(GPIO_TypeDef * GPIO, uint16_t mode, uint16_t Pin);

#endif /* CONFIGURATION_H_ */
