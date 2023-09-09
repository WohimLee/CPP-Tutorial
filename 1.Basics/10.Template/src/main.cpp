#include <iostream>

template <class T> 
T GetMax(T a, T b)
{
    T res; // 在模板函数 GetMax() 里，类型 T 可以被用来声明新的对象
    res = a > b ? a : b;
    return res;
}

int main()
{
    int var1 = 5, var2 = 6;
    float var3 = 10, var4 = 20;
    int res1 = GetMax(var1, var2);       // 省略类型声明
    float res2 = GetMax<float>(var3, var4); // 写类型声明

    printf("res1 = %d\n", res1);
    printf("res2 = %f\n", res2);

    return 0;
}