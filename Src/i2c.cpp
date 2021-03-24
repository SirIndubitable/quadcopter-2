/****************************************************************************************
* File: i2c.cpp
*
* Description: I2C communication protocol object
*
* Created by Matt Olson
****************************************************************************************/
//#if defined(HAL_I2C_MODULE_ENABLED)
/*---------------------------------------------------------------------------------------
*                                       INCLUDES
*--------------------------------------------------------------------------------------*/
#include "i2c.h"

/*---------------------------------------------------------------------------------------
*                                   LITERAL CONSTANTS
*--------------------------------------------------------------------------------------*/
#define _I2C_READ_MASK(VAL)        ((VAL) | 0b00000001)
#define _I2C_WRITE_MASK(VAL)       ((VAL) & 0b11111110)

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

I2C::I2C(I2C_HandleTypeDef* i2c)
{
    this->m_i2c = i2c;
}

void I2C::Init(void)
{
}

void I2C::ReadReg(uint8_t regAddress, uint8_t* data, uint16_t dataSize)
{
    HAL_I2C_Master_Receive(this->m_i2c, _I2C_READ_MASK(regAddress << 1), data, dataSize, 50);
}

void I2C::WriteReg(uint8_t regAddress, uint8_t* outData, uint16_t dataSize)
{
    HAL_I2C_Master_Transmit(this->m_i2c, _I2C_WRITE_MASK(regAddress << 1), outData, dataSize, 50);
}

//#endif // defined(HAL_I2C_MODULE_ENABLED)