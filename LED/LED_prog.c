/*
 * LED_prog.c
 *
 *  Created on: May 5, 2023
 *      Author: dell
 */

#include "stdTypes.h"
#include "errorStates.h"

#include "LED_priv.h"
#include "LED_config.h"

#include "DIO_int.h"

ES_t LED_enuInit(LED_t * Copy_pstrLedConfig)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_pstrLedConfig != NULL)
	{
		u8 Local_enuIterator=0;
		for (Local_enuIterator=0; Local_enuIterator < LED_NUM ; Local_enuIterator++)
		{
			Local_enuErrorState = DIO_enuSetPinDirection(Copy_pstrLedConfig[Local_enuIterator].LED_u8PortID , Copy_pstrLedConfig[Local_enuIterator].LED_u8PinID , DIO_u8OUTPUT );
			if (Copy_pstrLedConfig[Local_enuIterator].LED_u8Connection == LED_SINK)
			{
				if (Copy_pstrLedConfig[Local_enuIterator].LED_u8InitState == LED_ON)
				{
					Local_enuErrorState =DIO_enuSetPinValue(Copy_pstrLedConfig[Local_enuIterator].LED_u8PortID , Copy_pstrLedConfig[Local_enuIterator].LED_u8PinID , DIO_u8LOW);
				}
				else if(Copy_pstrLedConfig[Local_enuIterator].LED_u8InitState == LED_OFF)
				{
					Local_enuErrorState =DIO_enuSetPinValue(Copy_pstrLedConfig[Local_enuIterator].LED_u8PortID , Copy_pstrLedConfig[Local_enuIterator].LED_u8PinID , DIO_u8HIGH);
				}
				else
				{
					return ES_OUT_OF_RANGE;
				}
			}
			else if (Copy_pstrLedConfig[Local_enuIterator].LED_u8Connection == LED_SOURCE)
			{
				if (Copy_pstrLedConfig[Local_enuIterator].LED_u8InitState == LED_ON)
				{
					Local_enuErrorState =DIO_enuSetPinValue(Copy_pstrLedConfig[Local_enuIterator].LED_u8PortID , Copy_pstrLedConfig[Local_enuIterator].LED_u8PinID , DIO_u8HIGH);
				}
				else if(Copy_pstrLedConfig[Local_enuIterator].LED_u8InitState == LED_OFF)
				{
					Local_enuErrorState =DIO_enuSetPinValue(Copy_pstrLedConfig[Local_enuIterator].LED_u8PortID , Copy_pstrLedConfig[Local_enuIterator].LED_u8PinID , DIO_u8LOW);
				}
				else
				{
					return ES_OUT_OF_RANGE;
				}
			}
			else
			{
				return ES_OUT_OF_RANGE;
			}
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t LED_enuTurnON(LED_t * Copy_pstrLedID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_pstrLedID != NULL)
	{
		if (Copy_pstrLedID->LED_u8Connection == LED_SINK )
		{
			Local_enuErrorState=DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID,DIO_u8LOW);
		}
		else if (Copy_pstrLedID->LED_u8Connection == LED_SOURCE)
		{
			Local_enuErrorState=DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID,DIO_u8HIGH);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t LED_enuTurnOFF(LED_t * Copy_pstrLedID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_pstrLedID != NULL)
	{
		if (Copy_pstrLedID->LED_u8Connection == LED_SINK )
		{
			Local_enuErrorState=DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID,DIO_u8HIGH);
		}
		else if (Copy_pstrLedID->LED_u8Connection == LED_SOURCE)
		{
			Local_enuErrorState=DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID,DIO_u8LOW);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

