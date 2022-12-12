&emsp;
# 多态（Polymorphism）

&emsp;
# 1 基本概念
多态分为两类
- 静态多态：函数重载和运算符重载属于静态多态，复用函数名
- 动态多态：派生类和虚函数实现运行时多态

静态多态和动态多态区别：
- 静态多态的函数地址早绑定 - 编译阶段确定函数地址
- 动态多态的函数地址晚绑定 - 运行阶段确定函数地址

&emsp;
## 1.1 静态多态
>示例，静态多态
```c++
#include <iostream>
#include <string>
using namespace std;

class Person 
{
public:
    void BuyTicket(int)
    {   
        cout << "乘客需要买票" << endl;
    }   
};

class Adult : public Person
{
    public :
        void BuyTicket(int)
        {
            cout << "成人全票" << endl;
        }
};

class Student : public Person
{
    public :
        void BuyTicket(int)
        {
            cout << "学生半票" << endl;
        }
};

class Child : public Person
{
    public:
        void BuyTicket(int)
        {   
            cout << "儿童免票" << endl;
        }   
};

int main(void)
{
    Person p;
    Adult a;
    Student s;
    Child c;

    p.BuyTicket(1);
    a.BuyTicket(1);
    s.BuyTicket(1);
    c.BuyTicket(1);

    // void buy(Person& obj) // 不加 virtual 不能通过这个函数调用子类的成员
    // {
    //     obj.BuyTicket(1);   
    // }
    // buy(p);
    // buy(a);
    // buy(s);
    // buy(c);
    
    return 0;
}
```
&emsp;
## 1.2 动态多态（virtual关键字）
动态多态满足条件：
- 有继承关系
- 子类重写父类的虚函数
>示例，动态多态

```c++
#include <iostream>
#include <string>
using namespace std;

class Person 
{
public:
    virtual void BuyTicket(int)
    {   
        cout << "乘客需要买票" << endl;
    }   
};

class Adult : public Person
{
    public :
        // 子类的 virtual 关键字可写可不写
        virtual void BuyTicket(int)
        {
            cout << "成人全票" << endl;
        }
};

class Student : public Person
{
    public :
        void BuyTicket(int)
        {
            cout << "学生半票" << endl;
        }
};

class Child : public Person
{
    public:
        void BuyTicket(int)
        {   
            cout << "儿童免票" << endl;
        }   
};

void buy(Person& obj)
{
    obj.BuyTicket(1);                                                                                                                             
}

int main(void)
{
    Person p;
    Adult a;
    Student s;
    Child c;

    buy(p);
    buy(a);
    buy(s);
    buy(c);

    return 0;
}
```


&emsp;
# 2 纯虚函数和抽象类

&emsp;&emsp;纯虚函数（pure virtual function）是一个在基类中声明的虚函数，它在该基类中没有定义具体实现，要求子类根据实际需要定义函数实现。纯虚构函数的作用是为派生类提供一个一致的接口（类似于声明的作用）。抽象类描述的是所有派生类的高度抽象的共性，这些高度抽象、无法具体化的共性就由纯虚函数来描述。

&emsp;&emsp;在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容，因此可以将虚函数改为纯虚函数，目的是为了让我们在写子类的时候必须重写这个函数。

&emsp;
>纯虚函数语法：
```c++
virtual 返回值类型 函数名（参数列表）= 0;
```
当类中有了纯虚函数，这个类就成为了抽象类。


注意：
- 带有纯虚函数的类（抽象类）不能实例化对象
- 子类必须重写抽象类中的纯虚函数，否则也属于抽象类，不能实例化对象
- 构造函数不能是虚函数
- 析构函数可以是虚函数，在复杂的类中通常是必要的

```c++
#include <iostream>
#include <string>
using namespace std;

class Person 
{
public:
    virtual void BuyTicket(int) = 0;
};

class Adult : public Person
{
    // public :
    //     virtual void BuyTicket(int)
    //     {
    //         cout << "成人全票" << endl;
    //     }
};

class Student : public Person
{
    public :
        void BuyTicket(int)
        {
            cout << "学生半票" << endl;
        }
};

class Child : public Person
{
    public:
        void BuyTicket(int)
        {   
            cout << "儿童免票" << endl;
        }   
};

void buy(Person& obj)
{
    obj.BuyTicket(1);                                                                                                                             
}

int main(void)
{
    // Person p; // 抽象类不能实例化对象
    // Adult a; // 没有重写父类的纯虚函数，也属于抽象类，不能实例化对象
    Student s;
    Child c;

    buy(s);
    buy(c);

    return 0;
}
```



&emsp;
# 3 虚析构和纯虚析构

&emsp;&emsp;多态使用时，如果子类中有属性开辟到堆区，父类指针在释放时无法调用到子类的析构函数。怎么解决父类指针释放子类对象不干净的问题呢？

&emsp;&emsp;解决方式：将父类中的析构函数改为虚析构或者纯虚析构

&emsp;
>虚析构和纯虚析构共性：
- 可以解决父类指针释放子类对象
- 都需要有具体的函数实现

&emsp;
>虚析构和纯虚析构区别：
- 如果是纯虚析构，该类属于`抽象类`，无法实例化对象

&emsp;
>虚析构语法：
```c++
virtual ~类名(){}
```

&emsp;
>纯虚析构声明语法（必须另外有实现）：
```c++
virtual ~类名() = 0;
```

&emsp;&emsp;下面代码用父类指针去指向子类对象，当delete父类指针的时候，不会执行子类的析构代码，也就是没有释放在堆区的Cat类对象的数据，会导致内存泄露。
>示例
```c++
#include <iostream>
#include <string>
using namespace std;

class Person 
{
    public:
        Person();
        // virtual ~Person();
        virtual ~Person() = 0;
        virtual void BuyTicket(int);
};

class Adult : public Person
{
    public :
        Adult(string _name);
        ~Adult();
        void BuyTicket(int);
    private :
        string* m_name;
};

class Student : public Person
{
    public :
        Student(string _name);
        ~Student();
        void BuyTicket(int);
    private :
        string* m_name;
};

class Child : public Person
{
    public:
        Child(string _name);
        ~Child();
        void BuyTicket(int);
    private :
        string* m_name;
};

Person::Person()
{
    cout << "Person构造函数" << endl;
}
Adult::Adult(string _name)
{
    cout << "Adult构造函数" << endl;
    m_name = new string(_name);

}
Student::Student(string _name)
{
    cout << "Student构造函数" << endl;
}
Child::Child(string _name)
{
    cout << "Child构造函数" << endl;
}
Person::~Person()
{
    cout << "~Person析构函数" << endl;
}
Adult::~Adult()
{
    if (m_name != NULL)
    {
        cout << "~Adult析构函数" << endl;
        delete m_name;
        m_name = NULL;
    }
}
Student::~Student()
{
    if (m_name != NULL)
    {
        cout << "~Student析构函数" << endl;
        delete m_name;
        m_name = NULL;
    }
}
Child::~Child()
{
    if (m_name != NULL)
    {
        cout << "~Child析构函数" << endl;
        delete m_name;
        m_name = NULL;
    }
}

void Person::BuyTicket(int)
{
    cout << "乘客请买票" << endl;
}
void Adult::BuyTicket(int)
{
    cout << "成人全票" << endl;
}
void Student::BuyTicket(int)
{
    cout << "学生半票" << endl;
}
void Child::BuyTicket(int)
{   
    cout << "儿童免票" << endl;
}   

void buy(Person* obj)
{
    obj->BuyTicket(1);                                                                                                              
}

int main(void)
{
    Person* p1 = new Adult("Papa");
    buy(p1);
    delete p1;

    Student* s = new Student("Big brother");
    buy(s);
    delete s;

    return 0;
}
```
总结：
- 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象的问题
- 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
- 拥有纯虚析构函数的类也属于抽象类，不能实例化对象