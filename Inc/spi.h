/****************************************************************************************
* File: spi.h
*
* Description: The definition of the spi object
*
* Created by Matt Olson
****************************************************************************************/
#ifndef _SPI_H
#define _SPI_H

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------------------
*                                       INCLUDES
*--------------------------------------------------------------------------------------*/
#include "stm32_hal.h"

#include "iSensorCommunication.h"

/*---------------------------------------------------------------------------------------
*                                   LITERAL CONSTANTS
*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------
*                                        TYPES
*--------------------------------------------------------------------------------------*/
class SPI : public ISensorCommunication
{
private:
    SPI_HandleTypeDef* m_spi;
    GPIO_TypeDef* m_chip_select_gpio;
    uint16_t m_chip_select_pin;
    void CS_Reset(void);
    void CS_Set(void);
public:
    SPI(SPI_HandleTypeDef* spi, GPIO_TypeDef* gpio, uint16_t pin);
    void Init(void);
    void ReadReg(uint8_t regAddress, uint8_t* data, uint16_t dataSize);
    void WriteReg(uint8_t regAddress, uint8_t* outData, uint16_t dataSize);
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