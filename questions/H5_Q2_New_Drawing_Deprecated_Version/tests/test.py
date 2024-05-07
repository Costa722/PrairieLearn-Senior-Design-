#! /usr/bin/python3

import cgrader

class QuestionGrader(cgrader.CGrader):
    def tests(self):
        # Compile the student's code from the file editor in the html file. Add the main.c file to the compilation. Add the check library to the compilation. Run the check suite.
        self.compile_file("studentCode.c", "studentCode", add_c_file="/grade/tests/main.c", flags=["-I/grade/tests", "-I/grade/student"], pkg_config_flags="check")
        self.run_check_suite("./studentCode")

        
g = QuestionGrader()
g.start()