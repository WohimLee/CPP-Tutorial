
#include <stdio.h>

void printArray(int num, int** array){
    int *ptr = (int*)array;
    for(int i=0; i<num; i++)
        printf("%d ", ptr[i]);
    printf("\n");
}


int main(int argc, char** argv){

    

    return 0;
}