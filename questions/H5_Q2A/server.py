import random, copy

def generate(data):

    #Random int 0 means its an output, 1 means its an input
    inputCountLeft = 0
    inputCountRight = 0
    outputCountLeft = 0
    outputCountRight = 0
    inputListLeft = set()
    inputListRight = set()
    outputListLeft = set()
    outputListRight = set()
    portList = ["A", "B", "C", "D", "E", "F"]
    portCheck = False
    IOCheck = False
    
    while 1:
        leftPortSelect = random.randint(0,5)
        rightPortSelect = random.randint(0,5)
        if leftPortSelect < rightPortSelect:
            leftPortLabel = portList[leftPortSelect]
            rightPortLabel = portList[rightPortSelect]
            for x in range(6):
                if rightPortSelect == 5:
                    startPortClock = "1"
                else:
                    startPortClock = "0"
                    
                if leftPortSelect == 4 or rightPortSelect == 4:
                    startPortClock += "1"
                else:
                    startPortClock += "0"
                    
                if leftPortSelect == 3 or rightPortSelect == 3:
                    startPortClock += "1"
                else:
                    startPortClock += "0"
                
                if leftPortSelect == 2 or rightPortSelect == 2:
                    startPortClock += "1"
                else:
                    startPortClock += "0"
                
                if leftPortSelect == 1 or rightPortSelect == 1:
                    startPortClock += "1"
                else:
                    startPortClock += "0"
                    
                if leftPortSelect == 0:
                    startPortClock += "1"
                else:
                    startPortClock += "0"
                
            portCheck = True
        
        leftPortBitSeven_IO = random.randint(0, 1)
        if leftPortBitSeven_IO == 1 :
            inputCountLeft+= 1
            inputListLeft.add(7)
            leftPortDirection = "0"
        else:
            outputCountLeft+= 1
            outputListLeft.add(7)
            leftPortDirection = "1"
            
        leftPortBitSix_IO = random.randint(0, 1)
        if leftPortBitSix_IO == 1 :
            inputCountLeft+= 1
            inputListLeft.add(6)
            leftPortDirection += "0"
        else:
            outputCountLeft+= 1
            outputListLeft.add(6)
            leftPortDirection += "1"
            
        leftPortBitFive_IO = random.randint(0, 1)
        if leftPortBitFive_IO == 1 :
            inputCountLeft+= 1
            inputListLeft.add(5)
            leftPortDirection += "0"
        else:
            outputCountLeft+= 1
            outputListLeft.add(5)
            leftPortDirection += "1"
            
        leftPortBitFour_IO = random.randint(0, 1)
        if leftPortBitFour_IO == 1 :
            inputCountLeft+= 1
            inputListLeft.add(4)
            leftPortDirection += "0"
        else:
            outputCountLeft+= 1
            outputListLeft.add(4)
            leftPortDirection += "1"
            
        leftPortBitThree_IO = random.randint(0, 1)
        if leftPortBitThree_IO == 1 :
            inputCountLeft+= 1
            inputListLeft.add(3)
            leftPortDirection += "0"
        else:
            outputCountLeft+= 1
            outputListLeft.add(3)
            leftPortDirection += "1"
            
        leftPortBitTwo_IO = random.randint(0, 1)
        if leftPortBitTwo_IO == 1 :
            inputCountLeft+= 1
            inputListLeft.add(2)
            leftPortDirection += "0"
        else:
            outputCountLeft+= 1
            outputListLeft.add(2)
            leftPortDirection += "1"
            
        leftPortBitOne_IO = random.randint(0, 1)
        if leftPortBitOne_IO == 1 :
            inputCountLeft+= 1
            inputListLeft.add(1)
            leftPortDirection += "0"
        else:
            outputCountLeft+= 1
            outputListLeft.add(1)
            leftPortDirection += "1"
            
        leftPortBitZero_IO = random.randint(0, 1)
        if leftPortBitZero_IO == 1 :
            inputCountLeft+= 1
            inputListLeft.add(0)
            leftPortDirection += "0"
        else:
            outputCountLeft+= 1
            outputListLeft.add(0)
            leftPortDirection += "1"
    
        rightPortBitSeven_IO = random.randint(0, 1)
        if rightPortBitSeven_IO == 1:
            inputCountRight+= 1
            inputListRight.add(7)
            rightPortDirection = "0"
        else:
            outputCountRight+= 1
            outputListRight.add(7)
            rightPortDirection = "1"
            
        rightPortBitSix_IO = random.randint(0, 1)
        if rightPortBitSix_IO == 1:
            inputCountRight+= 1
            inputListRight.add(6)
            rightPortDirection += "0"
        else:
            outputCountRight+= 1
            outputListRight.add(6)
            rightPortDirection += "1"
            
        rightPortBitFive_IO = random.randint(0, 1)
        if rightPortBitFive_IO == 1:
            inputCountRight+= 1
            inputListRight.add(5)
            rightPortDirection += "0"
        else:
            outputCountRight+= 1
            outputListRight.add(5)
            rightPortDirection += "1"
            
        rightPortBitFour_IO = random.randint(0, 1)
        if rightPortBitFour_IO == 1:
            inputCountRight+= 1
            inputListRight.add(4)
            rightPortDirection += "0"
        else:
            outputCountRight+= 1
            outputListRight.add(4)
            rightPortDirection += "1"
            
        rightPortBitThree_IO = random.randint(0, 1)
        if rightPortBitThree_IO == 1:
            inputCountRight+= 1
            inputListRight.add(3)
            rightPortDirection += "0"
        else:
            outputCountRight+= 1
            outputListRight.add(3)
            rightPortDirection += "1"
            
        rightPortBitTwo_IO = random.randint(0, 1)
        if rightPortBitTwo_IO == 1:
            inputCountRight+= 1
            inputListRight.add(2)
            rightPortDirection += "0"
        else:
            outputCountRight+= 1
            outputListRight.add(2)
            rightPortDirection += "1"
            
        rightPortBitOne_IO = random.randint(0, 1)
        if rightPortBitOne_IO == 1:
            inputCountRight+= 1
            inputListRight.add(1)
            rightPortDirection += "0"
        else:
            outputCountRight+= 1
            outputListRight.add(1)
            rightPortDirection += "1"
            
        rightPortBitZero_IO = random.randint(0, 1)
        if rightPortBitZero_IO == 1:
            inputCountRight+= 1
            inputListRight.add(0)
            rightPortDirection += "0"
        else:
            outputCountRight+= 1
            outputListRight.add(0)
            rightPortDirection += "1"
        
        if inputCountLeft >= 2 and inputCountRight >= 2 and outputCountLeft >= 2 and outputCountRight >= 2:
            inputCountLeft = 0
            inputCountRight = 0
            outputCountLeft = 0
            outputCountRight = 0
            
            #x1="85 - 365"(40 gap)
            
            leftCircleButtonZero_bit = random.choice(list(inputListLeft))
            leftCircleButtonZero_x1 = 365 - 40 * leftCircleButtonZero_bit
            inputListLeft.remove(leftCircleButtonZero_bit)
            leftCircleButtonOne_bit = random.choice(list(inputListLeft))
            leftCircleButtonOne_x1 = 365 - 40 * leftCircleButtonOne_bit
            inputListLeft.remove(leftCircleButtonOne_bit)
            leftCircleLEDZero_bit = random.choice(list(outputListLeft))
            leftCircleLEDZero_x1 = 365 - 40 * leftCircleLEDZero_bit
            outputListLeft.remove(leftCircleLEDZero_bit)
            leftCircleLEDOne_bit = random.choice(list(outputListLeft))
            leftCircleLEDOne_x1 = 365 - 40 * leftCircleLEDOne_bit
            outputListLeft.remove(leftCircleLEDOne_bit)
            
            rightCircleButtonTwo_bit = random.choice(list(inputListRight))
            rightCircleButtonTwo_x1 = 685 - 40 * rightCircleButtonTwo_bit
            inputListRight.remove(rightCircleButtonTwo_bit)
            rightCircleButtonThree_bit = random.choice(list(inputListRight))
            inputListRight.remove(rightCircleButtonThree_bit)
            rightCircleButtonThree_x1 = 685 - 40 * rightCircleButtonThree_bit
            rightCircleLEDTwo_bit = random.choice(list(outputListRight))
            rightCircleLEDTwo_x1 = 685 - 40 * rightCircleLEDTwo_bit
            outputListRight.remove(rightCircleLEDTwo_bit)
            rightCircleLEDThree_bit = random.choice(list(outputListRight))
            rightCircleLEDThree_x1 = 685 - 40 * rightCircleLEDThree_bit
            outputListRight.remove(rightCircleLEDThree_bit)
            
            IOCheck = True
            
            inputListLeft.clear()
            outputListLeft.clear()
            inputListRight.clear()
            outputListRight.clear()
            
        if portCheck == True and IOCheck == True:
            break;
    
    leftPortBitSeven_y1 = 200 + 100*leftPortBitSeven_IO
    leftPortBitSeven_angle = 90 + 180*leftPortBitSeven_IO
    leftPortBitSix_y1 = 200 + 100*leftPortBitSix_IO
    leftPortBitSix_angle = 90 + 180*leftPortBitSix_IO
    leftPortBitFive_y1 = 200 + 100*leftPortBitFive_IO
    leftPortBitFive_angle = 90 + 180*leftPortBitFive_IO
    leftPortBitFour_y1 = 200 + 100*leftPortBitFour_IO
    leftPortBitFour_angle = 90 + 180*leftPortBitFour_IO
    leftPortBitThree_y1 = 200 + 100*leftPortBitThree_IO
    leftPortBitThree_angle = 90 + 180*leftPortBitThree_IO
    leftPortBitTwo_y1 = 200 + 100*leftPortBitTwo_IO
    leftPortBitTwo_angle = 90 + 180*leftPortBitTwo_IO
    leftPortBitOne_y1 = 200 + 100*leftPortBitOne_IO
    leftPortBitOne_angle = 90 + 180*leftPortBitOne_IO
    leftPortBitZero_y1 = 200 + 100*leftPortBitZero_IO
    leftPortBitZero_angle = 90 + 180*leftPortBitZero_IO
    
    rightPortBitSeven_y1 = 200 + 100*rightPortBitSeven_IO
    rightPortBitSeven_angle = 90 + 180*rightPortBitSeven_IO
    rightPortBitSix_y1 = 200 + 100*rightPortBitSix_IO
    rightPortBitSix_angle = 90 + 180*rightPortBitSix_IO
    rightPortBitFive_y1 = 200 + 100*rightPortBitFive_IO
    rightPortBitFive_angle = 90 + 180*rightPortBitFive_IO
    rightPortBitFour_y1 = 200 + 100*rightPortBitFour_IO
    rightPortBitFour_angle = 90 + 180*rightPortBitFour_IO
    rightPortBitThree_y1 = 200 + 100*rightPortBitThree_IO
    rightPortBitThree_angle = 90 + 180*rightPortBitThree_IO
    rightPortBitTwo_y1 = 200 + 100*rightPortBitTwo_IO
    rightPortBitTwo_angle = 90 + 180*rightPortBitTwo_IO
    rightPortBitOne_y1 = 200 + 100*rightPortBitOne_IO
    rightPortBitOne_angle = 90 + 180*rightPortBitOne_IO
    rightPortBitZero_y1 = 200 + 100*rightPortBitZero_IO
    rightPortBitZero_angle = 90 + 180*rightPortBitZero_IO
    
    data['params']['leftPortLabel'] = leftPortLabel
    data['params']['rightPortLabel'] = rightPortLabel
    data['params']['leftPortDirection'] = leftPortDirection
    data['params']['rightPortDirection'] = rightPortDirection
    
    data['params']['leftPortBitSeven_y1'] = leftPortBitSeven_y1
    data['params']['leftPortBitSeven_angle'] = leftPortBitSeven_angle
    data['params']['leftPortBitSix_y1'] = leftPortBitSix_y1
    data['params']['leftPortBitSix_angle'] = leftPortBitSix_angle
    data['params']['leftPortBitFive_y1'] = leftPortBitFive_y1
    data['params']['leftPortBitFive_angle'] = leftPortBitFive_angle
    data['params']['leftPortBitFour_y1'] = leftPortBitFour_y1
    data['params']['leftPortBitFour_angle'] = leftPortBitFour_angle
    data['params']['leftPortBitThree_y1'] = leftPortBitThree_y1
    data['params']['leftPortBitThree_angle'] = leftPortBitThree_angle
    data['params']['leftPortBitTwo_y1'] = leftPortBitTwo_y1
    data['params']['leftPortBitTwo_angle'] = leftPortBitTwo_angle
    data['params']['leftPortBitOne_y1'] = leftPortBitOne_y1
    data['params']['leftPortBitOne_angle'] = leftPortBitOne_angle
    data['params']['leftPortBitZero_y1'] = leftPortBitZero_y1
    data['params']['leftPortBitZero_angle'] = leftPortBitZero_angle
    
    data['params']['rightPortBitSeven_y1'] = rightPortBitSeven_y1
    data['params']['rightPortBitSeven_angle'] = rightPortBitSeven_angle
    data['params']['rightPortBitSix_y1'] = rightPortBitSix_y1
    data['params']['rightPortBitSix_angle'] = rightPortBitSix_angle
    data['params']['rightPortBitFive_y1'] = rightPortBitFive_y1
    data['params']['rightPortBitFive_angle'] = rightPortBitFive_angle
    data['params']['rightPortBitFour_y1'] = rightPortBitFour_y1
    data['params']['rightPortBitFour_angle'] = rightPortBitFour_angle
    data['params']['rightPortBitThree_y1'] = rightPortBitThree_y1
    data['params']['rightPortBitThree_angle'] = rightPortBitThree_angle
    data['params']['rightPortBitTwo_y1'] = rightPortBitTwo_y1
    data['params']['rightPortBitTwo_angle'] = rightPortBitTwo_angle
    data['params']['rightPortBitOne_y1'] = rightPortBitOne_y1
    data['params']['rightPortBitOne_angle'] = rightPortBitOne_angle
    data['params']['rightPortBitZero_y1'] = rightPortBitZero_y1
    data['params']['rightPortBitZero_angle'] = rightPortBitZero_angle
    
    data['params']['leftCircleButtonZero_x1'] = leftCircleButtonZero_x1
    data['params']['leftCircleButtonOne_x1'] = leftCircleButtonOne_x1
    data['params']['leftCircleLEDZero_x1'] = leftCircleLEDZero_x1
    data['params']['leftCircleLEDOne_x1'] = leftCircleLEDOne_x1
    data['params']['rightCircleButtonTwo_x1'] = rightCircleButtonTwo_x1
    data['params']['rightCircleButtonThree_x1'] = rightCircleButtonThree_x1
    data['params']['rightCircleLEDTwo_x1'] = rightCircleLEDTwo_x1
    data['params']['rightCircleLEDThree_x1'] = rightCircleLEDThree_x1
    
    data['correct_answers']['Start'] = "SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R | 0b" + startPortClock + ";"
    data['correct_answers']['enable1'] = "GPIO_PORT" + leftPortLabel + "_DEN_R = 0xFF;"
    data['correct_answers']['enable2'] = "GPIO_PORT" + rightPortLabel + "_DEN_R = 0xFF;"
    data['correct_answers']['set1'] = "GPIO_PORT" + leftPortLabel + "_DIR_R = 0x" + leftPortDirection + ";"
    data['correct_answers']['set2'] = "GPIO_PORT" + rightPortLabel + "_DIR_R = 0x" + rightPortDirection + ";"