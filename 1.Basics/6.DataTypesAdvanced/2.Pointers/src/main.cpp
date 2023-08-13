#include <stdio.h>

// int main(int argc, char *argv[])
int main(int argc, char** argv)
{
    printf("输入的参数共有: %d条\n", argc);
    for (int i = 0; i < argc; i++)
        printf("%s\n", argv[i]);


    int nElem = 10;
    int array[nElem]; // array: int(*)[n]
    for(int i=0; i<nElem; i++)
        array[i]= 30+i;
    int* pArray = array;
    int** ppArray = &pArray;

    int n = 5;
    printf("value of Array[i]     : %d, value of array   : %p\n", array[n], array);
    printf("value of pArray[i]    : %d, value of pArray  : %p\n", pArray[n], pArray);
    printf("value of ppArray[i]   : %d, value of ppArray : %p\n", ppArray[n], ppArray);
    // *ppArray = pArray
    printf("value of (*ppArray)[n]: %d, value of *ppArray: %p\n", (*ppArray)[n], (*ppArray));

    return 0;
}