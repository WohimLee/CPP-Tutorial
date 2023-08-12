
#include <stdio.h>

int main()
{
    int nElem = 10;
    int array[nElem]; // array: int(*)[n]
    for(int i=0; i<nElem; i++)
        array[i]= 30+i;

    int* p1 = array; // 数组名
    int** pp1 = &p1;
    // int** pp2 = &array; // 报错

    // 从上面看好像 p1 和 array 类型就是相同的
    // 但是为什么报错？因为: array: int(*)[n]
    int (*p2)[nElem] = &array; // 这样就可以

    // 注意: int* p1 = array 将 int(*)[n] 转成了 int*
    // 多维数组, 也只有最后一维的指针有这样的 syntatic sugar

    return 0;
}