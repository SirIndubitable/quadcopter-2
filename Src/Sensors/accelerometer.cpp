/****************************************************************************************
* File: accelerometer.cpp
*
* Description: 
*
* Created by Matt Olson
****************************************************************************************/

/*---------------------------------------------------------------------------------------
*                                       INCLUDES
*--------------------------------------------------------------------------------------*/
#include <cstring>
#include "Sensors/accelerometer.h"

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
Accelerometer::Accelerometer()
{
    this->X = 0.0;
    this->Y = 0.0;
    this->Z = 0.0;
    memset(this->raw_data, 0x00, 3 * sizeof(int16_t));
}
