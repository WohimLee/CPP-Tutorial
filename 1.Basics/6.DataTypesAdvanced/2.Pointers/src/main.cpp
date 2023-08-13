#include <stdio.h>

// int main(int argc, char *argv[])
int main(int argc, char** argv)
{
    // block, row, col
    int a[3][2][2] = {0,1,2,3,4,5,6,7,8,9,10,11};

    // address of block 0; int*[2][2]
    printf("value of a  : %p\n", a);
    printf("value of a+1: %p\n", a+1);

    // address of block 1, row 0; int*[2]
    printf("value of a[1]  : %p\n", a[1]);
    printf("value of a[1]+1: %p\n", a[1]+1);

    // address of block 2, row 1, 1st element; 
    printf("value of a[2][1]  : %p\n", a[2][1]);
    printf("value of a[2][1]+1: %p\n", a[2][1]+1);

    printf("value of a[2][0][1]:%d\n", a[2][0][1]);
    printf("value of *(a[2][0] + 1): %d\n", *(a[2][0]+1));

    return 0;
}