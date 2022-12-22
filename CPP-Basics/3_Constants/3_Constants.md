# 1 定义常量
## 1.1 预处理指令#define定义
&emsp;&emsp;使用预处理器指令#define 可以将那些经常使用的常量定义为你自己取的名字而不需要借助于变量。
>语法格式
```c++
#define identititer value
```

>示例
```c++
#define PI 3.14159265
#define NEWLINE '\n'
#define WIDTH 100
```

上面定义了3个常量。一旦做了这些声明，你可以在后而的程序中使用这些常量，就像使用其他任何常量一样，例如∶
```c++

circle = 2 * PI * r;
cout << NEWLINE;
```

&emsp;&emsp;编译器在遇到 #detine 指令的时候，做的只是把任何出现这些常量名（在前面的例子中为 PI、NEWLINE 或 WIDTH）的地方替换成它们被定义为的代码（分别为 3.14159265、'\n'和100）。因此，由 #define 定义的常量被称为宏常量（macro constants）。

&emsp;&emsp;#define 指令不是代码语句，它是预处理器指令，因此指令行末尾不需要加分号（;）。如果你在宏定义行末尾加了分号（;），当预处理器在程序中做常量替换的时候，分号也会被加到被替换的行中，这样可能导致错误。

&emsp;
## 1.2 const定义
&emsp;&emsp;通常使用const前缀可以定义自定类型的常量，就像定义一个变量一样：
```c++
const int width = 100;
const char tab = '\t';
```

&emsp;
# 2 整型常量
（1）简单示例：
```c++
75   // 十进制 decimal
0113 // 八进制 octal
0x4b // 十六进制 hexadecimal
```

（2）C与C++中进制的输出
```c++
#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    cout << "————————C语言————————" << endl;
    printf("%o\n",35);    //按八进制格式输出
    printf("%d\n",35);    //按十进制格式输出
    printf("%x\n",35);    //按十六进制格式输出
    
    cout << " " << endl;
    cout << "————————C++语言————————" << endl;

    cout << "35的8进制:" << std::oct << 35<< endl;  
    cout << "35的10进制" << std::dec << 35 << endl;  
    cout << "35的16进制:" << std::hex << 35 << endl;  
    cout << "35的2进制: " << bitset<8>(35) << endl;  //<8>：表示保留8位输出
    return 0;
}
```
（3）像变量一样，常量也是有数据类型的。默认的整数字常量的类型为int 型。我们可以通过在后面加字母 u或l来追使它为无符号（unsigned）的类型或长整型（long）。
```c++
75   // int
75u  // unsigned int
75l  // long
75ul // usigned long
```

这里后缀u和l可以是大写的，也可以是小写的。
&emsp;
# 3 浮点型常量
（1）简单示例：
```c++
3.14159  // 3.14159
6.02e23  // 6.02*10^23
1.6e-19  // 1.6*10^-19
3.0      // 3.0
```

（2）浮点数的默认数据类型为 double。如果你想使用 float 或 long double 类型，可以在后面加 F 或 l 后缀，同样大小写都可以∶
```c++
3.14159L // long double
6.02e23f // float
```

&emsp;
# 4 字符型常量
（1）在表示单独字符的时候，我们用单引号''，在表示字符串或多于一个字符的时候，我们用双引号""。下面例子中，前两个表达式表示单独的字符，后面两个表示由若干字符组成的字符串。

```c++
'z'
'p'
"Hello world"
```
（2）如果每一行代码以反斜杠（\）结束，字符串常量可以分多行代码表示∶
```c++
"string expressed in \
two lines"
```
（3）字符常量可以将多个被空格（blank space）、跳跃符（tabulator）、换行符（newline）或其他有效空白符号分隔开的字符串常量连接在一起∶
```c++
"we form" "a single" "string" "of characters"
```
&emsp;
# 5 布尔型常量
布尔型只有两个有效的值∶ true 和 false，其数据类型为 bool。
