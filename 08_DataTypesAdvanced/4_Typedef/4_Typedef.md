
# 定义自己的数据类型

&emsp;&emsp;
# 1 typedef
&emsp;&emsp;C++可以在现有数据类型的基础上定义自己的数据类型。我们将用关键字typedef来实现这种定义，它的形式是：
```c++
typedef existing_type new_type_name;
```
- existing_type是C++基本数据类型或其它已经被定义了的数据类型
- new_type_name是我们将要定义的新数据类型的名称

>示例
```c++
#include <iostream>
using namespace std;

int main()
{
    typedef char C;
    typedef unsigned int WORD;
    typedef char* string_t;
    typedef char field[50];
    typedef int ListElem_t;

    C c1, c2, *p_c;
    WORD w1, w2, *w3;
    string_t s1;
    field name;
    ListElem_t e1;
    
    return 0;
}
```

>示例，typedef与struct结合使用

```c++
#include <stdio.h>

int main()
{
    typedef struct student
    {
        char name[50];
        char dept[50];
        long no;
        float score[4];
    }stu_t;

    // typedef student stu_t;

    stu_t stu1 = {"Tom", "Math", 20090001, 87.5, 70.5, 93, 91};
    stu_t *p;
    p = &stu1;
    p->no = 2009005;

    printf("%8s %8s %ld %5.2f %5.2f %5.2f %5.2f\n",
                stu1.name, //引用结构体数组元素的成员
                stu1.dept, 
                stu1.no, 
                stu1.score[0], //成员是数组，引用其中元素
                stu1.score[1], 
                stu1.score[2], 
                stu1.score[3]);

    return 0;
}
```

&emsp;
# 2 typedef在C与C++中的区别
## 2.1 在C语言中
（1）在C中定义一个结构体类型时如果要用typedef:
```c
typedef struct Student
{
   int no;
   char name[12];
}Stu,student; // Stu student 是 Student 的别名
```
于是在声明变量的时候就可：
```c
Stu stu1;     // 或者：
student stu2; // Stu 和student 同时为Student的别名)
```

（2）如果没有typedef即：
```c
struct Student
{
   int no;
   char name[12];
}Stu;
```

&emsp;&emsp;就必须用
```c++
struct Student stu1; // 或者

// 而C++可以直接
Student stu1;
Student stu1;
```

&emsp;
## 2.2 在C++语言中
>示例
```c++
struct Student
{
   int no;
   char name[12];
}stu1;//stu1是一个实例

typedef struct Student2
{
   int no;
   char name[12];
}stu2;//stu2 是 Student2的别名
```

```c
stu1.no  // stu1使用时可以直接访问 

stu2 s2; //但是stu2则必须先定义才能访问
s2.no=10;
```

&emsp;
# 总结（struct 和 typedef 的结合使用）

## C/C++ 共同点
- 不加 typedef 关键字，结构体后的内容表示一个实例化的对象
- 加 typedef 关键字，结构体后的内容表示这个结构体的别名

## C/C++ 区别
- 不加typedef 关键字情况下，C语言声明一个结构体变量必须加 struct 关键字，而在C++中则可以直接使用结构体的名称去声明结构体变量。
