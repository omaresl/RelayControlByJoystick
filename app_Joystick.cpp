/*
 * app_Joystick.cpp
 *
 *  Created on: 29 ene. 2019
 *      Author: Admin
 */
/* Interfaces */
#include "app_Joystick.h"

/* Variables */
unsigned int ruw_XAxis,ruw_YAxis;

/* Funcitons */
/***************************************
 * Name: app_JoystickInit
 * Description: TBD
 ***************************************/
void app_JoystickInit(void)
{
	/* Initialize pins */
	pinMode(APP_JOYSTICK_UP_PIN,OUTPUT);
	pinMode(APP_JOYSTICK_DOWN_PIN,OUTPUT);
	pinMode(APP_JOYSTICK_LEFT_PIN,OUTPUT);
	pinMode(APP_JOYSTICK_RIGHT_PIN,OUTPUT);

	/* Initialize value of the axis */
	ruw_XAxis = 128u;
	ruw_YAxis = 128u;
}

/***************************************
 * Name: app_JoystickInit
 * Description: TBD
 ***************************************/
void app_JoystickTask(void)
{
	/* Measure Axis */
	ruw_XAxis = analogRead(APP_JOYSTICK_XAXIS_PIN);
	ruw_YAxis = analogRead(APP_JOYSTICK_YAXIS_PIN);

	/* Take actions depending on the axis values */
	//X AXIS
	if(ruw_XAxis >= APP_JOYSTICK_POS_THRESHOLD)
	{
		/* TURN ON UP LED */
		digitalWrite(APP_JOYSTICK_UP_PIN,false);
		/* TURN OFF DOWN LED */
		digitalWrite(APP_JOYSTICK_DOWN_PIN,true);
	}
	else if(ruw_XAxis <= APP_JOYSTICK_NEG_THRESHOLD)
	{
		/* TURN ON DOWN LED */
		digitalWrite(APP_JOYSTICK_DOWN_PIN,false);
		/* TURN OFF UP LED */
		digitalWrite(APP_JOYSTICK_UP_PIN,true);
	}
	else
	{
		/* TURN OFF UP LED */
		digitalWrite(APP_JOYSTICK_UP_PIN,true);
		/* TURN OFF DOWN LED */
		digitalWrite(APP_JOYSTICK_DOWN_PIN,true);
	}

	//Y AXIS
	if(ruw_YAxis >= APP_JOYSTICK_POS_THRESHOLD)
	{
		/* TURN ON LEFT LED */
		digitalWrite(APP_JOYSTICK_LEFT_PIN,false);
		/* TURN OFF RIGHT LED */
		digitalWrite(APP_JOYSTICK_RIGHT_PIN,true);
	}
	else if(ruw_YAxis <= APP_JOYSTICK_NEG_THRESHOLD)
	{
		/* TURN ON RIGHT LED */
		digitalWrite(APP_JOYSTICK_RIGHT_PIN,false);
		/* TURN OFF LEFT LED */
		digitalWrite(APP_JOYSTICK_LEFT_PIN,true);
	}
	else
	{
		/* TURN OFF LEFT LED */
		digitalWrite(APP_JOYSTICK_LEFT_PIN,true);
		/* TURN OFF RIGHT LED */
		digitalWrite(APP_JOYSTICK_RIGHT_PIN,true);
	}
}
