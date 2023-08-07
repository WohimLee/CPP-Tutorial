#include <stdio.h>

struct Camera{
    double focal=500;
    double fx;
    double fy;
    double cx;
    double cy;
}cam1, cam2;

// struct Test{
//     int a; // 4
//     char b; // 1
//     float c; // 4
//     double d; // 8
// }test;

struct Test{
    double d; // 8
    char b; // 1
    int a; // 4
    float c; // 4
}test;

int main()
{
    printf("size of Camera: %lu\n", sizeof(Camera));
    printf("size of cam1  : %lu\n", sizeof(cam1));
    printf("size of 5*sizeof(double): %lu\n", 5*sizeof(double));

    printf("size of Test: %lu\n", sizeof(Test));
    printf("size of test  : %lu\n", sizeof(test));
    printf("size of int+char+float+double: %lu\n", 
        sizeof(int)+sizeof(char)+sizeof(float)+sizeof(double));
    return 0;
}