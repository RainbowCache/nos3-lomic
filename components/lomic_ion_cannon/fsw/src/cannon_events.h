/************************************************************************
** File:
**    cannon_events.h
**
** Purpose:
**  Define CANNON application event IDs
**
*************************************************************************/

#ifndef _CANNON_EVENTS_H_
#define _CANNON_EVENTS_H_

/* Standard app event IDs */
#define CANNON_RESERVED_EID              0
#define CANNON_STARTUP_INF_EID           1
#define CANNON_LEN_ERR_EID               2
#define CANNON_PIPE_ERR_EID              3
#define CANNON_SUB_CMD_ERR_EID           4
#define CANNON_SUB_REQ_HK_ERR_EID        5
#define CANNON_PROCESS_CMD_ERR_EID       6

/* Standard command event IDs */
#define CANNON_CMD_ERR_EID               10
#define CANNON_CMD_NOOP_INF_EID          11
#define CANNON_CMD_RESET_INF_EID         12
#define CANNON_CMD_ENABLE_INF_EID        13
#define CANNON_ENABLE_INF_EID            14
#define CANNON_ENABLE_ERR_EID            15
#define CANNON_CMD_DISABLE_INF_EID       16
#define CANNON_DISABLE_INF_EID           17
#define CANNON_DISABLE_ERR_EID           18

/* Device specific command event IDs */
#define CANNON_CMD_CONFIG_INF_EID        20

/* Standard telemetry event IDs */
#define CANNON_DEVICE_TLM_ERR_EID        30
#define CANNON_REQ_HK_ERR_EID            31

/* Device specific telemetry event IDs */
#define CANNON_REQ_DATA_ERR_EID          32

/* Hardware protocol event IDs */
#define CANNON_UART_INIT_ERR_EID         40
#define CANNON_UART_CLOSE_ERR_EID        41

#endif /* _CANNON_EVENTS_H_ */
