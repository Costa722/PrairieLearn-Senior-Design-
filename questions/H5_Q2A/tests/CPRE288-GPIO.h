// File Name: CPRE288-GPIO.h
// Description: Header file for GPIO related data structures and helper function
//              for autogenerating, and autgrading GPIO related CPRE 288 questions.
// Author: Dr. Phillip Jones.
// Date: 12/28/2023

 // Make sure file only included once
#ifndef CPRE288_GPIO_H  
#define CPRE288_GPIO_H


// Class for GPIO Port specific information
class GPIO_PORT_Regs
{ 
  public: 
  unsigned int GPIO_PORTx_DEN_R;    // Digital enable register for Port’s pins
  unsigned int GPIO_PORTx_DIR_R;    // Direction register for Port’s pins
  unsigned int GPIO_PORTx_DATA_R;   // Port’s data register
  unsigned int GPIO_PORTx_AFSEL_R;  // Alternative Function Select reg. for Port’s pins
  unsigned int GPIO_PORTx_PCTL_R;   // Peripheral Select reg. for Port’s pins

  // Member Functions for setting / getting register values
  GPIO_PORT_Regs(); // Constructor
  void Set_Port_Pin_DEN(unsigned int PinID, unsigned int value); // Set DEN value of a given pin
  unsigned int Get_Port_Pin_DEN(unsigned int PinID); // Get DEN value of a specified pin
  void Set_Port_DEN(unsigned int value); // Set DEN value for all Port pins
  unsigned int Get_Port_DEN(); // Get DEN value for all Port pins
  void Set_Port_Pin_DIR(unsigned int PinID, unsigned int value); // Set DIR value of a given pin
  unsigned int Get_Port_Pin_DIR(unsigned int PinID); // Get DIR value of a specified pin
  void Set_Port_DIR(unsigned int value); // Set DIR value for all Port pins
  unsigned int Get_Port_DIR(); // Get DIR value for all Port pins 
  void Set_Port_Pin_DATA(unsigned int PinID, unsigned int value); // Set DATA value of a given pin
  unsigned int Get_Port_Pin_DATA(unsigned int PinID); // Get DATA value of a specified pin
  void Set_Port_DATA(unsigned int value); // Set DATA value for all Port pins
  unsigned int Get_Port_DATA(); // Get DATA value for all Port pins
  void Set_Port_Pin_AFSEL(unsigned int PinID, unsigned int value); // Set AFSEL value of a given pin
  unsigned int Get_Port_Pin_AFSEL(unsigned int PinID); // Get AFSEL value of a specified pin
  void Set_Port_AFSEL(unsigned int value); // Set AFSEL value for all Port pins
  unsigned int Get_Port_AFSEL(); // Get AFSEL value for all Port pins
  void Set_Port_Pin_PCTL(unsigned int PinID, unsigned int value); // Set PCTL value of a given pin
  unsigned int Get_Port_Pin_PCTL(unsigned int PinID); // Get PCTL value of a specified pin
  void Set_Port_PCTL(unsigned int value); // Set PCTL value for all Port pins
  unsigned int Get_Port_PCTL(void); // Get PCTL value for all Port pins
};


// Class for GPIO Device configuration information
class GPIO_Device
{ 
  public:
  GPIO_PORT_Regs GPIO_PORT_Reg_array[6]; // Registers for each GPIO Port A-F => 0-5
  unsigned int SYSCTL_RCGCGPIO_R;  // Port clock enable 
  
  // Members
  GPIO_Device(); // Constructor
  void Set_Port_Clock_En_Id(unsigned int PortID, unsigned int value); // Set clock enable value for Port PortID (Port A-F => 0-5)
  unsigned int Get_Port_Clock_En_Id(unsigned int PortID); // Get Enable clock setting for Port PortID (Port A-F => 0-5)
  void Set_Port_Clock_En_Reg(unsigned int value); // Directly set Port Clock Enable Reg value
  unsigned int Get_Port_Clock_En_Reg(); // Directly get Port Clock En Reg value

};


// Map Ports A-F to 0-5
// See CPRE288-GPIO.cpp for initialization
extern const char PortName[6];

// 4D-array indexed by [Port][wire][Mux value][Device Name]
// See CPRE288-GPIO.cpp for initialization
// Data Sheet table PTCL values (Note: Simplified, only encoding 0 – 8 Mux values)
extern const char GPIO_PTCL_Table[6][8][9][20];

#endif // Make sure file only included once