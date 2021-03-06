/*
 * stm32f4Xx_gpio_driver.c
 *
 *  Created on: Sep 16, 2021
 *      Author: Koppolu Ananth Ashrith
 */


#include "stm32f4Xx_gpio_driver.h"

	/*
	 * @breif:
	 * @para1:
	 * @para2:
	 * @para3:
	 * @return value :none
	 */

	void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
	{
		//1.configure the mode

		uint32_t temp=0;

		 temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		 pGPIOHandle->pGPIOx->MODER &=  ~(0x3 <<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		 pGPIOHandle->pGPIOx->MODER |=temp;  //setting of the value
		    temp=0;
		//2.configure the speed
		   temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed<< (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		   pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 <<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	    	pGPIOHandle->pGPIOx->OSPEEDR |=temp;
	    	temp=0;
		//3.configure the pull up and pull down settings
            temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinPupdrControl<<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
            pGPIOHandle->pGPIOx->PUPDR &= ~(0x3<<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
            pGPIOHandle->pGPIOx->PUPDR |=temp;
            temp=0;
		//4.configure the Output type
             temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinOutputtype<<(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
             pGPIOHandle->pGPIOx->OTYPER &= ~(0x1<<(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
             pGPIOHandle->pGPIOx->OTYPER |=temp;
             temp=0;

		//5.configure the Alternate Function Mode

	    	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode==GPIO_MODE_ALTER)
	    	{
	    		uint8_t temp1,temp2;
	    		temp1=pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber/8;
	    		temp2=pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber%8;
	    		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF  <<(4*temp2));
	    		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode<<(4*temp2));
	    	}

	}

	/*
	 * @Brief:
	 * @para1:
	 * @para2:
	 * @para3:
	 * @return value :none
	 */

	void GPIO_DeInit(GPIO_RegDef_t  *pGPIOx)
	{
		if(pGPIOx ==GPIOA)
		{
			GPIOA_REG_RESET();
		}
		else if(pGPIOx ==GPIOB)
		{
		GPIOB_REG_RESET();
		}
		else if(pGPIOx ==GPIOC)
				{
				GPIOC_REG_RESET();
				}
		else if(pGPIOx ==GPIOD)
				{
				GPIOD_REG_RESET();
				}
		else if(pGPIOx ==GPIOE)
				{
				GPIOE_REG_RESET();
				}
		else if(pGPIOx ==GPIOF)
				{
				GPIOF_REG_RESET();
				}
		else if(pGPIOx ==GPIOG)
			    {
				GPIOG_REG_RESET();
				}
		else if(pGPIOx ==GPIOH)
				{
				GPIOH_REG_RESET();
				}
		else if(pGPIOx ==GPIOI)
				{
				GPIOI_REG_RESET();
				}
		else if(pGPIOx ==GPIOJ)
				{
				GPIOJ_REG_RESET();
				}


	}


	/*
	 * @Brief:
	 * @para1:
	 * @para2:
	 * @para3:
	 * @return value :none
	 */

	void GPIO_PeriClockControl(GPIO_RegDef_t  *pGPIOx, uint8_t EnorDi)
	{
		if (EnorDi == ENABLE)
		{
			if(pGPIOx==GPIOA)
			{
				GPIOA_PCLK_EN();
			}
			else if(pGPIOx==GPIOB)
			{
				GPIOB_PCLK_EN();
			}
			else if(pGPIOx==GPIOC)
						{
							GPIOC_PCLK_EN();
						}
			else if(pGPIOx==GPIOD)
						{
							GPIOD_PCLK_EN();
						}
			else if(pGPIOx==GPIOE)
						{
							GPIOE_PCLK_EN();
						}
			else if(pGPIOx==GPIOF)
						{
							GPIOF_PCLK_EN();
						}
			else if(pGPIOx==GPIOG)
						{
							GPIOG_PCLK_EN();
						}
			else if(pGPIOx==GPIOH)
						{
							GPIOH_PCLK_EN();
						}
			else if(pGPIOx==GPIOI)
						{
							GPIOI_PCLK_EN();
						}
			else if(pGPIOx==GPIOJ)
						{
							GPIOJ_PCLK_EN();
						}

		}
		else
		{
						if(pGPIOx==GPIOA)
						{
							GPIOA_PCLK_DI();
						}
						else if(pGPIOx==GPIOB)
						{
							GPIOB_PCLK_DI();
						}
						else if(pGPIOx==GPIOC)
									{
										GPIOC_PCLK_DI();
									}
						else if(pGPIOx==GPIOD)
									{
										GPIOD_PCLK_DI();
									}
						else if(pGPIOx==GPIOE)
									{
										GPIOE_PCLK_DI();
									}
						else if(pGPIOx==GPIOF)
									{
										GPIOF_PCLK_DI();
									}
						else if(pGPIOx==GPIOG)
									{
										GPIOG_PCLK_DI();
									}
						else if(pGPIOx==GPIOH)
									{
										GPIOH_PCLK_DI();
									}
						else if(pGPIOx==GPIOI)
									{
										GPIOI_PCLK_DI();
									}
						else if(pGPIOx==GPIOJ)
									{
										GPIOJ_PCLK_DI();
									}

		}
	}


	/*
	 * @breif:
	 * @para1:
	 * @para2:
	 * @para3:
	 * @return value :none
	 */

	uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t  *pGPIOx,uint8_t PinNumber)
	{

           uint8_t Value;
           Value = (uint8_t)((pGPIOx->IDR>>PinNumber)& 0x00000001); //masking technique
           return Value;
	}
	/*
	 * @Brief:
	 * @para1:
	 * @para2:
	 * @para3:
	 * @return value :none
	 */

	uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t  *pGPIOx)
	{

		uint16_t Value;
		Value = (uint16_t)pGPIOx->IDR;
		return Value;

	}


	/*
	 * @Brief:
	 * @para1:
	 * @para2:
	 * @para3:
	 * @return value :none
	 */

	void GPIO_WriteOutInputPin(GPIO_RegDef_t  *pGPIOx,uint8_t PinNumber,uint8_t Value)
	{
		if(Value ==GPIO_PIN_SET)
		{
			pGPIOx->ODR |=(1<<PinNumber);
		}
		else
		{
			pGPIOx->ODR &= ~(1<<PinNumber);
		}

	}
	/*
	 * @breif:
	 * @para1:
	 * @para2:
	 * @para3:
	 * @return value :none
	 */

	void GPIO_WriteOutInputPort(GPIO_RegDef_t  *pGPIOx,uint8_t Value)
	{
         pGPIOx->ODR = Value;
	}
	/*
	 * @breif:
	 * @para1:
	 * @para2:
	 * @para3:
	 * @return value :none
	 */

	void GPIO_ToggleOutputPin(GPIO_RegDef_t  *pGPIOx,uint8_t PinNumber)
	{

		pGPIOx->ODR ^=(1<<PinNumber);
	}


