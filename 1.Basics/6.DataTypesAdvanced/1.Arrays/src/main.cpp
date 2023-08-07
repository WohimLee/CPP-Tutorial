
#include <stdio.h>

int main()
{
    int a[3][2][2] = {0,1,2,3,4,5,6,7,8,9,10,11};
    // 相当于索引 11 = 2*(2*2) + 1*1 + 1
    printf("value of a[2][1][1]: %d\n", a[2][1][1]);

    // printf("value of a[11]: %d\n", a[11]); // 有问题, 不是想要的数字, 指针讲解
    int* ptr = (int*)a;
    printf("value of ptr[11]   : %d\n", ptr[11]);

    return 0;
}