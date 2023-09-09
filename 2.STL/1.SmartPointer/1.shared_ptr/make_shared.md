

&emsp;
# make_shared
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

