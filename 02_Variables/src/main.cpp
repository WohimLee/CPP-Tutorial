#include <typeinfo>
#include <iostream>
using namespace std;

int main()
{
    auto a = 12.4;
    cout << typeid(a).name() << endl;

    return 0;
}