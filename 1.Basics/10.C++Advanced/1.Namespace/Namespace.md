# 命名空间（Namespace）

# 1 命名空间的定义


&emsp;&emsp;通过使用命名空间（Namespaces）可以将一组全局范围有效的类、对象或函数组织到一个名字下面。换种说法，就是它将全局范围分割成许多子域范围，每个子域范围叫做一个命名空间

&emsp;
>命名空间格式
```c++
namespace identifier{
    namespace-body
}
```
- identifier是一个有效的标识符
- namespace-body是该命名空间包含的一组类、对象和函数

&emsp;
>示例
```c++
namespace general{
    int a, b;
}
```
&emsp;&emsp;在这个例子中，a和b是命名空间general中的整型变量。想要在这个命名空间外面访问这两个变量，我们必须使用范围操作符`（::）`。例如，要想访问前面的两个变量，需要这样写：
```c++
general::a
general::b
```

&emsp;&emsp;命名空间的作用在于，全局对象或函数很有可能重名而造成重复定义的错误，命名空间的使用可以避免这些错误的发生。

>示例，命名空间的简单例子
```c++
#include <iostream>
using namespace std;

namespace A
{
    int var = 5;
}

namespace B
{
    double var = 3.14159;
}

int main()
{
    cout << A::var << endl;
    cout << B::var << endl;
    return 0;
}
```

>示例
- 声明和实现都要加上namespace
```c++
// 声明.h文件内
namespace myslam
{
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
}

// 实现.cpp文件内

```

&emsp;
# 2 命名空间的使用
&emsp;&emsp;using namespace xxx 可以将当前的嵌套层与一个指定的命名空间连在一起，以便使该命名空间下定义的对象和函数可以被访问，就好像它们是在全局范围内被定义的一样。它的使用遵循以下原型定义：
```c++
using namespace identifier;
```

>示例, 命名空间的使用
```c++
#include <iostream>
using namespace std;
namespace first {
    int var = 5;
}
    
namespace second {
    double var = 3.1416;
}
    
int main() {
    using namespace second;
    cout << var << endl;
    cout << (var * 2) << endl;
    return 0;
}   
```

&emsp;&emsp;这里要注意，语句using namespace只在其被声明的语句块内有效（一个语句块指在一对花括号（{}）内的一组指令），如果using namespace是在全局范围内被声明的，则在所有代码中都有效。


&emsp;
>示例，命名空间的再次使用
```c++
#include <iostream>
using namespace std;
namespace first {
    int var = 5;
}
    
namespace second {
    double var = 3.1416;
}
    
int main() {
    {
        using namespace first;
        cout << var << endl;
    }
    {
        using namespace second;
        cout << var << endl;
    }
    return 0;
}   

```

&emsp;
# 3 别名定义

我们可以为已经存在的命名空间定义别名，格式为：
```c++
namespace new_name = current_name;
```

&emsp;
# 4 标准命名空间


&emsp;&emsp;关于命名空间的最好例子就是标准C++函数库本身。例如ANSI C++标准定义，标准C++库中的所有类、对象和函数都是定义在命名空间std下面的。

&emsp;&emsp;ANSI标准完全重新设计了这些函数库，利用了模板功能，而且遵循了这条规则，将所有的函数和便令定义在命名空间std下。

&emsp;&emsp;该标准为这些头文件定义了新的名字，对针对C++的文件基本上使用同样的名字，但没有.h的扩展名，例如iostream.h变成了iostream。

>示例，标准命名空间的使用
```c++
// ANSI-C++ compliant hello world
#include <iostream>
    
int main() {
    std::cout << "Hello world in ANSI-C++\n";
    return 0;
}  
```

&emsp;&emsp;更常用的方法是使用using namespace，这样我们就不必在所有标准空间中定义的函数或对象前面使用范围操作符（::）了：
```c++
// ANSI-C++ compliant hello world
#include <iostream>
using namespace std;
    
int main() {
    cout << "Hello world in ANSI-C++\n";
    return 0;
}  
```
