#include <stdio.h>
#include <iostream>

int main() {
    char str1[] = {'H', 'e','l','l','o','\0'};
    char str2[] = {'H', 'e','l','l','o'}; // 有的编译器或者C++版本中，如果没有 `\0`, 则会一直打印后面的字符
    char str3[] = "Hello"; // 字符串常量初始化，自动加 \0

    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl; 
    std::cout << str3 << std::endl;

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);

    return 0;
}