# 预处理

# 1 预处理指令
预处理指令是我们写在程序代码中的给预处理器（preprocessor）的命令，而不是程序本身的语句。预处理器在编译一个 C++ 程序时由编译器自动执行，它负责控制对程序代码的第一次验证和消化。

所有这些指令必须写在单独的一行中，它们不需要加结尾的分号（;），如果有多行可以使用续行符（ \\ ）。 

&emsp;
## 1.1 #include
这个指令我们已经见到过很多次。当预处理器找到一个#include指令时，它用指定文件的全部内容替换这条语句。声明包含一个文件有两种方式;
```c++
#include "file"
#include <file>
```
- 如果文件名是在双引号号（""）中，编译器首先在包含这条指令的文件所在的目寻找。如果找不到指定文件，编译器再到被配置的默认路径下（也就是标准头文件路径下）寻找。
- 如果文件名是在尖括号（<>）中，编译器就会直接到默认标准头文件路径下导找。 

&emsp;
## 1.2 #define
（1） #define 可以被用来生成宏定义常量，它的使用形式是∶
```c++
#define name value
```
它的作用是定义一个叫作 name 的宏定义，然后每当在程序中遇到这个名字的时候，它就会被 value 代替，例如∶
```c++
#include <iostream>
using namespace std;

#define NUM 5

int main()
{
    char array[NUM];
    for (int i; i < NUM; i++)
    {
        array[i] = i;
    }
    
    return 0;
}
```


（2）#define 也可以被用来定义宏函数∶ 
```c++
#include <iostream>
using namespace std;

// #define getmax(a, b) a > b ? a : b
#define getmax(a, b)  ((a) > (b)) ? (a) : (b)

int main()
{
    int x = 5, y;
    y = getmax(x, 2);
    cout << y << endl;
    return 0;
}
```
这段代码执行后y 的值为5。 


## 1.3 #undef
#undef 完成与 #define 相反的工作，它取消对传入的参数的宏定义
>示例
```c++
#include <iostream>
using namespace std;

#define MAX_WIDTH 100
#undef MAX_WIDTH
#define MAX_WIDTH 200

int main()
{
    cout << MAX_WIDTH << endl;
    return 0;
}
```

#ifdef、#ifndef、#if、#endif、#else和#elif指令可以使程序的一部分在某种条件下被忽略。

#ifdef 可以使一段程序只有在某个指定常量已经被定义了的情况下才被编译.无论被定义的值是什么。它的操作是∶
```c++
#ifdef name
// code here
#endif
```

&emsp;
>示例
```c++
#include <iostream>
using namespace std;

#define NUM 10

#ifdef NUM
int a = NUM;
#endif

int main()
{
    cout << a << endl;
    return 0;
}
```

在这个例子中，语句 char str[MAX WIDTH];只有在宏定义常量 MAX_WIDTH 已经被定义的情况下才被编译器考虑，不管它的值是什么。如果它还没有被定义，这一行代码就不会被包括在程序中。

#ifndef 起相反的作用∶在指令#ifndef 和 #endif 之间的代码只有在某个常量没有被定义的情况下才被编译

>示例
```c++
#include <iostream>
using namespace std;

#define NUM 5

#ifndef NUM
#define NUM 10
#endif

int main()
{
    cout << NUM << endl;
    return 0;
}
```

这个例子中，如果处理到这段代码的时候 MAX_WIDTH 还没有被定义，它就会被定义为值 100。而如果它已经被定义了，那么它会保持原值（因为#define 语句这一行不会被执行）。

指令#if、#else 和#elif（elif=else if用来使得其后面所跟的程序部分只有在特定条件下才被编译。这些条件只能够是常量表达式

>示例
```c++
#include <iostream>
using namespace std;

#define NUM 888
#if NUM > 200
#undef NUM
#define NUM 200

#elif NUM < 50
#undef NUM
#define NUM 50

#else
#undef NUM
#define NUM 100
#endif


int main()
{
    cout << NUM << endl;
    return 0;
}
```




## 1.4 #pragma
这个指令是用来对编译器进行配置的，针对你所使用的`平台`和`编译器`而有所不同。

知果你的编译器不支持某个#pragma 的特定参数，这个参数会被忽略，不会产生出错。



&emsp;
## 1.5 拓展
为了避免同一个文件被include多次
```
1   #ifndef方式
2   #pragma once方式
```
在能够支持这两种方式的编译器上，二者并没有太大的区别
```C++
    方式一：

    #ifndef __SOMEFILE_H__
    #define __SOMEFILE_H__
    ... ... // 一些声明语句
    #endif

    方式二：

    #pragma once
    ... ... // 一些声明语句
```




# 2 预定义宏
- \_\_FILE__: 当前文件路径
- \_\_LINE__: 当前程序所在行号
- \_\_VA_ARGS__: 宏的变参
- \_WIN32: 当前是windows32bit的编译环境
- \_WIN64: 当前是windows64bit的编译环境
- \_\_APPLE__: 当前是苹果平台
- \_\_ANDROID__: 当前是安卓平台
- \_\_linux__: 当前是Linux平台
- \_\_unix__: 当前是Unix平台
- \_\_FUNCTION__: 当前的函数名
- \_\_TIME__: 当前文件的时间

&emsp;
## 2.1 通过__func__显示函数名称
有时候我们为了调试方便，想在某个函数中打印出函数名。C++11 提供了一个预定义__func__（注意两边各有两条下画线），用于表示函数名称。该宏使用起来很简单，将它当作一个字符串即可，这样在需要打印的地方，按照字符串的打印方式即可显示函数名称。

>示例，使用宏__func_得到函数名
```c++
const char *test()
{
    return __func__;
}
int main()
{
    printf("%s, %s\n", __func__, test());
    return 0;
}
```




## 2.2 变长参数__VA_ARGS__
- __VA_ARGS__是一个表示变长参数的宏，它以前属于 c99 标准，现在 C++11 把它正式纳入 C++标准。变长参数是指参数列表的最后一个参数是省略号，而变长参数的宏 \_\_VA_ARGS\_\_ 则可以替换省略号所代表的字符串，这个功能在轻量级调试中非常有用，我们可以自己定叉一些日志函数、打印函数来丰富调试信息。

>示例 1
```c++
// 对 printf 重新定义，然后调用 printf 的地方就可以用 PT 来代替
#include <stdio.h>
#define PT(...) printf(__VA_ARGS__);

int main()
{
    PT("%d,%s\n", 5, "abc");
}
```

>示例 2
```c++
// 实现一个日志打印函数
#include <stdio.h>

#define INFO(...)     \
{                        \
    // 打印出源代码文件名、函数名和行数
    printf("%s\n%s,%d\n", __FILE__, __func__, __LINE__); \
    // 打印变量值
    printf(__VA_ARGS__); \
}                        
 
int main()
{
    int a = 5;
    INFO("a = %d\n", a);
    return 0;
}
```



这个例子综合性地用到了前面介绍的几个宏，它们和 \_\_VA_ARGS\_\_ 一起较好地显示出了一些调试信息，比如当前文件名称、函数名称和行数，以及自己想查看的变量值，这里就是 ret。这样的打印信息对于一些无法单步调试的环境非常重要，比如内核调试环境等。

&emsp;
# 3 # 和 ## 操作符


## 3.1 # 操作符
`#` 只能出现在带参的宏的替换文本中，将参数转换成`字符串常量`
>示例 1
```cpp
#include <iostream>
using namespace std;

#define STRING1(x) "x"
#define STRING2(x) #x
#define STRING3(x) "aaa"#x"bbb"
#define STRING4(x, y) #x#y

int main()
{
    int test = 10;
    cout << STRING1(test) << endl;
    cout << STRING2(test) << endl;
    cout << STRING3(test) << endl;
    cout << STRING4(test, 888) << endl;

    return 0;
}
```

>示例 2
```cpp
#include <stdlib.h>
#include <stdio.h>
// 打印信息时带上文件和行号
#define INFO(...)                                \
    do{                                          \
        printf("[%s:%d]: ", __FILE__, __LINE__); \
        printf(__VA_ARGS__);                     \
        printf("\n");                            \
    }while(0)

// 断言的定义
#define Assert(cond)                                    \
    do{                                                 \
        bool op = !(!(cond));                           \
        if(!op){                                        \
            INFO("Assert failed, op = %s\n", #cond);    \
            abort();                                    \
        }                                               \
    }while(0)

int main()
{
    Assert(2 > 3);
    return 0;
}
```

&emsp;
## 3.2 ## 合并操作符
- `##` 是一种运算符，是将两个运算对象连接在一起，只能出现在带参宏定义的替换文本中

- 注意：使用合并操作符 `##` 时，自身的标识符必须预先有定义，否则编译器会报 "undefined" 的编译错误。字符序列合并成新的标识符不是字符串。
>示例 
```cpp
#include <iostream>
using namespace std;

#define NUM1(x, y, z) x##y##z
#define NUM2(x, y, z) z##y##x
#define NUM3(x, y, z) x##z##y##x

int main()
{
    cout << NUM1(1, 2, 3) << endl;
    cout << NUM2(1, 2, 3) << endl;
    cout << NUM3(1, 2, 3) << endl;

    return 0;
}
```

&emsp;
# 4 do...while在宏定义中的作用

- #define是在预处理的时候进行直接替换
>示例 1
```cpp
#include <iostream>
using namespace std;

void print(){
    cout << "print: " << endl;
}
void send(){
    cout << "send: " << endl;
}

#define LOG print();send();

int main()
{
    if(false)
        LOG
    cout << "hello " << endl;
    /* 上面的代码相当于:
    if (false)
        print();

    send();
    cout <<"hello world"<<endl;
    */
    return 0;
}
```
这个代码输出什么? 理论上，if(false)里面的代码不会被执行，也就是LOG不会被执行，所以只应该打印出"hello world".
但是事实上：
```
send: 
hello 
```

 

怎么解决？有些人马上想到，用{...}把 #define 的值括住不就可以了。的确，在这里是可以的。

>示例 2
```cpp
#include <iostream>
using namespace std;

void print(){
    cout << "print: " << endl;
}
void send(){
    cout << "send: " << endl;
}

#define LOG {print();send();};

int main()
{
    if(false)
        LOG
    cout << "hello " << endl;
    /* 上面的代码相当于:
    if (false)
    {
        print();
        send();
    };
    cout <<"hello world"<<endl;
    */
    return 0;
}
```

当我们的if后面有一个else呢？
>示例 3
```cpp
#include <iostream>
using namespace std;

void print(){
    cout << "print: " << endl;
}
void send(){
    cout << "send: " << endl;
}

#define LOG {print();send();};

int main()
{
    if(false)
        LOG
    else // 报语法错误
        cout << "hello " << endl;
    /* 上面的代码相当于:
    if (false)
    {
        print();
        send();
    }
    cout <<"hello world"<<endl;
    */
    return 0;
}
```
这样就会因为if语句后面多加了个;而编译不通过。要是开发一个大型项目的时候有的时候只需要if，有的时候需要if else 那到底加还是不加;了...

>示例 终极方案
```cpp
#define LOG do{print();send();}while (0);

int main(){

    if (false)
        LOG
    else
    {
        cout <<"hello"<<endl;
    }
    cout <<"hello world"<<endl;

    return 0;
}
/*就相当于：
if (false)
    do{
        print();
        send();
    }while (0);
else
{
cout <<"hello"<<endl;
}
cout <<"hello world"<<endl;
*/
```
用do{...}while(0);包裹住要操作的#define,无论你外面怎么操作，都不会影响 #define 的操作



