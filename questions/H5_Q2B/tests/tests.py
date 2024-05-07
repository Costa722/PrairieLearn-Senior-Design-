#! /usr/bin/python3

import cgrader

class QuestionGrader(cgrader.CGrader):
    def tests(self):
        leftPortLabel = self.data['params']['leftPortLabel'];
        rightPortLabel = self.data['params']['rightPortLabel'];
        leftCircleButtonZero_bit = self.data['params']['leftCircleButtonZero_bit'];
        leftCircleButtonOne_bit = self.data['params']['leftCircleButtonOne_bit'];
        rightCircleButtonTwo_bit = self.data['params']['rightCircleButtonTwo_bit'];
        rightCircleButtonThree_bit = self.data['params']['rightCircleButtonThree_bit'];
        leftCircleLEDZero_bit = self.data['params']['leftCircleLEDZero_bit'];
        leftCircleLEDOne_bit = self.data['params']['leftCircleLEDOne_bit'];
        rightCircleLEDTwo_bit = self.data['params']['rightCircleLEDTwo_bit'];
        rightCircleLEDThree_bit = self.data['params']['rightCircleLEDThree_bit'];
        
        #Compiling student code test
        self.test_compile_file("student.c", "student", add_c_file=["/grade/tests/main.c", "/grade/tests/globals.c"], name="Compiling Student File", add_warning_result_msg=False)
        self.test_run("./student", input= "" + leftPortLabel + " " + rightPortLabel + " " + str(leftCircleButtonZero_bit) + " " + str(leftCircleButtonOne_bit) + " " + str(rightCircleButtonTwo_bit) + " " + str(rightCircleButtonThree_bit) + " " + str(leftCircleLEDZero_bit) + " " + str(leftCircleLEDOne_bit) + " " + str(rightCircleLEDTwo_bit) + " " + str(rightCircleLEDThree_bit) + "", exp_output="Success!")
        #self.compile_file("/grade/tests/studentInputC++.cpp", "studentInputC++", add_c_file=["/grade/tests/CPRE288-GPIO.cpp"])
        #self.run_command("./studentInputC++")
        
        #Running answer code
        #self.compile_file("/grade/tests/CPRE288-H5_Q2.cpp", "CPRE288-H5_Q2", add_c_file=["/grade/tests/CPRE288-GPIO.cpp"])
        #self.run_command("./CPRE288-H5_Q2", input="" + leftPortDirection + " " + rightPortDirection + " " + leftPortLabel +  " " + rightPortLabel + " /grade/tests/generatedAnswers.txt")
        
g = QuestionGrader()
g.start()