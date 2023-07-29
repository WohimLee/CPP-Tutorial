
# String

## 1 基本概念
>本质
- string 是 C++ 风格的字符串，而 string 本质上是一个类

&emsp;
>string 和 char* 区别
- char * 是一个指针
- string 是一个类，类内部封装了char \*，管理这个字符串，是一个char*型的容器
- 转换成 C 字符串指针
    ```c++
    #include <stdio.h>
    #include <string>
    using namespace std;

    int main()
    {
        string str1 = "abcdefg";
        printf("%s\n", str1.c_str());
        
        return 0;
    }
    ```

&emsp;
>特点
- string类内部封装了很多成员方法，例如：查找find，拷贝copy，删除delete，替换replace，插入insert
string 管理 char* 所分配的内存（动态分配和释放），不用担心复制越界和取值越界等，由类内部进行负责


&emsp;
## 2 构造函数
```c++
string();                  // 创建一个空的字符串，例如：string str
string(const char* s);     // 使用字符串 s 初始化
string(const string& str); // 使用一个 string 对象初始化另一个string对象
string(int n, char c);     // 使用n个字符c初始化
```
>示例
```C++
#include <iostream>
#include <string>
using namespace std;
int main()
{
    const char * str = "hello STL"; // c风格字符串
    string str1(str);  // c风格字符串转成string
    string str2(str1); // 调用拷贝构造成字符串
    string str3(3, 'x');
    cout << str1 << endl; // 
    cout << str2 << endl; // 
    cout << str3 << endl;
} 
```

&emsp;
## 3 赋值操作
赋值的函数原型：
```c++
string& operator=(const char* s);     // char* 类型字符串赋值给当前的字符串
string& operator=(const string& s);   // 把字符串s赋给当前的字符串
string& assign(const char *s);        // 把字符串s赋给当前的字符串
string& assign(const char *s, int n, int m); // 把字符串s从n的位置取m个字符赋给当前的字符串
string& assign(const string& s);      // 把字符串s赋给当前字符串
string& assign(int n, char c);        // 用n个字符c赋给当前字符串
```

>示例
```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1 = "hello STL";
    string str2 = str1;
    string str3, str4, str5, str6;
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3.assign(str1) << endl;
    cout << str4.assign(str1, 3, 4) << endl;
    cout << str5.assign(str4) << endl;
    cout << str6.assign(5, '8') << endl;
} 
```



&emsp;
## 4 字符串拼接
函数原型
```c++
string& operator+=(const char* str);             // 重载+=操作符
string& operator+=(const char c);                // 重载+=操作符
string& operator+=(const string& str);           // 重载+=操作符
string& append(const char *s);                   // 把字符串s连接到当前字符串结尾
string& append(const char *s, int n);            // 把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);                 // 同operator+=(const string& str)
string& append(const string& s, int pos, int n); // 字符串s中从pos开始的n个字符连接到字符串结尾
```
>示例
```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1 = "aaa";
    str1 += " bbb ";
    cout << str1 << endl;
    str1 += 'x';
    cout << str1 << endl;

    string str2 = " 123456";
    str1 += str2;
    cout << str1 << endl;

    str1.append(" hello");
    cout << str1 << endl;

    str1.append(" world", 3);
    cout << str1 << endl;

    string str3 = " 98k ";
    str1.append(str3);
    cout << str1 << endl;

    str1.append(str2, 3, 2);
    cout << str1 << endl;
} 
```




&emsp;
## 5 查找与替换
- 查找：查找指定字符串是否存在
- 替换：在指定的位置替换字符串
>函数原型：
```c++
int find(const string& str, int pos = 0) const; // 查找str第一次出现位置，从pos开始查找
int find(const char* s, int pos = 0) const; // 查找s第一次出现位置，从pos开始查找
int find(const char* s, int pos, int n) const; // 从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const; // 查找字符c第一次出现位置

int rfind(const string& str, int pos = npos)  const; // 查找str最后一次位置，从pos往前开始查找
int rfind(const char* s, int pos = npos) const; // 查找s最后一次出现位置，从pos往前开始查找
int rfind(const char c, int pos, int n) const; // 从pos往前查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; // 查找字符c最后一次出现位置

string& replace(int pos, int n, const string& str); // 替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s); // 替换从pos开始的n个字符为字符串s
```


```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1 = "abcdefga";
    cout << str1.find("bc") << endl;
    cout << str1.rfind('a') << endl;
    cout << str1.replace(2, 3, "88") << endl;
} 
```


&emsp;
## 6 字符串比较

比较原理：
- = 返回 0
- \> 返回 1
- < 返回 -1

函数原型
```c++
int compare(const string &s) const; // 与字符串s比较
int compare(const char *s) const;   // 与字符串s比较
```

>示例
```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1 = "hello";
    string str2 = "hello";

    if(str1.compare(str2) == 0)
    {
        cout << "str1 等于 str2" << endl;
    }
    else if (str1.compare(str2) > 0)
    {
        cout << "str1 大于 str2" << endl;
    }
    else
    {
        cout << "str1 小于 str2" << endl;
    }
} 
```

&emsp;
## 7 字符串存取
>string 中单个字符存取方式有两种
```c++
char& operator[](int n);// 通过[]方式取字符
char& at(int n);        // 通过at方法获取字符
```

>示例
```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1 = "hello";
    cout << str1[2] << endl;
    cout << str1.at(4) << endl;
    str1[1] = 'x';
    cout << str1 << endl;
    str1.at(0) = 'x';
    cout << str1 << endl;
} 
```

&emsp;
## 8 插入与删除
函数原型：
```c++
string& insert(int pos, const char* s);     // 插入字符串
string& insert(int pos, const string& str); // 插入字符串
string& insert(int pos, int n, char c);     // 在指定位置插入n个字符c
string& erase(int pos, int n = npos);     // 删除从pos开始的n个字符
```

```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1 = "hello";
    cout << str1.insert(1, "xx") << endl;
    string str2 = "8888";
    cout << str1.insert(3, str2) << endl;
    cout << str1.insert(5, 3, '$') << endl;
    cout << str1.erase(1, 2) << endl;
} 
```

&emsp;
## 9 子串获取
>函数原型
```c++
string substr(int pos = 0, int n = npos) const; // 返回由pos开始的n个字符组成的字符串
```

>示例
```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "abcdefg";
    cout << str.substr(1, 3) << endl;
} 
```
