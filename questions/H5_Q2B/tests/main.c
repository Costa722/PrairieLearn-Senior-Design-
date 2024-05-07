#include <stdio.h>
#include <stdint.h>
#include "/grade/tests/buttonZeroCases.c"
#include "/grade/tests/buttonOneCases.c"
#include "/grade/tests/buttonTwoCases.c"
#include "/grade/tests/buttonThreeCases.c"

/*void init_ports(){
    //Don't know if you need to initialize for this problem
}*/

//void buttonCheck();

void resetGPIO_DATA_R_registers(){
    GPIO_PORTA_DATA_R = 0x00000000;
    GPIO_PORTB_DATA_R = 0x00000000;
    GPIO_PORTC_DATA_R = 0x00000000;
    GPIO_PORTD_DATA_R = 0x00000000;
    GPIO_PORTE_DATA_R = 0x00000000;
    GPIO_PORTF_DATA_R = 0x00000000;
}

int main(){
    /*FILE* outputFile = fopen("/grade/tests/studentAnswers.txt", "w");
    if (outputFile == NULL) {
        printf("Unable to open file.\n");
        return 1; // Return with error
    }*/
    
    scanf("%c %c %d %d %d %d %d %d %d %d", &leftPortLabel, &rightPortLabel, &buttonZeroBit, &buttonOneBit, &buttonTwoBit, &buttonThreeBit, &LEDZeroBit, &LEDOneBit, &LEDTwoBit, &LEDThreeBit);
    
    buttonZeroSuccess = buttonZeroCases();
    resetGPIO_DATA_R_registers();

    buttonOneSuccess = buttonOneCases();
    resetGPIO_DATA_R_registers();

    buttonTwoSuccess = buttonTwoCases();
    resetGPIO_DATA_R_registers();

    buttonThreeSuccess = buttonThreeCases();
    
    if(buttonZeroSuccess == true && buttonOneSuccess == true && buttonTwoSuccess == true && buttonThreeSuccess == true)
        printf("Success!");
    else{
        if(buttonZeroSuccess == false)
            printf("Button Zero Code is incorrect\n");
        if(buttonOneSuccess == false)
            printf("Button One Code is incorrect\n");
        if(buttonTwoSuccess == false)
            printf("Button Two Code is incorrect\n");
        if(buttonThreeSuccess == false)
            printf("Button Three Code is incorrect\n");
    }
    
    //fclose(outputFile);
    return 1;
}