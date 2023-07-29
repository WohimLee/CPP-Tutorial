&emsp;
# 变量

## 1 变量的定义
要使用一个变量必须先定义（有的地方会说声明）该变量的数据类型

定义一个新变量的语法是写出数据类型标识符（例如 int、short、float 等），后面跟一个有效的变量标识名称

>基本用法：[数据类型] + [变量名]
```c++
int nlevels;
int nfeatures;
int iniThFAST;
int minThFAST;
bool bNoMore;
double scaleFactor;
```

>声明多个相同类型的变量，可以写在同一行
```c++
int nlevels, nfeatures, iniThFAST, minThFAST;
```

>修饰符
- 整型数据类型（char、short、long和 int）可以是有符号的（signed）或无符号的（unsigned）
  - signed: 有符号类型，可以表示正数和负数
  - unsigned: 无符号类型， 只能表示正数和0
```c++
unsigned int mnLastKeyFrameId;
unsigned int mnLastRelocFrameId;

unsigned char a;
signed int b = -1

// 如果我们没有特别写出 signed 或 unsigned
// 那么变量默认为 signed，下面两种写法等同
signed short = -10;
short = -10;
```

>short 和 long 
- short 和 long 可以被单独用来表示整型基本数据类型，short 相当于 short int，long 相当于 long int，例如下面两个声明是等价的。
```c++
short year;
short int year;
```

>*signed 和 unsigned
- signed 和 unsigned 也可以被单独用来表示简单类型，意思分别同 signed int 和 unsigned int，即以下两种声明互相等同：
```c++
unsigned MyBirthYear;
unsigned int MyBirthYear;
```

&emsp;
## 2 C++ 中的 auto
上面的例子都是一个变量使用之前必须进行显式类型的定义（声明），比如通过 `int a;`告诉编译器 a 是个整型变量。    

C++11中用 `auto` 关键字让编译器在编译阶段推导出变量的类型

>Example
```c++
// 编译器自动推导a为int型，auto被认为是int
auto a = 20;    

// 编译器自动推导f为double型，auto被认为是double
static auto f = 0.1    

// 编译器自动推导 p 为 int* 型，auto 被认为是 int*
auto p = new auto(5);  

// q 自动推导为 const int* 型
// k 自动推导为 const int 型，auto 被认为是 int
const auto *q=&a, k=8; 
```

>注意
- 使用 auto 定义变量时，必须同时进行初始化，即赋值
- auto 相当于一个类型的占位符，先占着位置。等到编译的时候推导出实示类型时再替换为真正的类型
- 同时定义多个变量时，不能产生二义性，否则报错
    - 比如上面 q 初始化内容为整型变量的地址，因此q被推导为 int*，auto 被认为是 int 这个实际类型，然后编译器再推导 k 为 int 型，先后一致，没问题
    - 如果我们这样初始化 k∶ `k=0.8;` 那么编译器就认为 k 是 double 型，即修饰 k 的实际类型应该是 double，而前面推导出 auto 是 int，就发生矛盾了，此时编译器将报错
- auto不能用于函数参数

&emsp;
## 3 查看数据类型


```c++
#include <typeinfo>
#include <iostream>
using namespace std;

int main()
{
    auto a = 12.4;
    cout << typeid(a).name() << endl;
    return 0;
}
```

>对应的数据类型
```
bool:                     b
char:                     c
signed char:              a
unsigned char:            h
(signed) short (int):     s
unsigned short (int):     t
(signed) (int):           i
unsigned (int):           j
(signed) long (int):      l
unsigned long (int):      m
(signed) long long (int): x
unsigned long long (int): y
float:                    f
double:                   d
long double:              e
```
