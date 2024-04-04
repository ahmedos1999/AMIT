/*
 * Trafiic Light Sign - TLS.c
 *
 * Created: 03/04/2024 7:01:41 pm
 * Author : ahmed
 */ 

/* LIB */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Error_State.h"

/* MCAL */
#include "DIO_Interface.h"
#include "TIMERS_interface.h"
#include "GIE_interface.h"

/* HAL */
#include "LED_interface.h"
#include "7-Seg_Interface.h"


/*SWC = 312500*/
void Timer1_CTC1A_APP(void)
{
	static u32 local_u32Counter = 0;
	static u8 local_u8Counter = 0;
	static u8 local_u8Color = 0;	// 0 = RED, 1 = YELLOW , 2 = GREEN
	
	local_u32Counter++;
	
	if (local_u32Counter == 1000)
	{
		local_u8Counter++;
		local_u32Counter = 0;
	}
	
	if ((local_u8Counter == 2) && (local_u8Color == 0))
	{
		local_u8Color++;

		LED_u8LedOff(DIO_PORTB, DIO_PIN0);		// Turn off RED
		LED_u8LedOn(DIO_PORTB, DIO_PIN1);		// Turn on YELLOW
		LED_u8LedOff(DIO_PORTB, DIO_PIN2);		// Turn off GREEN
		local_u8Counter = 0;
	}
	else if ((local_u8Counter == 1) && (local_u8Color == 1))
	{
		local_u8Color++;
		
		LED_u8LedOff(DIO_PORTB, DIO_PIN0);		// Turn off RED
		LED_u8LedOff(DIO_PORTB, DIO_PIN1);		// Turn off YELLOW
		LED_u8LedOn(DIO_PORTB, DIO_PIN2);		// Turn on GREEN
		local_u8Counter = 0;
	}
	else if ((local_u8Counter == 2) && (local_u8Color == 2))
	{
		local_u8Color = 0;

		LED_u8LedOn(DIO_PORTB, DIO_PIN0);		// Turn on RED
		LED_u8LedOff(DIO_PORTB, DIO_PIN1);		// Turn off YELLOW
		LED_u8LedOff(DIO_PORTB, DIO_PIN2);		// Turn off GREEN
		local_u8Counter = 0;
	}
}


int main(void)
{
    /* LED directons : 3 Outputs*/
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN0, DIO_PIN_OUTPUT);		// RED
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN1, DIO_PIN_OUTPUT);		// YELLOW
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN2, DIO_PIN_OUTPUT);		// GREEN
	
	DIO_u8SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);		// GREEN
	
	LED_u8LedOn(DIO_PORTB, DIO_PIN0);		// Light RED first
	
	TIMER1_voidInit();

	TIMERS_u8CallBackFunction(Timer1_CTC1A_APP, CTC1A);
	GIE_Enable();
	
    while (1) 
    {
		/* 7 Seg counter ss*/
		/* LED RED = 1, LED GREEN = 0, LED YELLOW = 0 for 60 seconds */
		/* LED RED = 0, LED GREEN = 0, LED YELLOW = 1 for 15 seconds */
		/* LED RED = 0, LED GREEN = 1, LED YELLOW = 0 for 60 seconds */
    }
}

