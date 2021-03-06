/****************************************************************************************
* File: accelerometer.h
*
* Description: The definition of the accelerometer object
*
* Created by Matt Olson
****************************************************************************************/
#ifndef _ISENSORCOMMUNICATION_H
#define _ISENSORCOMMUNICATION_H

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------------------
*                                       INCLUDES
*--------------------------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/*---------------------------------------------------------------------------------------
*                                   LITERAL CONSTANTS
*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------
*                                        TYPES
*--------------------------------------------------------------------------------------*/
class ISensorCommunication
{
private:
    
public:
    virtual void Init(void) = 0;
    virtual void ReadReg(uint8_t regAddress, uint8_t* data, uint16_t dataSize) = 0;
    virtual void WriteReg(uint8_t regAddress, uint8_t* outData, uint16_t dataSize) = 0;
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