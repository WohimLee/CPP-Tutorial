
// #include <math.h>
#include <cmath>
#include <stdio.h>
#include <iostream>

int main()
{
    int a = 10;
    bool var = (a < 0 || a > 10);
    printf("value of var: %s.\n", var==true? "true" : "false");
    return 0;
}