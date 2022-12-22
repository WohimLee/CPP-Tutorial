


&emsp;
# 函数
一个函数（function）是一个可以从程序其他地方调用执行的语句块。以下是它的格式;
```
type name（argument1，Araument2，，..) statement
```

- type 函数返回值类型
- name 函数名
- argument 形参
- statement 是函数的内容。语句块就用花括号"{}"括起来。

&emsp;
# 1 一个函数例子

>示例
```c++
#include <iostream>
using namespace std;

void printmessage1 ()
{
  cout << "I'm a function!\n";
}
// void在参数的位置，表示这个函数在被调用时不需要任何参数，可省
void printmessage2(void){cout << "I'm a function!\n";}

int main ()
{
  printmessage1();
  printmessage2();
  return 0;
}
```
&emsp;
>函数的几个过程
- 声明
    ```cpp
    void printmessage1();
    void printmessage2(void);
    ```
- 实现
    ```cpp
    void printmessage1 ()
    {
    cout << "I'm a function!\n";
    }
    void printmessage2(void){cout << "I'm a function!\n";}
    ```
- 调用
    ```cpp
    printmessage1();
    printmessage2();
    ```
- 编译注意事项
  - 声明、头文件、命名空间、typedef、结构体放 .hpp/.h
  - 实现部分放在 .cpp
  - 如果没有头文件，main.cpp 直接 #include ".cpp"，会报错: 重定义

&emsp;
# 2 函数参数（Function Arguments）


## 2.1 值传递（Call by value）
```c++
#include <iostream>
using namespace std;

int addition (int a, int b)
{
    // 值传递 int a（形参） = x（实参）
    // 值传递 int b（形参） = y（实参）
    printf("Address of a(in function): %p\n", &a);
    printf("Address of b(in function): %p\n", &b);
    printf("\n");
    printf("Value of a(in function): %d\n", a); 
    printf("Value of b(in function): %d\n", b); 

    return a + b;
    // return (a + b);
}

int main ()
{
    int res;
    int x = 5;
    int y = 3;
    printf("Address of x: %p\n", &x); // 内存地址跟函数里 a 的不一样
    printf("Address of y: %p\n", &y); // 内存地址跟函数里 b 的不一样
    printf("\n");

    res = addition(x, y);
    
    printf("\n");
    cout << "The result is " << res <<endl;
    return 0;
}
```


&emsp;
## 2.2 引用传递（Call by reference）
&emsp;&emsp;如果要在函数内控制函数外的变量，必须使用按引用传递或地址传递的参数（arguments passed by reference）

>示例
```c++
#include <iostream>
using namespace std;
 
void duplicate(int& a, int& b, int &c)
{
  // int& a = x, int& b = y, int& c = z
  cout << "Address of a: " << &a << endl;
  cout << "Address of b: " << &b << endl;
  cout << "Address of c: " << &c << endl;
  printf("\n");
  cout << "Value of a: "   << a  << endl;
  cout << "Value of b: "   << b  << endl;
  cout << "Value of c: "   << c  << endl;
  
  a *= 2; 
  b *= 2; 
  c *= 2; 
}

int main()
{
    int x = 1, y = 3, z = 7;
    cout << "Address of x: " << &x << endl;
    cout << "Address of y: " << &y << endl;
    cout << "Address of z: " << &z << endl;
    printf("\n");
    duplicate(x, y, z);
    cout << "x=" << x
         << ", y=" << y
         << ", z=" << z <<endl;
    return 0;
}
```

&emsp;
## 2.3 地址传递（Call by address）

>示例
```cpp
#include <iostream>
using namespace std;
 
void duplicate(int* a, int* b, int *c)
{
  // int* a = &x, int* b = &y, int* c = &z
  cout << "Address of a: " << &a << endl;
  cout << "Address of b: " << &b << endl;
  cout << "Address of c: " << &c << endl;
  printf("\n");

  cout << "Value of a: "   << a  << endl;
  cout << "Value of b: "   << b  << endl;
  cout << "Value of c: "   << c  << endl;
  printf("\n");

  cout << "Value pointed by a: "   << *a  << endl;
  cout << "Value pointed by b: "   << *b  << endl;
  cout << "Value pointed by c: "   << *c  << endl;
  
  *a *= 2;
  *b *= 2;
  *c *= 2;
}

int main()
{
    int x = 1, y = 3, z = 7;
    cout << "Address of x: " << &x << endl;
    cout << "Address of y: " << &y << endl;
    cout << "Address of z: " << &z << endl;
    printf("\n");
    duplicate(&x, &y, &z);
    cout << "x=" << x
         << ", y=" << y
         << ", z=" << z <<endl;
    return 0;
}
```





&emsp;
## 2.4 参数的默认值
&emsp;声明函数时，可以给参数指定一个默认值。调用时没有给出该参数的值，那么这个默认值将被使用。

&emsp;注意类的成员函数在类外实现时，不需要再写默认值，否则会报错

```c++
#include <iostream>
int divide (int a, int b=2)
{
    int r;
    r = a/b;
    return (r);
}

int main()
{
    cout << divide(12);    // b用默认值, b=2
    cout << endl;
    cout << divide(20, 4); // b=4
    return 0;
}
```

&emsp;
# 3 函数的重载（Overload）
作用：函数名可以相同，提高复用性
函数重载满足条件：
- 同一个作用域下
- 函数名称相同
- 函数 `参数类型不同` 或者 `参数个数不同` 或者 `参数顺序不同`
- 跟返回值、形参的名字没有关系

>函数重载的例子
```c++
#include <iostream>
using namespace std;
 
int myadd(int a, int b)
{
  cout << "调用 int add(int, int)..." << endl;
  return (a + b);
}

float myadd(float a, float b)
{
  cout << "调用 float add(float, float)..." << endl;
  return (a + b);
}

// 报错：重定义
// float add(float x, float y)
// {
//   cout << "调用 float add()..." << endl;
//   return x + y;
// }

int main() {
    int a1 = 1, b1 = 2;
    float a2 = 1.1, b2 = 2.2;
    cout << myadd(a1, b1) << endl;
    cout << myadd(a2, b2) << endl;
    return 0;
}
```


&emsp;&emsp;编译器（compiler）通过检查传入的参数的类型来确定是略一个函数被调用。如果调用传入的是两个整数参数，那么原型定义中有两个整型（int）参量的函数被调再。如果传入的是两个浮点数，那么原型定义中有两个浮点型（float）参量的函数被调用。





&emsp;
# 4 内联函数
- inline 可以放在函数声明之前，要求该函数`必须在被调用的地方以代码形式被编译`。这相当于一个宏定义（macro）。
- 必须放在被调用的 .cpp 文件内，不能被其它编译单元调用（可以写在头文件，被调用的 .cpp 文件 include 进去）。不能像普通函数一样 `声明（.hpp）`和 `实现（.cpp）`分离，如果分离会报链接（undefined reference）
- inline 的好处是只对短小的函数有效，这种情况下，因为避免了调用函数的一些常规操作的时间（overhead），如参数堆栈操作的时间，所以编译结果的运行会更快一些。

>它的声明形式是：
```c++
inline type name(arguments ...) {instructions ...}
```

&emsp;&emsp;内联函数的调用和其它的函数调用一样。调用函数的时候并不需要写关键字inline，只有在函数声明前需要写。


&emsp;
# 5 匿名函数
匿名函数（英文名：lambda）就是没有名字的函数。最简单的匿名函数是`[](){}`，它没有参数也没有返回值
- `[]`里面用来捕获函数外部的变量
- `()`里面就是匿名函数的参数
- `{}`里面就是函数的执行代码

捕获列表描述了lambda表达式可以访问上下文中的哪些变量
- `[]`: 表示不捕获任何变量
- `[=]`: 表示按值捕获变量
- `[&]`: 表示按引用捕获变量
- `[this]`: 值传递捕获当前的 this
- 可以连用如:`[=,&a,&b]`表示以引用传递的方式捕捉变量a和b，以值传递方式捕捉其它所有变量
- 注意:捕捉列表不允许变量重复传递比如[&,&a]

>示例
```c++
template<typename _T>
shared_ptr<_T> make_nvshared(_T* ptr){
    return shared_ptr<_T>(ptr, [](_T* p){p->destroy();})
}
```

>示例
```c++
// 计算 iou 的 lambda 函数
  auto iou = [](const Box& a, const Box& b){
      float cross_left   = std::max(a.left, b.left);
      float cross_top    = std::max(a.top, b.top);
      float cross_right  = std::min(a.right, b.right);
      float cross_bottom = std::min(a.bottom, b.bottom);

      float cross_area = std::max(0.0f, cross_right - cross_left)*std::max(0.0f, cross_bottom-cross_top);
      float union_area = std::max(0.0f, a.right-a.left)*std::max(0.0f, a.bottom-a.top) +
                          std::max(0.0f, b.right-b.left)*std::max(0.0f, b.bottom-b.top) -
                          cross_area;
      if(cross_area == 0 || union_area == 0) return 0.0f;
      return cross_area / union_area;
  }
```


&emsp;
# 6 递归
- 递归（recursivity）指函数将被自己调用。

>利用递归计算阶乘     

&emsp;&emsp;要获得一个数字n的阶乘，它的数学公式是∶
```
n! = n * n(n-1) * (n-2) * (n-3)...* 1
```
```c++
#include <iostream>
using namespace std;
 
long factorial(long a) {
    if (a > 1) return (a * factorial(a - 1));
    else return (1);
}

int main() {
    long l;
    cout << "Type a number: ";
    cin >> l;
    cout << "!" << l << " = " << factorial(l)<<endl;
    return 0;
}
```
