/***********************************************************************/
/***********************************************************************/
/********************  Author: Ahmed Osama      *************************/
/********************  SWC: 7-Seg                *************************/
/********************  LAYER: HAL             *************************/
/********************  VERSION: 1.0            *************************/
/********************  DATE:13/3/2024         *************************/
/***********************************************************************/
/***********************************************************************/

/* LIB */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Error_State.h"

/* MCAL */
#include "DIO_Interface.h"

/* HAL */
#include "7-Seg_Config.h"
#include "7-Seg_Interface.h"

void SevenSeg_voidPrintNum(u8 copy_u8Number)
{
	u8 local_u8Counter = 0;
	u8 local_u8ShiftedBits = 4;
	
	for( local_u8Counter = 0; local_u8Counter < 3; local_u8Counter++)
	{
		DIO_u8SetPinValue(SEVEN_SEG_PORT, (local_u8Counter + local_u8ShiftedBits), GET_BIT(copy_u8Number, local_u8Counter));	
	}
}

void SevenSeg_voidInit (void)
{
	#if (SEVEN_SEG_PORT) != (NULL)
	DIO_u8SetPortDirection(SEVEN_SEG_PORT, DIO_PORT_OUTPUT);
#endif
	
	DIO_u8SetPinDirection(SEVEN_SEG_PORT,SEVEN_SEG_1_EN, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(SEVEN_SEG_PORT,SEVEN_SEG_2_EN, DIO_PIN_OUTPUT);

}