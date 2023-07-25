#include <iostream>
using namespace std;

#define NUM(x, y, z) (x)##(z)##(y)##(x)

int main()
{
    cout << NUM(1+1, 2+1, 3+1) << endl;
    // 1+1##3+1##2+1##1+1
    return 0;
}








