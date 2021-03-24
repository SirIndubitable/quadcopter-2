/****************************************************************************************
* File: accelerometer.h
*
* Description: The definition of the spi object
*
* Created by Matt Olson
****************************************************************************************/
#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------------------
*                                       INCLUDES
*--------------------------------------------------------------------------------------*/
#include "stm32_hal.h"

/*---------------------------------------------------------------------------------------
*                                   LITERAL CONSTANTS
*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------
*                                        TYPES
*--------------------------------------------------------------------------------------*/
class Accelerometer
{
private:

protected:

public:
    int16_t raw_data[3];
    float X, Y, Z;
    Accelerometer();
    virtual void Init(void) = 0;
    virtual void UpdateData(void) = 0;
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

#endif // ACCELEROMETER_H_