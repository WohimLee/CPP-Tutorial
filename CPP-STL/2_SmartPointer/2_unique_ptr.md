&emsp;
# unique_ptr

std::unique_ptr 是 C++11 起引入的智能指针。为什么必须要在 C++11 起才有该特性，主要还是 C++11 增加了move语义，否则无法对对象的所有权进行传递。

## 1 unique_ptr 介绍
>unique_ptr 不共享它的指针
- 它无法复制到其他 unique_ptr
- 无法通过值传递到函数
- 无法用于需要副本的任何标准模板库 (STL) 算法
- 只能移动unique_ptr

这意味着，内存资源所有权将转移到另一 unique_ptr，并且原始 unique_ptr 不再拥有此资源

建议将对象限制为由一个所有者所有，因为多个所有权会使程序逻辑变得复杂。因此，当需要智能指针用于纯 C++ 对象时，可使用 unique_ptr，而当构造 unique_ptr 时，可使用 make_unique 函数

>std::unique_ptr 实现了独享所有权的语义
- 一个非空的 std::unique_ptr 总是拥有它所指向的资源
    - 转移一个 std::unique_ptr 将会把所有权也从源指针转移给目标指针（源指针被置空）
    - 拷贝一个 std::unique_ptr 将不被允许，因为如果你拷贝一个 std::unique_ptr ,那么拷贝结束后，这两个 std::unique_ptr 都会指向相同的资源，它们都认为自己拥有这块资源（所以都会企图释放）
    - 因此 std::unique_ptr 是一个仅能移动（move_only）的类型
    - 当指针析构时，它所拥有的资源也被销毁。默认情况下，资源的析构是伴随着调用 std::unique_ptr 内部的原始指针的 delete 操作的
- unique_ptr 实例之间的所有权转换：

&emsp;
## 2 创建unique_ptr
unique_ptr 不像 shared_ptr 一样拥有标准库函数 make_shared 来创建一个 shared_ptr 实例。要想创建一个 unique_ptr，我们需要将一个new 操作符返回的指针传递给 unique_ptr 的构造函数。

std::make_unique 是 C++14 才有的特性。
>示例：
```c++
int main()
{
    // 创建一个unique_ptr实例
    unique_ptr<int> pInt(new int(5));
    cout << *pInt;
}
```

&emsp;
## 3 无法进行复制构造和赋值操作
unique_ptr 没有copy构造函数，不支持普通的拷贝和赋值操作。
>示例：
```c++
int main() 
{
    // 创建一个unique_ptr实例
    unique_ptr<int> pInt(new int(5));
    unique_ptr<int> pInt2(pInt);    // 报错
    unique_ptr<int> pInt3 = pInt;   // 报错
}
```

&emsp;
## 4 可以进行移动构造和移动赋值操作
unique_ptr 虽然没有支持普通的拷贝和赋值操作，但却提供了一种移动机制来将指针的所有权从一个 unique_ptr 转移给另一个 unique_ptr 。如果需要转移所有权，可以使用std::move()函数。

>示例：
```c++
int main() 
{
    unique_ptr<int> pInt(new int(5));
    unique_ptr<int> pInt2 = std::move(pInt);    // 转移所有权
    //cout << *pInt << endl; // 出错，pInt为空
    cout << *pInt2 << endl;
    unique_ptr<int> pInt3(std::move(pInt2));
}
```

&emsp;
## 5 可以返回unique_ptr
unique_ptr不支持拷贝操作，但却有一个例外：可以从函数中返回一个unique_ptr。

>示例
```c++
unique_ptr<int> clone(int p)
{
    unique_ptr<int> pInt(new int(p));
    return pInt;    // 返回unique_ptr
}

int main() {
    int p = 5;
    unique_ptr<int> ret = clone(p);
    cout << *ret << endl;
}
```

&emsp;
## 6 unique_ptr使用示例
```c++
{
    //创建一个指向int的空指针
    std::unique_ptr<int> fPtr1;
    std::unique_ptr<int> fPtr2(new int(4));
    auto fPtr3 = std::make_unique<int>();
    
 	//fPtr2释放指向对象的所有权，并且被置为nullptr
    std::cout << "fPtr2 release before:" << fPtr2.get() << std::endl;
    int *pF = fPtr2.release();
    std::cout << "fPtr2 release before:" << fPtr2.get() << " and pF value:" << *pF << std::endl;
    
	//所有权转移，转移后fPtr3变为空指针
    std::cout << "move before fPtr1 address:" << fPtr1.get() << " fPtr3 address:" << fPtr3.get() << std::endl;
    fPtr1 = std::move(fPtr3);
    std::cout << "move after fPtr1 address:" << fPtr1.get() << " fPtr3 address:" << fPtr3.get() << std::endl;

	std::cout << "move before fPtr1 address:" << fPtr1.get() << std::endl;
    fPtr1.reset();
    std::cout << "move after fPtr1 address:" << fPtr1.get() << std::endl;
}
```

&emsp;
## 7 unique_ptr使用场景
>示例1：为动态申请的资源提供异常安全保证
```c++
void Func()
{
    int *p = new int(5);
    // ...（可能会抛出异常）
    delete p;
}
```
- 这是我们传统的写法：当我们动态申请内存后，有可能我们接下来的代码由于抛出异常或者提前退出（if语句）而没有执行delete操作。

- 解决的方法是使用 unique_ptr 来管理动态内存，只要 unique_ptr 指针创建成功，其析构函数都会被调用，确保动态资源被释放。

```c++
void Func()
{
    unique_ptr<int> p(new int(5));
}
```

&emsp;
>示例2：返回函数内动态申请资源的所有权
```c++
unique_ptr<int> Func(int p)
{
    unique_ptr<int> pInt(new int(p));
    return pInt;    // 返回unique_ptr
}

int main() {
    int p = 5;
    unique_ptr<int> ret = Func(p);
    cout << *ret << endl;
    // 函数结束后，自动释放资源
}
```

&emsp;
>示例3：在容器中保存指针
```c++
int main() 
{
    vector<unique_ptr<int>> vec;
    unique_ptr<int> p(new int(5));
    vec.push_back(std::move(p));    // 使用移动语义
}
```

&emsp;
>示例4：管理动态数组
标准库提供了一个可以管理动态数组的 unique_ptr 版本。
```c++
int main() 
{
    unique_ptr<int[]> p(new int[5] {1, 2, 3, 4, 5});
    p[0] = 0;   // 重载了operator[]
}
```

&emsp;
>示例5：作为auto_ptr的替代品
```c++
// 创建与释放举例
#include <iostream>
#include <memory>
#include <stdlib.h>

struct Foo
{
    Foo() { std::cout << "Foo::Foo\n"; }
    ~Foo() { std::cout << "Foo::~Foo\n"; }
    void bar() { std::cout << "Foo::bar\n"; }
};

void f(const Foo &){
    std::cout << "f(const Foo&)\n";
}

struct D{
    void operator()(Foo* foo){
        std::cout << "D operator()" << std::endl;
        delete foo;
    }
};

void TestAutoDestroy(){
    //1. 普通的new对象.
    std::cout << "TestDestroy...................." << std::endl;
    {std::unique_ptr<Foo> p1(new Foo);}

    //2. 普通的new[]对象.
    {std::unique_ptr<Foo[]> p2(new Foo[4]);}

    //3. 自定义的deleter.
    {std::unique_ptr<Foo, D> p3(new Foo);}
}

void TestOwner()
{
    std::cout << "TestOwner...................." << std::endl;
    //1. new object.
    std::unique_ptr<Foo> p1(new Foo);  // p1 owns Foo
    if (p1) 
    	p1->bar();
    {
        std::unique_ptr<Foo> p2(std::move(p1));  // now p2 owns Foo
        f(*p2);

        p1 = std::move(p2);  // ownership returns to p1
        p2->bar();
        std::cout << "destroying p2...\n";
    }

    p1->bar();
}

void TestArrayOwner()
{
    std::cout << "TestArrayOwner...................." << std::endl;
    //1. new[] object.
    std::unique_ptr<Foo[]> p1(new Foo[4]);  // p1 owns Foo
    if (p1) 
    	p1[0].bar();
    {
        std::unique_ptr<Foo[]> p2(std::move(p1));  // now p2 owns Foo
        f(p2[0]);

        p1 = std::move(p2);  // ownership returns to p1
        p2[0].bar();
        std::cout << "destroying p2...\n";
    }

    p1[0].bar();
}

int main()
{
    TestAutoDestroy();
    TestOwner();
    TestArrayOwner();
}
```

&emsp;
## 8 总结
- unique_ptr 独占管理对象，只有移动语义。
- unique_ptr 可以不占用对象，即为空。可以通过reset()或者赋值nullptr释放管理对象。
- 标准库早期版本中定了auto_ptr，它具有unique_ptr的部分特征，但不是全部。例如不能在容器中保存auto_ptr，不能从函数中返回auto_ptr等等，这也是unique_ptr主要的使用场景。
