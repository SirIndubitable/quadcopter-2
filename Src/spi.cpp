/****************************************************************************************
* File: spi.cpp
*
* Description: SPI communication protocol object
*
* Created by Matt Olson
****************************************************************************************/

/*---------------------------------------------------------------------------------------
*                                       INCLUDES
*--------------------------------------------------------------------------------------*/
#if defined(HAL_SPI_MODULE_ENABLED)
#include "spi.h"

/*---------------------------------------------------------------------------------------
*                                   LITERAL CONSTANTS
*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------
*                                        TYPES
*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------
*                                   MEMORY CONSTANTS
*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------
*                                      VARIABLES
*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------
*                                     PROCEDURES
*--------------------------------------------------------------------------------------*/
SPI::SPI(SPI_HandleTypeDef* spi, GPIO_TypeDef* gpio, uint16_t pin)
{
    this->m_spi = spi;
    this->m_chip_select_gpio = gpio;
    this->m_chip_select_pin = pin;
}

void SPI::Init(void)
{
    this->CS_Set();
}

void SPI::CS_Reset(void)
{
    HAL_GPIO_WritePin(this->m_chip_select_gpio, this->m_chip_select_pin, GPIO_PIN_RESET); //CS --> Low
}

void SPI::CS_Set(void)
{
    HAL_GPIO_WritePin(this->m_chip_select_gpio, this->m_chip_select_pin, GPIO_PIN_SET); //CS --> High
}

void SPI::ReadReg(uint8_t regAddress, uint8_t* data, uint16_t dataSize)
{
    this->CS_Reset();
    HAL_SPI_Transmit(this->m_spi, &regAddress, 1, 50);
    HAL_SPI_Receive(this->m_spi, data, dataSize, 50);
    this->CS_Set();
}

void SPI::WriteReg(uint8_t regAddress, uint8_t* outData, uint16_t dataSize)
{
    this->CS_Reset();
    HAL_SPI_Transmit(this->m_spi, &regAddress, 1, 50);
    HAL_SPI_Transmit(this->m_spi, outData, dataSize, 50);
    this->CS_Set();
}

#endif // defined(HAL_SPI_MODULE_ENABLED)