//This is a template that can be used at the start of each day.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// max lines of txt file
#define MAX_ENTRY 1000U

int main()
{

    FILE *filePtr;

    char name[20];
    
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;

    char c1;
    char c2;
    char c3;

    int sumPart1 = 0;
    int sumPart2 = 0;

 
    // opening file in reading mode
    filePtr = fopen("input.txt", "r");
 
    // error handling
    if (NULL == filePtr) {
        printf("file can't be opened \n");
    }

    // check for max calories
    for(int i = 0; i<MAX_ENTRY; i++){
        fgets(name, 20, filePtr);
        //printf("%d \n", aoti(name));

        sscanf(name, "%d %c %d %c %d %c %d", &num1, &c1, &num2, &c2, &num3, &c3, &num4);

        printf("%d %d %d %d \n", num1, num2, num3, num4);

        if((num1 >= num3 && num2 <= num4) || (num3 >= num1 && num4 <= num2)) sumPart1 += 1;

        if((num2 >= num3) && (num1 <= num4)) sumPart2 += 1;

        puts(name);
        //printf("%c %c \n", name[0], name[2]);
    }

    // close file
    fclose(filePtr);

    printf("Sum Part1 is: %d, and Sum Part2 is: %d \n", sumPart1, sumPart2);

    return 0;
}
