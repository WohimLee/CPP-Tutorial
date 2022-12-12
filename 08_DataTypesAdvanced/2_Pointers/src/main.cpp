#include <iostream>
using namespace std;

int addition(int a, int b)
{
    return a + b;
}

int substraction(int a, int b)
{
    return a - b;
}

int(*myfunc)(int, int) = substraction;

int operation(int x, int y, int(*functocall)(int, int))
{
    return ((*functocall)(x, y));
}

int main()
{
    int m, n;
    m = operation(7, 5, addition);
    n = operation(20, 10, myfunc);
    cout << m << endl;
    cout << n << endl;

    return 0;
}