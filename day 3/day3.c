#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// max lines of txt file
#define MAX_ENTRY 300U

typedef struct ASCIILookup {
    char letter;
    int num;
} ASCIILookup;

ASCIILookup Table[52] = {
    {'a', 1},
    {'b', 2},
    {'c', 3},
    {'d', 4},
    {'e', 5},
    {'f', 6},
    {'g', 7},
    {'h', 8},
    {'i', 9},
    {'j', 10},
    {'k', 11},
    {'l', 12},
    {'m', 13},
    {'n', 14},
    {'o', 15},
    {'p', 16},
    {'q', 17},
    {'r', 18},
    {'s', 19},
    {'t', 20},
    {'u', 21},
    {'v', 22},
    {'w', 23},
    {'x', 24},
    {'y', 25},
    {'z', 26},
    {'A', 27},
    {'B', 28},
    {'C', 29},
    {'D', 30},
    {'E', 31},
    {'F', 32},
    {'G', 33},
    {'H', 34},
    {'I', 35},
    {'J', 36},
    {'K', 37},
    {'L', 38},
    {'M', 39},
    {'N', 40},
    {'O', 41},
    {'P', 42},
    {'Q', 43},
    {'R', 44},
    {'S', 45},
    {'T', 46},
    {'U', 47},
    {'V', 48},
    {'W', 49},
    {'X', 50},
    {'Y', 51},
    {'Z', 52}
};

int priority(char a){

    int num = 0;

    for(int i = 0; i < 52; i++){
        if(a == Table[i].letter) num = Table[i].num; 
    }

    return num;
}

int main()
{

    FILE *filePtr;

    char name[100];
    
    int sum = 0;
    char duplicate;
 
    // opening file in reading mode
    filePtr = fopen("input.txt", "r");
 
    // error handling
    if (NULL == filePtr) {
        printf("file can't be opened \n");
    }


    for(int i = 0; i<MAX_ENTRY; i++){
        fgets(name, 100, filePtr);
        puts(name);
        printf("%ld \n", strlen(name)-1);
        //printf("%d \n", (int)name[0]);

        // for(int j = 0; j < (strlen(name)-1)/2; j++){ //this gives left side
        //     printf("%c \n", name[j]);
        // }

        // for(int k = (strlen(name)-1)/2; k <  strlen(name)-1; k++){ //this gives left side
        //     printf("%c \n", name[k]);
        // }

        //  PcPlnShmrLmBnmcwBhrmcm bHNGFGpwdFFwGNjNbGqNHH

        for(int j = 0; j < (strlen(name)-1)/2; j++){
            for(int k = (strlen(name)-1)/2; k <  strlen(name)-1; k++){
                if(name[j] == name[k]) {
                    printf("%c %c \n", name[j], name[k]);
                    sum += priority(name[j]);
                    j = k = 10000; //breaks out of both loops
                    break;
                }
            }
        }

    }
    // close file
    fclose(filePtr);

    printf("Sum of Priority: %d \n", sum);


    return 0;
}
