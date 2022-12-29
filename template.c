//This is a template that can be used at the start of each day.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// max lines of txt file
#define MAX_ENTRY 300U

int main()
{

    FILE *filePtr;

    char name[20];
 
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
        
        //puts(name);
        printf("%c %c \n", name[0], name[2]);

    }

    // close file
    fclose(filePtr);

    return 0;
}
