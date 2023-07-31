#include <stdio.h>
int main()
{
    printf("%f\n\n", 3.1415926);

    // * 代替最小输出宽度
    printf("%*f\n", 10, 3.1415926);
    // * 代替最小输出宽度和精度
    printf("%*.*f\n", 10, 3, 3.1415926);

    return 0;
}