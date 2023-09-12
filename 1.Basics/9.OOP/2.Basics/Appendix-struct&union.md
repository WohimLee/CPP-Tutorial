
&emsp;
# Appendix - struct & union

struct 和 union 与 class 非常相似
## 1 struct
- 在 C++中，类和数据结构的概念很相似，所以 struct 和 class 的作用几乎是一样的（也就是说，在C++中，struct定义的类也可以有成员函数，而不仅仅有数据成员）
- 两者定义类的权限区别在于
    - `class` 定义的类所有成员默认访问权限为 `private`
    - `struct` 定义的类所有成员默认访问权限为 `public`
- 除此之外，两个关键字的作用是相同的

- struct 也可以用初始化列表
```c++
// 代价函数的计算模型
struct CURVE_FITTING_COST
{
    CURVE_FITTING_COST ( double x, double y ) : _x ( x ), _y ( y ) {}
    // 残差的计算
    template <typename T>
    // abc: 模型参数，有 3 维
    // residual: 残差
    bool operator() (const T* const abc, T* residual ) const 
    {
        // y-exp(ax^2+bx+c)
        residual[0] = T ( _y ) - ceres::exp( abc[0]*T ( _x ) *T ( _x ) + abc[1]*T ( _x ) + abc[2] );
        return true;
    }
    const double _x, _y; // x,y 数据
};
```

&emsp;
## 2 union
- union 的概念与 struct 和 class 定义的类不同，因为 union 在同一时间只能存储一个数据成员，但是由 union 定义的类也是可以有成员函数的。
- union 定义的类访问权限默认为 `public`


