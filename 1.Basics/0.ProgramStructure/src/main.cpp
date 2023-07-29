
#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("输入的参数共有：%d条\n", argc);
    for (int i = 0; i < argc; i++)
        printf("%s\n", argv[i]);
    return 0;
}








