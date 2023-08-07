#include <stdio.h>

#include <stdio.h>

int main()
{
    int a[3][2][2] = {0,1,2,3,4,5,6,7,8,9,10,11};

    // address of block 0; int*[2][2] const
    printf("value of a  : %p\n", a);
    printf("value of a+1: %p\n", a+1);
    // interval = 4*4Bytes = 16Bytes
    printf("interval = %d\n\n", 4*4);

    // address of block 1, row 0; int*[2] const
    printf("value of a[1]  : %p\n", a[1]);
    printf("value of a[1]+1: %p\n", a[1]+1);
    // interval = 2*4Bytes = 8Bytes
    printf("interval = %d\n\n", 2*4);


    // address of block 2, row 1, col 0; int* const
    printf("value of a[2][1]  : %p\n", a[2][1]);
    printf("value of a[2][1]+1: %p\n", a[2][1]+1);
    // interval = 1*4Bytes = 4Bytes
    printf("interval = %d\n\n", 1*4);


    // Syntatic Sugar 语法糖
    printf("value of a[2][0][0]  : %d\n", a[2][0][1]);
    printf("Syntatic Sugar: equivalent to:\n");
    printf("value of *(a[2][0]+1): %d\n", *(a[2][0]+1));

    return 0;
}
