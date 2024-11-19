/************************************************************************
** File:
**   $Id: cannon_platform_cfg.h  $
**
** Purpose:
**  Define cannon Platform Configuration Parameters
**
** Notes:
**
*************************************************************************/
#ifndef _CANNON_PLATFORM_CFG_H_
#define _CANNON_PLATFORM_CFG_H_

/*
** Default CANNON Configuration
*/
#ifndef CANNON_CFG
    /* Notes: 
    **   NOS3 uart requires matching handle and bus number
    */
    #define CANNON_CFG_STRING           "usart_16"
    #define CANNON_CFG_HANDLE           16
    #define CANNON_CFG_BAUDRATE_HZ      115200
    #define CANNON_CFG_MS_TIMEOUT       50            /* Max 255 */
    /* Note: Debug flag disabled (commented out) by default */
    //#define CANNON_CFG_DEBUG
#endif

#endif /* _CANNON_PLATFORM_CFG_H_ */
