#include <stdio.h>

void printArray(int num, int *array[]){

    int *ptr = (int*)array;
    for(int i=0; i<num; i++)
        printf("%d ", ptr[i]);
    printf("\n");
}

void printArray(int num, int **array){
    int *ptr = (int*)array;
    for(int i=0; i<num; i++)
        printf("%d ", ptr[i]);
    printf("\n");
}

// int main(int argc, char *argv[])
int main(int argc, char** argv){

    printf("输入的参数共有: %d条\n", argc);
    for (int i = 0; i < argc; i++)
        printf("%s ", argv[i]);
    printf("\n");


    int array[10];
    for(int i=0; i<10; i++)
        array[i] = 10+i;

    printArray(10, (int**)&array);

}