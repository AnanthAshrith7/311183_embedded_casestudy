/*
 * stm32f407xx.h
 *
 *  Created on: Sep 16, 2021
 *      Author: Koppolu Ananth Ashrith
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_
#include <stdint.h>
#define _vo volatile

/*
 * Memory mapping
 */

#define FLASH_BASEADDR    0x08000000U
#define SRAM1_BASEADDR    0x20000000U
#define SRAM2_BASEADDR    0x2001C000U
#define ROM_BASEADDR      0X1FFF0000U
#define SRAM_BASEADDR     SRAM1_BASEADDR

/*
 * APBx AND AHBx BUS PERIPHERIALS
 */
#define PERIPH_BASEADDR          0x40000000U
#define APB1PERIPH_BASEADDR      PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR      0x40010000U
#define AHB1PERIPH_BASEADDR      0x40020000U
#define AHB2PERIPH_BASEADDR      0x50000000U
#define AHB3PERIPH_BASEADDR      0xA0000000U
/*
 * Base address 0f peripherals hanging on AHB1 bus
 */

#define GPIOA_BASEADDR    (AHB1PERIPH_BASEADDR +  0x0000 )
#define GPIOB_BASEADDR    (AHB1PERIPH_BASEADDR +  0x0400 )
#define GPIOC_BASEADDR    (AHB1PERIPH_BASEADDR +  0x0800 )
#define GPIOD_BASEADDR    (AHB1PERIPH_BASEADDR +  0x0C00 )
#define GPIOE_BASEADDR    (AHB1PERIPH_BASEADDR +  0x1000 )
#define GPIOF_BASEADDR    (AHB1PERIPH_BASEADDR +  0x1400 )
#define GPIOG_BASEADDR    (AHB1PERIPH_BASEADDR +  0x1800 )
#define GPIOH_BASEADDR    (AHB1PERIPH_BASEADDR +  0x1C00 )
#define GPIOI_BASEADDR    (AHB1PERIPH_BASEADDR +  0x2000 )
#define GPIOJ_BASEADDR    (AHB1PERIPH_BASEADDR +  0X2400 )
#define RCC_BASEADDR      (AHB1PERIPH_BASEADDR +  0x3800 )
/*
 * Base address 0f peripherals hanging on APB1 bus
 */
#define I2C1_BASEADDR    (APB1PERIPH_BASEADDR +  0x5400 )
#define I2C2_BASEADDR    (APB1PERIPH_BASEADDR +  0x5800 )
#define I2C3_BASEADDR    (APB1PERIPH_BASEADDR +  0x5C00 )
#define SPI2_BASEADDR    (APB1PERIPH_BASEADDR +  0x3800 )
#define SPI3_BASEADDR    (APB1PERIPH_BASEADDR +  0x3C00 )
#define USART2_BASEADDR  (APB1PERIPH_BASEADDR +  0x4400 )
#define USART3_BASEADDR  (APB1PERIPH_BASEADDR +  0x4800 )
#define UART4_BASEADDR   (APB1PERIPH_BASEADDR +  0x4C00 )
#define UART5_BASEADDR   (APB1PERIPH_BASEADDR +  0x5000 )


/*
 * Base address 0f peripherals hanging on APB2 bus
 */
#define EXTI_BASEADDR    (APB2PERIPH_BASEADDR +  0x3C00 )
#define SYSCFG_BASEADDR  (APB2PERIPH_BASEADDR +  0x3800 )
#define SPI1_BASEADDR    (APB2PERIPH_BASEADDR +  0x3000 )
#define SPI4_BASEADDR    (APB2PERIPH_BASEADDR +  0x3400 )
#define USART6_BASEADDR  (APB2PERIPH_BASEADDR +  0x1400 )
#define USART1_BASEADDR  (APB2PERIPH_BASEADDR +  0x1000 )


/*
 * peripheral structure defination
 */
typedef struct
{
	_vo	uint32_t MODER;
	_vo	uint32_t OTYPER;
	_vo	uint32_t OSPEEDR;
	_vo	uint32_t PUPDR;
	_vo	uint32_t IDR;
	_vo	uint32_t ODR;
	_vo	uint32_t BSRR;
	_vo	uint32_t LCKR;
	_vo	uint32_t AFR[2];
}GPIO_RegDef_t;

typedef struct
{
	uint32_t CR;
	uint32_t PLLCFGR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t AHB1RSTR;
	uint32_t AHB2RSTR;
	uint32_t AHB3RSTR;
	uint32_t RESERVED0;
	uint32_t APB1RSTR;
	uint32_t APB2RSTR;
	uint32_t RESERVED1[2];
	uint32_t AHB1ENR;
	uint32_t AHB2ENR;
	uint32_t AHB3ENR;
	uint32_t RESERVED2;
	uint32_t APB1ENR;
	uint32_t APB2ENR;
	uint32_t RESERVED3[2];
	uint32_t AHB1LPENR;
	uint32_t AHB2LPENR;
	uint32_t AHB3LPENR;
	uint32_t RESERVED4;
	uint32_t APB1LPENR;
	uint32_t APB2LPENR;
	uint32_t RESERVED5[2];
	uint32_t BDCR;
	uint32_t CSR;
	uint32_t RESERVED6[2];
	uint32_t SSCGR;
	uint32_t PLLI2SCFGR;

}RCC_RegDef_t;

/*
 * peripheral definition
 */

#define GPIOA    ((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB    ((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC    ((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD    ((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE    ((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF    ((GPIO_RegDef_t*) GPIOF_BASEADDR)
#define GPIOG    ((GPIO_RegDef_t*) GPIOG_BASEADDR)
#define GPIOH    ((GPIO_RegDef_t*) GPIOH_BASEADDR)
#define GPIOI    ((GPIO_RegDef_t*) GPIOI_BASEADDR)
#define GPIOJ    ((GPIO_RegDef_t*) GPIOJ_BASEADDR)
#define RCC      ((RCC_RegDef_t*)  RCC_BASEADDR)

/*
 * ENABLE MARCROS
 */

#define GPIOA_PCLK_EN()    (RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN()    (RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN()    (RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN()    (RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN()    (RCC->AHB1ENR |= (1<<4))
#define GPIOF_PCLK_EN()    (RCC->AHB1ENR |= (1<<5))
#define GPIOG_PCLK_EN()    (RCC->AHB1ENR |= (1<<6))
#define GPIOH_PCLK_EN()    (RCC->AHB1ENR |= (1<<7))
#define GPIOI_PCLK_EN()    (RCC->AHB1ENR |= (1<<8))
#define GPIOJ_PCLK_EN()    (RCC->AHB1ENR |= (1<<9))


#define I2C1_PCLK_EN()    (RCC->AHB1ENR  |= (1<<21))
#define I2C2_PCLK_EN()    (RCC->AHB1ENR |= (1<<22))
#define I2C3_PCLK_EN()    (RCC->AHB1ENR  |= (1<<23))


#define SPI1_PCLK_EN()    (RCC->AHB2ENR  |= (1<<12))
#define SPI2_PCLK_EN())    (RCC->AHB1ENR  |= (1<<14))
#define SPI3_PCLK_EN())    (RCC->AHB1ENR  |= 1<<15))


#define USART1_PCLK_EN()    (RCC->AHB2ENR  |= (1<<4))
#define USART2_PCLK_EN()    (RCC->AHB1ENR  |= (1<<17))
#define USART3_PCLK_EN()    (RCC->AHB1ENR  |= (1<<18))
#define UART4_PCLK_EN()     (RCC->AHB1ENR  |= (1<<19))
#define UART5_PCLK_EN()     (RCC->AHB1ENR  |= (1<<20))


#define SYSCFG_PCLK_EN()    (RCC->AHB2ENR  |= (1<<18))


/*
 * DIABLE MACROS
 */
#define GPIOA_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<4))
#define GPIOF_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<5))
#define GPIOG_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<6))
#define GPIOH_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<7))
#define GPIOI_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<8))
#define GPIOJ_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<9))


#define I2C1_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<21))
#define I2C2_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<22))
#define I2C3_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<23))


#define SPI1_PCLK_DI()    (RCC->AHB2ENR &= ~(1<<12))
#define SPI2_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<14))
#define SPI3_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<15))


#define USART1_PCLK_DI()    (RCC->AHB2ENR &= ~(1<<4))
#define USART2_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<17))
#define USART3_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<18))
#define UART4_PCLK_DI()     (RCC->AHB1ENR &= ~(1<<19))
#define UART5_PCLK_DI()     (RCC->AHB1ENR &= ~(1<<20))


#define SYSCFG_PCLK_DI()    (RCC->AHB2ENR &= ~(1<<18))

/*
 * GPIO RESTTING
 */

#define GPIOA_REG_RESET()   do{ (RCC->AHB1RSTR |= (1<<0));    ( RCC->AHB1RSTR &= ~(1<<0)); }while(0)
#define GPIOB_REG_RESET()   do{ (RCC->AHB1RSTR |= (1<<1));    ( RCC->AHB1RSTR &= ~(1<<1)); }while(0)
#define GPIOC_REG_RESET()   do{ (RCC->AHB1RSTR |= (1<<2));    ( RCC->AHB1RSTR &= ~(1<<2)); }while(0)
#define GPIOD_REG_RESET()   do{ (RCC->AHB1RSTR |= (1<<3));    ( RCC->AHB1RSTR &= ~(1<<3)); }while(0)
#define GPIOE_REG_RESET()   do{ (RCC->AHB1RSTR |= (1<<4));    ( RCC->AHB1RSTR &= ~(1<<4)); }while(0)
#define GPIOF_REG_RESET()   do{ (RCC->AHB1RSTR |= (1<<5));    ( RCC->AHB1RSTR &= ~(1<<5)); }while(0)
#define GPIOG_REG_RESET()   do{ (RCC->AHB1RSTR |= (1<<6));    ( RCC->AHB1RSTR &= ~(1<<6)); }while(0)
#define GPIOH_REG_RESET()   do{ (RCC->AHB1RSTR |= (1<<7));    ( RCC->AHB1RSTR &= ~(1<<7)); }while(0)
#define GPIOI_REG_RESET()   do{ (RCC->AHB1RSTR |= (1<<8));    ( RCC->AHB1RSTR &= ~(1<<8)); }while(0)
#define GPIOJ_REG_RESET()   do{ (RCC->AHB1RSTR |= (1<<9));    ( RCC->AHB1RSTR &= ~(1<<9)); }while(0)

/***Geniric Macros**/
#define ENABLE         1
#define DISABLE        0
#define SET            ENABLE //1
#define RESET          DISABLE//0
#define GPIO_PIN_SET   SET
#define GPIO_PIN_RESET   RESET
#define Two_Blink     2
#define Three_Blink   3


#include "stm32f4Xx_gpio_driver.h"

#endif /* INC_STM32F407XX_H_ */
