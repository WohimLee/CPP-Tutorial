
#include <stdio.h>
#include "add.hpp"
#include "minus.hpp"


int main(int argc, char** argv){

    int a=10, b=5;
    printf("a+b = %d\n", add(a, b));
    printf("a-b = %d\n", minus(a, b));

    return 0;
}