/****************************************************************************************
* File: LIS3DSH.cpp
*
* Description: This object deals with an LIS3DSH senseor that you inteface with using
* register reads through a sensor communication protocol
* https://www.st.com/resource/en/datasheet/lis3dsh.pdf
*
* Created by Matt Olson
****************************************************************************************/

/*---------------------------------------------------------------------------------------
*                                       INCLUDES
*--------------------------------------------------------------------------------------*/
#include "Sensors/lis3dsh.h"

/*---------------------------------------------------------------------------------------
*                                   LITERAL CONSTANTS
*--------------------------------------------------------------------------------------*/
#define READ_MASK(VAL)        ((VAL) | 0b10000000)
#define WRITE_MASK(VAL)       ((VAL) & 0b01111111)

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
LIS3DSH::LIS3DSH(ISensorCommunication* sensor)
{
    this->m_sensor = sensor;
    this->X = 0.0;
    this->Y = 0.0;
    this->Z = 0.0;
}

void LIS3DSH::Init(void)
{
    this->m_sensor->Init();

    // Write CTRL_REG4 (0x20) to enable XYZ (xxxxx111) to continuously update (xxxx0xxx) at 100Hz (0110xxx)
    uint8_t ctrl_reg4_data = 0b01100111;
    this->m_sensor->WriteReg(WRITE_MASK(0x20), &ctrl_reg4_data, 1);
}

void LIS3DSH::UpdateData(void)
{
    uint16_t x, y, z;
    uint8_t buffer[6];

    // Make the highest bit a 1 to indicate to the sensor should read the register instead of write to it
    // Read 6 registers, X_Low, X_High, Y_Low, Y_High, Z_Low, Z_High
    this->m_sensor->ReadReg(READ_MASK(0x28), buffer, 6);

    x = ((uint16_t)buffer[1] << 8) | buffer[0];
    y = ((uint16_t)buffer[3] << 8) | buffer[2];
    z = ((uint16_t)buffer[5] << 8) | buffer[4];

    this->X = ((int16_t)x) / 2000.0;
    this->Y = ((int16_t)y) / 2000.0;
    this->Z = ((int16_t)z) / 2000.0;
}
