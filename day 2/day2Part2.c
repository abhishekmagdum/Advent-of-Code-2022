#include <stdio.h>
#include <stdlib.h>

// max lines of txt file
#define MAX_ENTRY 2500U

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

    //  For Part 2:
    //  X = Lose
    //  Y = Draw
    //  Z = Win

    char c;

    //part 2 win remap
    if (a == 'A' && b == 'Z') c = 'Y';
    if (a == 'B' && b == 'Z') c = 'Z';
    if (a == 'C' && b == 'Z') c = 'X';

    //part 2 draw remap
    if (a == 'A' && b == 'Y') c = 'X';
    if (a == 'B' && b == 'Y') c = 'Y';
    if (a == 'C' && b == 'Y') c = 'Z';

    //part 2 lose remap
    if (a == 'A' && b == 'X') c = 'Z';
    if (a == 'B' && b == 'X') c = 'X';
    if (a == 'C' && b == 'X') c = 'Y';

    //win condition
    if ((a == 'A' && c == 'Y') || (a == 'C' && c == 'X') || (a == 'B' && c == 'Z')) score += 6;

    //draw condition
    if ((a == 'A' && c == 'X') || (a == 'B' && c == 'Y') || (a == 'C' && c == 'Z')) score += 3;

    //choice conditions
    if(c == 'X') score += 1;
    if(c == 'Y') score += 2;
    if(c == 'Z') score += 3;

    return score;
}

//3+1, 6+3, 3+3

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
        printf("%c %c \n", name[0], name[2]);

        finalScore += calculateScore(name[0], name[2]);
    }

    // close file
    fclose(filePtr);

    printf("final score: %d \n", finalScore);

    return 0;
}
