/*******************************************************************************
** File:
**   LOMIC_thruster_msg.h
**
** Purpose:
**  Define LOMIC_THRUSTER application commands and telemetry messages
**
*******************************************************************************/
#ifndef _LOMIC_THRUSTER_MSG_H_
#define _LOMIC_THRUSTER_MSG_H_

#include "cfe.h"


/*
** Ground Command Codes
*/
#define LOMIC_THRUSTER_NOOP_CC                 0
#define LOMIC_THRUSTER_RESET_COUNTERS_CC       1
#define LOMIC_THRUSTER_ENABLE_CC               2
#define LOMIC_THRUSTER_DISABLE_CC              3
#define LOMIC_THRUSTER_PERCENTAGE_CC           4

/* 
** Telemetry Request Command Codes
*/
#define LOMIC_THRUSTER_REQ_HK_TLM              0
#define LOMIC_THRUSTER_REQ_DATA_TLM            1


/*
** Generic "no arguments" command type definition
*/
typedef struct
{
    /* Every command requires a header used to identify it */
    CFE_MSG_CommandHeader_t CmdHeader;

} LOMIC_THRUSTER_NoArgs_cmd_t;

/*
** GENERIC_THRUSTER write configuration command
*/
typedef struct
{
    CFE_MSG_CommandHeader_t CmdHeader;
    uint32   DeviceCfg;

} LOMIC_THRUSTER_Config_cmd_t;

typedef struct
{
    CFE_MSG_CommandHeader_t CmdHeader;
    uint8                   ThrusterNumber;
    uint8                   Percentage;
    
} LOMIC_THRUSTER_Percentage_cmd_t;

/*
** GENERIC_THRUSTER housekeeping type definition
*/
typedef struct 
{
    CFE_MSG_TelemetryHeader_t TlmHeader;
    uint8   CommandErrorCount;
    uint8   CommandCount;
    uint8   DeviceErrorCount;
    uint8   DeviceCount;
    uint8   DeviceEnabled;

} __attribute__((packed)) LOMIC_THRUSTER_Hk_tlm_t;
#define LOMIC_THRUSTER_HK_TLM_LNGTH sizeof ( LOMIC_THRUSTER_Hk_tlm_t )

/*
** LOMIC_THRUSTER Telemetry type definition
*/
typedef struct 
{
    CFE_MSG_TelemetryHeader_t TlmHeader;
    uint8   CommandErrorCount;
    uint8   CommandCount;
    uint8   DeviceErrorCount;
    uint8   DeviceCount;
    uint8   DeviceEnabled;
    uint8   Thruster0Percentage;
    uint8   Thruster1Percentage;
    uint8   Thruster2Percentage;
    uint8   Thruster3Percentage;
    uint8   Thruster4Percentage;

} __attribute__((packed)) LOMIC_THRUSTER_tlm_t;
#define LOMIC_THRUSTER_TLM_LNGTH sizeof ( LOMIC_THRUSTER_tlm_t )

#endif /* _LOMIC_THRUSTER_MSG_H_ */
