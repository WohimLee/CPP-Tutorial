&emsp;
# Operator

## 1 赋值运算符
赋值运算符的功能是将一个值赋给一个变量
```c++
int a = 5; // 将整数5 赋给变量a 
```

运算符左边的部分叫作 `lvalue（left value）`，右边的部分叫作 `rvalue（right value）`
- 左边 lvalue 必须是一个变量
- 右边 rvalue 可以是一个常量、一个变量、一个运算（operation）的结果或是前面几项的任意组合
- 赋值运算符永远是将右边的值赋给左边，不会反过来。
- 将变量 b（rvalue）的值赋给变量 a （lvalue），不论 a 当时存储的是什么值
- 只是将 b 的数值赋给 a，以后如果 b 的值改变了，并不会影响到 a 的值


>Example 1
- C++ 拥有而其他语言没有的一个特性是赋值符（=）可以被用作另一个赋值符的 rvalue（或 rvalue的一部分）
```c++
// 先将 5 赋给变量 b，然后把前面对b的赋值运算的结果（即 5）加上2 再赋给变量 a，这样最后a中的值为7
a = 2 + (b = 5);
```
>Example 2
```c++
a = b = c = 5; //将5同时城给3个变量a、b和c 
```

&emsp;
## 2 数学运算符
>数学运算符
- ＋（加，adldition）
- -（减，subtraction）
- *（乘，multiplicu∶.on）
- /（除，division）
- %（取模，module）

&emsp;
## 3 组合运算符
组合运算符（+=、 -、* 和 /= 及其他），这些运算符使得只用一个基本运算符就可以改写变量的值∶
```c++
value += increase;   // 等同于value = value + increase
a -= 5;
a /= b;
price *= unita + 1;  // 等同于price = price * (unita + 1);
```

&emsp;
## 4 递增和递减
- 递增（increase）运算符（++）
- 递减（decrease）运算符（--）

它们使得变量中存储的值加 1或减1，分别等同于+=1和-=1

>示例
```c++
a++;
a += 1;
a = a+1;
```


- 注意 a++ 和 ++a 在运算式中代表不同的意思∶
  - 前缀（++a），变量 a 的值先增加，再计算整个表达式的值
  - 后缀（a++），变量 a 的值在表达式计算后才增加
```c++
#include <iostream>
using namespace std;

int main()
{
    int a = 3;          // a = 3
    cout << a << endl;

    int b = ++a;        // a = 4, b = a = 4
    cout << a << endl;
    cout << b << endl;

    int c = a++;        // c = a = 4, a + 1 = 5
    cout << a << endl;
    cout << c << endl;
    return 0;
}
```


&emsp;
## 5 关系运算符
&emsp;&emsp;关系运算的结果是一个 bool 值，根据运算结果的不同，它的值只能是 true 或 false。

- == 相等（Equl）
- != 不等（Different）
- \> 大于（Greater than）
- < 小于（Lessthan）
- \>= 大于等于（Greater or equal than）
- <= 小于等于（Less or equal than）

>示例
```c++
（7 = 5）将返回 false
（5 > 4）将返回 true
（3 != 2）将返回 true
（6 > 6）将返回 false
```



&emsp;&emsp;在 ANSI-C++标准出现之前，许多编译器中，就像 C 语言中，关系运算并不返回值为 true 或 false 的 bool 值，而是返回一个整型数值为结果，它的数值可以为 0，代表 false，或一个非0数值（通常为1），代表 true。

&emsp;

## 6 逻辑运算符
&emsp;&emsp;运算符 ! 等同于 boolean 运算 NOT （取非）

>示例
```c++
!true  // 返回 false
!false // 返回 true。
```
&emsp;&emsp;逻辑运算符 `&&` 和 `||` 用来计算两个表达式而获得一个结果值。它们分别对应逻辑运算中的与运算（AND）和或运算（OR）。


&emsp;
## 7 条件运算符（三目运算符）
>语法格式
```
condition ? result1 : result2 
```
如果条件为true，整个表达式返回result1，否则返回result2。
```c++
7==5 ? 4:3      // 返回3，因为7不等于5. 
7=-5+2 ? 4:3    // 返回4，因为7等于5+2。 
5>3 ? a:b       // 返回a，因为5大于3。
a>b ? a:b       // 返回较大值，a或b。
```
示例
```c++
#include <iostream>
using namespace std;

int main ()
{
  int a,b,c;

  a=2;
  b=7;
  c = (a>b) ? a : b;

  cout << c <<endl;

  return 0;
}
```
&emsp;
## 8 逗号运算符
&emsp;&emsp;逗号运算符（，）用来分开多个表达式，并只取最右边的表达式的值返回。
例如以下代码∶
```c++
a = (b = 3, b + 2);
```
&emsp;&emsp;这行代码首先将 3 赋值给变量 b，然后将 b+2 赋值给变量 a。所以最后变量a的值为5，而变量b的值为3。

&emsp;
## 9 *位运算符
位运算符以比特位改写变量存储的数值，也就是改写变量值的二进制表示∶

- &	    逻辑与（Logic AND） 
- |		逻辑或（Loglc OR）
- ^		逻辑异或（Logical exclusive OR）
- ~		对l取补（位反转）（Complement to one（bit inversion）） 
- <<	左移（Shift Left）
- \>>	右移（Shfft Right )


&emsp;
## 10 变量类型转换运算符
- 变量类型转换运算符可以将一种类型的数据转换为另一种类型的数据
- 在原转换的表达式前面加用括号"()"括起来的新数据类型
>示例
```c++
int i;
float f = 3.14;
i = (int)f;
```
