/*
 * app_Joystick.h
 *
 *  Created on: 29 ene. 2019
 *      Author: Admin
 */

#ifndef APP_JOYSTICK_H_
#define APP_JOYSTICK_H_

#include <Arduino.h>

/* Macros and Definitions */
#define APP_JOYSTICK_XAXIS_PIN		(A0)
#define APP_JOYSTICK_YAXIS_PIN		(A1)

#define APP_JOYSTICK_UP_PIN			(0)
#define APP_JOYSTICK_DOWN_PIN		(1)
#define APP_JOYSTICK_LEFT_PIN		(2)
#define APP_JOYSTICK_RIGHT_PIN		(3)

#define APP_JOYSTICK_POS_THRESHOLD	(180u)
#define APP_JOYSTICK_NEG_THRESHOLD	(80u)

/* Public Prototypes */
extern void app_JoystickInit(void);
extern void app_JoystickTask(void);

#endif /* APP_JOYSTICK_H_ */
