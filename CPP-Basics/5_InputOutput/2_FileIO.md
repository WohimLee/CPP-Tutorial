&emsp;
# 文件输入输出

>头文件
```c++
#include <fstream>
```

头文件 fstream 定义了三个类型来支持文件IO
- ifstream，从一个给定文件读取数据
- ofstream，向一个给定文件写入数据
- fstream，可以读写给定文件

&emsp;
## 1 打开文件

在 fstream 类中，成员函数 open() 实现打开文件的操作，从而将数据流和文件进行关联，通过 ofstream，ifstream，fstream 对象进行对文件的读写操作

>open() 函数声明
```c++
 
public member function
 
void open ( const char * filename,
            ios_base::openmode mode = ios_base::in | ios_base::out );
 
void open(const wchar_t *_Filename,
        ios_base::openmode mode= ios_base::in | ios_base::out,
        int prot = ios_base::_Openprot)；
```
- filename：操作文件名
- mode：打开文件的方式，这些方式是能够进行组合使用的，以“或”运算（“|”）的方式
    - ios::in：为输入(读)而打开文件
    - ios::out：为输出(写)而打开文件
    - ios::ate：初始位置：文件尾
    - ios::app：所有输出附加在文件末尾
    - ios::trunc：如果文件已存在则先删除该文件
    - ios::binary：二进制方式
- prot：打开文件的属性（基本很少用到），对于文件的属性也可以使用“或”运算和“+”进行组合使用
    - 0：普通文件，打开操作
    - 1：只读文件
    - 2：隐含文件
    - 4：系统文件

&emsp;
## 2 关闭文件


当文件读写操作完成之后，我们必须将文件关闭以使文件重新变为可访问的。成员函数 close()，它负责将缓存中的数据排放出来并关闭文件。这个函数一旦被调用，原先的流对象就可以被用来打开其它的文件了，这个文件也就可以重新被其它的进程所访问了。为防止流对象被销毁时还联系着打开的文件，析构函数将会自动调用关闭函数 close。


&emsp;
## 3 文本文件的读写
类 ofstream, ifstream 和 fstream 是分别从 ostream, istream 和iostream 中引申而来的。这就是为什么 fstream 的对象可以使用其父类的成员来访问数据。

一般来说，我们将使用这些类与同控制台(console)交互同样的成员函数(cin 和 cout)来进行输入输出。如下面的例题所示，我们使用重载的插入操作符<<：
>示例：out<<
```c++
    // writing on a text file
#include <fiostream.h>
int main () {
    ofstream out("out.txt");
    if (out.is_open()) 
    {
        out << "This is a line.\n";
        out << "This is another line.\n";
        out.close();
    }
    return 0;
}
```
>示例：cin>>
```c++
// reading a text file
#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>

int main () {
    char buffer[256];
    ifstream in("test.txt");
    if (! in.is_open())
    { cout << "Error opening file"; exit (1); }
    while (!in.eof() )
    {
        in.getline (buffer,100);
        cout << buffer << endl;
    }
    return 0;
}
//结果 在屏幕上输出
    This is a line.
    This is another line
```

&emsp;
## 4 二进制文件的读写
在二进制文件中，使用 << 和 >>，以及函数（如getline）来操作符输入和输出数据，没有什么实际意义，虽然它们是符合语法的。

文件流包括两个为顺序读写数据特殊设计的成员函数：write 和 read
- write：是 ostream 的一个成员函数，都是被 ofstream所继承
- read：是 istream 的一个成员函数，被ifstream 所继承

类 fstream 的对象同时拥有这两个函数。它们的原型是：
```c++
write (char * buffer, streamsize size);
read (char * buffer, streamsize size);
```
- buffer：是一块内存的地址，用来存储或读出数据
- size：是一个整数值，表示要从缓存（buffer）中读出或写入的字符数

>示例
- static 关键字作用是：只能在本文将调用这个函数
```c++
static std::vector<uint8_t> load_file(const string& file){

    ifstream in(file, ios::in | ios::binary);
    if (!in.is_open())
        return {};

    in.seekg(0, ios::end);
    size_t length = in.tellg();

    std::vector<uint8_t> data;
    if (length > 0){
        in.seekg(0, ios::beg);
        data.resize(length);

        in.read((char*)&data[0], length);
    }
    in.close();
    return data;
}
```


&emsp;
## 5 状态标志符的验证(Verification of state flags)

>bad()
- 如果在读写过程中出错，返回 true 
- 例如：当我们要对一个不是打开为写状态的文件进行写入时，或者我们要写入的设备没有剩余空间的时候

>fail()
- 除了与 bad() 同样的情况下会返回 true 以外，加上格式错误时也返回true ，例如当想要读入一个整数，而获得了一个字母的时候

>eof()
- 如果读文件到达文件末尾，返回true

>good()
- 这是最通用的：如果调用以上任何一个函数返回true 的话，此函数返回 false

要想重置以上成员函数所检查的状态标志，你可以使用成员函数clear()，没有参数。

&emsp;
## 6 获得和设置流指针(get and put stream pointers)
所有输入/输出流对象(i/o streams objects)都有至少一个流指针：
- ifstream，类似istream, 有一个被称为get pointer的指针，指向下一个将被读取的元素。
- ofstream，类似 ostream, 有一个指针 put pointer ，指向写入下一个元素的位置。
- fstream，类似 iostream, 同时继承了get 和 put

我们可以通过使用以下成员函数来读出或配置这些指向流中读写位置的流指针：

&emsp;
### tellg() 和 tellp()
返回 pos_type 类型的值(根据ANSI-C++ 标准) ，就是一个整数
- tellg：代表当前 get 流指针的位置
- tellp：代表当前 put 流指针的位置

&emsp;
### seekg() 和 seekp()
这对函数分别用来改变流指针 get 和 put 的位置。有两种不同的原型：
>第一种
```c++
seekg( pos_type position );
seekp( pos_type position );
```
- 使用这个原型，流指针被改变为指向从文件开始计算的一个绝对位置。要求传入的参数类型与函数 tellg 和 tellp 的返回值类型相同。

>第二种
```c++
seekg( off_type offset, seekdir direction );
seekp( off_type offset, seekdir direction );
```
- 第一个实参是一个 long 类型的整数，表示文件中的偏移量。这就是想要移动到的 `字节数`。L 字符可以强制编译器将该数字视为一个 long 类型的整数。该语句可以将文件的写入位置移动到编号为 20 的字节（所有编号从 0 开始，因此编号为 20 的字节实际上是第 21 个字节）
- 第二个实参称为模式标志，它指定从哪里计算偏移量。标志 ios::beg 表示偏移量是从文件开头算起的。也可以修改该参数，从文件末尾或文件中的当前位置计算偏移量。下面列出了所有 3 种随机访问模式的标志：
    - ios::beg：从流开始位置计算的位移
    - ios::cur：从流指针当前位置开始计算的位移
    - ios::end：从流末尾处开始计算的位移

>示例
```c++
// 将写入位置设置为从文件开头开始的第 33 个字节（字节 32)
file.seekp(32L, ios::beg); 
// 将写入位置设置为从文件末尾开始的第 11 个字节（字节 10)
file.seekp(-10L, ios::end); 
// 将写入位置设置为从当前位置开始的第 121 个字节（字节 120)
file.seekp(120L, ios::cur); 
// 将读取位置设置为从文件开头开始的第 3 个字节（字节 2)
file.seekg(2L, ios::beg); 
// 将读取位置设置为从文件末尾开始的第 101 个字节（字节 100)
file.seekg(-100L, ios::end); 
// 将读取位置设置为从当前位置开始的第 41 个字节（字节 40)
file.seekg(40L, ios::cur); 
// 将读取位置设置为文件末尾
file.seekg(0L, ios:rend); 
```
- 注意：上面的一些示例使用了负偏移量。负偏移量导致读或写位置在文件中向后移动，而正偏移量则导致向前移动。

流指针 get 和 put 的值对 `文本文件(text file)` 和 `二进制文件(binary file)` 的计算方法都是不同的，因为文本模式的文件中某些特殊字符可能被修改。由于这个原因，建议
- 对以文本文件：总是使用 seekg 和 seekp 的第一种原型，而且不要对 tellg 或 tellp 的返回值进行修改
- 对二进制文件：你可以任意使用这些函数，应该不会有任何意外的行为产生

>示例：获取文件长度
```c++
ifstream in(file, ios::in | ios::binary);
if (!in.is_open())
    return {};
// 定位读指针到文件尾部
in.seekg(0, ios::end);
// 获取文件长度
size_t length = in.tellg();
```
