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
lis3dsh_md_t mode{ lis3dsh_md_t::LIS3DSH_100Hz, lis3dsh_md_t::LIS3DSH_2g };

/*---------------------------------------------------------------------------------------
*                                     PROCEDURES
*--------------------------------------------------------------------------------------*/
static int32_t spi_write(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len)
{
    //SPI_HandleTypeDef* spi_handle = (SPI_HandleTypeDef*)handle;

    return (int32_t)HAL_ERROR;
}

static int32_t spi_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len)
{
    //SPI_HandleTypeDef* spi_handle = (SPI_HandleTypeDef*)handle;

    return (int32_t)HAL_ERROR;
}

LIS3DSH::LIS3DSH(SPI_HandleTypeDef* spi_handle) : Accelerometer()
{
    this->m_sensor.write_reg = spi_write;
    this->m_sensor.read_reg = spi_read;
    this->m_sensor.handle = (void*)spi_handle;
}

void LIS3DSH::Init(void)
{
    lis3dsh_init_set(&this->m_sensor, LIS3DSH_DRV_RDY);

    lis3dsh_mode_set(&this->m_sensor, &mode);
}

void LIS3DSH::UpdateData(void)
{
    lis3dsh_data_t data;
    lis3dsh_data_get(&this->m_sensor, &mode, &data);

    this->X = data.xl.mg[0];
    this->Y = data.xl.mg[1];
    this->Z = data.xl.mg[2];
}
