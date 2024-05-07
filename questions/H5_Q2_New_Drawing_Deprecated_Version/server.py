import random, copy

#Written by: Ryan Bumann

#function to generate the initPorts.c file describing what the students should do based on the generated ports
def generateInitCFile(firstPort, secondPort):
    with open ("tests/initPorts.c", "w") as f:
        f.write("#include \"registers.h\"\n\n")
        f.write("void init_ports(void) {\n")
        
        f.write("    // Start Port %s and Port %s clock\n\n" % (firstPort, secondPort))
        
        
        f.write("    // Enable Digital functionality of Port %s and Port %s\n\n" % (firstPort, secondPort))
        
        
        f.write("    // Set direction of Port %s's pins, based on the figure\n\n" % (firstPort))
        
        
        f.write("    // Set direction of Port %s's pins, based on the figure\n" % (secondPort))
        
        f.write("}\n")

#function to generate the main.c file that will run the tests on the students code, and parameters are the answers
def generateTestCFile(start, enable1, enable2, set1, set2, dir1, dir2):
    with open("tests/main.c", "w") as f:
        f.write("#include <check.h>\n")
        f.write("#include \"registers.h\"\n\n")
    
        f.write("void init_ports(void);\n\n")
        
        f.write("START_TEST(test_init_ports)\n")
        f.write("{\n")
        f.write("    init_ports();\n")
        f.write("    ck_assert_int_eq(SYSCTL_RCGCGPIO_R, %s);\n" % (start))
        f.write("    ck_assert_int_eq(%s, 0xFF);\n" % (enable1))
        f.write("    ck_assert_int_eq(%s, 0xFF);\n" % (enable2))
        f.write("    ck_assert_int_eq(%s, %s);\n" % (set1, dir1))
        f.write("    ck_assert_int_eq(%s, %s);\n" % (set2, dir2))
        f.write("}\n")
        f.write("END_TEST\n\n")
        
        # Write the main function
        f.write("int main(void)\n")
        f.write("{\n")
        f.write("    Suite *s = suite_create(\"init_ports\");\n\n")
        
        f.write("    TCase *tc_init_ports = tcase_create(\"init_ports\");\n")
        f.write("    tcase_add_test(tc_init_ports, test_init_ports);\n")
        f.write("    suite_add_tcase(s, tc_init_ports);\n\n")
        
        f.write("    SRunner *sr = srunner_create(s);\n\n")
        
        f.write("    srunner_run_all(sr, CK_NORMAL);\n")
        f.write("    srunner_free(sr);\n\n")
        
        f.write("    return 0;\n")
        f.write("}\n")



def generate(data):

    #randomly generate the two ports
    letters = ["A","B","C","D","E","F"]
    oneNum = random.randint(0, 5)
    #oneNum = random.randint(0, 4)
    #twoNum = oneNum+1
    twoNum = random.randint(0, 5)
    while twoNum == oneNum:
        twoNum = random.randint(0, 5)
    
    one = letters[oneNum]
    two = letters[twoNum]
    #pictures = ["diagram1.png", "diagram2.png", "diagram3.png", "diagram4.png", "diagram5.png"]

    # Put the two ports into data['params']
    data['params']['one'] = one
    data['params']['two'] = two
    #data['params']['picture'] = pictures[oneNum]

    # Generate the initPorts.c file
    generateInitCFile(one, two)



    # sets the correct answer for the clock based on the ports generated
    array = [0,0,0,0,0,0]
    array[len(array)-1 - oneNum] = 1
    array[len(array)-1 - twoNum] = 1
    str1 = ""
    for x in array:
        str1 += str(x)

    # sets the correct clock answer and the ports being used
    start = "0b" + str1
    enable1 = "GPIO_PORT" + one + "_DEN_R"
    enable2 = "GPIO_PORT" + two + "_DEN_R"
    set1 = "GPIO_PORT" + one + "_DIR_R"
    set2 = "GPIO_PORT" + two +"_DIR_R"

    

    randNumArr = []
    # Generate 16 random numbers between 0 and 1
    for i in range(16):
        randNumArr.append(random.randint(0, 1))
    
    # Make sure there are at least 2 0's in the first 8 numbers
    count = 0
    for i in range(8):
        if randNumArr[i] == 0:
            count+=1

    while count < 2:
        #randomly replace 1's with 0's until there are 2 0's
        rand = random.randint(0, 7)
        if randNumArr[rand] == 1:
            randNumArr[rand] = 0
            count+=1

    count = 0
    for i in range(8, 16):
        if randNumArr[i] == 0:
            count+=1

    while count < 2:
        #random 8 through 15
        rand = random.randint(8, 15)
        if randNumArr[rand] == 1:
            randNumArr[rand] = 0
            count+=1
    
    # Open the microcontroller.js file and replace the first 3 lines with the variables needed to generate the microcontroller diagram
    with open("microcontroller.js", "r") as f:
        lines = f.readlines()
        lines[0] = "var onePort = \"" + one + "\";\n"
        lines[1] = "var twoPort = \"" + two + "\";\n"
        lines[2] = "var randNumArr = " + str(randNumArr) + ";\n"
        
    with open("microcontroller.js", "w") as f:
        f.writelines(lines)

    # set the direction answers
    dir1 = "0b" + str(randNumArr[0]) + str(randNumArr[1]) + str(randNumArr[2]) + str(randNumArr[3]) + str(randNumArr[4]) + str(randNumArr[5]) + str(randNumArr[6]) + str(randNumArr[7])
    dir2 = "0b" + str(randNumArr[8]) + str(randNumArr[9]) + str(randNumArr[10]) + str(randNumArr[11]) + str(randNumArr[12]) + str(randNumArr[13]) + str(randNumArr[14]) + str(randNumArr[15])

    # Pass all the correct answers to the generateTestCFile function and generate the test file
    generateTestCFile(start, enable1, enable2, set1, set2, dir1, dir2)
