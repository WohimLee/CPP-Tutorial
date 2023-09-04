&emsp;
# Appendix
## 别名定义

我们可以为已经存在的命名空间定义别名
>语法
```c++
namespace new_name = current_name;
```

>Example
```c++
#include <iostream>

namespace xxx = std;
int main()
{
    xxx::cout << "Hello" << xxx::endl;
    return 0;
}
```
