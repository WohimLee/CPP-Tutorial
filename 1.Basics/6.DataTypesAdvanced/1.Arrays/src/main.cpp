#include <stdio.h>
#include <iostream>

int main() {
    char str1[] = {'H', 'e','l','l','o','\0'};
    char str2[] = {'H', 'e','l','l','o'};
    char str3[] = "Hello"; // 字符串常量初始化，自动加 \0

    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl; // 没有结束符，会一直打印内存后面接着的char 
    std::cout << str3 << std::endl;

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);

    return 0;
}