#! /usr/bin/python3

import cgrader

class QuestionGrader(cgrader.CGrader):
    def tests(self):
        leftPortLabel = self.data['params']['leftPortLabel'];
        rightPortLabel = self.data['params']['rightPortLabel'];
        leftPortDirection = self.data['params']['leftPortDirection'];
        rightPortDirection = self.data['params']['rightPortDirection'];
        
        #Allows users to write to file
        self.change_mode("/grade/tests/studentAnswers.txt", "777")
        self.change_mode("/grade/tests/generatedAnswers.txt", "777")
        
        #Compiling student code test
        self.test_compile_file("student.c", "student", add_c_file=["/grade/tests/main.c"], name="Compiling Student File")
        self.run_command("./student")
        self.compile_file("/grade/tests/CPRE288-H5_Q2A_Student.cpp", "CPRE288_H5_Q2A_Student", add_c_file=["/grade/tests/CPRE288-GPIO.cpp"])
        self.run_command("./CPRE288_H5_Q2A_Student")
        
        #Running answer code
        self.compile_file("/grade/tests/CPRE288-H5_Q2A_Generated.cpp", "CPRE288-H5_Q2A_Generated", add_c_file=["/grade/tests/CPRE288-GPIO.cpp"])
        self.run_command("./CPRE288-H5_Q2A_Generated", input="" + leftPortDirection + " " + rightPortDirection + " " + leftPortLabel +  " " + rightPortLabel + " /grade/tests/generatedAnswers.txt")
        
        #Compares Student answer with Generated Answer
        self.compile_file("/grade/tests/compareFiles.c", "compareFiles")
        self.test_run("./compareFiles", exp_output="Success!", name="Comparing Answers to Student Input")
        
g = QuestionGrader()
g.start()