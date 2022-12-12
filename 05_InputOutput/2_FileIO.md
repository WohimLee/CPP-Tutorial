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
>fstream特有的操作

|||
:--|:--
fstream fstrm; | 创建一个未绑定的文件流。fstream 是头文件 fstream 中定义的一个类型
fstream fstrm (s); |创建一个fstream，并打开名为s的文件。s可以是 string 类型，或者是一个指向C风格字符串的指针。默认的文件模式 mode 依赖于 fstream的类型
fstream fstrm(s,mode); | 与前一个构造函数类似，但按指定 mode 打开文件
fstrm.open (s); | 打开名为 s的文件，并将文件与 fstrm 绑定。s 可以是一个string或一个指向C风格字符串的指针。默认的文件mode 依赖于fstream 的类型。返回 
void fstrm.close(); | 关闭与 fstrm绑定的文件。
fstrm.is_open() | 返回 void 返回一个bool值，指出与fstrm关联的文件是否成功打开且尚未关闭


&emsp;
# 1 使用文件流对象
- 当我们想要读写一个文件时，可以定义一个文件流对象，并将对象与文件关联起来。
- 每个文件流类都定义了一个名为 open 的成员函数，它完成一些系统相关的操作，来定位给定的文件，并视情况打开为读或写模式。
- 创建文件流对象时，我们可以提供文件名（可选的）。如果提供了一个文件名，则 open 会自动被调用

>示例
```c++
//构造一个 ifstream 并打开给定文件
ifstream in(ifile);
// 输出文件流未关联到任何文件
ofstream out;
```
- 这段代码定义了一个输入流 in，它被初始化为从文件读取数据
- 文件名由 string类型的参数ifile指定
- 第二条语句定义了一个输出流 out，未与任何文件关联
- 在新C++标准中，文件名既可以是库类型string对象，也可以是C风格字符数组。旧版本的标准库只允许 C 风格字符数组。

&emsp;
## 1.1用 fstream 代替 iostream&

```c++
//打开销售记录文件
ifstream input(argv[1]);
//打开输出文件
ofstream output(argv [2] );Sales_data total;
// 保存销售总额的变量//读取第一条销售记录
if(read(input,total)){//保存下一条销售记录的变量Sales_data trans;// 读取剩余记录
while (read(input,trans))(
// 检查 isbn
if(total.isbn(>== trans.isbn()>
//更新销售总额
total.combine(trans);else(
// 打印结果
print(output,total)<< endl;
//处理下一本书
total = trans;，
，
//打印最后一本书的销售额
print(output,total)<< endl;else
// 文件中无输入数据
cerr << "No data?!" << endl;
```
除了读写的是命名文件外，这段程序与229页的加法程序几乎是完全相同的。重要的部分是对 read 和 print 的调用。虽然两个函数定义时指定的形参分别是 istreams和ostream6，但我们可以向它们传递fstream 对象。成员函数 open 和 close
如果我们定义了一个空文件流对象，可以随后调用 open来将它与文件关联起来∶

