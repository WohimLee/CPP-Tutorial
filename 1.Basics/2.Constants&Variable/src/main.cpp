#include <stdio.h>
#include <iostream>

#define PI 3.1415926


int main()
{
    auto a = 20;
    std::cout << typeid(a).name() << std::endl;
    return 0;
}