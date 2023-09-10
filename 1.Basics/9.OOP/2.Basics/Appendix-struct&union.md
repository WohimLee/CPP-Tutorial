
&emsp;
# Appendix
## struct & union

struct 和 union 与 class 非常相似
>struct
- 在 C++中，类和数据结构的概念很相似，所以 struct 和 class 的作用几乎是一样的（也就是说，在C++中，struct定义的类也可以有成员函数，而不仅仅有数据成员）
- 两者定义类的权限区别在于
    - `class` 定义的类所有成员默认访问权限为 `private`
    - `struct` 定义的类所有成员默认访问权限为 `public`
- 除此之外，两个关键字的作用是相同的

>union
- union 的概念与 struct 和 class 定义的类不同，因为 union 在同一时间只能存储一个数据成员，但是由 union 定义的类也是可以有成员函数的。
- union 定义的类访问权限默认为 `public`


