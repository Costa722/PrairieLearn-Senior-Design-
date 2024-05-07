#include <stdio.h>
#include <stdint.h>

uint32_t  SYSCTL_RCGCGPIO_R = 0x00000000;
uint32_t  GPIO_PORTA_DEN_R  = 0x00000000;
uint32_t  GPIO_PORTB_DEN_R  = 0x00000000;
uint32_t  GPIO_PORTC_DEN_R  = 0x00000000;
uint32_t  GPIO_PORTD_DEN_R  = 0x00000000;
uint32_t  GPIO_PORTE_DEN_R  = 0x00000000;
uint32_t  GPIO_PORTF_DEN_R  = 0x00000000;
uint32_t  GPIO_PORTA_DIR_R  = 0x00000000;
uint32_t  GPIO_PORTB_DIR_R  = 0x00000000;
uint32_t  GPIO_PORTC_DIR_R  = 0x00000000;
uint32_t  GPIO_PORTD_DIR_R  = 0x00000000;
uint32_t  GPIO_PORTE_DIR_R  = 0x00000000;
uint32_t  GPIO_PORTF_DIR_R  = 0x00000000;

void init_ports(void);

int main(){
    FILE* outputFile = fopen("/grade/tests/studentAnswers.txt", "w");
    if (outputFile == NULL) {
        printf("Unable to open file.\n");
        return 1; // Return with error
    }
    
    init_ports();
    
    fprintf(outputFile, "SYSCTL_RCGCGPIO_R = 0x%x\n", SYSCTL_RCGCGPIO_R);
    
    if(GPIO_PORTA_DEN_R != 0x00000000){
        fprintf(outputFile, "GPIO_PORTA_DEN_R = 0x%x\n", GPIO_PORTA_DEN_R);
    }
    if(GPIO_PORTB_DEN_R != 0x00000000){
        fprintf(outputFile, "GPIO_PORTB_DEN_R = 0x%x\n", GPIO_PORTB_DEN_R);
    }
    if(GPIO_PORTC_DEN_R != 0x00000000){
        fprintf(outputFile, "GPIO_PORTC_DEN_R = 0x%x\n", GPIO_PORTC_DEN_R);
    }
    if(GPIO_PORTD_DEN_R != 0x00000000){
        fprintf(outputFile, "GPIO_PORTD_DEN_R = 0x%x\n", GPIO_PORTD_DEN_R);
    }
    if(GPIO_PORTE_DEN_R != 0x00000000){
        fprintf(outputFile, "GPIO_PORTE_DEN_R = 0x%x\n", GPIO_PORTE_DEN_R);
    }
    if(GPIO_PORTF_DEN_R != 0x00000000){
        fprintf(outputFile, "GPIO_PORTF_DEN_R = 0x%x\n", GPIO_PORTF_DEN_R);
    }
    
    if(GPIO_PORTA_DIR_R != 0x00000000){
        fprintf(outputFile, "GPIO_PORTA_DIR_R = 0x%x\n", GPIO_PORTA_DIR_R);
    }
    if(GPIO_PORTB_DIR_R != 0x00000000){
        fprintf(outputFile, "GPIO_PORTB_DIR_R = 0x%x\n", GPIO_PORTB_DIR_R);
    }
    if(GPIO_PORTC_DIR_R != 0x00000000){
        fprintf(outputFile, "GPIO_PORTC_DIR_R = 0x%x\n", GPIO_PORTC_DIR_R);
    }
    if(GPIO_PORTD_DIR_R != 0x00000000){
        fprintf(outputFile, "GPIO_PORTD_DIR_R = 0x%x\n", GPIO_PORTD_DIR_R);
    }
    if(GPIO_PORTE_DIR_R != 0x00000000){
        fprintf(outputFile, "GPIO_PORTE_DIR_R = 0x%x\n", GPIO_PORTE_DIR_R);
    }
    if(GPIO_PORTF_DIR_R != 0x00000000){
        fprintf(outputFile, "GPIO_PORTF_DIR_R = 0x%x\n", GPIO_PORTF_DIR_R);
    }
    
    fclose(outputFile);
    return 1;
}