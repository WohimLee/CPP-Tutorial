#include <iostream>
using namespace std;

int main()
{
    int a[3][2][2] = {0,1,2,3,4,5,6,7,8,9,10,11};
    // cout << a[0] << endl;
    // cout << a[1] << endl; // 偏移16个字节，也就是第1块开始的位置

    // cout << a[0][0] << endl;
    // cout << a[0][1] << endl; // 偏移 8 个字节，也就是每行开始的位置

    int* p = (int*)a;     // 多维数组的索引是每个维度对应的首地址
    cout << p[0] << endl;
    cout << p[10] << endl;

    return 0;
}