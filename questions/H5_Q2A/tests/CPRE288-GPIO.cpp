// File Name: CPRE288-GPIO.cpp
// Description: Source file for GPIO related data helper functions
//              for auto-generating, and auto-grading GPIO related CPRE 288 questions.
// Author: Dr. Phillip Jones.
// Date: 12/28/2023

#include "CPRE288-GPIO.h"

//////////////////////////////////////////
//  GPIO_Device functions               //
//////////////////////////////////////////

// Constructor for GPIO_Device class
GPIO_Device::GPIO_Device()
{
  SYSCTL_RCGCGPIO_R = 0; // Disable all GPIO Port clocks
}


// Set clock enable value for Port PortID (Port A-F => 0-5)
void GPIO_Device::Set_Port_Clock_En_Id(unsigned int PortID, unsigned int value)
{
  unsigned int mask = 1;
  mask = mask << PortID; // Shift 1 to PinID position
  if(value == 0) 
  {
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R & ~(mask); // force bit position PortID to 0
  } 
  else 
  {
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R | mask; // force bit position PortID to 1
  }
} 


// Get clock enable setting for Port PortID (Port A-F => 0-5)
unsigned int GPIO_Device::Get_Port_Clock_En_Id(unsigned int PortID)
{
  unsigned int value = 0;
  unsigned int mask = 1;
  mask = mask << PortID; // Shift 1 to PortID position
  value = (SYSCTL_RCGCGPIO_R & mask); // Zero out all other positions
  value = value >> PortID; // move the value (1 or 0) to bit0 of value
  return value; // Will return 0 or 1 
}


// Directly set Port Clock Enable Reg value
void GPIO_Device::Set_Port_Clock_En_Reg(unsigned int value)
{
  SYSCTL_RCGCGPIO_R = value;
} 


// Directly get Port Clock Enable Reg value
unsigned int GPIO_Device::Get_Port_Clock_En_Reg()
{
  return SYSCTL_RCGCGPIO_R;
}




//////////////////////////////////////////
//  GPIO_PORT_Regs functions            //
//////////////////////////////////////////


// Constructor for GPIO_PORT_Regs class
GPIO_PORT_Regs::GPIO_PORT_Regs()
{
  // Initialize all registers to 0
  GPIO_PORTx_DEN_R =   0;  // Digital enable register for Port’s pins
  GPIO_PORTx_DIR_R =   0;  // Direction register for Port’s pins
  GPIO_PORTx_DATA_R =  0;  // Port’s data register
  GPIO_PORTx_AFSEL_R = 0;  // Alternative Function Select reg. for Port’s pins
  GPIO_PORTx_PCTL_R =  0;  // Peripheral Select reg. for Port’s pins
}


// Set DEN value of a given pin
void GPIO_PORT_Regs::Set_Port_Pin_DEN(unsigned int PinID, unsigned int value) 
{ 
  unsigned int mask = 1;
  mask = mask << PinID; // Shift 1 to PinID position
  if(value == 0) {
    GPIO_PORTx_DEN_R = GPIO_PORTx_DEN_R & ~(mask); // force bit position PinID to 0
  } 
  else {
    GPIO_PORTx_DEN_R = GPIO_PORTx_DEN_R | mask; // force bit position PinID to 1
  }
}


// Get DEN value of a specified pin
unsigned int GPIO_PORT_Regs::Get_Port_Pin_DEN(unsigned int PinID) 
{ 
  unsigned int value = 0;
  unsigned int mask = 1;
  mask = mask << PinID; // Shift 1 to PinID position
  value = (GPIO_PORTx_DEN_R & mask); // Zero out all other positions
  value = value >> PinID; // move the value (1 or 0) to bit0 of value
  return value; // Will return 0 or 1 
}


// Set DEN value for all Port pins
void GPIO_PORT_Regs::Set_Port_DEN(unsigned int value) 
{ 
  GPIO_PORTx_DEN_R = value;
}


// Get DEN value for all Port pins
unsigned int GPIO_PORT_Regs::Get_Port_DEN() 
{ 
  return GPIO_PORTx_DEN_R;
}


// Set DIR value of a given pin
void GPIO_PORT_Regs::Set_Port_Pin_DIR(unsigned int PinID, unsigned int value) 
{ 
  unsigned int mask = 1;
  mask = mask << PinID; // Shift 1 to PinID position
  if(value == 0) {
    GPIO_PORTx_DIR_R = GPIO_PORTx_DIR_R & ~(mask); // force bit position PinID to 0
  } 
  else {
    GPIO_PORTx_DIR_R = GPIO_PORTx_DIR_R | mask; // force bit position PinID to 1
  }
}


// Get DIR value of a specified pin
unsigned int GPIO_PORT_Regs::Get_Port_Pin_DIR(unsigned int PinID) 
{ 
  unsigned int value = 0;
  unsigned int mask = 1;
  mask = mask << PinID; // Shift 1 to PinID position
  value = (GPIO_PORTx_DIR_R & mask); // Zero out all other positions
  value = value >> PinID; // move the value (1 or 0) to bit0 of value
  return value; // Will return 0 or 1 
}


// Set DIR value for all Port pins
void GPIO_PORT_Regs::Set_Port_DIR(unsigned int value) 
{ 
  GPIO_PORTx_DIR_R = value;
}


// Get DIR value for all Port pins
unsigned int GPIO_PORT_Regs::Get_Port_DIR() 
{ 
  return GPIO_PORTx_DIR_R;
}


// Set DATA value of a given pin
void GPIO_PORT_Regs::Set_Port_Pin_DATA(unsigned int PinID, unsigned int value) 
{ 
  unsigned int mask = 1;
  mask = mask << PinID; // Shift 1 to PinID position
  if(value == 0) {
    GPIO_PORTx_DATA_R = GPIO_PORTx_DATA_R & ~(mask); // force bit position PinID to 0
  } 
  else {
    GPIO_PORTx_DATA_R = GPIO_PORTx_DATA_R | mask; // force bit position PinID to 1
  }
}


// Get DATA value of a specified pin
unsigned int GPIO_PORT_Regs::Get_Port_Pin_DATA(unsigned int PinID) 
{ 
  unsigned int value = 0;
  unsigned int mask = 1;
  mask = mask << PinID; // Shift 1 to PinID position
  value = (GPIO_PORTx_DATA_R & mask); // Zero out all other positions
  value = value >> PinID; // move the value (1 or 0) to bit0 of value
  return value; // Will return 0 or 1 
}


// Set DATA value for all Port pins
void GPIO_PORT_Regs::Set_Port_DATA(unsigned int value) 
{
  GPIO_PORTx_DATA_R = value;
}


// Get DATA value for all Port pins
unsigned int GPIO_PORT_Regs::Get_Port_DATA() 
{ 
  return GPIO_PORTx_DATA_R;
}


// Set AFSEL value of a given pin
void GPIO_PORT_Regs::Set_Port_Pin_AFSEL(unsigned int PinID, unsigned int value) 
{ 
  unsigned int mask = 1;
  mask = mask << PinID; // Shift 1 to PinID position
  if(value == 0) {
    GPIO_PORTx_AFSEL_R = GPIO_PORTx_AFSEL_R & ~(mask); // force bit position PinID to 0
  } 
  else {
    GPIO_PORTx_AFSEL_R = GPIO_PORTx_AFSEL_R | mask; // force bit position PinID to 1
  }
}


// Get AFSEL value of a specified pin
unsigned int GPIO_PORT_Regs::Get_Port_Pin_AFSEL(unsigned int PinID) 
{ 
  unsigned int value = 0;
  unsigned int mask = 1;
  mask = mask << PinID; // Shift 1 to PinID position
  value = (GPIO_PORTx_AFSEL_R & mask); // Zero out all other positions
  value = value >> PinID; // move the value (1 or 0) to bit0 of value
  return value; // Will return 0 or 1 
}


// Set AFSEL value for all Port pins
void GPIO_PORT_Regs::Set_Port_AFSEL(unsigned int value) 
{ 
  GPIO_PORTx_AFSEL_R = value;
}


// Get AFSEL value for all Port pins
unsigned int GPIO_PORT_Regs::Get_Port_AFSEL() 
{ 
  return GPIO_PORTx_AFSEL_R;
}


// Set PCTL value of a given pin
void GPIO_PORT_Regs::Set_Port_Pin_PCTL(unsigned int PinID, unsigned int value) 
{ 
  unsigned int mask = 0b1111; // Note each pin position is 4-bits
  value = value << (PinID*4); // Shift value to correct PinID position
  mask = mask << (PinID*4); // Shift 0b1111 mask to PinID position
  GPIO_PORTx_PCTL_R = GPIO_PORTx_PCTL_R & ~(mask); // clear pin position to 0
  GPIO_PORTx_PCTL_R = GPIO_PORTx_PCTL_R | value; // Set correct bits of pin position to 1
}


// Get PCTL value of a specified pin
unsigned int GPIO_PORT_Regs::Get_Port_Pin_PCTL(unsigned int PinID) 
{ 
  unsigned int value = 0; // Initialize value to 0
  unsigned int mask = 0b1111;  // Note each pin position is 4-bits
  mask = mask << (PinID*4); // Shift 0b1111 to current PinID position
  value = (GPIO_PORTx_PCTL_R & mask); // Zero out all other positions
  value = value >> (PinID*4); // move the 4-bit value to position 0
  return value; // Return the 4-bit value
}


// Set PCTL value for all Port pins
void GPIO_PORT_Regs::Set_Port_PCTL(unsigned int value) 
{ 
  GPIO_PORTx_PCTL_R = value;
}


// Get PCTL value for all Port pins
unsigned int GPIO_PORT_Regs::Get_Port_PCTL(void) 
{ 
  return GPIO_PORTx_PCTL_R;
}



// Map Ports A-F to 0-5
const char PortName[6] = {'A', 'B', 'C', 'D', 'E', 'F'}; 

// 4D-array indexed by [Port][wire][Mux value][Device Name]
// Data Sheet table PTCL values (Note: Simplified, only encoding 0 – 8 Mux values)
const char GPIO_PTCL_Table[6][8][9][20] =
{
 {
// Port A: Analog & Digital options for each PMCx
//    0         1         2         3         4         5         6         7         8
// PA0 (wire 0)   
  {"BLANK",  "U0Rx",   "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "CAN1Rx"},
// PA1 (wire 1) 
  {"BLANK",  "U0Tx",   "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "CAN1Tx"},
// PA2 (wire 2)
  {"BLANK",  "BLANK",  "SSI0Clk","BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK"},
// PA3 (wire 3)
  {"BLANK",  "BLANK",  "SSI0Fss","BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK"},
// PA4 (wire 4)
  {"BLANK",  "BLANK",  "SSI0Rx", "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK"},
// PA5 (wire 5)
  {"BLANK",  "BLANK",  "SSI0Tx", "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK"},
// PA6 (wire 6)
  {"BLANK",  "BLANK",  "BLANK",  "I2C1SCL","BLANK",  "M1PWM2", "BLANK",  "BLANK",  "BLANK"},
// PA7 (wire 7)
  {"BLANK",  "BLANK",  "BLANK",  "I2C1SDA","BLANK",  "M1PWM3", "BLANK",  "BLANK",  "BLANK"}
 },


 {
// Port B: Analog & Digital options for each PMCx
//    0         1         2         3         4         5         6         7         8
// PB0 (wire 0)   
  {"BLANK",  "U1Rx",   "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "T2CCP0", "BLANK"},
// PB1 (wire 1) 
  {"BLANK",  "U1Tx",   "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "T2CCP1", "BLANK"},
// PB2 (wire 2)
  {"BLANK",  "BLANK",  "BLANK",  "I2C0SCL","BLANK",  "BLANK",  "BLANK",  "T3CCP0", "BLANK"},
// PB3 (wire 3)
  {"BLANK",  "BLANK",  "BLANK",  "I2C0SDA","BLANK",  "BLANK",  "BLANK",  "T3CCP1", "BLANK"},
// PB4 (wire 4)
  {"BLANK",  "BLANK",  "SSI2Cl", "BLANK",  "M0PWM2", "BLANK",  "BLANK",  "T1CCP0", "CAN0Rx"},
// PB5 (wire 5)
  {"BLANK",  "BLANK",  "SSI2Fss","BLANK",  "M0PWM3", "BLANK",  "BLANK",  "T1CCP1", "CAN0Tx"},
// PB6 (wire 6)
  {"BLANK",  "BLANK",  "SSI2Rx", "BLANK",  "M0PWM0", "BLANK",  "BLANK",  "T0CCP0", "BLANK"},
// PB7 (wire 7)
  {"BLANK",  "BLANK",  "SSI2Tx", "BLANK",  "M0PWM1", "BLANK",  "BLANK",  "T0CCP1", "BLANK"}
 },


 {
// Port C: Analog & Digital options for each PMCx
//    0         1         2         3         4         5         6         7         8
// PB0 (wire 0)   
  {"BLANK",  "U1Rx",   "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "T2CCP0", "BLANK"},
// PB1 (wire 1) 
  {"BLANK",  "U1Tx",   "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "T2CCP1", "BLANK"},
// PB2 (wire 2)
  {"BLANK",  "BLANK",  "BLANK",  "I2C0SCL","BLANK",  "BLANK",  "BLANK",  "T3CCP0", "BLANK"},
// PB3 (wire 3)
  {"BLANK",  "BLANK",  "BLANK",  "I2C0SDA","BLANK",  "BLANK",  "BLANK",  "T3CCP1", "BLANK"},
// PB4 (wire 4)
  {"BLANK",  "BLANK",  "SSI2Cl", "BLANK",  "M0PWM2", "BLANK",  "BLANK",  "T1CCP0", "CAN0Rx"},
// PB5 (wire 5)
  {"BLANK",  "BLANK",  "SSI2Fss","BLANK",  "M0PWM3", "BLANK",  "BLANK",  "T1CCP1", "CAN0Tx"},
// PB6 (wire 6)
  {"BLANK",  "BLANK",  "SSI2Rx", "BLANK",  "M0PWM0", "BLANK",  "BLANK",  "T0CCP0", "BLANK"},
// PB7 (wire 7)
  {"BLANK",  "BLANK",  "SSI2Tx", "BLANK",  "M0PWM1", "BLANK",  "BLANK",  "T0CCP1", "BLANK"}
 },


 {
// Port D: Analog & Digital options for each PMCx
//    0         1         2         3         4         5         6         7         8
// PB0 (wire 0)   
  {"BLANK",  "U1Rx",   "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "T2CCP0", "BLANK"},
// PB1 (wire 1) 
  {"BLANK",  "U1Tx",   "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "T2CCP1", "BLANK"},
// PB2 (wire 2)
  {"BLANK",  "BLANK",  "BLANK",  "I2C0SCL","BLANK",  "BLANK",  "BLANK",  "T3CCP0", "BLANK"},
// PB3 (wire 3)
  {"BLANK",  "BLANK",  "BLANK",  "I2C0SDA","BLANK",  "BLANK",  "BLANK",  "T3CCP1", "BLANK"},
// PB4 (wire 4)
  {"BLANK",  "BLANK",  "SSI2Cl", "BLANK",  "M0PWM2", "BLANK",  "BLANK",  "T1CCP0", "CAN0Rx"},
// PB5 (wire 5)
  {"BLANK",  "BLANK",  "SSI2Fss","BLANK",  "M0PWM3", "BLANK",  "BLANK",  "T1CCP1", "CAN0Tx"},
// PB6 (wire 6)
  {"BLANK",  "BLANK",  "SSI2Rx", "BLANK",  "M0PWM0", "BLANK",  "BLANK",  "T0CCP0", "BLANK"},
// PB7 (wire 7)
  {"BLANK",  "BLANK",  "SSI2Tx", "BLANK",  "M0PWM1", "BLANK",  "BLANK",  "T0CCP1", "BLANK"}
 },


 {
// Port E: Analog & Digital options for each PMCx
//    0         1         2         3         4         5         6         7         8
// PB0 (wire 0)   
  {"BLANK",  "U1Rx",   "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "T2CCP0", "BLANK"},
// PB1 (wire 1) 
  {"BLANK",  "U1Tx",   "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "T2CCP1", "BLANK"},
// PB2 (wire 2)
  {"BLANK",  "BLANK",  "BLANK",  "I2C0SCL","BLANK",  "BLANK",  "BLANK",  "T3CCP0", "BLANK"},
// PB3 (wire 3)
  {"BLANK",  "BLANK",  "BLANK",  "I2C0SDA","BLANK",  "BLANK",  "BLANK",  "T3CCP1", "BLANK"},
// PB4 (wire 4)
  {"BLANK",  "BLANK",  "SSI2Cl", "BLANK",  "M0PWM2", "BLANK",  "BLANK",  "T1CCP0", "CAN0Rx"},
// PB5 (wire 5)
  {"BLANK",  "BLANK",  "SSI2Fss","BLANK",  "M0PWM3", "BLANK",  "BLANK",  "T1CCP1", "CAN0Tx"},
// PB6 (wire 6)
  {"BLANK",  "BLANK",  "SSI2Rx", "BLANK",  "M0PWM0", "BLANK",  "BLANK",  "T0CCP0", "BLANK"},
// PB7 (wire 7)
  {"BLANK",  "BLANK",  "SSI2Tx", "BLANK",  "M0PWM1", "BLANK",  "BLANK",  "T0CCP1", "BLANK"}
 },


 {
// Port F: Analog & Digital options for each PMCx
//    0         1         2         3         4         5         6         7         8
// PB0 (wire 0)   
  {"BLANK",  "U1Rx",   "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "T2CCP0", "BLANK"},
// PB1 (wire 1) 
  {"BLANK",  "U1Tx",   "BLANK",  "BLANK",  "BLANK",  "BLANK",  "BLANK",  "T2CCP1", "BLANK"},
// PB2 (wire 2)
  {"BLANK",  "BLANK",  "BLANK",  "I2C0SCL","BLANK",  "BLANK",  "BLANK",  "T3CCP0", "BLANK"},
// PB3 (wire 3)
  {"BLANK",  "BLANK",  "BLANK",  "I2C0SDA","BLANK",  "BLANK",  "BLANK",  "T3CCP1", "BLANK"},
// PB4 (wire 4)
  {"BLANK",  "BLANK",  "SSI2Cl", "BLANK",  "M0PWM2", "BLANK",  "BLANK",  "T1CCP0", "CAN0Rx"},
// PB5 (wire 5)
  {"BLANK",  "BLANK",  "SSI2Fss","BLANK",  "M0PWM3", "BLANK",  "BLANK",  "T1CCP1", "CAN0Tx"},
// PB6 (wire 6)
  {"BLANK",  "BLANK",  "SSI2Rx", "BLANK",  "M0PWM0", "BLANK",  "BLANK",  "T0CCP0", "BLANK"},
// PB7 (wire 7)
  {"BLANK",  "BLANK",  "SSI2Tx", "BLANK",  "M0PWM1", "BLANK",  "BLANK",  "T0CCP1", "BLANK"}
 }

};



