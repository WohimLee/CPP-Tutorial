
#include <iostream>

class Person
{
public:
    Person(){
        printf("Call constructor: Person::Person()\n");
    }
    virtual ~Person() = 0;
};

Person::~Person(){
    printf("Call destructor: Person::~Person()\n");
}

class Adult : public Person
{
public :
    Adult(){
        printf("Call constructor: Adult::Adult()\n");
    }
    ~Adult(){
        printf("Call constructor: Adult::~Adult()\n");
    }
};


int main(int argc, char** argv)
{
    Person* p = new Adult();
    delete p;

    return 0;
}