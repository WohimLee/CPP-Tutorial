
#include <stdio.h>

int main()
{

    int a  = 10;
    int b  = a;
    int &c = a;

    printf("value of a: %d\n", a);
    printf("value of b: %d\n", b);
    printf("value of c: %d\n", c);

    // int numbers[5];
    // int* p;
    // p = numbers;
    // *p = 10;
    // p++;
    // *p = 20;
    // p = &numbers[2];
    // *p = 30;
    // p = numbers+3;
    // *p = 40;
    // p = numbers;
    // *(p+4) = 50;

    // for (int i=0; i<5; i++)
    //     printf("%d element: %d\n", i, numbers[i]);

    return 0;
}