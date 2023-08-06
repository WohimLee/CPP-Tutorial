#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int a[3][2][2] = {0,1,2,3,4,5,6,7,8,9,10,11};
    // address of block 2, row 0; point to 2 int
    printf("%s: %p\n", "value of a[2][0]", a[2][0]);
    printf("%s: %d\n\n", "value of a[2][0][0]", a[2][0][0]);

    // same address; point to 1 int
    int *ptr = (int*)a[2][0];
    printf("value of ptr: %p\n", ptr); 
    printf("value pointed by ptr: %d\n", *ptr);
    return 0;
}