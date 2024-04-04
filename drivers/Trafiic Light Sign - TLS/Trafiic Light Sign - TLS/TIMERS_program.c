/***********************************************************************/
/***********************************************************************/
/********************  Author: Eman Assem      *************************/
/********************  SWC: TIMERS                *************************/
/********************  LAYER: MCAL             *************************/
/********************  VERSION: 1.1            *************************/
/********************  DATE:2/3/2024         *************************/
/***********************************************************************/
/***********************************************************************/

/*LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Error_State.h"

/*MCAL*/
#include "TIMERS_config.h"
#include "TIMERS_private.h"
#include "TIMERS_interface.h"
#include "TIMERS_register.h"

/*/ Timer/Counter2 Compare Match */
void(*TIMER2_CTC_ptrFunction)(void) = NULL;
/* Timer/Counter2 Overflow */
void(*TIMER2_OVF_ptrFunction)(void) = NULL;

/* Timer/Counter1 Capture Event */
void(*TIMER1_ICU_ptrFunction)(void) = NULL;
/* Timer/Counter1 Compare Match A */
void(*TIMER1A_CTC_ptrFunction)(void) = NULL;
/* Timer/Counter1 Compare Match B */
void(*TIMER1B_CTC_ptrFunction)(void) = NULL;
/* Timer/Counter1 Overflow */
void(*TIMER1_OVF_ptrFunction)(void) = NULL;

/* Timer/Counter0 Compare Match */
void(*TIMER0_CTC_ptrFunction)(void) = NULL;
/* Timer/Counter0 Overflow */
void(*TIMER0_OVF_ptrFunction)(void) = NULL;

void TIMER0_voidInit(void)
{
	#if TIMER0_WAVE_GEN_MODE == TIMER0_WGM_NORMAL
	/* WGM */
	CLR_BIT(TIMERS_TCCR0, TCCR0_WGM00);
	CLR_BIT(TIMERS_TCCR0, TCCR0_WGM01);
	SET_BIT(TIMERS_TIMSK, TIMSK_TOIE0);		// Overflow enable
	
	#elif TIMER0_WAVE_GEN_MODE == TIMER0_WGM_CTC
	/* WGM */
	CLR_BIT(TIMERS_TCCR0, TCCR0_WGM00);
	SET_BIT(TIMERS_TCCR0, TCCR0_WGM01);
	TIMERS_OCR0 = TIMER0_COMPARE_VALUE;		// Compare Match Value
	SET_BIT(TIMERS_TIMSK, TIMSK_OCIE0);		// Compare Enable
	
	#elif TIMER0_WAVE_GEN_MODE == TIMER0_WGM_FAST_PWM
	/* WGM */
	SET_BIT(TIMERS_TCCR0, TCCR0_WGM00);
	SET_BIT(TIMERS_TCCR0, TCCR0_WGM01);
	
	#elif TIMER0_WAVE_GEN_MODE == TIMER0_WGM_PHASE_CORRECT_PWM
	/* WGM */
	SET_BIT(TIMERS_TCCR0, TCCR0_WGM00);
	CLR_BIT(TIMERS_TCCR0, TCCR0_WGM01);
	
	#else
	#error "WGM_CONFIG_FILE"
	
	#endif
	
	/* Pre-Scaler */
	TIMERS_TCCR0 &= 0b11111000;
	TIMERS_TCCR0 |= TIMER0_PRESCALER;
}

void TIMER0_voidPWM(u8 copy_DutyCycle)
{
	TIMERS_OCR0 = (copy_DutyCycle/100) * (2^8) - 1;
}

void TIMER1_voidInit(void)
{
	#if TIMER1_WAVE_GEN_MODE == TIMER1_NORMAL
	SET_BIT(TIMERS_TIMSK, TIMSK_TOIE1);		// Enables Overflow Interrupt
	
	/* WGM */
	CLR_BIT(TIMERS_TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TIMERS_TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TIMERS_TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TIMERS_TCCR1B, TCCR1B_WGM13);
	
	#elif TIMER1_WAVE_GEN_MODE == TIMER1_PWM_PHASE_CORRECT_8
	
	/* WGM */
	SET_BIT(TIMERS_TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TIMERS_TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TIMERS_TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TIMERS_TCCR1B, TCCR1B_WGM13);
	
	#elif TIMER1_WAVE_GEN_MODE == TIMER1_PWM_PHASE_CORRECT_9
	
	/* WGM */
	CLR_BIT(TIMERS_TCCR1A, TCCR1A_WGM10);
	SET_BIT(TIMERS_TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TIMERS_TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TIMERS_TCCR1B, TCCR1B_WGM13);
	
	#elif TIMER1_WAVE_GEN_MODE == TIMER1_PWM_PHASE_CORRECT_10
	
	/* WGM */
	SET_BIT(TIMERS_TCCR1A, TCCR1A_WGM10);
	SET_BIT(TIMERS_TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TIMERS_TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TIMERS_TCCR1B, TCCR1B_WGM13);
	
	#elif TIMER1_WAVE_GEN_MODE == TIMER1_CTC
	/* WGM */
	CLR_BIT(TIMERS_TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TIMERS_TCCR1A, TCCR1A_WGM11);
	SET_BIT(TIMERS_TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TIMERS_TCCR1B, TCCR1B_WGM13);
	
	TIMERS_OCR1AL = TIMER1_COMPARE_VALUE;	// Setting Compare Match Value of A
	TIMERS_OCR1BDATA = TIMER1_COMPARE_VALUE;	// Setting Compare Match Value of B
	
	SET_BIT(TIMERS_TIMSK, TIMSK_OCIE1A);	// Enables Compare Match on A
	SET_BIT(TIMERS_TIMSK, TIMSK_OCIE1B);	// Enables Compare Match on B
	
	#elif TIMER1_WAVE_GEN_MODE == TIMER1_FAST_PWM_8
	SET_BIT(TIMERS_TIMSK, TIMSK_TOIE1);		// Enables Overflow Interrupt
	SET_BIT(TIMERS_TIMSK, TIMSK_OCIE1A);	// Enables Compare Match on A
	SET_BIT(TIMERS_TIMSK, TIMSK_OCIE1B);	// Enables Compare Match on B
	/* WGM */
	SET_BIT(TIMERS_TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TIMERS_TCCR1A, TCCR1A_WGM11);
	SET_BIT(TIMERS_TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TIMERS_TCCR1B, TCCR1B_WGM13);
	
	#elif TIMER1_WAVE_GEN_MODE == TIMER1_FAST_PWM_9
	SET_BIT(TIMERS_TIMSK, TIMSK_TOIE1);		// Enables Overflow Interrupt
	SET_BIT(TIMERS_TIMSK, TIMSK_OCIE1A);	// Enables Compare Match on A
	SET_BIT(TIMERS_TIMSK, TIMSK_OCIE1B);	// Enables Compare Match on B
	/* WGM */
	CLR_BIT(TIMERS_TCCR1A, TCCR1A_WGM10);
	SET_BIT(TIMERS_TCCR1A, TCCR1A_WGM11);
	SET_BIT(TIMERS_TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TIMERS_TCCR1B, TCCR1B_WGM13);
	
	#elif TIMER1_WAVE_GEN_MODE == TIMER1_FAST_PWM_10
	SET_BIT(TIMERS_TIMSK, TIMSK_TOIE1);		// Enables Overflow Interrupt
	SET_BIT(TIMERS_TIMSK, TIMSK_OCIE1A);	// Enables Compare Match on A
	SET_BIT(TIMERS_TIMSK, TIMSK_OCIE1B);	// Enables Compare Match on B
	
	/* WGM */
	SET_BIT(TIMERS_TCCR1A, TCCR1A_WGM10);
	SET_BIT(TIMERS_TCCR1A, TCCR1A_WGM11);
	SET_BIT(TIMERS_TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TIMERS_TCCR1B, TCCR1B_WGM13);
	
	#elif TIMER1_WAVE_GEN_MODE == TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1
	
	/* WGM */
	CLR_BIT(TIMERS_TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TIMERS_TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TIMERS_TCCR1B, TCCR1B_WGM12);
	SET_BIT(TIMERS_TCCR1B, TCCR1B_WGM13);
	
	#elif TIMER1_WAVE_GEN_MODE == TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A
	
	/* WGM */
	SET_BIT(TIMERS_TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TIMERS_TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TIMERS_TCCR1B, TCCR1B_WGM12);
	SET_BIT(TIMERS_TCCR1B, TCCR1B_WGM13);
	
	#elif TIMER1_WAVE_GEN_MODE == TIMER1_PWM_PHASE_CORRECT_ICR1
	
	/* WGM */
	CLR_BIT(TIMERS_TCCR1A, TCCR1A_WGM10);
	SET_BIT(TIMERS_TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TIMERS_TCCR1B, TCCR1B_WGM12);
	SET_BIT(TIMERS_TCCR1B, TCCR1B_WGM13);
	
	TIMERS_ICR1DATA = TIMER1_TOP;			// Set the TOP Value
	
	#elif TIMER1_WAVE_GEN_MODE == TIMER1_PWM_PHASE_CORRECT_OCR1A
	
	/* WGM */
	SET_BIT(TIMERS_TCCR1A, TCCR1A_WGM10);
	SET_BIT(TIMERS_TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TIMERS_TCCR1B, TCCR1B_WGM12);
	SET_BIT(TIMERS_TCCR1B, TCCR1B_WGM13);
	
	#elif TIMER1_WAVE_GEN_MODE == TIMER1_CTC_ICR1
	SET_BIT(TIMERS_TIMSK, TIMSK_TICIE1);	// Enables Input Capture
	SET_BIT(TIMERS_TIMSK, TIMSK_OCIE1A);	// Enables Compare Match on A
	SET_BIT(TIMERS_TIMSK, TIMSK_OCIE1B);	// Enables Compare Match on B
	
	/* WGM */
	CLR_BIT(TIMERS_TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TIMERS_TCCR1A, TCCR1A_WGM11);
	SET_BIT(TIMERS_TCCR1B, TCCR1B_WGM12);
	SET_BIT(TIMERS_TCCR1B, TCCR1B_WGM13);
	
	TIMERS_ICR1DATA = TIMER1_TOP;			// Set the TOP Value
	
	#elif TIMER1_WAVE_GEN_MODE == TIMER1_FAST_PWM_ICR1

	/* WGM */
	CLR_BIT(TIMERS_TCCR1A, TCCR1A_WGM10);
	SET_BIT(TIMERS_TCCR1A, TCCR1A_WGM11);
	SET_BIT(TIMERS_TCCR1B, TCCR1B_WGM12);
	SET_BIT(TIMERS_TCCR1B, TCCR1B_WGM13);

	TIMERS_ICR1DATA = TIMER1_TOP;			// Set the TOP Value
	
	#elif TIMER1_WAVE_GEN_MODE == TIMER1_FAST_PWM_OCR1A
	
	/* WGM */
	SET_BIT(TIMERS_TCCR1A, TCCR1A_WGM10);
	SET_BIT(TIMERS_TCCR1A, TCCR1A_WGM11);
	SET_BIT(TIMERS_TCCR1B, TCCR1B_WGM12);
	SET_BIT(TIMERS_TCCR1B, TCCR1B_WGM13);
	
	#else
	#error "WGM_CONFIG_FILE"
	
#endif

	/* Pre-Scaler */
	TIMERS_TCCR1B &= 0b11111000;		// Clearing Pre-Scaler Bits
	TIMERS_TCCR1B |= TIMER1_PRESCALER;

}
//void TIMER1_voidPWM(u16 copy_u16CompareValue){}


u8 TIMERS_u8CallBackFunction(void(*copy_ptrFunction)(void), u8 copy_ptrNum)
{
	u8 Error_u8State = OK;
	
	if (copy_ptrNum == CTC2)
	{
		TIMER2_CTC_ptrFunction = copy_ptrFunction;
	}	
	else if (copy_ptrNum == OVF2)
	{
		TIMER2_OVF_ptrFunction = copy_ptrFunction;	 
	}
	else if (copy_ptrNum == ICU1)
	{
		TIMER1_ICU_ptrFunction = copy_ptrFunction;
	}
	else if (copy_ptrNum == CTC1A)
	{
		TIMER1A_CTC_ptrFunction = copy_ptrFunction;	
	}
	else if (copy_ptrNum == CTC1B)
	{
		TIMER1B_CTC_ptrFunction = copy_ptrFunction;
	}
	else if (copy_ptrNum == OVF1)
	{
		TIMER1_OVF_ptrFunction = copy_ptrFunction;
	}
	else if (copy_ptrNum == CTC0)
	{
		TIMER0_CTC_ptrFunction = copy_ptrFunction;
	}
	else if (copy_ptrNum == OVF0)
	{
		TIMER0_OVF_ptrFunction = copy_ptrFunction;
	}
	
	return Error_u8State;
}

void __vector_4(void) __attribute__((signal));
void __vector_4(void)	// Timer/Counter2 Compare Match
{
	if(TIMER2_CTC_ptrFunction != NULL)
	{
		TIMER2_CTC_ptrFunction();
	}
	else
	{}
}

void __vector_5(void) __attribute__((signal));
void __vector_5(void)	// Timer/Counter2 Overflow
{
	if(TIMER2_OVF_ptrFunction != NULL)
	{
		TIMER2_OVF_ptrFunction();
	}
	else
	{}
}

void __vector_6(void) __attribute__((signal));
void __vector_6(void)	// Timer/Counter1 Capture Event
{
	if(TIMER1_ICU_ptrFunction != NULL)
	{
		TIMER1_ICU_ptrFunction();
	}
	else
	{}
}

void __vector_7(void) __attribute__((signal));
void __vector_7(void)	// Timer/Counter1 Compare Match A
{
	if(TIMER1A_CTC_ptrFunction != NULL)
	{
		TIMER1A_CTC_ptrFunction();
	}
	else
	{}
}

void __vector_8(void) __attribute__((signal));
void __vector_8(void)	// Timer/Counter1 Compare Match B
{
	if(TIMER1B_CTC_ptrFunction != NULL)
	{
		TIMER1B_CTC_ptrFunction();
	}
	else
	{}
}

void __vector_9(void) __attribute__((signal));
void __vector_9(void)	// Timer/Counter1 Overflow
{
	if(TIMER1_OVF_ptrFunction != NULL)
	{
		TIMER1_OVF_ptrFunction();
	}
	else
	{}
	
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)	// Timer/Counter0 Compare Match
{
	if(TIMER0_CTC_ptrFunction != NULL)
	{
		TIMER0_CTC_ptrFunction();
	}
	else
	{}
}
	
void __vector_11(void) __attribute__((signal));
void __vector_11(void)	// Timer/Counter0 Overflow
{
	if(TIMER0_OVF_ptrFunction != NULL)
	{
		TIMER0_OVF_ptrFunction();
	}
	else
	{}
}