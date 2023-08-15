#include <stdio.h>
#include <stdlib.h>

int main()
{
    // char* ptr;
    // ptr = (char*)malloc(10);
    char* ptr = (char*)malloc(10);
    if(ptr == NULL) printf("malloc failed.\n");

    return 0;
}