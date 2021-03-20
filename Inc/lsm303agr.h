/****************************************************************************************
* File: lsm303agr.h
*
* Description: The definition of the lsm303agr object
*
* Created by Matt Olson
****************************************************************************************/
#ifndef _LSM303AGR_H
#define _LSM303AGR_H

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------------------
*                                       INCLUDES
*--------------------------------------------------------------------------------------*/
#include "iSensorCommunication.h"

/*---------------------------------------------------------------------------------------
*                                   LITERAL CONSTANTS
*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------
*                                        TYPES
*--------------------------------------------------------------------------------------*/
class LSM303AGR
{
private:
    ISensorCommunication* m_sensor;
public:
    float X, Y, Z;
    LSM303AGR(ISensorCommunication* sensor);
    void Init(void);
    void UpdateData(void);
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