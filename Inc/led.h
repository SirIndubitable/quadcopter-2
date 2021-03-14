/****************************************************************************************
* File: led.h
*
* Description: The definition of the LED object
*
* Created by Matt Olson
****************************************************************************************/
#ifndef _LED_H
#define _LED_H

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------------------
*                                       INCLUDES
*--------------------------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"


/*---------------------------------------------------------------------------------------
*                                   LITERAL CONSTANTS
*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------
*                                        TYPES
*--------------------------------------------------------------------------------------*/
class LED
{
private: 
    GPIO_TypeDef* m_gpio;
    uint16_t m_pin;
public:
    LED(GPIO_TypeDef* gpio, uint16_t pin);
    void Init();
    void On();
    void Off();
    void Toggle();
};

/*---------------------------------------------------------------------------------------
*                                   MEMORY CONSTANTS
*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------
*                                      VARIABLES
*--------------------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif