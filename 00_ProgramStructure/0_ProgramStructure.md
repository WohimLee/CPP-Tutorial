# 1 程序结构

```c++
// first program in C++
#include <iostream>
using namespace std;

int main()
{
    cout << "hello, world\n";
    return 0;
}
```

- **注释**      
&emsp;&emsp;"//"用来写注释

- **头文件**    
&emsp;&emsp;以#标志开始的句子是预处理器的指示语句。它们不是可执行代码，只是对编译器做出指示。#include<iostream>告诉编译器的预处理器将输入输出流的标准头文件（iostream）包括在本程序中。这个头文件包括 C++中定义的标准输入输出程序库的声明。此处它被包括进来是因为在本程序的后面将用到它的功能。
- **命名空间**      
&emsp;&emsp;C++标准函数库的所有元素都被声明在一个命名空间中，这就是 std 命名空间。为了能够访问它的功能，我们用这条语句来表达将使用标准命名空间中定义的元素。
- **main函数**    
&emsp;&emsp;这一行是主函数（main function）的起始声明。main function 是所有C++程序运行的起始点。不管它是在代码的开头、结尾还是中间，此函数中的代码总是在程序开始运行时第一个被执行的。

&emsp;
# 2 main函数的参数
&emsp;&emsp;main（）函数有两个参数，它的形式是∶
``` 
main(int argc, char *argv[])
```
- argc 的数据类型为整型，用于记录运行参数的个数
- argv 的数据类型为字符型指针数组，用于保存运行参数 

&emsp;&emsp;有些程序在终端运行时，输入完程序文件名后可加上一些额外的运行参数，main()函数的参数即是用来向程序传递这些运行参数的入口。所输入的程序名也是运行参数，所以不输入其他运行参数的情况下，也会被捕获到一个运行参数。

```c++
#include <stdio.h>

int main(int argc, char *argv[]) //定义主函数参数
{
    int i;   //声明循环控制变量
    printf("您输入的运行参数共有∶%d条\n", argc); //输出参数的条数 
    for(i = 0 ; i < argc; i++)  //以参数的条数为条件循环
        printf("%s\n", argv[i]);          //输出每条参数
    return 0;
}
```
