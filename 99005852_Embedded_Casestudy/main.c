#include "stm32f407xx.h"
#define BTN_PRESSED1 ENABLE
#define BTN_PRESSED2 Two_Blink
#define BTN_PRESSED3 Three_Blink
void delay(void)
{
	for (uint32_t i=0; i<5000000; i++);
}
int main(void)
{
	GPIO_Handle_t GpioLedG,GpioLedO,GpioLedR,GpioLedB,GPIOBUT;
	GpioLedG.pGPIOx = GPIOD;
	GpioLedG.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_12;
	GpioLedG.GPIO_PinConfig.GPIO_PinMode =GPIO_MODE_OUT;
	GpioLedG.GPIO_PinConfig.GPIO_PinSpeed =GPIO_SPEED_LOW;
	GpioLedG.GPIO_PinConfig.GPIO_PinOutputtype = GPIO_OP_TYPE_PP;
	GpioLedG.GPIO_PinConfig.GPIO_PinPupdrControl=GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLedG);

	GpioLedO.pGPIOx = GPIOD;
	GpioLedO.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_13;
	GpioLedO.GPIO_PinConfig.GPIO_PinMode =GPIO_MODE_OUT;
	GpioLedO.GPIO_PinConfig.GPIO_PinSpeed =GPIO_SPEED_LOW;
	GpioLedO.GPIO_PinConfig.GPIO_PinOutputtype = GPIO_OP_TYPE_PP;
	GpioLedO.GPIO_PinConfig.GPIO_PinPupdrControl=GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLedO);


	GpioLedR.pGPIOx = GPIOD;
	GpioLedR.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_14;
	GpioLedR.GPIO_PinConfig.GPIO_PinMode =GPIO_MODE_OUT;
	GpioLedR.GPIO_PinConfig.GPIO_PinSpeed =GPIO_SPEED_LOW;
	GpioLedR.GPIO_PinConfig.GPIO_PinOutputtype = GPIO_OP_TYPE_PP;
	GpioLedR.GPIO_PinConfig.GPIO_PinPupdrControl=GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLedR);

	GpioLedB.pGPIOx = GPIOD;
	GpioLedB.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_15;
	GpioLedB.GPIO_PinConfig.GPIO_PinMode =GPIO_MODE_OUT;
	GpioLedB.GPIO_PinConfig.GPIO_PinSpeed =GPIO_SPEED_LOW;
	GpioLedB.GPIO_PinConfig.GPIO_PinOutputtype = GPIO_OP_TYPE_PP;
	GpioLedB.GPIO_PinConfig.GPIO_PinPupdrControl=GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLedB);

	GPIOBUT.pGPIOx = GPIOA;
	GPIOBUT.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_0;
	GPIOBUT.GPIO_PinConfig.GPIO_PinMode =GPIO_MODE_IN;
	GPIOBUT.GPIO_PinConfig.GPIO_PinSpeed =GPIO_SPEED_MED;
	GPIOBUT.GPIO_PinConfig.GPIO_PinPupdrControl=GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GPIOBUT);

	while(1)
	{
		GPIO_ToggleOutputPin((GPIOD), GPIO_PIN_NO_12);
		delay();
		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESSED1)
		{
			while(1)
			{
				GPIO_ToggleOutputPin((GPIOD), GPIO_PIN_NO_12);
				delay();
				GPIO_ToggleOutputPin((GPIOD), GPIO_PIN_NO_13);
				delay();
				GPIO_ToggleOutputPin((GPIOD), GPIO_PIN_NO_14);
				delay();
				GPIO_ToggleOutputPin((GPIOD), GPIO_PIN_NO_15);
				delay();

			}


		}
		else if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESSED2)
		{
			GPIO_ToggleOutputPin((GPIOD), GPIO_PIN_NO_14);
			delay();
			//break;

		}
		else if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESSED3)
		{
			GPIO_ToggleOutputPin((GPIOD), GPIO_PIN_NO_15);
			delay();
			//break;

		}


	}



    return 0;
}