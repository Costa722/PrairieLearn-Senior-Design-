#include "globals.h"

char leftPortLabel;
char rightPortLabel;
int buttonZeroBit;
int buttonOneBit;
int buttonTwoBit;
int buttonThreeBit;
int LEDZeroBit;
int LEDOneBit;
int LEDTwoBit;
int LEDThreeBit;
    
bool buttonZeroSuccess = false;
bool buttonOneSuccess = false;
bool buttonTwoSuccess = false;
bool buttonThreeSuccess = false;

uint32_t  GPIO_PORTA_DATA_R  = 0x00000000;
uint32_t  GPIO_PORTB_DATA_R  = 0x00000000;
uint32_t  GPIO_PORTC_DATA_R  = 0x00000000;
uint32_t  GPIO_PORTD_DATA_R  = 0x00000000;
uint32_t  GPIO_PORTE_DATA_R  = 0x00000000;
uint32_t  GPIO_PORTF_DATA_R  = 0x00000000;