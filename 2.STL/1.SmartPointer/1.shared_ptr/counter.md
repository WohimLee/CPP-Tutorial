

&emsp;
# counter
## 1 shared_ptr 计数器的递增递减
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
## 2 shared_ptr 自动销毁所管理的对象
- 当指向一个对象的最后一个 shared_ptr 被销毁时，shared_ptr类会自动销毁此对象
- 它是通过另一个特殊的成员函数——析构函数（destructor）完成销毁工作的
- 析构函数一般用来释放对象所分配的资源


shared_ptr 的析构函数会递减它所指向的对象的引用计数
如果引用计数变为0，shared_ptr的析构函数就会销毁对象，并释放它占用的内存。

