#ifndef _CANNON_CHECKOUT_DEVICE_CFG_H_
#define _CANNON_CHECKOUT_DEVICE_CFG_H_

/*
** CANNON Checkout Configuration
*/
#define CANNON_CFG
/* Note: NOS3 uart requires matching handle and bus number */
#define CANNON_CFG_STRING           "/dev/usart_15"
#define CANNON_CFG_HANDLE           15
#define CANNON_CFG_BAUDRATE_HZ      115200
#define CANNON_CFG_MS_TIMEOUT       250
#define CANNON_CFG_DEBUG

#endif /* _CANNON_CHECKOUT_DEVICE_CFG_H_ */
