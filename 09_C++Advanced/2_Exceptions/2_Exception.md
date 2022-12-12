# 1 异常的定义

&emsp;&emsp;有时候我们无法确定一段代码是否总是能够正常工作，或者因为程序访问了并不存在的资源，或者由于一些变量超出了预期的范围，等等，这些情况统称为出错（异常），C++新引入的3种操作符能够帮助我们处理这些出错的情况：try、throw和catch。

它们的一般用法是：
```c++
try{
    // code to be tried
    throw exception;
}
catch (type exception){
    // code to be executed in case of exception
}
```
&emsp;&emsp;所进行的操作为：try语句块中的代码被正常执行。如果有例外发生，代码必须使用关键字throw和一个参数来扔出一个例外。这个参数可以是任何有效的数据类型，它的类型反映了例外的特征。

&emsp;&emsp;如果有例外发生，也就是说在try语句块中有一个throw指令被执行了，catch语句块就会被执行，用来接收throw传来的例外参数。

&emsp;
## 1.1 异常处理基本结构

>示例，异常处理
```c++
#include <iostream>
using namespace std;
int main() {
    char myarray[10];
    try {
        for (int n = 0; n <= 10; n++) {
            if (n > 9) throw "Out of range";
            myarray[n] = 'z';
        }
    }
    catch (char const* str) {  // Out of range 是一个char const
        cout << "Exception: " << str << endl;
    }
    return 0;
}   
```
&emsp;&emsp;这个例子中
- 如果在n循环中，n变得大于9了，就扔出一个例外，超出了数组的元素个数会指向一个无效的内存地址。
- 当throw被执行的时候，try语句块立即被停止执行，在try语句块中生成的所有对象会被销毁。
- 此后，控制权被传递给响应的catch语句块（上面的例子执行中就是执行仅有的一个catch）。最后程序紧跟着catch语句块继续向下执行，在上面的例子中就是执行return0;。

&emsp;
## 1.2 多个catch块异常处理
>示例
```c++
#include <iostream>
using namespace std;
int main() {
    try {
        char * mystring;
        mystring = new char[10];
        if (mystring == NULL) throw "Allocation failure";
        for (int n = 0; n <= 100; n++) {
            if (n > 9) throw n;
            mystring[n] = 'z';
        }
    }
    catch (int i) {
        cout << "Exception: ";
        cout << "index " << i << " is out of range" << endl;
    }
    catch (char const* str) { 
        cout << "Exception: " << str << endl;
    }
    return 0;
}   
```
在上面的例子中，有两种不同的例外可能发生：
- 要求的10个字符空间不能够被赋值（这种情况很少，但是有可能发生），这种情况下，扔出的例外就会被catch（char const* str）捕获。
- n超过了mystring的最大索引值（index），这种情况下，扔出的例外将被catch(int)捕获，因为它的参数是一个整型值。


&emsp;
## 1.3 接收任何异常处理
&emsp;&emsp;我们还可以定义一个catch语句块来捕获所有的例外，不论扔出的是什么类型的参数。这种情况下，我们需要在catch或后面的括号中写3个点来代替原来的阐述类型和名称：
```c++
try{
    // code here
}
catch(...){
    cout << "Exception occured"; << endl;
}
```

&emsp;
## 1.4 abort()

abort函数的原型位于头文件cstdlib（或stdlib.h）中，其典型实现是向标准错误流（即cerr使用的错误流）发送消息abnormal program termination（程序异常终止），然后终止程序。

它还返回一个随实现而异的值，告诉操作系统（如果程序是由另一个程序调用的，则告诉父进程），处理失败。

abort()是否刷新文件缓冲区（用于存储读写到文件中的数据内存区域）取决于实现。如果愿意，也可以使用exit()，该函数刷新文件缓冲区，但不显示消息。


>示例
```cpp
// 计算两个数的调和平均数: 1.0 * x * y / (x + y)
#include <iostream>
#include <cstdlib>
double hmean(double a, double b);

int main()
{
    double x, y, z;

    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        z = hmean(x, y);
        std::cout << "Harmonic mean of " << x << " and " << y
                  << " is " << z << std::endl;
        std::cout << "Enter next set of numbers <q to quit>: ";
    }
    std::cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b) // 根据公式，互为复数的话分母为零
    {
        std::cout << "untenable arguments to hmean()\n";
        std::abort();
    }
    return 2.0 * a * b / (a + b);
}
```

在hmean()中调用abort()函数将直接终止程序。（所以看不到"Bye!"）
为了避免异常终止，程序员在调用hmean()函数之前应检查x和y的值。然而，依靠程序员来执行这中间查是不安全的。

&emsp;
## 1.5 exit
exit为C++的退出函数，声明于stdlib.h中，对于C++其标准的头文件为cstdlib
>声明
```c++
void exit(int value);
```
exit的功能为，退出当前运行的程序，并将参数value返回给主调进程。

- 在 main 中 return v;的效果 与exit(v);相同。
- exit(0)，表示程序正常退出，非0表示非正常退出
- exit(1)，返回1到主调程序
- exit(-1)，返回-1到主调程序
- exit(0)，则是返回0



&emsp;
# 2 标准异常
&emsp;&emsp;一些C++标准语言库中的函数也会扔出一些例外，我们可以用try语句来捕获它们。这些例外扔出的参数都是std::exception引申出的子类类型的。这个类（std::exception）被定义在C++标准头文件中，用来作为exceptions标准结构的模型。

&emsp;&emsp;这是一个类结构，如果包括了一个catch语句块使用地址（reference）来捕获这个结构中的任意一种例外（也及时说在类型后面加地址符（&）），你同时可以捕获所有引申类的例外（C++的继承原则）

>示例，标准异常的例子
```c++
#include <iostream>
#include <exception>
#include <typeinfo>
using namespace std;

class A{
    virtual void f(){};
};

int main(){
    try{
        A* a = NULL;
        typeid(*a);
    }
    catch (std::exception& e){
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
```

