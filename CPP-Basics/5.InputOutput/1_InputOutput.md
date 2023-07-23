&emsp;
# 1 C语言stdio.h中的IO
&emsp;&emsp;在 C语言中，没有专门的输入输出语句，所有的输入输出操作都是通过对标准输入输出库函数（包含在 stdio.h 头文件中）的调用实现。最常用的输入输出函数有 scanf（）、printf（）、getchar（）和 putchar（）

&emsp;
## 1.1 scanf()
&emsp;&emsp;格式化输入函数 scanf（）的功能是取得从键盘上输入的数据，所获得的数据按指定输入格式被赋给相应的输入项。该函数一般形式为∶
```
scanf("%<修饰符>格式字符", 输入项列表)
```

- 修饰符: 可选，表示输入字段宽度（数字）、约定整数是否是长整型（l）
- 格式字符数据类型

    ![](images/scanf.png)

（2）输入项列表

- 一个或多个变量地址，变量地址有多个时，用逗号"，"分隔。  

- 变量要加取地址操作符"&"， 只有这样函数才能改变其值。

- 输入类型与变量类型应尽量一致，以避免类型不匹配而造成的错误。

&emsp;&emsp;如果需要输入一个十进制长整型数据，且规定字段宽度为 9 位有效数字，可用下面的代码完成。

&emsp;
>示例
```c++
#include <iostream>
using namespace std;

int main()
{
    // 示例1：
    long a;            //声明一个长整型变量
    scanf("%9ld", &a); //输入一个字段宽度为 9 位有效数字的十进制长整型数据，保存在变量a中

    /*程序运行时，会要求在终端上输入数据，输入后按 Enter 键，程序继续运行。假如输入的数据是 1234567890，那么前 9 位数字将作为有效的输入，变量 a 保存的数值为 123456789。*/

    // 示例2：
    int a, b, c; //声明 3个整型变量
    //输入3个整型数据，分别保存在变量 a、b、c中, 注意用逗号隔开
    scanf("%d, %d, %d", &a, &b, &c); 
    printf("%d, %d, %d\n", a, b, c);
}
```



&emsp;
## 1.2 printf()
- 按格式化字符串输出
>基本格式
```c++
printf("%[标志][输出最小宽度][.精度][长度][类型]"，输出项列表)
```

&emsp;
>[类型] 

![](images/printftypes.png)

&emsp;
>[标志] 

![](images/printfflags.png)
```c++
#include <iostream>
using namespace std;

int main()
{
    printf("%5d\n",1000); 				 //默认右对齐,左边补空格
    printf("%-5d\n",1000); 				 //左对齐,右边补空格
    printf("%+d %+d\n",1000,-1000);		 //输出正负号
    printf("% d % d\n",1000,-1000);		 //正号用空格替代，负号输出
    printf("%x %#x\n",1000,1000);		 //输出0x
    printf("%.0f %#.0f\n",1000.0,1000.0);//当小数点后不输出值时依然输出小数点
    printf("%g %#g\n",1000.0,1000.0);	 //保留小数点后后的0
    printf("%05d\n",1000);				 //前面补0
}
```

&emsp;
>[输出最小宽度] : 

![](images/printfwidth.png)

&emsp;
>[.精度]

![](images/printfprecision.png)
```c++
printf("%.8d\n",1000);			//不足指定宽度补前导0，效果等同于%08d
printf("%.8f\n",1000.123456789);//超过精度，截断
printf("%.8f\n",1000.123456);	//不足精度，补后置0
printf("%.8g\n",1000.123456);	//最大有效数字为8位
printf("%.8s\n",“abcdefghij”);	//超过指定长度截断
```

&emsp;
>[长度]

![](images/printflength.png)
```c++
#include <iostream>
using namespace std;

int main()
{
    printf("%hhd\n",'A');				//输出有符号char
    printf("%hhu\n",'A'+128);			//输出无符号char
    printf("%hd\n",32767);				//输出有符号短整型short int
    printf("%hu\n",65535);				//输出无符号短整型unsigned short int
    printf("%ld\n",0x7fffffffffffffff);	//输出有符号长整型long int
    printf("%lu\n",0xffffffffffffffff);	//输出有符号长整型unsigned long int
}
```



>示例1
```c++
#include <iostream>
using namespace std;

int main()
{
    int a =123;         // 定义一个整型变量并赋值
    float b = 45.6789;  // 定义一个浮点型变量并赋值
    printf("%5d-%5.2f\n", a, b); 
    // 格式化输出变量a和b，变量 a字段宽度为 5，
    // 变量b在小数点前字段宽度为 5，小数点后为2
}
```

>示例2，常用案例
```c++
#include <iostream>
using namespace std;

int main()
{
    float sec1,sec2;  // 定义两个浮点型变量，表示某学生第
                  // 一和第二学期的成绩
    sec1 = 88.0;      // 为变量赋值
    sec2 = 79.5;
    printf("第一学期成绩是∶ %2.1f\n", sec1); // 输出第-学期成绩
    printf("第二学期成绩是∶ %2.1f\n", sec2); // 输出第二学期成绩
    printf("总分是∶ %3.1f，平均分是∶ %2.1f\n",
        sec1 + sec2,(sec1 + sec2)/ 2);    // 输出两学期的总分和平均分
}
```

&emsp;
## 1.3 sprintf()

- 函数功能：把格式化的数据写入某个字符串
- 函数原型：int sprintf( char *buffer, const char *format [, argument] … );
- 返回值：字符串长度（strlen）

&emsp;
>示例
```c++
#include <stdio.h>

int main()
{
    const char* a = "aaa";
    const char* b = "bbb";
    char s[50];

    // 产生："aaa connect bbb." 字符串写到 s 中
    sprintf(s, "%s conncet %s.", a, b); 
    printf("%s\n", s);
    // 产生："3.142" 字符串写到 s 中
    sprintf(s, "%.3f", 3.1415926); 
    printf("%s\n", s);
    return 0;
}
```

&emsp;
## 1.4 getchar()和putchar()
- getchar（）函数的作用是从终端获得一个字符
- putchar（）函数的作用是向终端输出一个字符。

getchar（）与 putchar（）函数每次只能操作一个 ASCII代码。因此，在设计基于文本界面的简单应用程序时，常利用这一特性实现菜单选择的输入和用户确认的输入。

&emsp;
>示例
```c++
int main()
{
    char ch;                                 // 声明一个字符型变量，用作接受输入
    printf("如果您要输出字母 A，请输入数字 1\n"); // 输出菜单文本
    printf("如果您要输出字母 B，请输入数字 2\n"); // 输出菜单文本 
    ch = getchar();       // 获取键盘上输入的字符 
    if (ch == '1'){       // 判断所输入的字符是否为 1
        putchar ('A');    // 输出字母A
    }
    else if (ch == '2'){  // 判断所输入的字符是否为 2
        putchar('B');     // 输出字母 B
    }
    else{                // 将1和2以外的字符作为非法输入处理
        printf("您输入的字符不在选择范围\n"); // 输出错误提示
    }
    return 0;                     // 程序结束
}
```

&emsp;
# 2 C++中iostream的IO

## 2.1 String

### 1 基本概念
>本质
- string是C++风格的字符串，而string本质上是一个类

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
### 2 构造函数
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
### 3 赋值操作
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
### 4 字符串拼接
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
### 5 查找与替换
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
### 6 字符串比较

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
### 7 字符串存取
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
### 8 插入与删除
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
### 9 子串获取
函数原型：
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

C++的iostream函数库
- cin 标准输入流，通常被定向到键盘
- cout 标准输出流，通常被定向到屏幕
- cerr 专门用来显示出错信息，可以被重新定向到标准输出设备
- clog 专门用来显示出错信息，可以被重新定向到一个日志文件（log file）

&emsp;&emsp;
## 2.2 输出（cout ）
&emsp;&emsp;输出流 cout 与运算符 << 一起使用

>示例
```c++
#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int age = 21;
    int zipcode = 88888;
    cout << "output sentence"; //扫印output sentence到屏幕E 
    cout << 120;     //打印数字 120 到屏幕下 
    cout << x;       //打印变量x 的催到屏露控
    cout << "Hello, I am " << age 
         << " years old and my zipcode is " << zipcode;
}
```

cout 并不会在末尾加换行符，换行符可以写作\n，也可以用操作符 endl 来换行
>示例
```c++
#include <iostream>
using namespace std;

int main()
{
    cout << "First sentence.\n";
    cout << "Second sentence.\nThird sentence.";
    cout << "First sentence." << endl;
    cout << "Second sentence." << endl;
}
```

cout.precision()

输出流cout的一个格式控制函数，是在iostream中的一个成员函数。precision()返回当前的浮点数的精度值，而cout.precision(val)其实就是在输出的时候设定输出值以新的浮点数精度值显示，即小数点后保留val位

```c++
float val = 3.1415926
cout .precision(3) // 后面的输出保留3位数
cout << val << endl;
```

&emsp;
## 2.3 输入（cin）
- cin 后面必须跟一个变量以便存储读入的数据
- 使用 cin输入的时候必须考虑后面的变量类型

>示例
```c++
#include <iostream>
using namespace std;

int main ()
{
    int a, b, c;

    cin >> a ;
    cout << "a: " << a << endl;
    // 输入时，两个变量之间可以以任何有效的空白符号间隔，包括空格、跳跃符（tab）或换行符。
    cin >> b >> c;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    return 0;
} 
```

&emsp;
## 2.4 cin 和字符串
- 使用 cin >> 可以读取字符串，cin >> 只能读取一个单词，一旦碰到任何空格，读取操作就会停止。
- 要一次读取一整行输入。需要使用 C++的函放 getline。

>示例
```c++
#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string mystr;
  cout << "What's your name? ";
  getline(cin, mystr);
  cout << "Name: " << mystr << endl;;
  cout << "What is your favorite color? ";
  getline(cin, mystr);
  cout << "Favourite color: " << mystr << endl;;
  return 0;
}
```

