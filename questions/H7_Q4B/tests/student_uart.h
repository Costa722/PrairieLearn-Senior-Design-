#ifndef STUDENT_UART_H_
#define STUDENT_UART_H_

#include "uart.h"
#include "main.h"

extern volatile int flag;

int student_main();
void init_UART();
void My_UART_Handler();

#endif
