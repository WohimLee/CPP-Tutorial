#include <stdlib.h>
#include <stdio.h>

#define OVERFLOW  -2
#define UNDERFLOW -3
#define ERROR 0

typedef int cudaError_t;

cudaError_t normMalloc(void* pDev, size_t size)
{
    // 内部做了:void* pDev = ptr
    pDev = (int*)malloc(size); // 并没有改变外面的 ptr
    if (!pDev)
        exit(OVERFLOW);
    return 0;
}

cudaError_t cudaMalloc(void** ppDev, size_t size)
{
    // 内部做了: void** ppDev = (void**)&ptr
    
    *ppDev = malloc(10); // *ppDev = ptr 改变了外面的 ptr
    if (!(*ppDev))
        exit(OVERFLOW);
    return 0;
}

int main()
{
    int* ptr = NULL;

    normMalloc(ptr, sizeof(int));
    if(ptr) printf("normalMalloc succeed!\n");
    else printf("normalMalloc faled!\n");

    // cudaMalloc((void**)&ptr, sizeof(int));
    // if(ptr) printf("cudaMalloc succeed!\n");
    // else printf("cudaMalloc faled!\n");

    return 0;
}