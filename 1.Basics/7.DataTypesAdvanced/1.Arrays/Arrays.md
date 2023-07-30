
&emsp;
# 数组（Arrays）

- 数组（Arrays）在内存中是连续存储的
- 数组中的元素必须是同一数据类型。

>数组声明格式 
```c++
type name[num];
```
- type：可以是任何一种有效的对象数据类型（object type），如 int、float等
- name：是一个有效的变量标识（identifier）
- num：元素个数，告诉编译器要给该数组分配多少内存空间。

>例如: 定义一个叫做billy存储5个整数的数组
```c++
int billy[5];
```


&emsp;
# 1 初始化数组
- 未初始化的数组内容是不确定的
- 如果声明一个全局数组（在所有函数之外），它的内容将被初始化为0
- 可以用花括号（{}）在声明数组时初始化

&emsp;
>示例
```c++
#include <iostream>
using namespace std;

int main()
{
    int a[5];
    int b[6] = {111, 22, 33};
    int c[] = {5, 6, 7, 8};

    cout << a[0] << endl;

    return 0;
}
```


&emsp;
# 2 存取数组中的值

读取和修改数组任一元素的数值，格式如下∶
```c++
name[index] 
```

>示例

```c++
#include <iostream>
using namespace std;

int main()
{
    int a[5];
    a[0] = 111;
    a[1] = 222;
    cout << a[3] << endl;

    return 0;
}
```




&emsp;
# 3 多维数组

>多维数组的声明
```cpp
type array[dim1][dim2][...]
```
- 多维数组只是一个抽象的概念，因为我们只需要把各个索引的乘积放入一个简单的数组中就可以获得同样的结果

>示例 1
```c++
#include <iostream>
using namespace std;

int main()
{
    // 数组维度：dim[d1][d2][d3]
    // 数组索引：index[x][y][z] = index[x*(d2*d3) + y*(d2) + d3]

    int a[3][2][2] = {0,1,2,3,4,5,6,7,8,9,10,11};
    cout << a[2][1][1] << endl; // 相当于索引 11 = 2*(2*2) + 1*1 + 1
    return 0;
}
```
>示例 2
```cpp
#include <iostream>
using namespace std;

int main()
{
    int a[3][2][2] = {0,1,2,3,4,5,6,7,8,9,10,11};
    cout << a[0] << endl;
    cout << a[1] << endl; // 偏移16个字节，也就是第1块开始的位置

    cout << a[0][0] << endl;
    cout << a[0][1] << endl; // 偏移 8 个字节，也就是每行开始的位置

    // 多维数组的索引是每个维度对应的首地址，偏移量是后面维度的乘积
    // 想按单个元素索引，需要将其转成 int* (4个字节偏移量)
    int* p = (int*)a;     
    cout << p[0] << endl;
    cout << p[10] << endl;

    return 0;
}
```



![](imgs/array.png)


&emsp;
# 4 数组传参
数组作为参数传给函数，将整块内存中的数值传递给函数是不可能的，但是允许传递它的地址，而且传递地址更快速有效。

>定义数组作为参数
```c++
type func(type array[]);
```
>数组参数调用方式
```c++
func(array);
```

>示例，把数组作为参数
```c++
#include <iostream>
using namespace std;
void printArray1(int* arr, int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void printArray2(int array[], int len) {
    for (int n = 0; n < len; n++) {
        cout << array[n] << " ";
    }
    cout << "\n";
}

int main() {
    int a[] = {5, 10, 15 };
    int b[] = {2, 4, 6, 8, 10};
    printArray1(a, 3);
    printArray2(b, 5);

    return 0;
}
```



&emsp;
# 5 字符数组
- 字符数组也叫字符序列，每个元素存放的是字符∶
>字符数组的声明
``` c++
char array[N];
```

&emsp;&emsp;系统会在字符串的有效内容的结尾处加一个 \0 空字符（null character）来表示字符结束，没有\0会一直打印后面的字符。




&emsp;
## 5.1 字符数组的初始化


>示例

```cpp
#include <iostream>
using namespace std;

int main() {
    char string1[] = {'H', 'e','l','l','o','\0'};
    char string2[] = {'H', 'e','l','l','o'};
    char string3[] = "Hello"; // 字符串常量初始化，自动加 \0
    cout << string1[5] << endl;
    cout << string2[5] << endl;
    cout << string3[5] << endl;
    cout << string1 << endl;
    cout << string2 << endl; // 没有结束符，会一直打印内存后面接着的char 
    cout << string3 << endl;

    return 0;
}
```


&emsp;
## 5.2 字符数组赋值
- 通常给字符序列赋值的方法是使用一些函数，例如 strcpy。strcpy（string copy）在函数库cstring（string.h）中被定义

>示例
```c++
#include <string.h>
#include <stdio.h>

int main() {

    char str1[10];
    char str2[20];
    str1[0] = 'H';
    str1[1] = 'e';
    str1[2] = 'l';
    str1[3] = 'l';
    str1[4] = 'o';
    str1[5] = '\0';
    strcpy(str2, "AAAA");

    printf("%s\n", str1);
    printf("%s\n", str2);
    return 0;
} 
```


通常 cin 与函数 getline 会一起使用给数组赋值
```c++
cin.getline(char buffer[], int length, char delimiter = '\n');
```

- buffer 用来存储输入的地址（例如一个数组名）
- length 是缓存 buffer 的最大容量
- delimiter 是用来判断用户输入结束的字符，它的默认值是换行符（'\n'）

>示例，通过cin输入字符数组
```c++
#include <iostream>
using namespace std;
 
int main() {
    char mybuffer[100];
    cout << "What's your name? ";
    cin.getline(mybuffer, 100);
    cout << "Hello " << mybuffer << ".\n";
    cout << "Which is your favourite team? ";
    cin.getline(mybuffer, 100);
    cout << "I like " << mybuffer << " too.\n";
    return 0;
}
```

注意，上面的例子中两次调用cin.getline时，我们都使用了同一个字符串标识（mybuffer）。程序在第二次调用时，新输入的内容将直接覆盖第一次输入 buffer 中的内容。

">>"符号可以直接从标准输入设备接收数据，也可以被用来输入字符串，例如，在上面的例子中，我们也可以用以下代码来读取用户输入∶
```c++
cin >> mybuffer;
```

但这种方法有以下局限性是 cin.getline 所没有的∶
- 它只能接收单独的词（而不能是完整的句子），因为这种方法以任何空白符为分隔符，包括空格（spaces）、跳跃符（tabulators）、换行符（newlines）和回车符（arriage returns）
- 它不能给 buffer 指定容量，这使得程序不稳定，如果用户输入超出数组长度，输入信息就会丢失。

所以建议在需要用 cin 来输入字符串时，使用 cin.getline 来代替 cin >>。




&emsp;
# 8 字符串和其它数据类型的转换

&emsp;&emsp;如果一个字符串的内容是"1977"，这 5 个字符组成的序列并不容易转换为一个单独的整数。因此，函数库 cstdlib（stdlib.h）提供了以下 3个有用的函数。
```c++
atoi∶ 将字符串（string）转换为整型（int）
atol∶ 将字符串（string）转换为长整型（long）
atof: 将字符串（string）转换为浮点型（float）
```
&emsp;&emsp;这 3 个函数接收一个参数，返回一个指定类型的数据（int、long 或 float）。这 3 个函数与 cin.getline 一起使用来获得用户输入的数值，比传统的 cin>> 方法更可靠。

>示例，字符串转换
```c++
#include <iostream>
using namespace std;
 
#include <stdlib.h>

int main() {
    char mybuffer[100];
    float price;
    int quantity;
    cout << "Enter price: ";
    cin.getline(mybuffer, 100);
    price = atof(mybuffer);
    cout << "Enter quantity: ";
    cin.getline(mybuffer, 100);
    quantity = atoi(mybuffer);
    cout << "Total price: " << price*quantity;
    return 0;
}

```

