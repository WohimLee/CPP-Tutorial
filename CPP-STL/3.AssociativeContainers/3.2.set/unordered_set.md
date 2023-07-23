# unordered_set
>头文件
```
#include <unordered_set>
```

# 1 unordered_set 是什么
unordered_set 容器，可直译为“无序 set 容器”。

unordered_set 容器和 set 容器很像，唯一的区别就在于 set 容器会自行对存储的数据进行排序，而 unordered_set 容器不会。

&emsp;
# 2 unordered_set的几个特性：

不再以键值对的形式存储数据，而是直接存储数据的值 ；
容器内部存储的各个元素的值都互不相等，且不能被修改；
不会对内部存储的数据进行排序

&emsp;
# 3 unordered_set 的初始化

```c++
// 创建空的set
unordered_set<int> set1;

// 拷贝构造
unordered_set<int> set2(set1);

// 使用迭代器构造
unordered_set<int> set3(set1.begin(), set1.end());

// 使用数组作为其初值进行构造
unordered_set<int> set4(arr,arr+5);

// 移动构造
unordered_set<int> set5(move(set2));

// 使用处置列表进行构造
unordered_set<int> set6 {1,2,10,10};
```

&emsp;
# 4 unordered_set的常用内置函数
>empty()
- 判断是否为空
- 若容器为空，则返回 true；否则 false
```c++
set1.empty();
```

>find()
- 查找
```c++
//查找2，找到返回迭代器，失败返回end()
set1.find(2);
```

>count()
- 出现次数
```c++
//返回指2出现的次数，0或1
set1.count(2);
```

>insert()
- 插入元素
```c++
//插入元素，返回pair<unordered_set<int>::iterator, bool>
set1.insert(3);
//使用initializer_list插入元素
set1.insert({1,2,3});
//指定插入位置，如果位置正确会减少插入时间，返回指向插入元素的迭代器
set1.insert(set1.end(), 4);
//使用范围迭代器插入
set1.insert(set2.begin(), set2.end());
```
- 返回值：
    - insert()只传入单个参数（待插入元素）：会返回一个 pair 对象，这个 pair 对象包含一个迭代器，以及一个附加的布尔值用来说明插入是否成功
        - 如果元素被插入，返回的迭代器会指向新元素
        - 如果没有被插入，迭代器指向阻止插入的元素
        ```c++
        auto pr = words.insert("ninety"); // Returns a pair - an iterator & a bool value
        ```
    - insert()传入两个参数（迭代器+待插入元素）：可以用一个迭代器作为insert() 的第一个参数，它指定了元素被插入的位置，在这种情况下，只会返回一个迭代器
        ```c++
        auto iter = words.insert (pr.first, "nine"); // 1st arg is a hint. Returns an iterator
        ```
    - insert()传入初始化列表：插入初始化表中的元素，在这种情况下，什么都没有返回
        ```c++
        words.insert({"ten", "seven", "six"});  // Inserting an initializer list
        ```

>emplace()
- 插入元素(转移构造)
```c++
//使用转移构造函数添加新元素3，比insert效率高
set1.emplace(3);
```

>erase()
- 删除元素
```c++
//删除操作，成功返回1，失败返回0
set1.erase(1);
//删除操作，成功返回下一个pair的迭代器
set1.erase(set1.find(1));
//删除set1的所有元素，返回指向end的迭代器
set1.erase(set1.begin(), set1.end());
```

>bucket_count()
- 篮子数目
```c++
//返回容器中的篮子总数
set1.bucket_count();
```

>bucket_size()
- 篮子中元素数目
```c++
//返回1号篮子中的元素数
set1.bucket_size(1);
```

>bucket()
- 在哪个篮子
```c++
//元素1在哪一个篮子
set1.bucket(1);
```

>clear()
- 清空
```c++
set1.clear();
```

>load_factor()
- 负载因子
```c++
//负载因子，返回每个篮子元素的平均数，即size/float(bucket_count);
set1.load_factor();
```

>rehash()
- 设置篮子数目并重新分布
```c++
//设置篮子的数量为20，并且重新rehash
set1.rehash(20);
```
