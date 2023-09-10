#include <iostream>

class Base
{
public:
    Base(){printf("Call constructor: Base::Base()\n");}
    ~Base(){printf("Call destructor: Base::~Base()\n");}
};


class Derive : public Base
{
public:
    Derive(){printf("Call constructor: Derive::Derive()\n");}
    ~Derive(){printf("Call destructor: Derive::~Derive()\n");}
};


int main()
{
    Derive* pObj = new Derive;
    delete pObj;
    return 0;
}