/***********************************************************************/
/***********************************************************************/
/********************  Author: Eman Assem      *************************/
/********************  SWC: TIMERS                *************************/
/********************  LAYER: MCAL             *************************/
/********************  VERSION: 1.0            *************************/
/********************  DATE:2/3/2024         *************************/
/***********************************************************************/
/***********************************************************************/


#ifndef TIMERS_CONFIG_H_
#define TIMERS_CONFIG_H_

/***** TIMER 0 CONFIG *****/
/*Pre-Scaler Timer0

TIMER0_PRESCALER_NoClockSRC
TIMER0_PRESCALER_1
TIMER0_PRESCALER_8
TIMER0_PRESCALER_64
TIMER0_PRESCALER_256
TIMER0_PRESCALER_1024
*/
#define TIMER0_PRESCALER    TIMER0_PRESCALER_1024

#define TIMER0_COMPARE_VALUE 200

/* WaveGeneration mode Timer0

TIMER0_WGM_Fast_PWM    
TIMER0_WGM_CORRECT_PWM 
TIMER0_WGM_NORMAL      
TIMER0_WGM_CTC         
*/
#define TIMER0_WAVE_GEN_MODE   TIMER0_WGM_CTC


/***** TIMER 1 CONFIG *****/
/*
****Pre-Scaler Timer1****
TIMER1_PRESCALER_NoClockSRC
TIMER1_PRESCALER_1
TIMER1_PRESCALER_8
TIMER1_PRESCALER_64
TIMER1_PRESCALER_256
TIMER1_PRESCALER_1024
TIMER1_EXT_CLK_FALLING_EDGE
TIMER1_EXT_CLK_RISING_EDGE
*/
#define TIMER1_PRESCALER    TIMER1_PRESCALER_1024

#define TIMER1_COMPARE_VALUE 10000

/*
***** WaveGeneration Mode Timer1 *****
TIMER1_NORMAL
TIMER1_PWM_PHASE_CORRECT_8
TIMER1_PWM_PHASE_CORRECT_9
TIMER1_PWM_PHASE_CORRECT_10
TIMER1_CTC
TIMER1_FAST_PWM_8
TIMER1_FAST_PWM_9
TIMER1_FAST_PWM_10
TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1
TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A
TIMER1_PWM_PHASE_CORRECT_ICR1
TIMER1_PWM_PHASE_CORRECT_OCR1A
TIMER1_CTC_ICR1
TIMER1_FAST_PWM_ICR1
TIMER1_FAST_PWM_OCR1A
*/
#define TIMER1_WAVE_GEN_MODE   TIMER1_CTC

#define TIMER1_TOP	5000

#endif
