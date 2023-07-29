
&emsp;
# 1 条件结构
```c++
if (condition_1) 
{
    statement_1
} 
else if (condition_2)
{
    statement_2
}
...
else if (condition_n)
{
    statement_n
} 
else
{
    statement
}
    
```
&emsp;&emsp;注意，当statement只有一句时，可以省略花括号"{}"，否则必须加花括号


&emsp;
# 2 循环结构
&emsp;&emsp;循环结构有 while 循环、do-while循环和for循环。

## 2.1 while 循环
>while循环语句的格式是∶
```c++
while （表达式expressior） 语句statement
```

&emsp;&emsp;它的功能是当expression 的值为 true 时重复执行 statement。例如，下面将用 while 循环来写一个倒计数程序。

>示例，while循环结构的使用
```c++
#include <iostream>
using namespace std;
int main ()
{
    int n;
    cout << "Enter the starting number > ";
    cin >> n;
    while (n>0) {
        cout << n << ", ";
        --n;
    }
    cout << "FIRE!\n";
    return 0;
} 
```

&emsp;&emsp;我们必须提供一些方法使得条件可以在某个时刻变为False，否则循环将无限重复下去。在这个例子里，我们用语句-n;使得循环在重复一定的次数后变为 false; 当 n 变为 0时，倒计数结束。

&emsp;
## 2.2 do-while 循环 
>do-while 循环语句的格式是∶
```c++
do 语句statement while（条件condition）;
```

&emsp;&emsp;do-while 循环中是先执行 statement 然后才检查条件（condition），而不像while循环中先检查条件然后才执行 statement。这样，即使条件从来没有被满足过，statement 仍至少被执行一次。

&emsp;&emsp;例如，下面的程序重复输出用户输入的任何数值，直到用户输入0为止。

>示例，do-while的使用
```c++
#include <iostream>
using namespace std;
int main ()
{
    unsigned long n;
    do {
        cout << "Enter number (0 to end): ";
        cin >> n;
        cout << "You entered: " << n << "\n";
    } while (n != 0);
    return 0;
} 
```

&emsp;
## 2.3 for 循环 
>for 循环语句的格式是∶
```c++
for (initialization; condition; increase) statement;
```

按以下方式工作∶

（1）执行初始化initialization。通常是设置一个计数器变量（counter variable）的初始值，初始化仅被执行一次。    

（2）检查条件 condition，如果条件为真，就继续循环，否则循环结束，循环中的语句 statement被跳过。

（3）执行语句 statement。像以前一样，它可以是一个单独的语句，也可以是一个由花括号（{}）括起来的语句块。

（4）最后增值域（increase field）中的语句被执行，循环返回第2 步。

>示例3.12，for循环使用
```c++
#include <iostream>
using namespace std;
int main ()
{
    for (int n=10; n>0; n--) {
    cout << n << ", ";
    }
    cout << "FIRE!\n";
return 0;
} 
```

&emsp;&emsp;初始化 initialization 和增值 increase 域是可选的（可以为空）。但这些域为空的时候，它们和其他域之间间隔的分号不可以省略。例如，我们可以写for（;n<10;）来表示没有初始化和增值语句，或 for （;n<10;n++）来表示有增值语句但没有初始化语句。

&emsp;&emsp;另外，我们也可以在 for 循环初始化或增值域中放一条以上的语句，中间用逗号（，）隔开。例如，假设想在循环中初始化一个以上的变量，可以用以下程序来实现∶
```c++
for (n=0, i=100; n!=i; n++, i--)
{
    // whatever here...
}
```

&emsp;&emsp;如果 n和i在循环内部都不被改变，这个循环将被执行 50 次。



&emsp;
# 3 分支控制和跳转
## 3.1 break语句
&emsp;&emsp;通过使用break语句，即使在结束条件没有满足的情况下，我们也可以跳出一个循环。它可以被用来结束一个无限循环（infinite loop），或强迫循环在其自然结束之前结束。

>示例，break语句的使用：
```c++
#include <iostream>
using namespace std;

int main ()
{
    int n;
    for (n=10; n>0; n--)
    {
        cout << n << ", ";
        if (n==3)
        {
            cout << "countdown aborted!\n";
            break;
        }
    }
    return 0;
} 
```

## 3.2 continue语句
&emsp;&emsp;continue语句使得程序跳过当前循环中剩下的部分而直接进入下一次循环。
>示例，continue语句的使用：
```c++
#include <iostream>
using namespace std;

int main ()
{
    for (int n=10; n>0; n--) {
    if (n==5) continue;
    cout << n << ", ";
    }
    cout << "FIRE!\n";
    return 0;
} 
```

## 3.3 goto语句（了解）
&emsp;通过使用goto语句可以使程序从一点跳转到另一点。注意！必须谨慎使用这条语句，因为它的执行可以忽略任何嵌套限制！

&emsp;&emsp;跳转的目标点可以由一个标识符（label）来标明，该标识符作为goto语句的参数。一个标识符由一个标识名称后面跟一个冒号（:）组成。

&emsp;&emsp;通常除了底层程序爱好者使用这条语句外，他在结构化或面向对象编程中并不常用。

>示例，goto语句的使用：
```c++
#include <iostream>
using namespace std;

int main ()
{
    int n=10;
    loop:
        cout << n << ", ";
        n--;

    if (n>0) goto loop;
    cout << "FIRE!\n";
    return 0;
} 
```

&emsp;
# 4 选择结构

>switch 语句的形式∶
```c++
switch (expression)
{
    case constant1 :
        block of instructions 1
        break;
    case constant2 :
        block of instructions 2
        break;
        ...    
    default :
        default block of instructions
}
```

按以下方式执行：

（1）switch计算表达式（expression）的值，并检查ta是否与第一个常量constant1相等，如果相等，程序执行常量1后面的语句块block of instructions 1直到碰到关键字break，程序跳转到switch选择结构的结尾处。

（2）如果expression不等于constant1，程序检查表达式expression的值是否等于第二个常量constant2，如果相等，程序将执行常量2后面的语句块block of instructions 2直到碰到关键字break。

（3）以此类推，直到最后表达式expression的值不等于任何前面的常量（你可以用case语句指明任意数量的常量值来要求检查），程序将执行默认区default：后面的语句，如果它存在的话。default选项是可以省略的。

>示例
```cpp
#include <iostream>
using namespace std;
int main()
{
    char choice;
    cout << "Enter A, B, or C: ";
    cin >> choice;
    switch (choice)
    {
        case 'A' :
            cout<< "You entered A. \n";
            break;
        case 'B' :
            cout << "You entered B. \n";
            break;
        case 'C' :
            cout << "You entered C.\n";
            break;
        default:
            cout << "You did not enter A, B, or C!\n";
    }
    return 0;
}
```


>注意

&emsp;&emsp;switch只能被用来比较表达式和不同常量的值（constants）。因此，我们不能够把变量或范围放在case之后，例如：
```c++
case(n*2);
case(1...3);
```