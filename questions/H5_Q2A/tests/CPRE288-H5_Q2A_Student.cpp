#include <stdio.h>  // For printf
#include <time.h>   // For time() to generate a seed for randomization
#include <stdlib.h> // For rand, srand
#include <string.h> // For strcpy, strcmp, etc.
#include <cstdio>
#include "CPRE288-GPIO.h"  // For CPRE288-GPIO classes, and data structures

int hexCharToInt(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'f')
        return 10 + c - 'a';
    else if (c >= 'A' && c <= 'F')
        return 10 + c - 'A';
    else if (c == 'x' || c == 'X')
        return 0;
    else
        return -1; // Invalid character
}

int hexToInt(const char* hex) {
    int result = 0;
    int len = strlen(hex);
    for (int i = 0; i < len; ++i) {
        int digit = hexCharToInt(hex[i]);
        if (digit == -1) {
            fprintf(stderr, "Invalid hexadecimal string\n");
            return -1;
        }
        result = result * 16 + digit;
    }
    return result;
}

int main(){
    // Note: See CPRE288-GPIO.cpp for definition of Portname[], and GPIO_PTCL_Table 

    char sysctlRegister[100];
    char leftPortDigEnable[100];
    char rightPortDigEnable[100];
    char leftPortDirection[100];
    char rightPortDirection[100];
    char leftPortLabel;
    int leftPortID;
    char rightPortLabel;
    int rightPortID;
    char studentAnswersTxtPath[99] = "/grade/tests/studentAnswers.txt";

    char line[100];
    FILE* readFile = fopen(studentAnswersTxtPath, "r");
    if(readFile == nullptr){
        perror("Error opening file");
        return 1;
    }
    
    if (fscanf(readFile, "%99[^\n]\n", line) == 1) {
        strcpy(sysctlRegister, line + strlen(line) - 2);
    }
    if (fscanf(readFile, "%99[^\n]\n", line) == 1) {
        strcpy(leftPortDigEnable, line + strlen(line) - 2);
        leftPortLabel = line[9];
    }
    if (fscanf(readFile, "%99[^\n]\n", line) == 1) {
        strcpy(rightPortDigEnable, line + strlen(line) - 2);
        rightPortLabel = line[9];
    }
    if (fscanf(readFile, "%99[^\n]\n", line) == 1) {
        strcpy(leftPortDirection, line + strlen(line) - 2);
    }
    if (fscanf(readFile, "%99[^\n]\n", line) == 1) {
        strcpy(rightPortDirection, line + strlen(line) - 2);
    }
    fclose(readFile);
    
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


    int sysctlRegisterValue = hexToInt(sysctlRegister);
    int leftPortDigEnableValue = hexToInt(leftPortDigEnable);
    int rightPortDigEnableValue = hexToInt(rightPortDigEnable);
    int leftPortDirectionValue = hexToInt(leftPortDirection);
    int rightPortDirectionValue = hexToInt(rightPortDirection);
    
    GPIO_Device GPIO_sol_cfg;
    
    GPIO_sol_cfg.Set_Port_Clock_En_Reg(sysctlRegisterValue);
    
    GPIO_sol_cfg.GPIO_PORT_Reg_array[leftPortID].Set_Port_DEN(leftPortDigEnableValue);
    GPIO_sol_cfg.GPIO_PORT_Reg_array[rightPortID].Set_Port_DEN(rightPortDigEnableValue);
    
    GPIO_sol_cfg.GPIO_PORT_Reg_array[leftPortID].Set_Port_DIR(leftPortDirectionValue);
    GPIO_sol_cfg.GPIO_PORT_Reg_array[rightPortID].Set_Port_DIR(rightPortDirectionValue);
    
    
    FILE* outputFile = fopen(studentAnswersTxtPath, "w");
    fprintf(outputFile, "SYSCTL_RCGCGPIO_R = 0x%08X\n", GPIO_sol_cfg.SYSCTL_RCGCGPIO_R);
    fprintf(outputFile, "GPIO_PORT%c_DEN_R = 0x%08X\n", leftPortLabel, GPIO_sol_cfg.GPIO_PORT_Reg_array[leftPortID].GPIO_PORTx_DEN_R);
    fprintf(outputFile, "GPIO_PORT%c_DEN_R = 0x%08X\n", rightPortLabel, GPIO_sol_cfg.GPIO_PORT_Reg_array[rightPortID].GPIO_PORTx_DEN_R);
    fprintf(outputFile, "GPIO_PORT%c_DIR_R = 0x%08X\n", leftPortLabel, GPIO_sol_cfg.GPIO_PORT_Reg_array[leftPortID].GPIO_PORTx_DIR_R);
    fprintf(outputFile, "GPIO_PORT%c_DIR_R = 0x%08X\n", rightPortLabel, GPIO_sol_cfg.GPIO_PORT_Reg_array[rightPortID].GPIO_PORTx_DIR_R);
    fclose(outputFile);

    readFile = fopen(studentAnswersTxtPath, "r");
    if(readFile == nullptr){
        perror("Error opening file");
        return 1;
    }
    while(fscanf(readFile, "%99[^\n]\n", line) == 1){
        printf("%s\n", line);
    }
}
