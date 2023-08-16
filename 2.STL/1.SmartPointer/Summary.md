

&emsp;
>shared_ptr和 unique_ptr 都支持的操作

|||
:---|:---
shared_ptr\<T> sp | 空智能指针，可以指向类型为T的对象
unique_ptr\<T> up | 空智能指针，可以指向类型为T的对象
p | 将p用作一个条件判断，若p指向一个对象，则为true
*p | 解引用 p，获得它指向的对象
p->mem | 等价于(*p).mem
p.get() | 返回p中保存的指针。要小心使用，若智能指针释放了其对象，返p.get()回的指针所指向的对象也就消失了
swap(p, q) | 交换 p 和 q 中的指针
p.swap(q) | 交换 p 和 q 中的指针
|||

&emsp;
>shared_ptr 独有的操作

|||
|:---|:---
make_shared\<T>(args) | 返回一个 shared_ptr，指向一个动态分配的类型为T的对象。使用 args 初始化此对象
shared_ptr\<T>p(q) | p 是 shared ptr q的拷贝;此操作会递增 q 中的计数器。q 中的指针必须能转换为T*
p = q | p和q都是 shared_ptr，所保存的指针必须能相互转换。此操作会递减 p 的引用计数，递增 q 的引用计数;若p的引用计数变为0，则将其管理的原内存释放
p.unique()| 若p.use_count（）为1，返回true;否则返回false
p.use_count() | 返回与p共享对象的智能指针数量;可能很慢，主要用于调试
|||

