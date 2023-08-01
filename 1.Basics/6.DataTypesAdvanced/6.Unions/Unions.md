
# 联合（Union）

## 1 联合
联合（Union）使得同一段内存可以按照不同的数据类型来访问，数据实际是存储在同一个位置的。它的声命和使用看起来与结构（structure）十分相似，但实际功能是完全不同的：
```c++
union model_name{
    type1 element1;
    type2 element2;
    type3 element3;
    ...
}object_name;
```
union中的所有被声明的元素占据同一段内存空间，其大小取声明中最长的元素的大小

>示例
```c++
#include <iostream>
using namespace std;

int main()
{
    union mytypes_t{
        char c;
        int i;
        float f;
    }mytypes;
    cout << sizeof(mytypes) << endl;

    return 0;
}
```
每一个是一种不同的数据类型。它们都指向同一段内存空间，改变其中一个元素的值会影响所有其它元素的值
>示例
```cpp
#include <iostream>
using namespace std;

int main()
{
    union mytypes_t{
        char c;
        int i;
        float f;
    }mytypes;
    mytypes.c = 'a';
    cout << mytypes.c << endl;

    mytypes.i = 10;
    cout << mytypes.i << endl;
    cout << mytypes.c << endl;

    mytypes.f = 3.14;
    cout << mytypes.c << endl;
    cout << mytypes.i << endl;
    cout << mytypes.f << endl;

    return 0;
}
```


&emsp;
## *2 匿名联合
如果将一个 union 包括在一个结构（structure）的定义中，并且不赋予它 object名称（就是跟在花括号（{}）后面的名字），这个 union 就是匿名的。这种情况下，我们可以直接使用 union 中元素的名字来访问该元素，而不需要在前面加 union 对象的名称
>联合（Union）
```c++
struct{
    char title[50];
    char author[50];
    union{
        float dollars;
        int yens;
    }price;  // 有object
}book;
```
>匿名联合（Anonymous Union）
```c++
struct{
    char title[50];
    char author[50];
    union{
        float dollars;
        int yens;
    };       // 没有object
}book
```

以上两种定义唯一的区别在于左边的定义中我们给了union一个名字price，而在右边的定义中没给。在使用时的区别是，当我们想访问一个对象（object）的元素dollars和yens时，在前一种定义情况下，需要使用：
```c++
book.price.dollars
book.price.yens
```
而在后一种定义下，我们直接使用：
```c++
book.dollars
book.yens
```
注意！因为这是一个联合（union），域 dollars 和 yens 占据的是同一块内存空间，所以它们不能被用来存储两个不同的值。也就是你可以使用一个 dollars 或 yens 的价格，但不能同时使用两者。





