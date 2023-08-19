

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

