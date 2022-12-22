# 枚举（enumerations）

- 枚举可以用来生成一些任意类型的数据
- 枚举数据类型在编译时是被编译为整型数值的，而它的数值列表可以是任何指定的整型常量。如果没有指定常量，没居中第一个列出的可能值为0，后面的每一个值为前面一个值加1
- 如果在定义枚举数据类型的时候明确指定某些可能值（例如第一个）的等价整数值，后面的数值将会再次基础上增加


>定义语法
```c++
enum model_name{
    value1,
    value2,
    value3,
    ...
    ...
}object_name;
```

注意：
- 这里没有使用任何基本数据类型
- model_name 是新的数据类型，没有基于任何已存在的数据类型
- 类型object_name，可以取花括号内任何一个值


>示例
```c++
#include <iostream>
using namespace std;

enum months_t{
        January = 1,
        February,
        March,
        April,
        May,
        June, 
        July,
        August,
        September,
        October,
        November,
        December
    }m;

enum weekday {Sun=7, Mon=1, Tue, Wed, Thu, Fri, Sat};

enum color_set {RED, BLUE, WHITE, BLACK}; 

int main()
{
    weekday w;
    color_set c;
    cout << m << endl;
    cout << w << endl;
    cout << c << endl;
    cout << endl;

    m = April;
    w = Wed;
    c = RED;

    cout << m << endl;
    cout << w << endl;
    cout << c << endl;

    return 0;
}
```




