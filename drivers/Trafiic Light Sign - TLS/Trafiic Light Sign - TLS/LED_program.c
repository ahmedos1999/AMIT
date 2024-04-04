/***********************************************************************/
/***********************************************************************/
/********************  Author: Ahmed Osama     *************************/
/********************  SWC: LED                *************************/
/********************  LAYER: HAL             *************************/
/********************  VERSION: 1.0            *************************/
/********************  DATE:03//2024         *************************/
/***********************************************************************/
/***********************************************************************/

/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Error_State.h"

/* MCAL */
#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_register.h"

/* HAL */
#include "LED_private.h"
#include "LED_config.h"
#include "LED_interface.h"

/* Implementation */
u8 LED_u8LedOn(u8 copy_u8Port, u8 copy_u8PinNumber)
{
	u8 Local_u8ErrorState = OK;
	
	DIO_u8SetPinValue(copy_u8Port, copy_u8PinNumber, CONNECTION);
	
	return Local_u8ErrorState;
}


u8 LED_u8LedOff(u8 copy_u8Port, u8 copy_u8PinNumber)
{
	u8 Local_u8ErrorState = OK;
	
	DIO_u8SetPinValue(copy_u8Port, copy_u8PinNumber, ((CONNECTION) ^ 1));
	
	return Local_u8ErrorState;
}


u8 LED_u8LedBlink(u8 copy_u8Port, u8 copy_u8PinNumber)
{
	u8 Local_u8ErrorState = OK;
	
	DIO_u8TogglePinValue(copy_u8Port, copy_u8PinNumber);
	_delay_ms(50);
	DIO_u8TogglePinValue(copy_u8Port, copy_u8PinNumber);
	
	return Local_u8ErrorState;
}