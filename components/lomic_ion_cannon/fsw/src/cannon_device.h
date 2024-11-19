/*******************************************************************************
** File: cannon_device.h
**
** Purpose:
**   This is the header file for the CANNON device.
**
*******************************************************************************/
#ifndef _CANNON_DEVICE_H_
#define _CANNON_DEVICE_H_

/*
** Required header files.
*/
#include "device_cfg.h"
#include "hwlib.h"
#include "cannon_platform_cfg.h"


/*
** Type definitions
** TODO: Make specific to your application
*/
#define CANNON_DEVICE_HDR              0xDEAD
#define CANNON_DEVICE_HDR_0            0xDE
#define CANNON_DEVICE_HDR_1            0xAD

#define CANNON_DEVICE_NOOP_CMD         0x00
#define CANNON_DEVICE_REQ_HK_CMD       0x01
#define CANNON_DEVICE_REQ_DATA_CMD     0x02
#define CANNON_DEVICE_CFG_CMD          0x03

#define CANNON_DEVICE_TRAILER          0xBEEF
#define CANNON_DEVICE_TRAILER_0        0xBE
#define CANNON_DEVICE_TRAILER_1        0xEF

#define CANNON_DEVICE_HDR_TRL_LEN      4
#define CANNON_DEVICE_CMD_SIZE         9

/*
** CANNON device housekeeping telemetry definition
*/
typedef struct
{
    uint32_t  DeviceCounter;
    uint32_t  DeviceConfig;
    uint32_t  DeviceStatus;

} __attribute__((packed)) CANNON_Device_HK_tlm_t;
#define CANNON_DEVICE_HK_LNGTH sizeof ( CANNON_Device_HK_tlm_t )
#define CANNON_DEVICE_HK_SIZE CANNON_DEVICE_HK_LNGTH + CANNON_DEVICE_HDR_TRL_LEN


/*
** CANNON device data telemetry definition
*/
typedef struct
{
    uint32_t  DeviceCounter;
    uint16_t  DeviceDataX;
    uint16_t  DeviceDataY;
    uint16_t  DeviceDataZ;

} __attribute__((packed)) CANNON_Device_Data_tlm_t;
#define CANNON_DEVICE_DATA_LNGTH sizeof ( CANNON_Device_Data_tlm_t )
#define CANNON_DEVICE_DATA_SIZE CANNON_DEVICE_DATA_LNGTH + CANNON_DEVICE_HDR_TRL_LEN


/*
** Prototypes
*/
int32_t CANNON_ReadData(uart_info_t* device, uint8_t* read_data, uint8_t data_length);
int32_t CANNON_CommandDevice(uart_info_t* device, uint8_t cmd, uint32_t payload);
int32_t CANNON_RequestHK(uart_info_t* device, CANNON_Device_HK_tlm_t* data);
int32_t CANNON_RequestData(uart_info_t* device, CANNON_Device_Data_tlm_t* data);


#endif /* _CANNON_DEVICE_H_ */
