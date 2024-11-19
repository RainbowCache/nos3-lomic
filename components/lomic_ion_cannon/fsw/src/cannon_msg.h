/*******************************************************************************
** File:
**   cannon_msg.h
**
** Purpose:
**  Define CANNON application commands and telemetry messages
**
*******************************************************************************/
#ifndef _CANNON_MSG_H_
#define _CANNON_MSG_H_

#include "cfe.h"
#include "cannon_device.h"


/*
** Ground Command Codes
** TODO: Add additional commands required by the specific component
*/
#define CANNON_NOOP_CC                 0
#define CANNON_RESET_COUNTERS_CC       1
#define CANNON_ENABLE_CC               2
#define CANNON_DISABLE_CC              3
#define CANNON_CONFIG_CC               4


/* 
** Telemetry Request Command Codes
** TODO: Add additional commands required by the specific component
*/
#define CANNON_REQ_HK_TLM              0
#define CANNON_REQ_DATA_TLM            1


/*
** Generic "no arguments" command type definition
*/
typedef struct
{
    /* Every command requires a header used to identify it */
    CFE_MSG_CommandHeader_t CmdHeader;

} CANNON_NoArgs_cmd_t;


/*
** CANNON write configuration command
*/
typedef struct
{
    CFE_MSG_CommandHeader_t CmdHeader;
    uint32   DeviceCfg;

} CANNON_Config_cmd_t;


/*
** CANNON device telemetry definition
*/
typedef struct 
{
    CFE_MSG_TelemetryHeader_t TlmHeader;
    CANNON_Device_Data_tlm_t CANNON;

} __attribute__((packed)) CANNON_Device_tlm_t;
#define CANNON_DEVICE_TLM_LNGTH sizeof ( CANNON_Device_tlm_t )


/*
** CANNON housekeeping type definition
*/
typedef struct 
{
    CFE_MSG_TelemetryHeader_t TlmHeader;
    uint8   CommandErrorCount;
    uint8   CommandCount;
    uint8   DeviceErrorCount;
    uint8   DeviceCount;
  
    /*
    ** TODO: Edit and add specific telemetry values to this struct
    */
    uint8   DeviceEnabled;
    CANNON_Device_HK_tlm_t DeviceHK;

} __attribute__((packed)) CANNON_Hk_tlm_t;
#define CANNON_HK_TLM_LNGTH sizeof ( CANNON_Hk_tlm_t )

#endif /* _CANNON_MSG_H_ */
