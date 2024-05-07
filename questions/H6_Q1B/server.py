import random, math

nvic_table = {
    0: "GPIO Port A",
    1: "GPIO Port B",
    2: "GPIO Port C",
    3: "GPIO Port D",
    4: "GPIO Port E",
    5: "UART0",
    6: "UART1",
    7: "SSI0",
    8: "I2C0",
    9: "PWM0 Fault",
    10: "PWM0 Generator 0",
    11: "PWM0 Generator 1",
    12: "PWM0 Generator 2",
    13: "QEI0",
    14: "ADC0 Sequence 0",
    15: "ADC0 Sequence 1",
    16: "ADC0 Sequence 2",
    17: "ADC0 Sequence 3",
    18: "Watchdog Timers 0 and 1",
    19: "16/32-Bit Timer 0A",
    20: "16/32-Bit Timer 0B",
    21: "16/32-Bit Timer 1A",
    22: "16/32-Bit Timer 1B",
    23: "16/32-Bit Timer 2A",
    24: "16/32-Bit Timer 2B",
    25: "Analog Comparator 0",
    26: "Analog Comparator 1",
    28: "System Control",
    29: "Flash Memory Control and EEPROM Control",
    30: "GPIO Port F",
    33: "UART2",
    34: "SSI1",
    35: "16/32-Bit Timer 3A",
    36: "16/32-Bit Timer 3B",
    37: "I2C1",
    38: "QEI1",
    39: "CAN0",
    40: "CAN1",
    43: "Hibernation Module",
    44: "USB",
    45: "PWM Generator 3",
    46: "uDMA Software",
    47: "uDMA Error",
    48: "ADC1 Sequence 0",
    49: "ADC1 Sequence 1",
    50: "ADC1 Sequence 2",
    51: "ADC1 Sequence 3",
    57: "SSI2",
    58: "SSI3",
    59: "UART3",
    60: "UART4",
    61: "UART5",
    62: "UART6",
    63: "UART7",
    68: "I2C2",
    69: "I2C3",
    70: "16/32-Bit Timer 4A",
    71: "16/32-Bit Timer 4B",
    92: "16/32-Bit Timer 5A",
    93: "16/32-Bit Timer 5B",
    94: "32/64-Bit Timer 0A",
    95: "32/64-Bit Timer 0B",
    96: "32/64-Bit Timer 1A",
    97: "32/64-Bit Timer 1B",
    98: "32/64-Bit Timer 2A",
    99: "32/64-Bit Timer 2B",
    100: "32/64-Bit Timer 3A",
    101: "32/64-Bit Timer 3B",
    102: "32/64-Bit Timer 4A",
    103: "32/64-Bit Timer 4B",
    104: "32/64-Bit Timer 5A",
    105: "32/64-Bit Timer 5B",
    134: "PWM1 Generator 0",
    135: "PWM1 Generator 1",
    136: "PWM1 Generator 2",
    137: "PWM1 Generator 3",
    138: "PWM1 Fault"
}

def generate(data):
    interrupt_number = random.choice(list(nvic_table.keys()))
    data['params']['interrupt'] = nvic_table[interrupt_number]
    data['correct_answers']['ans_x'] = interrupt_number // 32
    data['correct_answers']['ans_mask'] = 1 << (interrupt_number % 32)