
#include <iostream>


class Person
{
public:
    int* m_age;
    int* m_id;

    Person(int age, int id){
        printf("Call constructor: Person(int age, int id)\n");
        m_age = new int;
        m_id =  new int;
        *m_age = age;
        *m_id = id;
    }

    ~Person(){
        printf("Call destructor: ~Person()\n");
        delete m_age;
        delete m_id;
    }
};

int main(int argc, char** argv)
{
    Person* p = new Person(20, 888888);
    delete p;

    return 0;
}
