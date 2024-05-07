#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareFiles(FILE* studentFile, FILE* generatedFile){
    char buffer1[1024];
    char buffer2[1024];
    size_t bytesRead1, bytesRead2;
    do {
        bytesRead1 = fread(buffer1, 1, sizeof(buffer1), studentFile);
        bytesRead2 = fread(buffer2, 1, sizeof(buffer2), generatedFile);

        if (bytesRead1 != bytesRead2 || memcmp(buffer1, buffer2, bytesRead1) != 0) {
            printf("Your Input:\n%.*s\n", (int)bytesRead1, buffer1);
            printf("Answer:\n%.*s\n", (int)bytesRead2, buffer2);
            return 1; // Files are different
        }
    } while (bytesRead1 != 0 && bytesRead2 != 0);

    // If both files reach the end at the same time, they are identical
    if (bytesRead1 == 0 && bytesRead2 == 0) {
        return 0;
    } else {
        return 1; // Files have different sizes
    }
}

int main(){
    FILE* studentFile = fopen("/grade/tests/studentAnswers.txt", "r");
    FILE* generatedFile = fopen("/grade/tests/generatedAnswers.txt", "r");
    
    if (studentFile == NULL || generatedFile == NULL) {
        perror("Error opening files");
        return EXIT_FAILURE;
    }
    
    int result = compareFiles(studentFile, generatedFile);
    
    if (result == 0) {
        printf("Success!\n");
    } else {
        printf("Incorrect.\n");
    }

    fclose(studentFile);
    fclose(generatedFile);

    return 1;
}