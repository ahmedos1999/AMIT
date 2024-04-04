/***********************************************************************/
/***********************************************************************/
/********************  Author: Eman Assem      *************************/
/********************  SWC: TIMERS                *************************/
/********************  LAYER: MCAL             *************************/
/********************  VERSION: 1.0            *************************/
/********************  DATE:2/3/2024         *************************/
/***********************************************************************/
/***********************************************************************/


#ifndef TIMERS_INTEFACE_H_
#define TIMERS_INTEFACE_H_

/* Call Back Fun. Numbers */
#define CTC2		10
#define OVF2		20
#define ICU1		30
#define CTC1A		40
#define CTC1B		50
#define OVF1		60
#define CTC0		70
#define OVF0		80


void TIMER0_voidInit(void);
void TIMER1_voidInit(void);
u8 TIMERS_u8CallBackFunction(void(*copy_ptrFunction)(void), u8 copy_ptrNum);

#endif
