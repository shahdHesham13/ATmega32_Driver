/*
 * Switch_config.c
 *
 *  Created on: May 5, 2023
 *      Author: dell
 */


#include "stdTypes.h"
#include "errorStates.h"

#include "Switch_priv.h"
#include "Switch_config.h"

#include "DIO_int.h"

SW_t Switch_AstrSwitchState [SW_NUM] =
{
		{DIO_u8PORTA , DIO_u8PIN4 , DIO_u8FLOAT},
		{DIO_u8PORTD , DIO_u8PIN3 , DIO_u8PULL_UP},
		{DIO_u8PORTC , DIO_u8PIN5 , DIO_u8PULL_UP}
};
