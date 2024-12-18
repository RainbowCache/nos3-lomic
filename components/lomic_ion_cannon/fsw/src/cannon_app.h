/*******************************************************************************
** File: cannon_app.h
**
** Purpose:
**   This is the main header file for the CANNON application.
**
*******************************************************************************/
#ifndef _CANNON_APP_H_
#define _CANNON_APP_H_

/*
** Include Files
*/
#include <time.h>
#include "cfe.h"
#include "cannon_device.h"
#include "cannon_events.h"
#include "cannon_platform_cfg.h"
#include "cannon_perfids.h"
#include "cannon_msg.h"
#include "cannon_msgids.h"
#include "cannon_version.h"
#include "hwlib.h"


/*
** Specified pipe depth - how many messages will be queued in the pipe
*/
#define CANNON_PIPE_DEPTH            32


/*
** Enabled and Disabled Definitions
*/
#define CANNON_DEVICE_DISABLED       0
#define CANNON_DEVICE_ENABLED        1


/*
** CANNON global data structure
** The cFE convention is to put all global app data in a single struct. 
** This struct is defined in the `cannon_app.h` file with one global instance 
** in the `.c` file.
*/
typedef struct
{
    /*
    ** Housekeeping telemetry packet
    ** Each app defines its own packet which contains its OWN telemetry
    */
    CANNON_Hk_tlm_t   HkTelemetryPkt;   /* CANNON Housekeeping Telemetry Packet */
    
    /*
    ** Operational data  - not reported in housekeeping
    */
    CFE_MSG_Message_t * MsgPtr;             /* Pointer to msg received on software bus */
    CFE_SB_PipeId_t CmdPipe;            /* Pipe Id for HK command pipe */
    uint32 RunStatus;                   /* App run status for controlling the application state */

    /*
	** Device data 
    ** TODO: Make specific to your application
	*/
    CANNON_Device_tlm_t DevicePkt;      /* Device specific data packet */

    /* 
    ** Device protocol
    ** TODO: Make specific to your application
    */ 
    uart_info_t CANNONUart;             /* Hardware protocol definition */

    /*
    ** Last update time to check firing power
    */
    time_t LastUpdateTime;              /* Last update time for firing power */

} CANNON_AppData_t;


/*
** Exported Data
** Extern the global struct in the header for the Unit Test Framework (UTF).
*/
extern CANNON_AppData_t CANNON_AppData; /* CANNON App Data */


/*
**
** Local function prototypes.
**
** Note: Except for the entry point (CANNON_AppMain), these
**       functions are not called from any other source module.
*/
void  CANNON_AppMain(void);
int32 CANNON_AppInit(void);
void  CANNON_ProcessCommandPacket(void);
void  CANNON_ProcessGroundCommand(void);
void  CANNON_ProcessTelemetryRequest(void);
void  CANNON_ReportHousekeeping(void);
void  CANNON_ReportDeviceTelemetry(void);
void  CANNON_ResetCounters(void);
void  CANNON_Enable(void);
void  CANNON_Disable(void);
int32 CANNON_VerifyCmdLength(CFE_MSG_Message_t * msg, uint16 expected_length);

#endif /* _CANNON_APP_H_ */
