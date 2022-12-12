
&emsp;
#  随机数

>头文件
```c++
#include <random>
```
- 在新标准出现之前，C 和 C++ 都依赖于一个简单的 C 库函数rand() 来生成随机数
- 此函数生成均匀分布的伪随机整数，每个随机数的范围在0和一个系统相关的最大值（至少为32767）之间

&emsp;
>rand() 函数的问题

- 有很多程序需要不同范围的随机数。一些应用需要随机浮点数。一些程序需要非均匀分布的数。而程序员为了解决这些问题而试图转换 rand生成的随机数的范围、类型或分布时，常常会引入非随机性。




&emsp;
>随机数库的组成

|||
:---|:---|
随机数引擎类（random-number engines） | 生成随机 unsigned 整数序列|
随机数分布类（random-number distribution） | 使用引擎返回服从特定概率分布的随机数|
|||

- 一个引擎类可以生成 unsigned 随机数序列
- 一个分布类使用一个引擎类生成指定类型的、在给定范围内的、服从特定概率分布的随机数。
- C++程序不应该使用库函数 rand，而应使用 default_random_engine 类

&emsp;
## 2.1 随机数引擎和分布
- 随机数引擎是函数对象类
- 随机数引擎定义了一个调用运算符，该运算符不接受参数并返回一个随机 unsigned 整数
- 标准库定义了多个随机数引擎类，区别在于性能和随机性质量不同。每个编译器都会指定其中一个作为 default_random_engine类型。此类型一般具有最常用的特性。

&emsp;
>随机数引擎操作
<table>
    <tr>
        <td>Engine e;</td>
        <td>默认构造函数∶使用该引擎类型默认的种子</td>
    </tr>
    <tr>
        <td>Engine e(s);</td>
        <td>使用整型值 s 作为种子</td>
    </tr>
    <tr>
        <td>e.seed(3)</td>
        <td>使用种子s 重置引擎的状态</td>
    </tr>
    <tr>
        <td>e.min()</td>
        <td rowspan = "2">此引擎可生成的最小值和最大值</td>
    </tr>
    <tr>
        <td>e.max()</td>
    </tr>
    <tr>
        <td>Engine::result_type</td>
        <td>此引擎生成的 unsigned 整型类型</td>
    </tr>
    <tr>
        <td>e.discard(u)</td>
        <td>将引擎推进u步∶u 的类型为 unsigned long long</td>
    </tr>
</table>



&emsp;
>示例
```c++
#include <random>
#include <iostream>
using namespace std;

int main()
{
    default_random_engine e; //生成随机无符号数
    for (int i = 0; i < 10; ++i)
    // e() "调用"对象来生成下一个随机数
        cout << e() << " ";
    cout << endl;
    return 0;
}
```


&emsp;
## 2.2 分布类型和引擎
- 为了得到在一个指定范围内的数，我们使用一个分布类型的对象
- 分布类型也是函数对象类
- 分布类型定义了一个调用运算符，它接受一个随机数引擎作为参数
- 分布对象使用它的引擎参数生成随机数，并将其映射到指定的分布
- 当我们说随机数发生器时，是指分布对象和引擎对象的组合

&emsp;
>示例
```c++
#include <random>
#include <iostream>
using namespace std;

int main()
{
    // 生成 0~9(包含) 之间均匀分布的随机数
    uniform_int_distribution<unsigned> u(0, 9);
    default_random_engine e; // 生成无符号随机整数
    for (int i = 0; i < 10; ++i)
        cout << u(e) << " ";
    cout << endl;
    return 0;
}
```

- 此处我们将 u 定义为uniform_int_distribution<unsigned>
- 此类型生成均匀分布的 unsigned 值
- 当我们定义一个这种类型的对象时，可以提供想要的最小值和最大值
- 在此程序中，u(0，9) 表示我们希望得到 0 到 9 之间（包含）的数

&emsp;
>注意
- 我们传递给分布对象的是引擎对象本身，即 u(e)
- 如果我们将调用写成u(e())，含义就变为将e生成的下一个值传递给 u, 会导致一个编译错误。






