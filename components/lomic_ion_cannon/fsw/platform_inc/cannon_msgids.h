/************************************************************************
** File:
**   $Id: cannon_msgids.h  $
**
** Purpose:
**  Define CANNON Message IDs
**
*************************************************************************/
#ifndef _CANNON_MSGIDS_H_
#define _CANNON_MSGIDS_H_

/* 
** CCSDS V1 Command Message IDs (MID) must be 0x18xx
*/
#define CANNON_CMD_MID              0x1813 /* TODO: Change this for your app */ 

/* 
** This MID is for commands telling the app to publish its telemetry message
*/
#define CANNON_REQ_HK_MID           0x1814 /* TODO: Change this for your app */

/* 
** CCSDS V1 Telemetry Message IDs must be 0x08xx
*/
#define CANNON_HK_TLM_MID           0x0813 /* TODO: Change this for your app */
#define CANNON_DEVICE_TLM_MID       0x0814 /* TODO: Change this for your app */

#endif /* _CANNON_MSGIDS_H_ */
