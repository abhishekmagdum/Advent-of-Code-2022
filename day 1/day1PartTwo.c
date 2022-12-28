#include <stdio.h>
#include <stdlib.h>

// max lines of txt file
#define MAX_ENTRY 2267U

int main()
{

    FILE *filePtr;

    char name[20];

    int num = 0;
    int sum = 0;
    int max = 0;

    int first = 0;
    int second = 0;
    int third = 0;

    int sumTop3 = 0;
 
    // opening file in reading mode
    filePtr = fopen("calories.txt", "r");
 
    // error handling
    if (NULL == filePtr) {
        printf("file can't be opened \n");
    }

    // check for max calories
    for(int i = 0; i<MAX_ENTRY; i++){
        fgets(name, 20, filePtr);
        num = atoi(name);
        //printf("%d \n", num);

        if (num != 0){
            sum += num;
        }

        if (sum > max){
            max = sum;
        }

        // compute top 3 calories
        if(sum > first){
            first = sum;
        }

        if (sum > second && sum < first){
            second = sum;
        }
        
        if (sum > third && sum < second && sum < first){
            third = sum;
        }

        //set sum back to 0
        if (num == 0){
            sum = 0;
        }

    }

    printf("max: %d \n", max);

    printf("first: %d \n", first);
    printf("second: %d \n", second);
    printf("third: %d \n", third);

    printf("sumTop3: %d \n", first + second + third);

    // close file
    fclose(filePtr);

    return 0;
}
