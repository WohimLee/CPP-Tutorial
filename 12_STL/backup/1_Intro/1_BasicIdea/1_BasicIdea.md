&emsp;
# Basic Idea

&emsp;&emsp;STL是一个功能强大且可扩展的工具集，用来组织和处理数据。为了最大限度地满足各种类型数据的需求，这个工具集全部由模板定义。STL 可以被划分为4个概念库∶

- `容器库（Containers Library）` 定义了管理和存储数据的容器。这个库的模板被定义在以下几个头文件中∶ array、vector、stack、queue、deque、list、forward list、set、unordered set、map 以及 unorderd_map。

- `迭代器库（Iterators Library）` 定义了迭代器，迭代器是类似于指针的对象，通常被用于引用容器类的对象序列。这个库被定义在单个的头文件iterator中。

- `算法库（Algorithms Library）`定义了一些使用比较广泛的通用算法，可以运用到容器中的一组元素上。这个库的模板被定义在 algorithm头文件中。

- `数值库（Numerics Library）`定义了一些通用的数学函数和一些对容器元素进行数值处理的操作。这个库也包含一些用于随机数生成的高级函数。这个库的模板被定义在 complex、cmath、valarray、numeric、random、ratio 以及 cfenv 这些头文件中。其中cmath 已经有一些年头了，由于它包含了很多的数学函数，因此在 C++11中得到了扩展。

&emsp;

&emsp;&emsp;只需要几行简洁明了的 STL代码，很多复杂困难的任务都可以轻松地完成。


&emsp;&emsp;例如，以下代码可以从标准输入流中读取任意数目的浮点数，然后计算并输出它们的平均值,我们没有使用循环去输入，因为这些工作STL 已帮我们完成。∶
```cpp
#include <vector>
#include <iostream>
#include <numeric>  // std::accumulate
#include <iterator> // std::istream_iterator

int main()
{
    std::vector<double> values;
    std::cout << "Enter values separated by one or more spaces.Enter Ctrl+Z to end:\n ";
    values.insert(std::begin(values),
                  std::istream_iterator<double>(std::cin),
                  std::istream_iterator<double> ());
    std::cout << "The average is "
              <<(std::accumulate(std::begin(values),
                                 std::end(values),
                                 0.0)/values.size())
              << std::endl;

    return 0;
}
```


