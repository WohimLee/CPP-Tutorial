#include <iostream>
using namespace std;

class Person;

class Police
{
public :
    Police(){};
    void getinfo(Person* person);
};

class Person
{
    // friend class Police;
    friend void Police::getinfo(Person* person);
public:
    Person(){};
    Person(int age, long deposit);
public :
    int age;
private :
    long deposit;
};

Person::Person(int _age, long _deposit)
{
    this->age = _age;
    this->deposit = _deposit;
}

void Police::getinfo(Person* person)
{
    cout << person->age << endl;
    cout << person->deposit << endl;
}

int main()
{
    Police police;
    Person man(34, 190000);
    police.getinfo(&man);
}