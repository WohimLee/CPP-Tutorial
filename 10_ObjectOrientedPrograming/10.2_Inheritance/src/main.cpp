#include <iostream>
using namespace std;


class Base
{
    public :
        int m_Age;
};


class Son1 : virtual public Base{};
class Son2 : virtual public Base{};
class Grandson : public Son1, public Son2{};


int main()
{
    Grandson g;
    g.Son1::m_Age = 10;
    g.Son2::m_Age = 20;

    cout << &g.m_Age << endl;
    cout << &g.Son1::m_Age << endl;
    cout << &g.Son2::m_Age << endl;

}













