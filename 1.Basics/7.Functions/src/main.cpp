
#include <stdio.h>
#include "add.hpp"



int main(int argc, char* argv[]){

    int a=10;
    int b=20;

    int res = add(a, b);
    printf("res = %d\n", res);
    return 0;
}