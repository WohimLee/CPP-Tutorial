#include <iostream>
using namespace std;


int main()
{
    float a = 3.1415926;   
    float b = 0.0018004887367; 

    printf("%6.2f\n", a); // 输出宽度 6, 保留 2 小数点
    printf("%6.3f\n", a); // 输出宽度 6, 保留 3 小数点

    printf("%-6.2f\n", a); // 靠左对齐, 输出宽度 6, 保留 2 小数点
    printf("%-6.3f\n\n", a); // 靠左对齐, 输出宽度 6, 保留 3 小数点

    printf("%14e\n", b); // 输出宽度 14
    printf("%14.4E\n", b); // 输出宽度 14, 保留 4 位小数

    printf("%-14e\n", b);
    printf("%-14.4E\n\n", b);

    // 控制字符串最小输出宽度
    printf("%-5s: %d bytes.\n", "int", sizeof(int));
    printf("%-5s: %d bytes.\n", "char", sizeof(char));
    printf("%-5s: %d bytes.\n\n", "float", sizeof(float));

    printf("%5s: %d bytes.\n", "int", sizeof(int));
    printf("%5s: %d bytes.\n", "char", sizeof(char));
    printf("%5s: %d bytes.\n", "float", sizeof(float));

    return 0;
}