import random


def generate(data):
    port = random.randint(0, 5)
    ports = ['A', 'B', 'C', 'D', 'E', 'F']

    # if(ports[port] == "A"):
    #     w0 = ["U0Rx", "CAN1Rx"]
    #     w1 = ["U0Tx", "CAN1Tx"]
    #     w2 = ["SSI0Clk"]
    #     w3 = ["SSI0Fss"]
    #     w4 = ["SSI0Rx"]
    #     w5 = ["SSI0Tx"]
    #     w6 = ["I2C1SCL", "M1PWM2"]
    #     w7 = ["I2C1SDA", "M1PWM3"]
    # elif(ports[port] == "B"):
    #     w0 = ["U1Rx", "T2CCP0"]
    #     w1 = ["U1Tx", "T2CCP1"]
    #     w2 = ["I2C0SCL", "T3CCP0"]
    #     w3 = ["I2C0SDA", "T3CCP1"]
    #     w4 = ["SSI2Clk", "M0PWM2", "T1CPP0", "CAN0Rx"]
    #     w5 = ["SSI2Fss", "M0PWM3", "T1CCP1", "CAN0Tx"]
    #     w6 = ["SSI2Rx", "M0PWM0", "T0CCP0"]
    #     w7 = ["SSI2Tx", "M0PWM1", "T0CCP1"]
    # elif(ports[port] == "C"):
    #     w0 = ["TCKSWCLK", "T4CCP0"]
    #     w1 = ["TMSSWDIO", "T4CCP1"]
    #     w2 = ["TDI", "T5CCP0"]
    #     w3 = ["TDOSWO", "T5CCP1"]
    #     w4 = ["U4Rx", "U1Rx", "M0PWM6", "IDX1", "WT0CCP0", "U1RTS"]
    #     w5 = ["U4Tx", "U1Tx", "M0PWM7", "PhA1", "WT0CCP1", "U1CTS"]
    #     w6 = ["U3Rx", "PhB1", "WT1CCP0", "USB0EPEN"]
    #     w7 = ["U3Tx", "WT1CCP1", "USB0PFLT"]
    # elif(ports[port] == "D"):
    #     w0 = ["SSI3Clk", "SSI1Clk", "I2C3SCL", "M0PWM6", "M1PWM0", "WT2CCPO"]
    #     w1 = ["SSI3Fss", "SSI1Fss", "I2C3SDA", "M0PWM7", "M1PWM1", "WT2CCP1"]
    #     w2 = ["SSI3Rx", "SSI1Rx", "M0FAULT0", "WT3CCP0", "USB0EPEN"]
    #     w3 = ["SSI3Tx", "SSI1Tx", "IDX0", "WT3CCP1", "USB0PFLT"]
    #     w4 = ["U6Rx", "WT4CCP0"]
    #     w5 = ["U6Tx", "WT4CCP1"]
    #     w6 = ["U2Rx", "M0FAULT0", "PhA0", "WT5CCP0"]
    #     w7 = ["U2Tx", "PhB0", "WT5CCP1", "NMI"]
    # elif(ports[port] == "E"):
    #     w0 = ["U7Rx"]
    #     w1 = ["U7Tx"]
    #     w2 = [""]
    #     w3 = [""]
    #     w4 = ["U5Rx", "I2C2SCL", "M0PWM4", "M1PWM2", "CAN0Rx"]
    #     w5 = ["U5Tx", "I2C2SDA", "M0PWM5", "M1PWM3", "CAN0TX"]
    #     w6 = [""]
    #     w7 = [""]
    # elif(ports[port] == "F"):
    #     w0 = ["U1RTS", "SSI1Rx", "CAN0Rx", "M1PWM4", "PhA0", "T0CCPO", "NMI", "C0o"]
    #     w1 = ["U1CTS", "SSITx", "M1PWM5", "PhB0", "T0CCP1", "C1o", "TRD1"]
    #     w2 = ["SSI1Clk", "M0FAULT0", "M1PWM6", "T1CCP0", "TRDO"]
    #     w3 = ["SSI1Fss", "CAN0Tx", "M1PWM7", "T1CCP1", "TRCLK"]
    #     w4 = ["M1FAULT0", "IDX0", "T2CCP0", "USB0EPEN"]
    #     w5 = [""]
    #     w6 = [""]
    #     w7 = [""]
        



    # Put these two integers into data['params']
    data["params"]["port"] = ports[port]
    data["params"]["a"] = ports[port]
    data["params"]["ioW0"] = "black"
    data["params"]["ioW1"] = "black"
    data["params"]["ioW2"] = "black"
    data["params"]["ioW3"] = "black"
    data["params"]["ioW4"] = "black"
    data["params"]["ioW5"] = "black"
    data["params"]["ioW6"] = "black"
    data["params"]["ioW7"] = "black"
    data["params"]["ioW8"] = "black"
    data["params"]["ioW9"] = "black"
    data["params"]["ioW10"] = "black"
    data["params"]["ioW11"] = "black"
    data["params"]["ioW12"] = "black"
    data["params"]["ioW13"] = "black"
    data["params"]["ioW14"] = "black"
    data["params"]["ioW15"] = "black"

    # Compute the sum of these two integers

    # Put the sum into data['correct_answers']
    # data["correct_answers"]["c"] = c
