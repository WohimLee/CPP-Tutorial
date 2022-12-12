# 继承（Inheritance）

&emsp;
# 1 基本语法
>继承的基本语法
```
class 子类 : 继承方式 父类
```

>示例
```c++
#include <iostream>
using namespace std;

class Animal
{
public:
    void speak(){cout << "动物叫" << endl;};
    void eat(){cout << "动物吃东西" << endl;};
};

class Cat : public Animal{};
class Dog : public Animal{};

int main()
{
    Cat c;
    c.eat();
    Dog d;
    d.speak();

    return 0;
}
```

&emsp;
# 2 继承方式
- 公共继承（public）
- 保护继承（protected）
- 私有继承（private）


>示例
```c++

class A
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son1 : public A 
{
public :
    void func()
    {
        m_A = 10; // 类内可访问父类public，权限没有变
        m_B = 20; // 类内可访问父类protected，权限没有变
        // m_C = 30; // 类内不可方位父类private，权限没有变
    }
};

class Son2 : protected A
{
public :
    void func()
    {
        m_A = 10; // 类内可访问父类public，权限变为protected
        m_B = 20; // 类内可访问父类protected，权限还是protected
        // m_C = 30; // 类内不可访问父类private，权限还是private
    }
};

class Son3 : private A
{
public :
    void func()
    {
        m_A = 10; // 类内可访问父类public，权限变为 private
        m_B = 20; // 类内可访问父类protected，权限变为 private
        // m_C = 30; // 类内不可方位父类private，权限还是 private
    }
};

int main()
{
    
    Son1 s1;
    Son2 s2;
    Son3 s3;

    s1.m_A; // 类外可访问父类 public
    // s1.m_B; // 类外不可访问父类 protected

    // s2.m_A; // protected继承, 父类public变成protected，类外不可访问
    return 0;
}
```

&emsp;
# 3 继承中的对象模型
>问题：从父类继承过来的成员，哪些属于子类对象中
- 父类中所有非静态成员属性都会被子类继承下去
- 父类中私有成员属性被编译器隐藏了，访问不到，但是确实被继承下去了

>示例
```c++

class A
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son : public A
{
public :
    int m_D;
};


int main()
{
    
    cout << sizeof(Son) << endl;
    return 0;
}
```


&emsp;
# 4 构造和析构顺序
子类继承父类后，当创建子类对象，也会调用父类的构造函数
>问题：父类和子类的构造和析构顺序是谁先谁后？

>示例
```c++
class Base
{
public :
    Base(){cout << "Base类构造函数" << endl;} 
    ~Base(){cout << "Base类析构函数" << endl;}
};

class Son : public Base{
public:
    Son(){cout << "Son类构造函数" << endl;}
    ~Son(){cout << "Son类析构函数" << endl;}
};

int main()
{
    Son a;
    return 0;
}
```



&emsp;
# 5 同名成员处理
## 5.1 非静态成员
&emsp;&emsp;当子类与父类出现同名的成员，如何通过子类对象访问到子类或父类中同名的数据？
- 访问子类同名成员：直接访问即可
- 访问父类同名成员：需要加作用域
    - 同名属性
    - 同名函数
    - 如果子类中出现跟父类同名的成员函数，子类的同名成员函数会隐藏掉父类中所有同名成员函数，需要加作用域

>示例
```c++

class Base
{
public :
    int m_A = 100;
    void func(){cout << "Base的函数调用" << endl;}
};

class Son : public Base{
public:
    int m_A = 200;
    void func(){cout << "Son的函数调用" << endl;}
};

int main()
{
    Son s;
    cout << s.m_A << endl;
    cout << s.Base::m_A << endl;
    s.func();
    s.Base::func();
    return 0;
}
```


&emsp;
## 5.2 静态成员

&emsp;&emsp;继承中同名的静态成员在子类对象上如何进行访问？
静态成员和非静态成员出现同名，处理方式一致
- 访问子类同名成员 直接访问即可
- 访问父类同名成员 需要加作用域

```c++
#include <iostream>
using namespace std;

class Base
{
public :
    static int m_A;
    static void func(){cout << "Base的函数调用" << endl;}
};

int Base::m_A = 100;

class Son : public Base{
public:
    static int m_A;
    static void func(){cout << "Son的函数调用" << endl;}
};

int Son::m_A  = 200;

int main()
{
    Son s;
    cout << s.m_A << endl;
    cout << s.Base::m_A << endl;
    s.func();
    s.Base::func();
    return 0;
}
```

&emsp;
# 6 多继承语法
&emsp;&emsp;C++允许一个类继承多个类（一个儿子认多个爹），实际不建议用，了解即可
>语法
```c++
class 子类 : 继承方式 父类1, 继承方式 父类2...
```

>示例
```c++
class Base1
{
public :
    Base1(){m_A = 100;}

    int m_A;
};

class Base2
{
public :
    Base2(){m_A = 200;}

    int m_A;
};

class Son : public Base1, public Base2
{
public :
    Son(){
        m_C = 300;
        m_D = 400;
    }
    int m_C;
    int m_D;
};

int main()
{
    Son s;
    cout << sizeof(s) << endl;
    cout << s.Base1::m_A << endl;
    cout << s.Base2::m_A << endl;

    return 0;
}

```


&emsp;
# 7 菱形继承问题以及虚继承

>菱形继承（钻石继承）概念：
- 两个派生类继承同一个基类
- 又有某个类同时继承两个派生类
![](images/WX20210728-184204@2x.png)

>菱形继承的问题
- 会有歧义，调用哪个父类的成员不明确
- 有两份数据，不符合常识或浪费资源

>解决方法
- 用加作用域、虚继承解决这个问题

>示例，不加 virtual 关键字
```c++
#include <iostream>
using namespace std;

class Base
{
    public :
        int m_Age;
};

class Son1 : public Base{};
class Son2 : public Base{};
class Grandson : public Son1, public Son2{};

int main()
{
    Grandson g;
    g.Son1::m_Age = 10; // 通过加作用域赋值
    g.Son2::m_Age = 20; 

    cout << g.Son1::m_Age << endl; // 通过加作用域调用
    cout << g.Son2::m_Age << endl;
    
    return 0;
}
```
>示例，加 virtual 关键字
```c++
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
    g.Son2::m_Age = 20; // 加 virtual 关键字后只有一份数据，最后一次赋值有效

    cout << g.m_Age << endl; // 可以直接通过 .属性 调用

    // // 下面两行输出的是同一份数据   
    // cout << &g.Son1::m_Age << endl; 
    // cout << &g.Son2::m_Age << endl;
    
    return 0;
}
```