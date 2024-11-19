/*******************************************************************************
** File: cannon_app.c
**
** Purpose:
**   This file contains the source code for the CANNON application.
**
*******************************************************************************/

/*
** Include Files
*/
#include <arpa/inet.h>
#include "cannon_app.h"


/*
** Global Data
*/
CANNON_AppData_t CANNON_AppData;

/*
** Application entry point and main process loop
*/
void CANNON_AppMain(void)
{
    int32 status = OS_SUCCESS;

    /*
    ** Create the first Performance Log entry
    */
    CFE_ES_PerfLogEntry(CANNON_PERF_ID);

    /* 
    ** Perform application initialization
    */
    status = CANNON_AppInit();
    if (status != CFE_SUCCESS)
    {
        CANNON_AppData.RunStatus = CFE_ES_RunStatus_APP_ERROR;
    }

    /*
    ** Main loop
    */
    while (CFE_ES_RunLoop(&CANNON_AppData.RunStatus) == true)
    {
        /*
        ** Performance log exit stamp
        */
        CFE_ES_PerfLogExit(CANNON_PERF_ID);

        /* 
        ** Pend on the arrival of the next Software Bus message
        ** Note that this is the standard, but timeouts are available
        */
        status = CFE_SB_ReceiveBuffer((CFE_SB_Buffer_t **)&CANNON_AppData.MsgPtr,  CANNON_AppData.CmdPipe,  CFE_SB_PEND_FOREVER);
        
        /* 
        ** Begin performance metrics on anything after this line. This will help to determine
        ** where we are spending most of the time during this app execution.
        */
        CFE_ES_PerfLogEntry(CANNON_PERF_ID);

        /*
        ** If the CFE_SB_ReceiveBuffer was successful, then continue to process the command packet
        ** If not, then exit the application in error.
        ** Note that a SB read error should not always result in an app quitting.
        */
        if (status == CFE_SUCCESS)
        {
            CANNON_ProcessCommandPacket();
        }
        else
        {
            CFE_EVS_SendEvent(CANNON_PIPE_ERR_EID, CFE_EVS_EventType_ERROR, "CANNON: SB Pipe Read Error = %d", (int) status);
            CANNON_AppData.RunStatus = CFE_ES_RunStatus_APP_ERROR;
        }
    }

    /*
    ** Disable component, which cleans up the interface, upon exit
    */
    CANNON_Disable();

    /*
    ** Performance log exit stamp
    */
    CFE_ES_PerfLogExit(CANNON_PERF_ID);

    /*
    ** Exit the application
    */
    CFE_ES_ExitApp(CANNON_AppData.RunStatus);
} 


/* 
** Initialize application
*/
int32 CANNON_AppInit(void)
{
    int32 status = OS_SUCCESS;
    
    CANNON_AppData.RunStatus = CFE_ES_RunStatus_APP_RUN;

    /*
    ** Register the events
    */ 
    status = CFE_EVS_Register(NULL, 0, CFE_EVS_EventFilter_BINARY);    /* as default, no filters are used */
    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("CANNON: Error registering for event services: 0x%08X\n", (unsigned int) status);
       return status;
    }

    /*
    ** Create the Software Bus command pipe 
    */
    status = CFE_SB_CreatePipe(&CANNON_AppData.CmdPipe, CANNON_PIPE_DEPTH, "CANNON_CMD_PIPE");
    if (status != CFE_SUCCESS)
    {
        CFE_EVS_SendEvent(CANNON_PIPE_ERR_EID, CFE_EVS_EventType_ERROR,
            "Error Creating SB Pipe,RC=0x%08X",(unsigned int) status);
       return status;
    }
    
    /*
    ** Subscribe to ground commands
    */
    status = CFE_SB_Subscribe(CFE_SB_ValueToMsgId(CANNON_CMD_MID), CANNON_AppData.CmdPipe);
    if (status != CFE_SUCCESS)
    {
        CFE_EVS_SendEvent(CANNON_SUB_CMD_ERR_EID, CFE_EVS_EventType_ERROR,
            "Error Subscribing to HK Gnd Cmds, MID=0x%04X, RC=0x%08X",
            CANNON_CMD_MID, (unsigned int) status);
        return status;
    }

    /*
    ** Subscribe to housekeeping (hk) message requests
    */
    status = CFE_SB_Subscribe(CFE_SB_ValueToMsgId(CANNON_REQ_HK_MID), CANNON_AppData.CmdPipe);
    if (status != CFE_SUCCESS)
    {
        CFE_EVS_SendEvent(CANNON_SUB_REQ_HK_ERR_EID, CFE_EVS_EventType_ERROR,
            "Error Subscribing to HK Request, MID=0x%04X, RC=0x%08X",
            CANNON_REQ_HK_MID, (unsigned int) status);
        return status;
    }

    /*
    ** TODO: Subscribe to any other messages here
    */


    /* 
    ** Initialize the published HK message - this HK message will contain the 
    ** telemetry that has been defined in the CANNON_HkTelemetryPkt for this app.
    */
    CFE_MSG_Init(CFE_MSG_PTR(CANNON_AppData.HkTelemetryPkt.TlmHeader),
                   CFE_SB_ValueToMsgId(CANNON_HK_TLM_MID),
                   CANNON_HK_TLM_LNGTH);

    /*
    ** Initialize the device packet message
    ** This packet is specific to your application
    */
    CFE_MSG_Init(CFE_MSG_PTR(CANNON_AppData.DevicePkt.TlmHeader),
                   CFE_SB_ValueToMsgId(CANNON_DEVICE_TLM_MID),
                   CANNON_DEVICE_TLM_LNGTH);

    /*
    ** TODO: Initialize any other messages that this app will publish
    */


    /* 
    ** Always reset all counters during application initialization 
    */
    CANNON_ResetCounters();

    /*
    ** Initialize application data
    ** Note that counters are excluded as they were reset in the previous code block
    */
    CANNON_AppData.HkTelemetryPkt.DeviceEnabled = CANNON_DEVICE_DISABLED;
    CANNON_AppData.HkTelemetryPkt.DeviceHK.DeviceCounter = 0;
    CANNON_AppData.HkTelemetryPkt.DeviceHK.DeviceConfig = 0;
    CANNON_AppData.HkTelemetryPkt.DeviceHK.DeviceStatus = 0;

    /* 
     ** Send an information event that the app has initialized. 
     ** This is useful for debugging the loading of individual applications.
     */
    status = CFE_EVS_SendEvent(CANNON_STARTUP_INF_EID, CFE_EVS_EventType_INFORMATION,
               "CANNON App Initialized. Version %d.%d.%d.%d",
                CANNON_MAJOR_VERSION,
                CANNON_MINOR_VERSION, 
                CANNON_REVISION, 
                CANNON_MISSION_REV);	
    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("CANNON: Error sending initialization event: 0x%08X\n", (unsigned int) status);
    }
    return status;
} 


/* 
** Process packets received on the CANNON command pipe
*/
void CANNON_ProcessCommandPacket(void)
{
    CFE_SB_MsgId_t MsgId = CFE_SB_INVALID_MSG_ID;
    CFE_MSG_GetMsgId(CANNON_AppData.MsgPtr, &MsgId);
    switch (CFE_SB_MsgIdToValue(MsgId))
    {
        /*
        ** Ground Commands with command codes fall under the CANNON_CMD_MID (Message ID)
        */
        case CANNON_CMD_MID:
            CANNON_ProcessGroundCommand();
            break;

        /*
        ** All other messages, other than ground commands, add to this case statement.
        */
        case CANNON_REQ_HK_MID:
            CANNON_ProcessTelemetryRequest();
            break;

        /*
        ** All other invalid messages that this app doesn't recognize, 
        ** increment the command error counter and log as an error event.  
        */
        default:
            CANNON_AppData.HkTelemetryPkt.CommandErrorCount++;
            CFE_EVS_SendEvent(CANNON_PROCESS_CMD_ERR_EID,CFE_EVS_EventType_ERROR, "CANNON: Invalid command packet, MID = 0x%x", CFE_SB_MsgIdToValue(MsgId));
            break;
    }
    return;
} 


/*
** Process ground commands
** TODO: Add additional commands required by the specific component
*/
void CANNON_ProcessGroundCommand(void)
{
    int32 status = OS_SUCCESS;
    CFE_SB_MsgId_t MsgId = CFE_SB_INVALID_MSG_ID;
    CFE_MSG_FcnCode_t CommandCode = 0;

    /*
    ** MsgId is only needed if the command code is not recognized. See default case
    */
    CFE_MSG_GetMsgId(CANNON_AppData.MsgPtr, &MsgId);

    /*
    ** Ground Commands, by definition, have a command code (_CC) associated with them
    ** Pull this command code from the message and then process
    */
    CFE_MSG_GetFcnCode(CANNON_AppData.MsgPtr, &CommandCode);
    switch (CommandCode)
    {
        /*
        ** NOOP Command
        */
        case CANNON_NOOP_CC:
            /*
            ** First, verify the command length immediately after CC identification 
            ** Note that VerifyCmdLength handles the command and command error counters
            */
            if (CANNON_VerifyCmdLength(CANNON_AppData.MsgPtr, sizeof(CANNON_NoArgs_cmd_t)) == OS_SUCCESS)
            {
                /* Second, send EVS event on successful receipt ground commands*/
                CFE_EVS_SendEvent(CANNON_CMD_NOOP_INF_EID, CFE_EVS_EventType_INFORMATION, "CANNON: NOOP command received");
                /* Third, do the desired command action if applicable, in the case of NOOP it is no operation */
            }
            break;

        /*
        ** Reset Counters Command
        */
        case CANNON_RESET_COUNTERS_CC:
            if (CANNON_VerifyCmdLength(CANNON_AppData.MsgPtr, sizeof(CANNON_NoArgs_cmd_t)) == OS_SUCCESS)
            {
                CFE_EVS_SendEvent(CANNON_CMD_RESET_INF_EID, CFE_EVS_EventType_INFORMATION, "CANNON: RESET counters command received");
                CANNON_ResetCounters();
            }
            break;

        /*
        ** Enable Command
        */
        case CANNON_ENABLE_CC:
            if (CANNON_VerifyCmdLength(CANNON_AppData.MsgPtr, sizeof(CANNON_NoArgs_cmd_t)) == OS_SUCCESS)
            {
                CFE_EVS_SendEvent(CANNON_CMD_ENABLE_INF_EID, CFE_EVS_EventType_INFORMATION, "CANNON: Enable command received");
                CANNON_Enable();
            }
            break;

        /*
        ** Disable Command
        */
        case CANNON_DISABLE_CC:
            if (CANNON_VerifyCmdLength(CANNON_AppData.MsgPtr, sizeof(CANNON_NoArgs_cmd_t)) == OS_SUCCESS)
            {
                CFE_EVS_SendEvent(CANNON_CMD_DISABLE_INF_EID, CFE_EVS_EventType_INFORMATION, "CANNON: Disable command received");
                CANNON_Disable();
            }
            break;

        /*
        ** TODO: Edit and add more command codes as appropriate for the application
        ** Set Configuration Command
        ** Note that this is an example of a command that has additional arguments
        */
        case CANNON_CONFIG_CC:
            if (CANNON_VerifyCmdLength(CANNON_AppData.MsgPtr, sizeof(CANNON_Config_cmd_t)) == OS_SUCCESS)
            {
                uint32_t config = ntohl(((CANNON_Config_cmd_t*) CANNON_AppData.MsgPtr)->DeviceCfg); // command is defined as big-endian... need to convert to host representation
                CFE_EVS_SendEvent(CANNON_CMD_CONFIG_INF_EID, CFE_EVS_EventType_INFORMATION, "CANNON: Configuration command received: %u", config);
                /* Command device to send HK */
                status = CANNON_CommandDevice(&CANNON_AppData.CANNONUart, CANNON_DEVICE_CFG_CMD, config);
                if (status == OS_SUCCESS)
                {
                    CANNON_AppData.HkTelemetryPkt.DeviceCount++;
                }
                else
                {
                    CANNON_AppData.HkTelemetryPkt.DeviceErrorCount++;
                }
            }
            break;

        /*
        ** Invalid Command Codes
        */
        default:
            /* Increment the error counter upon receipt of an invalid command */
            CANNON_AppData.HkTelemetryPkt.CommandErrorCount++;
            CFE_EVS_SendEvent(CANNON_CMD_ERR_EID, CFE_EVS_EventType_ERROR, 
                "CANNON: Invalid command code for packet, MID = 0x%x, cmdCode = 0x%x", CFE_SB_MsgIdToValue(MsgId), CommandCode);
            break;
    }
    return;
} 


/*
** Process Telemetry Request - Triggered in response to a telemetery request
** TODO: Add additional telemetry required by the specific component
*/
void CANNON_ProcessTelemetryRequest(void)
{
    CFE_SB_MsgId_t MsgId = CFE_SB_INVALID_MSG_ID;
    CFE_MSG_FcnCode_t CommandCode = 0;

    /* MsgId is only needed if the command code is not recognized. See default case */
    CFE_MSG_GetMsgId(CANNON_AppData.MsgPtr, &MsgId);

    /* Pull this command code from the message and then process */
    CFE_MSG_GetFcnCode(CANNON_AppData.MsgPtr, &CommandCode);
    switch (CommandCode)
    {
        case CANNON_REQ_HK_TLM:
            CANNON_ReportHousekeeping();
            break;

        case CANNON_REQ_DATA_TLM:
            CANNON_ReportDeviceTelemetry();
            break;

        /*
        ** Invalid Command Codes
        */
        default:
            /* Increment the error counter upon receipt of an invalid command */
            CANNON_AppData.HkTelemetryPkt.CommandErrorCount++;
            CFE_EVS_SendEvent(CANNON_DEVICE_TLM_ERR_EID, CFE_EVS_EventType_ERROR, 
                "CANNON: Invalid command code for packet, MID = 0x%x, cmdCode = 0x%x", CFE_SB_MsgIdToValue(MsgId), CommandCode);
            break;
    }
    return;
}


/* 
** Report Application Housekeeping
*/
void CANNON_ReportHousekeeping(void)
{
    int32 status = OS_SUCCESS;

    /* Check that device is enabled */
    if (CANNON_AppData.HkTelemetryPkt.DeviceEnabled == CANNON_DEVICE_ENABLED)
    {
        status = CANNON_RequestHK(&CANNON_AppData.CANNONUart, (CANNON_Device_HK_tlm_t*) &CANNON_AppData.HkTelemetryPkt.DeviceHK);
        if (status == OS_SUCCESS)
        {
            CANNON_AppData.HkTelemetryPkt.DeviceCount++;
        }
        else
        {
            CANNON_AppData.HkTelemetryPkt.DeviceErrorCount++;
            CFE_EVS_SendEvent(CANNON_REQ_HK_ERR_EID, CFE_EVS_EventType_ERROR, 
                    "CANNON: Request device HK reported error %d", status);
        }
    }
    /* Intentionally do not report errors if disabled */

    /* Time stamp and publish housekeeping telemetry */
    CFE_SB_TimeStampMsg((CFE_MSG_Message_t *) &CANNON_AppData.HkTelemetryPkt);
    CFE_SB_TransmitMsg((CFE_MSG_Message_t *) &CANNON_AppData.HkTelemetryPkt, true);
    return;
}


/*
** Collect and Report Device Telemetry
*/
void CANNON_ReportDeviceTelemetry(void)
{
    int32 status = OS_SUCCESS;

    /* Check that device is enabled */
    if (CANNON_AppData.HkTelemetryPkt.DeviceEnabled == CANNON_DEVICE_ENABLED)
    {
        status = CANNON_RequestData(&CANNON_AppData.CANNONUart, (CANNON_Device_Data_tlm_t*) &CANNON_AppData.DevicePkt.CANNON);
        if (status == OS_SUCCESS)
        {
            CANNON_AppData.HkTelemetryPkt.DeviceCount++;
            /* Time stamp and publish data telemetry */
            CFE_SB_TimeStampMsg((CFE_MSG_Message_t *) &CANNON_AppData.DevicePkt);
            CFE_SB_TransmitMsg((CFE_MSG_Message_t *) &CANNON_AppData.DevicePkt, true);
        }
        else
        {
            CANNON_AppData.HkTelemetryPkt.DeviceErrorCount++;
            CFE_EVS_SendEvent(CANNON_REQ_DATA_ERR_EID, CFE_EVS_EventType_ERROR, 
                    "CANNON: Request device data reported error %d", status);
        }
    }
    /* Intentionally do not report errors if disabled */
    return;
}


/*
** Reset all global counter variables
*/
void CANNON_ResetCounters(void)
{
    CANNON_AppData.HkTelemetryPkt.CommandErrorCount = 0;
    CANNON_AppData.HkTelemetryPkt.CommandCount = 0;
    CANNON_AppData.HkTelemetryPkt.DeviceErrorCount = 0;
    CANNON_AppData.HkTelemetryPkt.DeviceCount = 0;
    return;
} 


/*
** Enable Component
** TODO: Edit for your specific component implementation
*/
void CANNON_Enable(void)
{
    int32 status = OS_SUCCESS;

    /* Check that device is disabled */
    if (CANNON_AppData.HkTelemetryPkt.DeviceEnabled == CANNON_DEVICE_DISABLED)
    {
        /*
        ** Initialize hardware interface data
        ** TODO: Make specific to your application depending on protocol in use
        ** Note that other components provide examples for the different protocols available
        */ 
        CANNON_AppData.CANNONUart.deviceString = CANNON_CFG_STRING;
        CANNON_AppData.CANNONUart.handle = CANNON_CFG_HANDLE;
        CANNON_AppData.CANNONUart.isOpen = PORT_CLOSED;
        CANNON_AppData.CANNONUart.baud = CANNON_CFG_BAUDRATE_HZ;
        CANNON_AppData.CANNONUart.access_option = uart_access_flag_RDWR;

        /* Open device specific protocols */
        status = uart_init_port(&CANNON_AppData.CANNONUart);
        if (status == OS_SUCCESS)
        {
            CANNON_AppData.HkTelemetryPkt.DeviceCount++;
            CANNON_AppData.HkTelemetryPkt.DeviceEnabled = CANNON_DEVICE_ENABLED;
            CFE_EVS_SendEvent(CANNON_ENABLE_INF_EID, CFE_EVS_EventType_INFORMATION, "CANNON: Device enabled");
        }
        else
        {
            CANNON_AppData.HkTelemetryPkt.DeviceErrorCount++;
            CFE_EVS_SendEvent(CANNON_UART_INIT_ERR_EID, CFE_EVS_EventType_ERROR, "CANNON: UART port initialization error %d", status);
        }
    }
    else
    {
        CANNON_AppData.HkTelemetryPkt.DeviceErrorCount++;
        CFE_EVS_SendEvent(CANNON_ENABLE_ERR_EID, CFE_EVS_EventType_ERROR, "CANNON: Device enable failed, already enabled");
    }
    return;
}


/*
** Disable Component
** TODO: Edit for your specific component implementation
*/
void CANNON_Disable(void)
{
    int32 status = OS_SUCCESS;

    /* Check that device is enabled */
    if (CANNON_AppData.HkTelemetryPkt.DeviceEnabled == CANNON_DEVICE_ENABLED)
    {
        /* Open device specific protocols */
        status = uart_close_port(&CANNON_AppData.CANNONUart);
        if (status == OS_SUCCESS)
        {
            CANNON_AppData.HkTelemetryPkt.DeviceCount++;
            CANNON_AppData.HkTelemetryPkt.DeviceEnabled = CANNON_DEVICE_DISABLED;
            CFE_EVS_SendEvent(CANNON_DISABLE_INF_EID, CFE_EVS_EventType_INFORMATION, "CANNON: Device disabled");
        }
        else
        {
            CANNON_AppData.HkTelemetryPkt.DeviceErrorCount++;
            CFE_EVS_SendEvent(CANNON_UART_CLOSE_ERR_EID, CFE_EVS_EventType_ERROR, "CANNON: UART port close error %d", status);
        }
    }
    else
    {
        CANNON_AppData.HkTelemetryPkt.DeviceErrorCount++;
        CFE_EVS_SendEvent(CANNON_DISABLE_ERR_EID, CFE_EVS_EventType_ERROR, "CANNON: Device disable failed, already disabled");
    }
    return;
}


/*
** Verify command packet length matches expected
*/
int32 CANNON_VerifyCmdLength(CFE_MSG_Message_t * msg, uint16 expected_length)
{     
    int32 status = OS_SUCCESS;
    CFE_SB_MsgId_t msg_id = CFE_SB_INVALID_MSG_ID;
    CFE_MSG_FcnCode_t cmd_code = 0;
    size_t actual_length = 0;

    CFE_MSG_GetSize(msg, &actual_length);
    if (expected_length == actual_length)
    {
        /* Increment the command counter upon receipt of an invalid command */
        CANNON_AppData.HkTelemetryPkt.CommandCount++;
    }
    else
    {
        CFE_MSG_GetMsgId(msg, &msg_id);
        CFE_MSG_GetFcnCode(msg, &cmd_code);

        CFE_EVS_SendEvent(CANNON_LEN_ERR_EID, CFE_EVS_EventType_ERROR,
           "Invalid msg length: ID = 0x%X,  CC = %d, Len = %ld, Expected = %d",
              CFE_SB_MsgIdToValue(msg_id), cmd_code, actual_length, expected_length);

        status = OS_ERROR;

        /* Increment the command error counter upon receipt of an invalid command */
        CANNON_AppData.HkTelemetryPkt.CommandErrorCount++;
    }
    return status;
} 
