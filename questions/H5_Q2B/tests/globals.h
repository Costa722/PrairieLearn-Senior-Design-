#ifndef GLOBALS_H_
#define GLOBALS_H_
#include <stdint.h>
#include <stdbool.h>

extern char leftPortLabel;
extern char rightPortLabel;
extern int buttonZeroBit;
extern int buttonOneBit;
extern int buttonTwoBit;
extern int buttonThreeBit;
extern int LEDZeroBit;
extern int LEDOneBit;
extern int LEDTwoBit;
extern int LEDThreeBit;
    
extern bool buttonZeroSuccess;
extern bool buttonOneSuccess;
extern bool buttonTwoSuccess;
extern bool buttonThreeSuccess;

extern uint32_t  GPIO_PORTA_DATA_R;
extern uint32_t  GPIO_PORTB_DATA_R;
extern uint32_t  GPIO_PORTC_DATA_R;
extern uint32_t  GPIO_PORTD_DATA_R;
extern uint32_t  GPIO_PORTE_DATA_R;
extern uint32_t  GPIO_PORTF_DATA_R;

#endif