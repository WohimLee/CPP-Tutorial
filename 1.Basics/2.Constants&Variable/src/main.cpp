#include <stdio.h>

int main()
{
    int a=10; char b='a'; float c = 3.14; double d = 3.14159;
    int* a_ptr = &a;    // 4 bytes
    char* b_ptr = &b;   // 1 bytes
    float* c_ptr = &c;  // 4 bytes
    double* d_ptr = &d; // 8 bytes
    void* ptr;

    // void* 可以转换成任意类型指针
    int* ptr_int = (int*)ptr;
    char* ptr_char = (char*)ptr;
    float* ptr_float = (float*)ptr;
    double* ptr_double = (double*)ptr;

    // int*
    char* int_char = (char*)a_ptr;
    float* int_float = (float*)a_ptr;
    double* int_double = (double*)a_ptr;

    // char*
    int* char_int = (int*)b_ptr;
    float* char_float = (float*)b_ptr;
    double* char_double = (double*)b_ptr;

    // float*
    int* float_int = (int*)c_ptr;
    char* float_char = (char*)c_ptr;
    double* float_double = (double*)c_ptr;

    // double* 自己试
    return 0;
}
