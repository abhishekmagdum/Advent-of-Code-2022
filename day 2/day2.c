#include <stdio.h>
#include <stdlib.h>

// max lines of txt file
#define MAX_ENTRY 3U

int calculateScore(char a, char b){

    //  Enemy (a)
    //  A = Rock
    //  B = Paper
    //  C = Scissors

    //  Me (b)
    //  X = Rock
    //  Y = Paper
    //  Z = Scissors

    //  Paper beats Rock
    //  Rock beats Scissors
    //  Scissors beats Paper

    int score = 0;

    //draw condition
    if ((a == 'A' && b == 'X') || (a == 'B' && b == 'Y') || (a == 'C' && b == 'Z')){
        score += 3;
    }

    //win condition
    if ((a == 'A' && b == 'Y') || (a == 'C' && b == 'X') || (a == 'B' && b == 'Z')){
        score += 6;
    }

    //choice conditions
    if(b == 'X') score += 1;
    if(b == 'Y') score += 2;
    if(b == 'Z') score += 3;

    //no need for losing conditions since no points gained

    return score;
}

int main()
{

    FILE *filePtr;

    char name[20];
    int finalScore = 0;
 
    // opening file in reading mode
    filePtr = fopen("puzzleInput.txt", "r");
 
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

        finalScore += calculateScore(name[0], name[2]);

    }

    // close file
    fclose(filePtr);

    printf("final score: %d \n", finalScore);

    return 0;
}
