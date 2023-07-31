
&emsp;
# 指针
- 存储其他变量地址的变量称为`指针（pointer）`
- 对程序来说，计算机内存只是一串连续的单字节单元（1byte cell），即最小数据单位，每一个单元有一个唯一地址

&emsp;
# 1 声明指针型变量
- 在声明指针的时候要指明它所指向的数据类型。指整型（int）或浮点型（float）数据的指针与指向一个字符型（char）数据的指针并不相同。

>指针的声明格式
```c++
type * pointer_name;
```
&emsp;&emsp;这里，type 是指针所指向的数据的类型，而不是指针自己的类型，例如∶ 
```c++
#include <iostream>
using namespace std;

int main()
{
    int* a;
    char* b;
    float* c;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;

    return 0;
}
```

&emsp;&emsp;它们是3个指针的声明，每一个指针指向不同的数据类型。这3个指针本身其实在内存中占用同样大小的内存空间（指针的大小取决于不同的操作系统），Linux64位操作系统是8字节。但它们所指向的数据是不同的类型，一个是整型（int），一个是字符型（char），还有一个是浮点型（float）。

&emsp;&emsp;需要强调的一点是:
- 声明时，星号（*）表示这里声明的是一个指针
- 使用时，星号（*）表示指针指向的值

&emsp;
>示例
```c++
#include <iostream>
using namespace std;
 
int main() {
    int value1 = 5, value2 = 15;
    int *p1, *p2;

    p1  = &value1; // p1 = address of value1
    p2  = &value2; // p2 = address of value2
    *p1 = 10;     // value pointed by p1 = 10
    *p2 = *p1;    // value pointed by p2 = value pointed by p1
    p1  = p2;      // p1 = p2 (value of pointer copied)
    *p1 = 20;     // value pointed by p1 = 20

    cout << "value1==" << value1 << "/ value2==" << value2<<endl;
    return 0;
}

```

&emsp;
# 2 操作符

## 2.1 & 操作符
在声明一个变量的同时，它必须被存储到内存中一个具体的单元中。我们并不会指定变量被存储到哪个具体的单元中，这通常是由编译器和操作系统自动完成的，一旦操作系统指定了一个地址，有时候我们可能会想知道变量被存储在哪里

操作符 & 表示 "...的地址"（address of），因此称为地址操作符（addressoperator），又称去引操作符（dereference operator）

>示例
```c++
#include <iostream>
using namespace std;

int main()
{
    int a = 25;
    int b = a;     // 将变量 a 的值赋给变量 b
    int *ptr = &a; // 把操作系统存储 a 的内存地址赋给 ptr
    cout << "Value of b: " << b << endl;
    cout << "Value of ptr: " << ptr << endl;
    cout << "Address of ptr: " << &ptr << endl;

    return 0;
}
```

&emsp;
## 2.2 * 操作符
&emsp;&emsp;使用星号（*）可以存储指针指向的变量所存储的数值，它可以被翻译为"所指向的数值"（value pointed by）。

>示例
```c++
#include <iostream>
using namespace std;

int main()
{
    int a = 25;
    int *ptr = &a;
    int b = *ptr; // Value pointed by ptr
    cout << "Value of ptr: " << ptr << endl;
    cout << "Value of b: " << b << endl;

    return 0;
}
```



&emsp;
# 3 指针的数学运算

- 对指针进行数学运算与其他整型数学运算不同:
    - 指针只有加法和减法运算，其他运算在指针的世界里没有意义
    - 指针的加法和减法的具体运算根据它`所指向的数据类型大小`的不同而有所不同。


- 不同的数据类型在内存中占用的存储空间是不一样的。例如，对于32位操作系统，整型数据，整型（int）占用4字节（1byte），双精度浮点型（double）占用8字节

- 当给指针加1时，实际上是指针指向下一个与它被定义的数据类型相同的元素。因此，它所指向的数据类型的长度字节数将会被加到指针的数值上，这一点对指针的加法和减法都适用。

>示例
```c++
#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    double b = 5.555;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << endl;

    int* p_a = &a;
    double* p_b = &b;
    cout << "Value of p_a: " << p_a << endl;
    cout << "Value of p_b: " << p_b << endl;
    cout << endl;

    p_a++;
    p_b++;
    cout << "Value of p_a: " << p_a << endl;
    cout << "Value of p_b: " << p_b << endl;

    return 0;
}
```


&emsp;
# 4 指针和数组

- 数组名相当于它的第一个元素的地址，就像一个指针，指向第一个元素的地址，因此其实它们是同一个东西。

&emsp;
>示例
```c++
#include <iostream>
using namespace std;

int main()
{
    int array[10];
    int* ptr = array; 
    
    cout << array     << endl;
    cout << &array[0] << endl;
    cout << ptr       << endl;
    return 0;
}
```

- ptr 只是一个普通的指针变量，array 是一个数组名，数组名的本质是一个`* const`。


&emsp;
>示例，指向数组的指针
```c++
#include <iostream>
using namespace std;
int main() {
    int numbers[5];
    int * p;
    p = numbers; // p指向数组numbers的第一个元素位置
    *p = 10;     // 对numbers的第一个元素进行赋值
    p++;         // 指针offset + 1，即numbers[1]
    *p = 20;     // numbers[1] = 20
    p = &numbers[2];  // 此时指针指向nubmers[2]
    *p = 30;          // numbers[2] = 30
    p = numbers + 3;  // numbers其实本身就是指针，相当于numbers[0]，numbers + 3相当于numbers[3]
    *p = 40;          // numbers[3] = 4
    p = numbers;      // 又回到最初的起点
    *(p + 4) = 50;    // numbers[4] = 50
    for (int n = 0; n < 5; n++)     // 遍历打印输出
        cout << numbers[n] << ", ";
    cout << endl;
    return 0;
}
```
- 在数组中使用中括号 `[]` 来指索引（index）。中括号 `[]` 也叫位移（offset）操作符，它相当于在指针中的地址上加上括号中的数字。

&emsp;
>示例
```c++
#include <iostream>
using namespace std;

int main()
{
    int array[10];
    array[5] = 555;     // a[offset of 5] = 0;
    *(array + 6) = 666; // value pointed by (a+5) = 0;
    
    cout << array[5] << endl;
    cout << *(array + 6) << endl;
    
    return 0;
}
```



&emsp;
# 5 指针的指针（二级指针）

声明时，两个星号（**）代表指针的指针∶
>示例
```cpp
#include <iostream>
using namespace std;

int main()
{
    int a = 5, b = 10, c = 15;

    int* ptr1  = &a;
    int** ptr2 = &ptr1; // ptr2 是二级指针
    // int** ptr3 = &b; // 报错，必须存的是指针的地址
    return 0;
}
```


&emsp;&emsp;
# 6 指针常量和常量指针
Read it backwards (as driven by Clockwise/Spiral Rule):

- `int* (ptr)` - pointer to int
- `int const * (ptr)` - pointer to const int
- `int * const (ptr)` - const pointer to int
- `int const * const (ptr)` - const pointer to const int

Now the first `const` can be on either side of the type so:

- `const int * (ptr)` == `int const * (ptr)`
- `const int * const (ptr)` == `int const * const (ptr)`

If you want to go really crazy you can do things like this:

- `int * (ptr) * (ptr)` - pointer to (pointer to int)
- `int * (ptr) * const (ptr)` - a const pointer to (a pointer to an int)
- `int * const (ptr) * (ptr)` - a pointer to (a const pointer to an int)
- `int const * (ptr) * (ptr)` - a pointer to (a pointer to a const int)
- `int * const * (ptr) const (ptr)` - a const pointer to (a const pointer to an int)
- ...


And to make sure we are clear on the meaning of `const`:

>示例
```c++
#include <iostream>
using namespace std;

int main()
{
    int a = 5, b = 10, c = 15;

    // ============ type* ptr ============
    int* ptr1 = &a;
    ptr1 = &b;   // value of pointer 可以改
    *ptr1 = 111; // value pointed by 可以改

    // ============ type const* ptr ============
    const int* ptr2 = &a;
    ptr2 = &b;      // value of pointer 可以改
    // *ptr2 = 222; // value pointed by 不可以改

    // ============ type * const ptr ============
    int* const ptr3 = &a;
    // ptr3 = &c;  // value of pointer 不可以改
    *ptr3 = 333;   // value pointed by 可以改

    // ============ type const * const ptr ============
    int const * const ptr4 = &a;
    // ptr3 = &c;   // value of pointer 不可以改
    // *ptr4 = 444; // value pointed by 不可以改

    cout << ptr1 << endl;
    cout << *ptr1 << endl;
    return 0;
}        
```


`foo` is a variable pointer to a constant integer. This lets you change what you point to but not the value that you point to. Most often this is seen with C-style strings where you have a pointer to a `const char`. You may change which string you point to but you can't change the content of these strings. This is important when the string itself is in the data segment of a program and shouldn't be changed.

`bar` is a constant or fixed pointer to a value that can be changed. This is like a reference without the extra syntactic sugar. Because of this fact, usually you would use a reference where you would use a `T* const` pointer unless you need to allow NULL pointers.






&emsp;
# 7 空指针
- void *是一种指针类型
- 常用在函数参数、函数返回值中需要兼容不同指针类型的地方
- 可以将别的类型的指针无需强制类型转换的赋值给void *类型
- 可以将void *强制类型转换成任何别的指针类型，至于强转的类型是否合理，就需要我们程序员自己控制了。

>示例，空指针实例
```c++
#include <iostream>
using namespace std;

int main()
{
    int a    = 2;
    double b = 2.0;

    void* ptr1;  //定义 void*
    cout << sizeof(ptr1) << endl;
    cout << ptr1 << endl;

    int* ptr2 = (int*) ptr1;
    float* ptr3 = (float*) ptr1;

    return 0;
}
```






&emsp;
# 8 函数指针


&emsp;&emsp;C++ 允许对指向函数的指针进行操作。它最大的作用是把一个函数作为参数传通给另一个函数。声明一个函数指针像声明一个函数原型一样，除了函数的名字需要被括在括号内并在前面加星号（*）。

>声明函数指针
```c++
type(* name)(type, type, ...)
```

>示例，函数指针的例子
```c++
#include <iostream>
using namespace std;
int addition(int a, int b) {
    return (a + b);
}

int subtraction(int a, int b) {
    return (a - b);
}
int(*myfunc)(int, int)  = subtraction;

int operation(int x, int y, int(*functocall)(int, int)) {
    int g;
    g = (*functocall)(x, y);
    return (g);
}

int main() {
    int m, n;
    m = operation(7, 5, addition);
    n = operation(20, m, myfunc);
    cout << n << endl;
    return 0;
}
```

&emsp;&emsp;在这个例子里，myfunc 是一个全局指针，指向一个有两个整型参数的函数，它被赋值指向函数 subtraction，这些由一行代码实现∶
```c++
int(* myfunc)(int, int) = sbustraction;
```
&emsp;&emsp;为什么（int int）只有类型，没有参数? 这里 int（*myfunc）（int int）实际是在定义一个指针变量，这个指针的名字叫作 myfunc，这个指针的类型指向subtraction，函数的类型有两个整型参数并返回一个整型值。也就是说有了这个定义后，myfunc 就代表函数 subtraction。因此，括号中的两个int 实际上只是一种变量类型的声明，也就是说是一种形式参数，而不是实际参数。

