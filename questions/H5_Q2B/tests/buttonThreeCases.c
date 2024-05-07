#include <stdbool.h>
#include "/grade/tests/globals.h"

bool buttonThreeCases(){
    //Button Three activated, check if LED Three is set properly
    //rightPortLabel can only be B-F because of server.py generation of picture
    switch(rightPortLabel){
        case 'B':
        switch(buttonThreeBit){
            case 0:
                GPIO_PORTB_DATA_R = 0b1;
                buttonCheck();
                switch(LEDThreeBit){
                    case 1:
                        if(GPIO_PORTB_DATA_R == 0b00000011)
                            return true;
                    case 2:
                        if(GPIO_PORTB_DATA_R == 0b00000101)
                            return true;
                    case 3:
                        if(GPIO_PORTB_DATA_R == 0b00001001)
                            return true;
                    case 4:
                        if(GPIO_PORTB_DATA_R == 0b00010001)
                            return true;
                    case 5:
                        if(GPIO_PORTB_DATA_R == 0b00100001)
                            return true;
                    case 6:
                        if(GPIO_PORTB_DATA_R == 0b01000001)
                            return true;
                    case 7:
                        if(GPIO_PORTB_DATA_R == 0b10000001)
                            return true;
                }
            case 1:
                GPIO_PORTB_DATA_R = 0b10;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTB_DATA_R == 0b00000011)
                            return true;
                    case 2:
                        if(GPIO_PORTB_DATA_R == 0b00000110)
                            return true;
                    case 3:
                        if(GPIO_PORTB_DATA_R == 0b00001010)
                            return true;
                    case 4:
                        if(GPIO_PORTB_DATA_R == 0b00010010)
                            return true;
                    case 5:
                        if(GPIO_PORTB_DATA_R == 0b00100010)
                            return true;
                    case 6:
                        if(GPIO_PORTB_DATA_R == 0b01000010)
                            return true;
                    case 7:
                        if(GPIO_PORTB_DATA_R == 0b10000010)
                            return true;
                }
            case 2:
                GPIO_PORTB_DATA_R = 0b100;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTB_DATA_R == 0b00000101)
                            return true;
                    case 1:
                        if(GPIO_PORTB_DATA_R == 0b00000110)
                            return true;
                    case 3:
                        if(GPIO_PORTB_DATA_R == 0b00001100)
                            return true;
                    case 4:
                        if(GPIO_PORTB_DATA_R == 0b00001100)
                            return true;
                    case 5:
                        if(GPIO_PORTB_DATA_R == 0b00010100)
                            return true;
                    case 6:
                        if(GPIO_PORTB_DATA_R == 0b01000100)
                            return true;
                    case 7:
                        if(GPIO_PORTB_DATA_R == 0b10000100)
                            return true;
                }
            case 3:
                GPIO_PORTB_DATA_R = 0b1000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTB_DATA_R == 0b00001001)
                            return true;
                    case 1:
                        if(GPIO_PORTB_DATA_R == 0b00001010)
                            return true;
                    case 2:
                        if(GPIO_PORTB_DATA_R == 0b00001100)
                            return true;
                    case 4:
                        if(GPIO_PORTB_DATA_R == 0b00011000)
                            return true;
                    case 5:
                        if(GPIO_PORTB_DATA_R == 0b00101000)
                            return true;
                    case 6:
                        if(GPIO_PORTB_DATA_R == 0b01001000)
                            return true;
                    case 7:
                        if(GPIO_PORTB_DATA_R == 0b10001000)
                            return true;
                }
            case 4:
                GPIO_PORTB_DATA_R = 0b10000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTB_DATA_R == 0b00010001)
                            return true;
                    case 1:
                        if(GPIO_PORTB_DATA_R == 0b00010010)
                            return true;
                    case 2:
                        if(GPIO_PORTB_DATA_R == 0b00010100)
                            return true;
                    case 3:
                        if(GPIO_PORTB_DATA_R == 0b00011000)
                            return true;
                    case 5:
                        if(GPIO_PORTB_DATA_R == 0b00110000)
                            return true;
                    case 6:
                        if(GPIO_PORTB_DATA_R == 0b01010000)
                            return true;
                    case 7:
                        if(GPIO_PORTB_DATA_R == 0b10010000)
                            return true;
                }
            case 5:
                GPIO_PORTB_DATA_R = 0b100000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTB_DATA_R == 0b00100001)
                            return true;
                    case 1:
                        if(GPIO_PORTB_DATA_R == 0b00100010)
                            return true;
                    case 2:
                        if(GPIO_PORTB_DATA_R == 0b00100100)
                            return true;
                    case 3:
                        if(GPIO_PORTB_DATA_R == 0b00101000)
                            return true;
                    case 4:
                        if(GPIO_PORTB_DATA_R == 0b00110000)
                            return true;
                    case 6:
                        if(GPIO_PORTB_DATA_R == 0b01100000)
                            return true;
                    case 7:
                        if(GPIO_PORTB_DATA_R == 0b10100000)
                            return true;
                }
            case 6:
                GPIO_PORTB_DATA_R = 0b1000000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTB_DATA_R == 0b01000001)
                            return true;
                    case 1:
                        if(GPIO_PORTB_DATA_R == 0b01000010)
                            return true;
                    case 2:
                        if(GPIO_PORTB_DATA_R == 0b01000100)
                            return true;
                    case 3:
                        if(GPIO_PORTB_DATA_R == 0b01001000)
                            return true;
                    case 4:
                        if(GPIO_PORTB_DATA_R == 0b01010000)
                            return true;
                    case 5:
                        if(GPIO_PORTB_DATA_R == 0b01100000)
                            return true;
                    case 7:
                        if(GPIO_PORTB_DATA_R == 0b11000000)
                            return true;
                }
            case 7:
                GPIO_PORTB_DATA_R = 0b10000000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTB_DATA_R == 0b10000001)
                            return true;
                    case 1:
                        if(GPIO_PORTB_DATA_R == 0b10000010)
                            return true;
                    case 2:
                        if(GPIO_PORTB_DATA_R == 0b10000100)
                            return true;
                    case 3:
                        if(GPIO_PORTB_DATA_R == 0b10001000)
                            return true;
                    case 4:
                        if(GPIO_PORTB_DATA_R == 0b10010000)
                            return true;
                    case 5:
                        if(GPIO_PORTB_DATA_R == 0b10100000)
                            return true;
                    case 6:
                        if(GPIO_PORTB_DATA_R == 0b11000000)
                            return true;
                }
        }
        case 'C':
        switch(buttonThreeBit){
            case 0:
                GPIO_PORTC_DATA_R = 0b1;
                buttonCheck();
                switch(LEDThreeBit){
                    case 1:
                        if(GPIO_PORTC_DATA_R == 0b00000011)
                            return true;
                    case 2:
                        if(GPIO_PORTC_DATA_R == 0b00000101)
                            return true;
                    case 3:
                        if(GPIO_PORTC_DATA_R == 0b00001001)
                            return true;
                    case 4:
                        if(GPIO_PORTC_DATA_R == 0b00010001)
                            return true;
                    case 5:
                        if(GPIO_PORTC_DATA_R == 0b00100001)
                            return true;
                    case 6:
                        if(GPIO_PORTC_DATA_R == 0b01000001)
                            return true;
                    case 7:
                        if(GPIO_PORTC_DATA_R == 0b10000001)
                            return true;
                }
            case 1:
                GPIO_PORTC_DATA_R = 0b10;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTC_DATA_R == 0b00000011)
                            return true;
                    case 2:
                        if(GPIO_PORTC_DATA_R == 0b00000110)
                            return true;
                    case 3:
                        if(GPIO_PORTC_DATA_R == 0b00001010)
                            return true;
                    case 4:
                        if(GPIO_PORTC_DATA_R == 0b00010010)
                            return true;
                    case 5:
                        if(GPIO_PORTC_DATA_R == 0b00100010)
                            return true;
                    case 6:
                        if(GPIO_PORTC_DATA_R == 0b01000010)
                            return true;
                    case 7:
                        if(GPIO_PORTC_DATA_R == 0b10000010)
                            return true;
                }
            case 2:
                GPIO_PORTC_DATA_R = 0b100;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTC_DATA_R == 0b00000101)
                            return true;
                    case 1:
                        if(GPIO_PORTC_DATA_R == 0b00000110)
                            return true;
                    case 3:
                        if(GPIO_PORTC_DATA_R == 0b00001100)
                            return true;
                    case 4:
                        if(GPIO_PORTC_DATA_R == 0b00001100)
                            return true;
                    case 5:
                        if(GPIO_PORTC_DATA_R == 0b00010100)
                            return true;
                    case 6:
                        if(GPIO_PORTC_DATA_R == 0b01000100)
                            return true;
                    case 7:
                        if(GPIO_PORTC_DATA_R == 0b10000100)
                            return true;
                }
            case 3:
                GPIO_PORTC_DATA_R = 0b1000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTC_DATA_R == 0b00001001)
                            return true;
                    case 1:
                        if(GPIO_PORTC_DATA_R == 0b00001010)
                            return true;
                    case 2:
                        if(GPIO_PORTC_DATA_R == 0b00001100)
                            return true;
                    case 4:
                        if(GPIO_PORTC_DATA_R == 0b00011000)
                            return true;
                    case 5:
                        if(GPIO_PORTC_DATA_R == 0b00101000)
                            return true;
                    case 6:
                        if(GPIO_PORTC_DATA_R == 0b01001000)
                            return true;
                    case 7:
                        if(GPIO_PORTC_DATA_R == 0b10001000)
                            return true;
                }
            case 4:
                GPIO_PORTC_DATA_R = 0b10000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTC_DATA_R == 0b00010001)
                            return true;
                    case 1:
                        if(GPIO_PORTC_DATA_R == 0b00010010)
                            return true;
                    case 2:
                        if(GPIO_PORTC_DATA_R == 0b00010100)
                            return true;
                    case 3:
                        if(GPIO_PORTC_DATA_R == 0b00011000)
                            return true;
                    case 5:
                        if(GPIO_PORTC_DATA_R == 0b00110000)
                            return true;
                    case 6:
                        if(GPIO_PORTC_DATA_R == 0b01010000)
                            return true;
                    case 7:
                        if(GPIO_PORTC_DATA_R == 0b10010000)
                            return true;
                }
            case 5:
                GPIO_PORTC_DATA_R = 0b100000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTC_DATA_R == 0b00100001)
                            return true;
                    case 1:
                        if(GPIO_PORTC_DATA_R == 0b00100010)
                            return true;
                    case 2:
                        if(GPIO_PORTC_DATA_R == 0b00100100)
                            return true;
                    case 3:
                        if(GPIO_PORTC_DATA_R == 0b00101000)
                            return true;
                    case 4:
                        if(GPIO_PORTC_DATA_R == 0b00110000)
                            return true;
                    case 6:
                        if(GPIO_PORTC_DATA_R == 0b01100000)
                            return true;
                    case 7:
                        if(GPIO_PORTC_DATA_R == 0b10100000)
                            return true;
                }
            case 6:
                GPIO_PORTC_DATA_R = 0b1000000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTC_DATA_R == 0b01000001)
                            return true;
                    case 1:
                        if(GPIO_PORTC_DATA_R == 0b01000010)
                            return true;
                    case 2:
                        if(GPIO_PORTC_DATA_R == 0b01000100)
                            return true;
                    case 3:
                        if(GPIO_PORTC_DATA_R == 0b01001000)
                            return true;
                    case 4:
                        if(GPIO_PORTC_DATA_R == 0b01010000)
                            return true;
                    case 5:
                        if(GPIO_PORTC_DATA_R == 0b01100000)
                            return true;
                    case 7:
                        if(GPIO_PORTC_DATA_R == 0b11000000)
                            return true;
                }
            case 7:
                GPIO_PORTC_DATA_R = 0b10000000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTC_DATA_R == 0b10000001)
                            return true;
                    case 1:
                        if(GPIO_PORTC_DATA_R == 0b10000010)
                            return true;
                    case 2:
                        if(GPIO_PORTC_DATA_R == 0b10000100)
                            return true;
                    case 3:
                        if(GPIO_PORTC_DATA_R == 0b10001000)
                            return true;
                    case 4:
                        if(GPIO_PORTC_DATA_R == 0b10010000)
                            return true;
                    case 5:
                        if(GPIO_PORTC_DATA_R == 0b10100000)
                            return true;
                    case 6:
                        if(GPIO_PORTC_DATA_R == 0b11000000)
                            return true;
                }
        }
        case 'D':
        switch(buttonThreeBit){
            case 0:
                GPIO_PORTD_DATA_R = 0b1;
                buttonCheck();
                switch(LEDThreeBit){
                    case 1:
                        if(GPIO_PORTD_DATA_R == 0b00000011)
                            return true;
                    case 2:
                        if(GPIO_PORTD_DATA_R == 0b00000101)
                            return true;
                    case 3:
                        if(GPIO_PORTD_DATA_R == 0b00001001)
                            return true;
                    case 4:
                        if(GPIO_PORTD_DATA_R == 0b00010001)
                            return true;
                    case 5:
                        if(GPIO_PORTD_DATA_R == 0b00100001)
                            return true;
                    case 6:
                        if(GPIO_PORTD_DATA_R == 0b01000001)
                            return true;
                    case 7:
                        if(GPIO_PORTD_DATA_R == 0b10000001)
                            return true;
                }
            case 1:
                GPIO_PORTD_DATA_R = 0b10;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTD_DATA_R == 0b00000011)
                            return true;
                    case 2:
                        if(GPIO_PORTD_DATA_R == 0b00000110)
                            return true;
                    case 3:
                        if(GPIO_PORTD_DATA_R == 0b00001010)
                            return true;
                    case 4:
                        if(GPIO_PORTD_DATA_R == 0b00010010)
                            return true;
                    case 5:
                        if(GPIO_PORTD_DATA_R == 0b00100010)
                            return true;
                    case 6:
                        if(GPIO_PORTD_DATA_R == 0b01000010)
                            return true;
                    case 7:
                        if(GPIO_PORTD_DATA_R == 0b10000010)
                            return true;
                }
            case 2:
                GPIO_PORTD_DATA_R = 0b100;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTD_DATA_R == 0b00000101)
                            return true;
                    case 1:
                        if(GPIO_PORTD_DATA_R == 0b00000110)
                            return true;
                    case 3:
                        if(GPIO_PORTD_DATA_R == 0b00001100)
                            return true;
                    case 4:
                        if(GPIO_PORTD_DATA_R == 0b00001100)
                            return true;
                    case 5:
                        if(GPIO_PORTD_DATA_R == 0b00010100)
                            return true;
                    case 6:
                        if(GPIO_PORTD_DATA_R == 0b01000100)
                            return true;
                    case 7:
                        if(GPIO_PORTD_DATA_R == 0b10000100)
                            return true;
                }
            case 3:
                GPIO_PORTD_DATA_R = 0b1000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTD_DATA_R == 0b00001001)
                            return true;
                    case 1:
                        if(GPIO_PORTD_DATA_R == 0b00001010)
                            return true;
                    case 2:
                        if(GPIO_PORTD_DATA_R == 0b00001100)
                            return true;
                    case 4:
                        if(GPIO_PORTD_DATA_R == 0b00011000)
                            return true;
                    case 5:
                        if(GPIO_PORTD_DATA_R == 0b00101000)
                            return true;
                    case 6:
                        if(GPIO_PORTD_DATA_R == 0b01001000)
                            return true;
                    case 7:
                        if(GPIO_PORTD_DATA_R == 0b10001000)
                            return true;
                }
            case 4:
                GPIO_PORTD_DATA_R = 0b10000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTD_DATA_R == 0b00010001)
                            return true;
                    case 1:
                        if(GPIO_PORTD_DATA_R == 0b00010010)
                            return true;
                    case 2:
                        if(GPIO_PORTD_DATA_R == 0b00010100)
                            return true;
                    case 3:
                        if(GPIO_PORTD_DATA_R == 0b00011000)
                            return true;
                    case 5:
                        if(GPIO_PORTD_DATA_R == 0b00110000)
                            return true;
                    case 6:
                        if(GPIO_PORTD_DATA_R == 0b01010000)
                            return true;
                    case 7:
                        if(GPIO_PORTD_DATA_R == 0b10010000)
                            return true;
                }
            case 5:
                GPIO_PORTD_DATA_R = 0b100000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTD_DATA_R == 0b00100001)
                            return true;
                    case 1:
                        if(GPIO_PORTD_DATA_R == 0b00100010)
                            return true;
                    case 2:
                        if(GPIO_PORTD_DATA_R == 0b00100100)
                            return true;
                    case 3:
                        if(GPIO_PORTD_DATA_R == 0b00101000)
                            return true;
                    case 4:
                        if(GPIO_PORTD_DATA_R == 0b00110000)
                            return true;
                    case 6:
                        if(GPIO_PORTD_DATA_R == 0b01100000)
                            return true;
                    case 7:
                        if(GPIO_PORTD_DATA_R == 0b10100000)
                            return true;
                }
            case 6:
                GPIO_PORTD_DATA_R = 0b1000000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTD_DATA_R == 0b01000001)
                            return true;
                    case 1:
                        if(GPIO_PORTD_DATA_R == 0b01000010)
                            return true;
                    case 2:
                        if(GPIO_PORTD_DATA_R == 0b01000100)
                            return true;
                    case 3:
                        if(GPIO_PORTD_DATA_R == 0b01001000)
                            return true;
                    case 4:
                        if(GPIO_PORTD_DATA_R == 0b01010000)
                            return true;
                    case 5:
                        if(GPIO_PORTD_DATA_R == 0b01100000)
                            return true;
                    case 7:
                        if(GPIO_PORTD_DATA_R == 0b11000000)
                            return true;
                }
            case 7:
                GPIO_PORTD_DATA_R = 0b10000000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTD_DATA_R == 0b10000001)
                            return true;
                    case 1:
                        if(GPIO_PORTD_DATA_R == 0b10000010)
                            return true;
                    case 2:
                        if(GPIO_PORTD_DATA_R == 0b10000100)
                            return true;
                    case 3:
                        if(GPIO_PORTD_DATA_R == 0b10001000)
                            return true;
                    case 4:
                        if(GPIO_PORTD_DATA_R == 0b10010000)
                            return true;
                    case 5:
                        if(GPIO_PORTD_DATA_R == 0b10100000)
                            return true;
                    case 6:
                        if(GPIO_PORTD_DATA_R == 0b11000000)
                            return true;
                }
        }
        case 'E':
        switch(buttonThreeBit){
            case 0:
                GPIO_PORTE_DATA_R = 0b1;
                buttonCheck();
                switch(LEDThreeBit){
                    case 1:
                        if(GPIO_PORTE_DATA_R == 0b00000011)
                            return true;
                    case 2:
                        if(GPIO_PORTE_DATA_R == 0b00000101)
                            return true;
                    case 3:
                        if(GPIO_PORTE_DATA_R == 0b00001001)
                            return true;
                    case 4:
                        if(GPIO_PORTE_DATA_R == 0b00010001)
                            return true;
                    case 5:
                        if(GPIO_PORTE_DATA_R == 0b00100001)
                            return true;
                    case 6:
                        if(GPIO_PORTE_DATA_R == 0b01000001)
                            return true;
                    case 7:
                        if(GPIO_PORTE_DATA_R == 0b10000001)
                            return true;
                }
            case 1:
                GPIO_PORTE_DATA_R = 0b10;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTE_DATA_R == 0b00000011)
                            return true;
                    case 2:
                        if(GPIO_PORTE_DATA_R == 0b00000110)
                            return true;
                    case 3:
                        if(GPIO_PORTE_DATA_R == 0b00001010)
                            return true;
                    case 4:
                        if(GPIO_PORTE_DATA_R == 0b00010010)
                            return true;
                    case 5:
                        if(GPIO_PORTE_DATA_R == 0b00100010)
                            return true;
                    case 6:
                        if(GPIO_PORTE_DATA_R == 0b01000010)
                            return true;
                    case 7:
                        if(GPIO_PORTE_DATA_R == 0b10000010)
                            return true;
                }
            case 2:
                GPIO_PORTE_DATA_R = 0b100;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTE_DATA_R == 0b00000101)
                            return true;
                    case 1:
                        if(GPIO_PORTE_DATA_R == 0b00000110)
                            return true;
                    case 3:
                        if(GPIO_PORTE_DATA_R == 0b00001100)
                            return true;
                    case 4:
                        if(GPIO_PORTE_DATA_R == 0b00001100)
                            return true;
                    case 5:
                        if(GPIO_PORTE_DATA_R == 0b00010100)
                            return true;
                    case 6:
                        if(GPIO_PORTE_DATA_R == 0b01000100)
                            return true;
                    case 7:
                        if(GPIO_PORTE_DATA_R == 0b10000100)
                            return true;
                }
            case 3:
                GPIO_PORTE_DATA_R = 0b1000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTE_DATA_R == 0b00001001)
                            return true;
                    case 1:
                        if(GPIO_PORTE_DATA_R == 0b00001010)
                            return true;
                    case 2:
                        if(GPIO_PORTE_DATA_R == 0b00001100)
                            return true;
                    case 4:
                        if(GPIO_PORTE_DATA_R == 0b00011000)
                            return true;
                    case 5:
                        if(GPIO_PORTE_DATA_R == 0b00101000)
                            return true;
                    case 6:
                        if(GPIO_PORTE_DATA_R == 0b01001000)
                            return true;
                    case 7:
                        if(GPIO_PORTE_DATA_R == 0b10001000)
                            return true;
                }
            case 4:
                GPIO_PORTE_DATA_R = 0b10000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTE_DATA_R == 0b00010001)
                            return true;
                    case 1:
                        if(GPIO_PORTE_DATA_R == 0b00010010)
                            return true;
                    case 2:
                        if(GPIO_PORTE_DATA_R == 0b00010100)
                            return true;
                    case 3:
                        if(GPIO_PORTE_DATA_R == 0b00011000)
                            return true;
                    case 5:
                        if(GPIO_PORTE_DATA_R == 0b00110000)
                            return true;
                    case 6:
                        if(GPIO_PORTE_DATA_R == 0b01010000)
                            return true;
                    case 7:
                        if(GPIO_PORTE_DATA_R == 0b10010000)
                            return true;
                }
            case 5:
                GPIO_PORTE_DATA_R = 0b100000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTE_DATA_R == 0b00100001)
                            return true;
                    case 1:
                        if(GPIO_PORTE_DATA_R == 0b00100010)
                            return true;
                    case 2:
                        if(GPIO_PORTE_DATA_R == 0b00100100)
                            return true;
                    case 3:
                        if(GPIO_PORTE_DATA_R == 0b00101000)
                            return true;
                    case 4:
                        if(GPIO_PORTE_DATA_R == 0b00110000)
                            return true;
                    case 6:
                        if(GPIO_PORTE_DATA_R == 0b01100000)
                            return true;
                    case 7:
                        if(GPIO_PORTE_DATA_R == 0b10100000)
                            return true;
                }
            case 6:
                GPIO_PORTE_DATA_R = 0b1000000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTE_DATA_R == 0b01000001)
                            return true;
                    case 1:
                        if(GPIO_PORTE_DATA_R == 0b01000010)
                            return true;
                    case 2:
                        if(GPIO_PORTE_DATA_R == 0b01000100)
                            return true;
                    case 3:
                        if(GPIO_PORTE_DATA_R == 0b01001000)
                            return true;
                    case 4:
                        if(GPIO_PORTE_DATA_R == 0b01010000)
                            return true;
                    case 5:
                        if(GPIO_PORTE_DATA_R == 0b01100000)
                            return true;
                    case 7:
                        if(GPIO_PORTE_DATA_R == 0b11000000)
                            return true;
                }
            case 7:
                GPIO_PORTE_DATA_R = 0b10000000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTE_DATA_R == 0b10000001)
                            return true;
                    case 1:
                        if(GPIO_PORTE_DATA_R == 0b10000010)
                            return true;
                    case 2:
                        if(GPIO_PORTE_DATA_R == 0b10000100)
                            return true;
                    case 3:
                        if(GPIO_PORTE_DATA_R == 0b10001000)
                            return true;
                    case 4:
                        if(GPIO_PORTE_DATA_R == 0b10010000)
                            return true;
                    case 5:
                        if(GPIO_PORTE_DATA_R == 0b10100000)
                            return true;
                    case 6:
                        if(GPIO_PORTE_DATA_R == 0b11000000)
                            return true;
                }
        }
        case 'F':
        switch(buttonThreeBit){
            case 0:
                GPIO_PORTF_DATA_R = 0b1;
                buttonCheck();
                switch(LEDThreeBit){
                    case 1:
                        if(GPIO_PORTF_DATA_R == 0b00000011)
                            return true;
                    case 2:
                        if(GPIO_PORTF_DATA_R == 0b00000101)
                            return true;
                    case 3:
                        if(GPIO_PORTF_DATA_R == 0b00001001)
                            return true;
                    case 4:
                        if(GPIO_PORTF_DATA_R == 0b00010001)
                            return true;
                    case 5:
                        if(GPIO_PORTF_DATA_R == 0b00100001)
                            return true;
                    case 6:
                        if(GPIO_PORTF_DATA_R == 0b01000001)
                            return true;
                    case 7:
                        if(GPIO_PORTF_DATA_R == 0b10000001)
                            return true;
                }
            case 1:
                GPIO_PORTF_DATA_R = 0b10;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTF_DATA_R == 0b00000011)
                            return true;
                    case 2:
                        if(GPIO_PORTF_DATA_R == 0b00000110)
                            return true;
                    case 3:
                        if(GPIO_PORTF_DATA_R == 0b00001010)
                            return true;
                    case 4:
                        if(GPIO_PORTF_DATA_R == 0b00010010)
                            return true;
                    case 5:
                        if(GPIO_PORTF_DATA_R == 0b00100010)
                            return true;
                    case 6:
                        if(GPIO_PORTF_DATA_R == 0b01000010)
                            return true;
                    case 7:
                        if(GPIO_PORTF_DATA_R == 0b10000010)
                            return true;
                }
            case 2:
                GPIO_PORTF_DATA_R = 0b100;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTF_DATA_R == 0b00000101)
                            return true;
                    case 1:
                        if(GPIO_PORTF_DATA_R == 0b00000110)
                            return true;
                    case 3:
                        if(GPIO_PORTF_DATA_R == 0b00001100)
                            return true;
                    case 4:
                        if(GPIO_PORTF_DATA_R == 0b00001100)
                            return true;
                    case 5:
                        if(GPIO_PORTF_DATA_R == 0b00010100)
                            return true;
                    case 6:
                        if(GPIO_PORTF_DATA_R == 0b01000100)
                            return true;
                    case 7:
                        if(GPIO_PORTF_DATA_R == 0b10000100)
                            return true;
                }
            case 3:
                GPIO_PORTF_DATA_R = 0b1000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTF_DATA_R == 0b00001001)
                            return true;
                    case 1:
                        if(GPIO_PORTF_DATA_R == 0b00001010)
                            return true;
                    case 2:
                        if(GPIO_PORTF_DATA_R == 0b00001100)
                            return true;
                    case 4:
                        if(GPIO_PORTF_DATA_R == 0b00011000)
                            return true;
                    case 5:
                        if(GPIO_PORTF_DATA_R == 0b00101000)
                            return true;
                    case 6:
                        if(GPIO_PORTF_DATA_R == 0b01001000)
                            return true;
                    case 7:
                        if(GPIO_PORTF_DATA_R == 0b10001000)
                            return true;
                }
            case 4:
                GPIO_PORTF_DATA_R = 0b10000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTF_DATA_R == 0b00010001)
                            return true;
                    case 1:
                        if(GPIO_PORTF_DATA_R == 0b00010010)
                            return true;
                    case 2:
                        if(GPIO_PORTF_DATA_R == 0b00010100)
                            return true;
                    case 3:
                        if(GPIO_PORTF_DATA_R == 0b00011000)
                            return true;
                    case 5:
                        if(GPIO_PORTF_DATA_R == 0b00110000)
                            return true;
                    case 6:
                        if(GPIO_PORTF_DATA_R == 0b01010000)
                            return true;
                    case 7:
                        if(GPIO_PORTF_DATA_R == 0b10010000)
                            return true;
                }
            case 5:
                GPIO_PORTF_DATA_R = 0b100000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTF_DATA_R == 0b00100001)
                            return true;
                    case 1:
                        if(GPIO_PORTF_DATA_R == 0b00100010)
                            return true;
                    case 2:
                        if(GPIO_PORTF_DATA_R == 0b00100100)
                            return true;
                    case 3:
                        if(GPIO_PORTF_DATA_R == 0b00101000)
                            return true;
                    case 4:
                        if(GPIO_PORTF_DATA_R == 0b00110000)
                            return true;
                    case 6:
                        if(GPIO_PORTF_DATA_R == 0b01100000)
                            return true;
                    case 7:
                        if(GPIO_PORTF_DATA_R == 0b10100000)
                            return true;
                }
            case 6:
                GPIO_PORTF_DATA_R = 0b1000000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTF_DATA_R == 0b01000001)
                            return true;
                    case 1:
                        if(GPIO_PORTF_DATA_R == 0b01000010)
                            return true;
                    case 2:
                        if(GPIO_PORTF_DATA_R == 0b01000100)
                            return true;
                    case 3:
                        if(GPIO_PORTF_DATA_R == 0b01001000)
                            return true;
                    case 4:
                        if(GPIO_PORTF_DATA_R == 0b01010000)
                            return true;
                    case 5:
                        if(GPIO_PORTF_DATA_R == 0b01100000)
                            return true;
                    case 7:
                        if(GPIO_PORTF_DATA_R == 0b11000000)
                            return true;
                }
            case 7:
                GPIO_PORTF_DATA_R = 0b10000000;
                buttonCheck();
                switch(LEDThreeBit){
                    case 0:
                        if(GPIO_PORTF_DATA_R == 0b10000001)
                            return true;
                    case 1:
                        if(GPIO_PORTF_DATA_R == 0b10000010)
                            return true;
                    case 2:
                        if(GPIO_PORTF_DATA_R == 0b10000100)
                            return true;
                    case 3:
                        if(GPIO_PORTF_DATA_R == 0b10001000)
                            return true;
                    case 4:
                        if(GPIO_PORTF_DATA_R == 0b10010000)
                            return true;
                    case 5:
                        if(GPIO_PORTF_DATA_R == 0b10100000)
                            return true;
                    case 6:
                        if(GPIO_PORTF_DATA_R == 0b11000000)
                            return true;
                }
        }
    }
}