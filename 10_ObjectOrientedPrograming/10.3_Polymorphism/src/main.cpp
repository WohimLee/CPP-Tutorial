#include <iostream>
#include <string>

using namespace std;


class Person
{
    public :   
        virtual ~Person() = 0;
        Person(); 

        virtual void BuyTicket(int num);      
};

class Adult : public Person
{
    public :
        ~Adult();
        Adult(string name);

        void BuyTicket(int num);
    private :
        string* m_name;
};

class Student : public Person
{
    public :
        ~Student();
        Student(string name);

        void BuyTicket(int num);
    private :
        string* m_name;
};

Person::Person(){cout << "Person构造函数" << endl;}
Person::~Person(){cout << "~Person析构函数" << endl;}
void Person::BuyTicket(int _num){cout << "乘客请买票" << endl;}

Adult::Adult(string _name){
    cout << "Adult构造函数" << endl;
    m_name = new string(_name);
}
Adult::~Adult(){
    if (m_name != NULL){
        cout << "~Adult析构函数" << endl;
    delete m_name;
    m_name = NULL;
    }
}
void Adult::BuyTicket(int _num){
    cout << "成人全票" << endl;
}

Student::Student(string _name){
    cout << "Student构造函数" << endl;
    m_name = new string(_name);
}
Student::~Student(){
    if (m_name != NULL){
        cout << "~Student析构函数" << endl;
    delete m_name;
    m_name = NULL;
    }
}
void Student::BuyTicket(int _num){
    cout << "学生半票" << endl;
}


void buy(Person* obj){
    obj->BuyTicket(1);
}

int main()
{
    Person* p1 = new Adult("Papa");
    buy(p1);
    delete p1;

    // Student* s = new Student("Son");

    return 0;
}





























