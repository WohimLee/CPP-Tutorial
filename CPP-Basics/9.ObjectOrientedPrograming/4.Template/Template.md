# 模板（Template）
&emsp;&emsp;模板（Templates）是ANSI-C++标准中新引入的概念。如果你使用的C++编译器不符合这个标准，那么很可能不能使用模板。


&emsp;
# 1 函数模板


&emsp;&emsp;函数使用模板可以生成通用函数，这些函数能够接收任意数据类型的采纳数，可返回任意类型的值，而不需要对所有可能的数据类型进行函数重载。

>模板的定义
```c++
template <class identifier> function_declaration;
template <typename identifier> function_declaration;
```
&emsp;&emsp;用一个类型pattern来调用一个模板的方法如下：
```c++
function <type> (parameters);
```

&emsp;&emsp;关键字 `class` 或 `typename` 实际是完全等价的，表达的意思和执行都一模一样。


>示例，第一个函数模板例子：
```c++
#include <iostream>
using namespace std;

// (1) 第一种写法
template <class T> T GetMax(T a, T b)
{
    T res; // 在模板函数GetMax()里，类型T可以被用来声明新的对象
    res = a > b ? a : b;
    return res;
}
// (2) 第二种写法
template <typename MyType> 
MyType GetMin(MyType a, MyType b)
{
    MyType res;
    res = a < b ? a : b;
    return res;
}

int main()
{
    int i = 5, j = 6;
    long l = 13, m = 3;

    int res1 = GetMax(i, j);       // 省略类型声明
    int res2 = GetMin<long>(l, m); // 写类型声明

    cout << res1 << endl;
    cout << res2 << endl;
    return 0;
}
```
- res是一个T类型的对象，这种类型就是当我们调用模板函数时，写在尖括号（<>）中的类型。
- 通用类型T被用作函数GetMax的参数，不需要说明\<int>或\<long>，编译器也可以自动检测到传入的数据类型
- 模板函数只包括一种数据类型（class T），而且它的两个参数都是同一种类型，所以不能够用两个不同类型的参数来调用它：
> 错误示范
```c++
int i;
long l;
k = GetMax(i, l);
```
&emsp;&emsp;我们其实可以使得模板函数接收两种或两种以上的类型的数据，例如：
>示例
```c++
#include <iostream>
using namespace std;

template <class T, class U>
T GetMax(T a, U b)
{
    return a > b ? a : b;
}

int main()
{
    int a = 10;
    float b = 5.4;
    cout << GetMax<int, float>(a, b) << endl;
    cout << GetMax(a, b) << endl;

    return 0;
}
```



&emsp;
# 2 类模板
>类模板的神明
```c++
template <class T>
class Pair{
    T values[2];
public:
    Pair(T a, T b){
        values[0] = a;
        values[1] = b;
    }    
};
```
>类模板的调用
```c++
// 注意类模板调用一定要指定数据类型
Pair<int> myobject (115, 36);
Pair<float> myfloats (3.0, 2.18); 
```

在上面的例子中，类的唯一一个成员函数已经被 inline 定义。如果我们要在类之外定义它的一个成员函数，就必须在每一个函数前面加
```c++
template<...>
```

>示例1: 类模板的例子
```c++
#include <iostream>
using namespace std;

template <class T1>
class Student
{
    T1 score[3];
    public :
        Student(T1 a, T1 b, T1 c);
        T1 getAverage();

        template <typename T2>
        void showinfo(T2 index);
};

// (1) 构造函数
template <class T1>
Student<T1>::Student(T1 a, T1 b, T1 c)
{
    score[0] = a;
    score[1] = b;
    score[2] = c;
}

// (2) 成员函数
template <class T1>
T1 Student<T1>::getAverage()
{
    T1 temp;
    temp = score[0] + score[1] + score[2];
    return temp / 3;
}

// (3) 模板函数
template<class T1>
template<typename T2>
void Student<T1>::showinfo(T2 index)
{
    cout << score[index] << endl;
}

int main()
{
    Student<float> s(68.5, 85.4, 90.0);
    s.showinfo(0);
    s.showinfo(1);
    s.showinfo(2);

    cout << "The average: " << s.getAverage() << endl;

    return 0;
}
```
所有写T的地方都是必须的，每次定义模板类的成员函数的时候，都需要遵循类似的格式（这里第二个T表示函数返回值的类型，这个根据需要可能会有变化）。

>示例 2：const 与类模板
- 注意 const 和 typename 在类内和类外的位置
```c++
template<class T> class Vector
{
public:
    Vector();

    class iterator;

	iterator begin();
	const iterator begin() const;
};


template<class T>
inline typename Vector<T>::iterator Vector<T>::begin()
{	
	return Vector<T>::iterator(&_elements[0]);
}

template<class T>
inline const typename Vector<T>::iterator Vector<T>::begin() const
{
	return Vector<T>::iterator(&_elements[0]);
}
```

&emsp;
# 3 模板的参数值

除了模板参数前面跟关键字class或typename表示一个通用类型外，函数模板和类模板还可以包含其它不是代表一个类型的参数，例如代表一个常数，这些通常是基本数据类型的。下面的例子定义了一个用来存储数组的类模板。

>示例，模板的参数值的例子
```c++
#include <iostream>
using namespace std;

template <class T, int N>
class Array
{
    T memblock[N];
    public :
        void setmember(int x, T value);
        T getmember(int x);
};

template <class T, int N>
void Array<T, N>::setmember(int x, T value)
{
    memblock[x] = value;
}

template <class T, int N>
T Array<T, N>::getmember(int x)
{
    return memblock[x];
}

int main()
{
    Array <int, 5> myints;
    Array <float, 5> myfloats;
    myints.setmember(0, 100);
    myfloats.setmember(3, 3.14159);

    cout << myints.getmember(0) << '\n';
    cout << myfloats.getmember(3) << '\n';
    return 0;
}
```




&emsp;
# 4 模板与多文件工程
- 模板在需要时才被编译（compiled on demand），也即是说一个模板的代码直到需要生成一个对象的时候（instantiation）才被编译

- 模板类大工程，通常接口类（interface）和实现类（implementation）是分开的：
    - 接口类（interface）：纯虚类，给实现类继承，只暴露对用户有用的函数接口，写在`.h头文件`中，#include 只包含本文件内需要的库，通常不用 using namespace, 在底部 #include "xxx.cpp" 实现文件
    - 实现类（implementation）：继承自接口类，写在 `.cpp原程序文件` 中，可以用 using namespace

- 如果我们想要建立一个函数模板的库，不能再使用头文件（.h），取而代之，应该生成一个模板文件（template file），将函数模板的接口和实现都放在这个文件中（这种文件没惯用扩展名，处理不要使用.h扩展名或不要不加任何扩展名）。
- 在一个工程中，多次包含同时具有声明和实现的模板文件并不会产生链接错误（linkage errors），因为它们只有在需要时才会被编译，二兼容模板的编译器应该已经考虑到这种情况，不会生成重复的代码。