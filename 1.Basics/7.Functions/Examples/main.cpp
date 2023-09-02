#include <stdlib.h>
#include <stdio.h>

#define OVERFLOW  -2
#define UNDERFLOW -3
#define ERROR 0

typedef int cudaError_t;

int* Malloc1(void* pDev, size_t size)
{

    pDev = (int*)malloc(size); // 并没有改变外面的 ptr
    if (!pDev)
        exit(OVERFLOW);
    return (int*)pDev;
}

int* Malloc2(void* pDev, size_t size)
{

    pDev = (int*)malloc(size); // 并没有改变外面的 ptr
    if (!pDev)
        exit(OVERFLOW);
    return (int*)pDev;
}


int main()
{
    int* ptr = NULL;

    ptr = normMalloc(ptr, sizeof(int));
    if(ptr) printf("normalMalloc succeed!\n");
    else printf("normalMalloc faled!\n");

    printf("ptr=%p\n", ptr);

    return 0;
}