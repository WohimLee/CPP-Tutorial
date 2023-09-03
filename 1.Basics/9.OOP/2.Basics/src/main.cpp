
#include <iostream>
using namespace std;

class Person
{
public :
    Person& PersonAddAge(Person &p)
    {
        this->m_age += p.m_age;
        return *this;
    }
public:
    int m_age;
};

int main()
{

    return 0;
}