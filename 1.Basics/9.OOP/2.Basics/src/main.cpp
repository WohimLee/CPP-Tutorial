

#include <iostream>
using namespace std;

class Person;

class Police
{
public:
    void getInfo(Person* person);
};


class Person
{
    friend void Police::getInfo(Person* person);
public:
    Person(){};
    Person(int age, long deposit);
public:
    int age;
private:
    long deposit;
};

Person::Person(int _age, long _deposit)
{
    this->age = _age;
    this->deposit = _deposit;
}

void Police::getInfo(Person* person)
{
    cout << person->age << endl;
    cout << person->deposit << endl;
}


int main(int argc, char** argv)
{
    Person person(18, 8888888);
    Police police;
    police.getInfo(&person);
    return 0;
}