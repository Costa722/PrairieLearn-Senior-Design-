// File Name: CPRE288-H5_Q2.cpp
// Description: 
//
// How to compile: gcc -o CPRE288-H5_Q2 CPRE288-H5_Q2.cpp CPRE288-GPIO.cpp
// How to run: ./GPIO-H5_Q2
//
// Author: Tyler Weberski.
// Date: 3/19/2023

#include <stdio.h>  // For printf
#include <time.h>   // For time() to generate a seed for randomization
#include <stdlib.h> // For rand, srand
#include <string.h> // For strcpy, strcmp, etc.
#include "CPRE288-GPIO.h"  // For CPRE288-GPIO classes, and data structures

int main(){
    // Note: See CPRE288-GPIO.cpp for definition of Portname[], and GPIO_PTCL_Table 

    char leftPortDirection[9];
    char rightPortDirection[9];
    char leftPortLabel;
    char rightPortLabel;
    char outputFilePath[100];

    scanf("%s %s %c %c %s", leftPortDirection, rightPortDirection, &leftPortLabel, &rightPortLabel, outputFilePath);

    GPIO_Device GPIO_sol_cfg;
    int leftPortID = 0; // 0 to 5 -> A to F
    int rightPortID = 0; // 0 to 5 -> A to F

    switch(leftPortLabel){
        case 'A':
            leftPortID = 0;
            break;
        case 'B':
            leftPortID = 1;
            break;
        case 'C':
            leftPortID = 2;
            break;
        case 'D':
            leftPortID = 3;
            break;
        case 'E':
            leftPortID = 4;
            break;
        case 'F':
            leftPortID = 5;
            break;
        default:
            leftPortID = 0;
    }

    switch(rightPortLabel){
        case 'A':
            rightPortID = 0;
            break;
        case 'B':
            rightPortID = 1;
            break;
        case 'C':
            rightPortID = 2;
            break;
        case 'D':
            rightPortID = 3;
            break;
        case 'E':
            rightPortID = 4;
            break;
        case 'F':
            rightPortID = 5;
            break;
        default:
            rightPortID = 0;
    }
    
    GPIO_sol_cfg.Set_Port_Clock_En_Id(leftPortID, 1);
    GPIO_sol_cfg.Set_Port_Clock_En_Id(rightPortID, 1);
    
    GPIO_sol_cfg.GPIO_PORT_Reg_array[leftPortID].Set_Port_DEN(255);
    GPIO_sol_cfg.GPIO_PORT_Reg_array[rightPortID].Set_Port_DEN(255);
    
    int j = 7;
    int i;
    
    for(i=0; i < sizeof(leftPortDirection) - 1; i++){
        if(leftPortDirection[j] == '0'){
            GPIO_sol_cfg.GPIO_PORT_Reg_array[leftPortID].Set_Port_Pin_DIR(i, 0);
        }
        else{
            GPIO_sol_cfg.GPIO_PORT_Reg_array[leftPortID].Set_Port_Pin_DIR(i, 1);
        }
        j--;
    }

    j = 7;

    for(int i=0; i < sizeof(rightPortDirection) - 1; i++){
        if(rightPortDirection[j] == '0'){
            GPIO_sol_cfg.GPIO_PORT_Reg_array[rightPortID].Set_Port_Pin_DIR(i, 0); 
        }
        else{
            GPIO_sol_cfg.GPIO_PORT_Reg_array[rightPortID].Set_Port_Pin_DIR(i, 1);
        }
        j--;
    }
    
    FILE* outputFile = fopen(outputFilePath, "w");
    fprintf(outputFile, "SYSCTL_RCGCGPIO_R = 0x%08X\n", GPIO_sol_cfg.SYSCTL_RCGCGPIO_R);
    fprintf(outputFile, "GPIO_PORT%c_DEN_R = 0x%08X\n", leftPortLabel, GPIO_sol_cfg.GPIO_PORT_Reg_array[leftPortID].GPIO_PORTx_DEN_R);
    fprintf(outputFile, "GPIO_PORT%c_DEN_R = 0x%08X\n", rightPortLabel, GPIO_sol_cfg.GPIO_PORT_Reg_array[rightPortID].GPIO_PORTx_DEN_R);
    fprintf(outputFile, "GPIO_PORT%c_DIR_R = 0x%08X\n", leftPortLabel, GPIO_sol_cfg.GPIO_PORT_Reg_array[leftPortID].GPIO_PORTx_DIR_R);
    fprintf(outputFile, "GPIO_PORT%c_DIR_R = 0x%08X\n", rightPortLabel, GPIO_sol_cfg.GPIO_PORT_Reg_array[rightPortID].GPIO_PORTx_DIR_R);
    fclose(outputFile);
    
    char line[100];
    FILE* readFile = fopen(outputFilePath, "r");
    if(readFile == nullptr){
        perror("Error opening file");
        return 1;
    }
    while(fscanf(readFile, "%99[^\n]\n", line) == 1){
        printf("%s\n", line);
    }
    fclose(readFile);
}
