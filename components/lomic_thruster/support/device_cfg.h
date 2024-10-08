#ifndef _GENERIC_THRUSTER_CHECKOUT_DEVICE_CFG_H_
#define _GENERIC_THRUSTER_CHECKOUT_DEVICE_CFG_H_

/*
** GENERIC_THRUSTER Checkout Configuration
*/
#define GENERIC_THRUSTER_CFG
/* Note: NOS3 uart requires matching handle and bus number */
#define GENERIC_THRUSTER_CFG_STRING           "/dev/usart_9"
#define GENERIC_THRUSTER_CFG_HANDLE           9
#define GENERIC_THRUSTER_CFG_BAUDRATE_HZ      115200
#define GENERIC_THRUSTER_CFG_MS_TIMEOUT       250
#define GENERIC_THRUSTER_CFG_DEBUG

#endif /* _GENERIC_THRUSTER_CHECKOUT_DEVICE_CFG_H_ */
