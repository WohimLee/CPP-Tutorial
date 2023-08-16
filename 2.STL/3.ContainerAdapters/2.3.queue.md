&emsp;
# queue（FIFO）

## 1 定义
queue是一种容器转换器模板，调用#include< queue>即可使用队列类。

## 2 queue初始化
queue<Type, Container> (<数据类型，容器类型>）
初始化时必须要有数据类型，容器可省略，省略时则默认为deque 类型

>示例: 初始化
```c++
queue<int>q1;
queue<double>q2;  
queue＜char＞q3；
//默认为用deque容器实现的queue；

queue＜char, list＜char＞＞q1；
//用list容器实现的queue 

queue＜int, deque＜int＞＞q2；
 //用deque容器实现的queue 
```

注意：不能用vector容器初始化queue
因为queue转换器要求容器支持front（）、back（）、push_back（）及 pop_front（），说明queue的数据从容器后端入栈而从前端出栈。所以可以使用deque和list对queue初始化，而vector因其缺少pop_front（），不能用于queue。

&emsp;
## 3 queue常用函数
>常用函数
- push() 在队尾插入一个元素
- pop() 删除队列第一个元素
- size() 返回队列中元素个数
- empty() 如果队列空则返回true
- front() 返回队列中的第一个元素
- back() 返回队列中最后一个元素

>示例
```c++
// push（）在队尾插入一个元素
queue <string> q;
    q.push("first");
    q.push("second");
    cout<<q.front()<<endl;
// pop() 将队列中最靠前位置的元素删除，没有返回值
queue <string> q;
	q.push("first");
	q.push("second");
	q.pop();
	cout<<q.front()<<endl;
// size() 返回队列中元素个数
queue <string> q;
	   q.push("first");
	   q.push("second");
	   cout<<q.size()<<endl;
// empty() 如果队列空则返回true
queue <string> q;
    cout<<q.empty()<<endl;
    q.push("first");
    q.push("second");
    cout<<q.empty()<<endl;
// front() 返回队列中的第一个元素
queue <string> q;
    q.push("first");
    q.push("second");
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
// back() 返回队列中最后一个元素
queue <string> q;
q.push("first");
q.push("second");
cout<<q.back()<<endl;
```