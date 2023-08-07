#include <iostream>
using namespace std;

#include <stdio.h>

typedef union {
    struct {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    } channels;
    unsigned int value;
} Color;

int main() {
    printf("sizeof uchar: %d\n", sizeof(unsigned char));
    return 0;
}

