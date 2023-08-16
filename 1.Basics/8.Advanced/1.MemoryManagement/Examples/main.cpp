#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printArray(int n, int* ptr){
    for(int i=0; i<n; i++)
        printf("%d ", ptr[i]);
    printf("\n");
}

int main()
{
    int pSrc[] = {1, 2, 3, 4, 5};

    int* pDst1 = (int*)malloc(5*sizeof(int));
    memcpy(pDst1, pSrc, 3*sizeof(int));
    printArray(3, pDst1);

    int* pDst2 = (int*)memcpy(pDst1, pSrc, 3*sizeof(int));
    printArray(3, pDst2);
    printf("value of pDst1: %p\n", pDst1);
    printf("value of pDst2: %p\n", pDst2);

    free(pDst1);
    pDst1 = NULL;
    return 0;
}