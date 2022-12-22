
&emsp;
# 1 shared_ptr
C++的动态内存的管理是通过一对运算符来完成的
- new，为对象分配空间并返回一个指向该对象的指针，我们可以选择对对象进行初始化
- delete，接受一个动态对象的指针，销毁该对象，并释放与之关联的内存。

动态内存的使用很容易出问题，因为确保在正确的时间释放内存是极其困难的。有时我们会忘记释放内存，在这种情况下就会产生内存泄漏;有时在尚有指针引用内存的情况下我们就释放了它，在这种情况下就会产生引用非法内存的指针。

为了更容易（同时也更安全）地使用动态内存，新的标准库提供了两种智能指针（smart pointer）类型来管理动态对象。
- shared_ptr：允许多个指针指向同一个对象
- unique_ptr：则"独占"所指向的对象
- weak_ptr：一种弱引用，指向 shared ptr所管理的对象

&emsp;
>头文件
```c++
#include <memory>
```
- 智能指针的行为类似常规指针
- 重要的区别是它负责自动释放所指向的对象


&emsp;
## 1.1 shared_ptr 类

- 智能指针也是模板类
- 创建一个智能指针时，指定指针可以指向的类型
- 指定类型在 `<>` 内给出类型，之后是智能指针的名字
- 默认初始化的智能指针中保存着一个空指针

>声明格式
```c++
std::shared_ptr<数据类型>
```

>示例1: shared_ptr 声明
```c++
#include <memory>
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

int main()
{
    shared_ptr<string> p1;        // 指向 string
    shared_ptr<list<int>> p2;     // 指向 int 的 list
    shared_ptr<vector<float>> p3; // 指向 float 的 vector
}
```
>示例2
```c++
class Config
{
    private:
        static std::shared_ptr<Config> mConfig;
        cv::FileStorage mFile;

        Config(){}
    public:
        ~Config();

        static void setParameterFile(const std::string& filename);
        template<typename T>
        static T get(const std::string& key);
};


```

- 智能指针的使用方式与普通指针类似。解引用一个智能指针返回它指向的对象
- 如果在一个条件判断中使用智能指针，效果就是检测它是否为空
```c++
#include <memory>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    shared_ptr<string> p1; 
    cout << p1 << endl;
    if (p1 && p1->empty()) // 判断不成立，因为是初始化是空指针
        *p1 = "aaa";

    return 0;
}
```
 

&emsp;
>shared_ptr和 unique_ptr 都支持的操作

|||
:---|:---
shared_ptr\<T> sp | 空智能指针，可以指向类型为T的对象
unique_ptr\<T> up | 空智能指针，可以指向类型为T的对象
p | 将p用作一个条件判断，若p指向一个对象，则为true
*p | 解引用 p，获得它指向的对象
p->mem | 等价于(*p).mem
p.get() | 返回p中保存的指针。要小心使用，若智能指针释放了其对象，返p.get()回的指针所指向的对象也就消失了
swap(p, q) | 交换 p 和 q 中的指针
p.swap(q) | 交换 p 和 q 中的指针
|||

&emsp;
>shared_ptr 独有的操作

|||
|:---|:---
make_shared\<T>(args) | 返回一个 shared_ptr，指向一个动态分配的类型为T的对象。使用 args 初始化此对象
shared_ptr\<T>p(q) | p 是 shared ptr q的拷贝;此操作会递增 q 中的计数器。q 中的指针必须能转换为T*
p = q | p和q都是 shared_ptr，所保存的指针必须能相互转换。此操作会递减 p 的引用计数，递增 q 的引用计数;若p的引用计数变为0，则将其管理的原内存释放
p.unique()| 若p.use_count（）为1，返回true;否则返回false
p.use_count() | 返回与p共享对象的智能指针数量;可能很慢，主要用于调试
|||



&emsp;
## 1.2 make_shared 函数
- 最安全的分配和使用动态内存的方法是调用一个名为 make_shared 的标准库函数
- 此函数在动态内存中分配一个对象并初始化它，返回指向此对象的 shared_ptr
- make_shared 也定义在头文件 memory 中
- 使用 make_shared，必须指定对象的类型。
- 定义方式与模板类相同，在函数名之后跟一个尖括号，在其中给出类型
- make_shared 用参数来构造给定类型的对象。例如，调用make_shared<string>时传递的参数必须与string 的某个构造函数相匹配
- 如果我们不传递任何参数，对象就会进行值初始化

&emsp;
>示例
```c++
#include <memory>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // shared_ptr<int> p1 = make_shared<int>();
    // shared_ptr<string> p2 = make_shared<string>("Test");
    // shared_ptr<vector<int>> p3 = make_shared<vector<int>>(10);

    // 用 auto ptr 接收 make_shared 的结果，这种方式较为简单
    auto p1 = make_shared<int>();
    auto p2 = make_shared<string>("Test");
    auto p3 = make_shared<vector<int>>(10);

    cout << *p1 << endl;
    cout << *p2 << endl;
    cout << p3->capacity() << endl;
    return 0;
}
```


&emsp;
## 1.3 shared_ptr的拷贝和赋值

&emsp;
>示例
```c++
#include <memory>
#include <iostream>
using namespace std;

int main()
{
    auto p1 = make_shared<int>(42); 
 
    auto p2(p1);  // 拷贝
    auto p3 = p1; // 赋值

    cout << *p1 << endl;
    cout << *p2 << endl;
    cout << *p3 << endl;

    return 0;
}
```


&emsp;
## 1.4 shared_ptr 计数器的递增递减
- 当进行拷贝或赋值操作时，每个 shared_ptr 都会记录有多少个其他 shared_ptr 指向相同的对象
- 每个 shared ptr 都有一个关联的计数器，通常称其为引用计数（reference count）
- 计数器递增
    - 拷贝一个 shared_ptr
    - 用一个 shared_ptr 初始化另一个 shared_ptr
    - 将 shared_ptr 作为参数传递给一个函数以及作为函数的返回值时
- 计数器递减
    - 给 shared_ptr赋予一个新值
    - shared_ptr 被销毁（例如一个局部的shared_ptr 离开其作用域）
- 一旦一个 shared_ptr的计数器变为 0，它就会自动释放自己所管理的对象

&emsp;
>示例 1
```c++
#include <memory>
#include <iostream>
using namespace std;

int main()
{
    auto p = make_shared<int>(42); // 只有 p 指向这份 "42" 的数据
    cout << p.use_count() << endl;

    // q 也指向了 "42" 的数据，共有2个 shared_ptr 指向这份数据
    auto q(p);  

    cout << q.use_count() << endl;  // q 的计数器记录为2
    cout << p.use_count() << endl; // p 的计数器记录为2
    return 0;
}
```

&emsp;
>示例 2
```c++
#include <memory>
#include <iostream>
using namespace std;

auto test(auto ptr){
    return ptr;
}

int main()
{
    auto p1 = make_shared<int>(42); 
    cout << "p1 use_count: " << p1.use_count() << endl;

    auto p2(p1);  
    cout << "p1 p2 use_count: " << p1.use_count() << endl;

    auto p3 = p1;
    cout << "p1 p2 p3 use_count: " <<p1.use_count() << endl;

    auto res = test(p1);
    cout << "p1 p2 p3 res use_count: " <<p1.use_count() << endl;

    cout << endl;
    auto p4 = make_shared<int>(888);
    p1 = p4;
    cout << "p1 p4 use_count: " << p1.use_count() << endl;
    cout << "p2 p3 res use_count: " << p2.use_count() << endl;

    return 0;
}
```


&emsp;
## 1.4 shared_ptr 自动销毁所管理的对象
- 当指向一个对象的最后一个 shared_ptr 被销毁时，shared_ptr类会自动销毁此对象
- 它是通过另一个特殊的成员函数——析构函数（destructor）完成销毁工作的
- 析构函数一般用来释放对象所分配的资源


shared_ptr 的析构函数会递减它所指向的对象的引用计数
如果引用计数变为0，shared_ptr的析构函数就会销毁对象，并释放它占用的内存。


&emsp;
## 1.5 给 shared_ptr 添加自定义删除器
当 shared_ptr 对象超出范围时，将调用其析构函数。在其析构函数中，它将引用计数减1，如果引用计数的新值为0，则删除关联的原始指针。

析构函数中删除内部原始指针，默认调用的是delete()函数。

我们可以将回调函数传递给 shared_ptr 的构造函数，该构造函数将从其析构函数中调用以进行删除，即

>示例1
```c++
// 自定义删除器
void deleter(Sample * x)
{
	std::cout << "DELETER FUNCTION CALLED\n";
	delete[] x;
}
// 构造函数传递自定义删除器指针
std::shared_ptr<Sample> p3(new Sample[12], deleter);
```


>示例2
```c++
template<typename _T>
shared_ptr<_T> make_nvshared(_T* ptr){
    return shared_ptr<_T>(ptr, [](_T* p){p->destroy();})
}
```














