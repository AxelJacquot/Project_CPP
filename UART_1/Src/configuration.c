#include "configuration.h"

/*--------------------------------------------------------------------------------------------------------------*/
/*									GPIO Configuration															*/
/*--------------------------------------------------------------------------------------------------------------*/

/* Fonction permettant la configuration de l'horloge des ports */
void GPIO_Configuration(GPIO_TypeDef * GPIO, uint16_t mode, uint16_t Pin){
	/* Activation de l'horloge du port */
	ENABLE_CLK_GPIO_PORT(GPIO);

	GPIO_InitTypeDef GPIO_Config;

	/* Configuration du mode */
	GPIO_Config.Mode = mode;

	/* Configuration des pins */
	GPIO_Config.Pin = Pin;

	/*Initialisation de la configuration */
	HAL_GPIO_Init(GPIO, &GPIO_Config);
}

/* Permet d'activer l'horloge du port */
void ENABLE_CLK_GPIO_PORT(GPIO_TypeDef *GPIO){
	if(GPIO == GPIOA)
		__HAL_RCC_GPIOA_CLK_ENABLE();
	else if(GPIO == GPIOB)
		__HAL_RCC_GPIOB_CLK_ENABLE();
	else if(GPIO == GPIOC)
		__HAL_RCC_GPIOC_CLK_ENABLE();
	else if(GPIO == GPIOD)
		__HAL_RCC_GPIOD_CLK_ENABLE();
	else if(GPIO == GPIOE)
		__HAL_RCC_GPIOE_CLK_ENABLE();
	else if(GPIO == GPIOF)
		__HAL_RCC_GPIOF_CLK_ENABLE();
	else if(GPIO == GPIOG)
		__HAL_RCC_GPIOG_CLK_ENABLE();
	else if(GPIO == GPIOH)
		__HAL_RCC_GPIOH_CLK_ENABLE();
}
