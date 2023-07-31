# Ceres

- Ceres solver：来自谷歌的 Ceres 库 
- 官方文档：http://ceres-solver.org/
- 官方GitHub：https://github.com/ceres-solver/ceres-solver


## 1 Ceres 简介

Ceres 库面向 `通用最小二乘问题` 的求解，我们需要做的就是定义优化问题，然后设置一些选项，输入进 Ceres 求解。Ceres 求解的最小二乘问题最一般的形式如下（带边界的核函数最小二乘）：

$$\min_x \frac{1}{2}\sum_i p_i\Big( 
    ||f_i(x_{i1}，...，x_{in})||^2\Big) \\
    s.t. \quad l_j \leq x_j \leq u_j$$

可以看到，目标函数由许多平方项，经过一个 `核函数 ρ(·)`之后，求和组成。

>核函数（拓展阅读）
- 类比深度学习中的激活函数（Activation Function）
- 在 SLAM 的 Boundle Adjustment(BA) 问题中，我们最小化误差项的二范数平方和，作为目标函数。

- 这种做法虽然很直观，但存在一个严重的问题：如果出于误匹配等原因，某个误差项给的数据是错误的，例如：把一条原本不应该加到图中的边给加进去了，然而优化算法并不能辨别出这是个错误数据，它会把所有的数据都当作误差来处理。这时，算法会看到一条误差很大的边，它的梯度也很大，意味着调整与它相关的变量会使目标函数下降更多。所以，算法将试图调整这条边所连接的节点的估计值，使它们顺应这条边的无理要求。由于这个边的误差真的很大，往往会抹平了其他正确边的影响，使优化算法专注于调整一个错误的值。

- 出现这种问题的原因是，当误差很大时，二范数增长得太快了。于是就有了核函数的存在。核函数保证每条边的误差不会大的没边，掩盖掉其他的边。具体的方式是，把原先误差的二范数度量，替换成一个增长没有那么快的函数，同时保证自己的光滑性质（不然没法求导）。因为它们使得整个优化结果更为鲁棒，所以又叫它们为`鲁棒核函数（Robust Kernel）`。


在 $Ceres$ 中，我们将定义优化变量 $\pmb{x}$ 和每个代价函数 $f_i$，再调用 $Ceres$ 进行求解。我们可以选择使用 $G-N$ 或者 $L-M$ 进行梯度下降，并设定梯度下降的条件，$Ceres$ 会在优化之后，将最优估计值返回给我们。下面，我们通过一个曲线拟合的实验，来实际操作一下 $Ceres$，理解优化的过程。



&emsp;
## 2 使用 Ceres 拟合曲线
假设有一条满足以下方程的曲线：

$$y = exp(ax^2 + bx +c) + w$$

```c++
template <typename T>
    // abc: 模型参数，有 3 维
    // residual: 残差（误差项/高斯噪声 w）
    // 因为 Ceres 的接口问题，必须这样去重载 ()
    bool operator() (const T* const abc, T* residual ) const 
    {
        // y-exp(ax^2+bx+c)
        residual[0] = T (_y) - ceres::exp( abc[0]*T(_x)*T(_x) + abc[1]*T(_x) + abc[2] );
        return true;
    }
```

其中 $a, b, c$ 为曲线的参数，$w$ 为高斯噪声。我们故意选择了这样一个非线性模型，以使问题不至于太简单。现在，假设我们有 $N$ 个关于 $x, y$ 的观测数据点，想根据这些数据点求出曲线的参数。那么，可以求解下面的最小二乘问题以估计曲线参数：

$$\min_{a,b,c} \frac{1}{2} \sum\limits^N_{i=1} 
||y_i - exp(ax^2_i + bx_i + c)||^2$$

在这个问题中，待估计的变量是 $a, b, c$，而不是 $x$。我们写一个程序，先根据模型生成 $x, y$ 的真值，然后在真值中添加高斯分布的噪声。随后，使用 Ceres 从带噪声的数据中拟合参数模型。


&emsp;
## 3 代码
&emsp;
>头文件
```c++
#ifndef CERES_APPLICATION_HPP
#define CERES_APPLICATION_HPP

#include <iostream>
#include <opencv2/core/core.hpp>
#include <ceres/ceres.h>
#include <chrono>
using namespace std;

// 代价函数的计算模型
struct CURVE_FITTING_COST
{
    CURVE_FITTING_COST ( double x, double y ) : _x ( x ), _y ( y ) {}
    // 残差的计算
    template <typename T>
    // abc: 模型参数，有 3 维
    // residual: 残差（误差项 w）
    // 因为 Ceres 的接口问题，必须这样去重载 ()
    bool operator() (const T* const abc, T* residual ) const 
    {
        // y-exp(ax^2+bx+c)
        residual[0] = T (_y) - ceres::exp( abc[0]*T(_x)*T(_x) + abc[1]*T(_x) + abc[2] );
        return true;
    }
    const double _x, _y; // x,y 数据
};

#endif
```

&emsp;
>库
```
ceres pthread glog cholmod lapack cxsparse
```


&emsp;
>主函数
```c++

#include "6.3_ceres_application.hpp"

int main(int argc, char** argv)
{
    // （1）生成实际的 y=exp(ax^2+bx+c) 曲线数据数据
    double a=1.0, b=2.0, c=1.0; // 真实参数值
    int N=100;                  // 生成 100 个数据点
    double w_sigma=1.0;         // 噪声方差：Sigma 值
    cv::RNG rng;                // OpenCV 随机数产生器

    cout << "Generating data: " << endl;
    vector<double> x_data, y_data; // 用来存储下面生成的 x, y 数据
    for ( int i=0; i<N; i++ )
    {
        double x = i/100.0; // 0, 0.01, 0.02, ..., 1
        x_data.push_back(x);
        // 计算 y 值
        y_data.push_back(exp(a*x*x + b*x + c) + rng.gaussian ( w_sigma ));
        cout << x_data[i] << " " << y_data[i] << endl;
    }

    // （2）构建最小二乘问题
    ceres::Problem problem;
    double abc[3] = {0,0,0};    // abc 参数的估计值
    for ( int i=0; i<N; i++ )
    {
        // 向问题中添加误差项
        problem.AddResidualBlock ( 
            // 参数1: 使用自动求导，模板参数：<误差类型，输出维度，输入维度>，数值参照前面 struct 中写法
            new ceres::AutoDiffCostFunction<CURVE_FITTING_COST, 1, 3>(
                new CURVE_FITTING_COST( x_data[i], y_data[i] )
                ),
            // 参数2: 核函数，这里不使用，为空
            nullptr, 
            // 参数3: 待估计参数
            abc 
        );
    }

    // 配置求解器
    ceres::Solver::Options options; // 这里有很多配置项可以填
    options.linear_solver_type = ceres::DENSE_QR; // 增量方程如何求解
    options.minimizer_progress_to_stdout = true;  // 输出到cout

    ceres::Solver::Summary summary; // 优化信息
    // 计时开始
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    ceres::Solve ( options, &problem, &summary ); // 开始优化
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    // 计时结束
    chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>( t2-t1 );
    // 输出计时结果
    cout << "solve time cost = " << time_used.count() << " seconds. " <<endl;

    // 输出结果
    cout << summary.BriefReport() <<endl;
    cout << "estimated a,b,c = ";
    for ( auto a:abc ) cout << a <<" ";
        cout << endl;
 
    return 0;
}
```


&emsp;
## 4 说明

>过程
- 我们用 OpenCV 的噪声生成器，生成 100 个带高斯噪声的数据。随后利用 Ceres 进行拟合。Ceres 的用法是这样的：

1. 定义 Cost Function 模型。方法是书写一个类，并在类中定义带模板参数的 `()` 运算符，这样该类成为了一个 `拟函数`（Functor，C++ 术语）。

    这种定义方式使得 Ceres 可以像调用函数一样，对该类的某个对象（比如说 `a`）调用 `a<double>()` 方法——这使对象具有像函数那样的行为。
    ```c++
    bool operator()(const T* const abc, T* residual )const 
    {
        // y-exp(ax^2+bx+c)
        residual[0] = T(_y) - ceres::exp(abc[0]*T(_x)*T ( _x) + abc[1]*T (_x) + abc[2]);
        return true;
    }
    ```

2. 调用 AddResidualBlock 将误差项添加到目标函数中。由于优化需要梯度，我们有若干种选择：
    - 使用 Ceres 的自动求导（Auto Diff）

    - 使用数值求导（Numeric Diff）
    - 自行推导解析的导数形式，提供给 Ceres。其中自动求导在编码上是最方便的，于是我们就使用自动求导啦！

3. 自动求导需要指定 `误差项` 和 `优化变量的维度`。这里的误差则是标量，维度为 1；优化的是 a, b, c 三个量，维度为 3。于是，在自动求导类的模板参数中设定变量维度为 1,3。

4. 设定好问题后，调用 solve 函数进行求解。你可以在 option 里配置优化选项。例如，我们可以选择使用 Line Search 还是 Trust Region，迭代次数，步长等等。

&emsp;
>结果
- 从 Ceres 给出的优化过程中可以看到，整体误差从 18248 左右下降到了 50.9，并且梯度也是越来越小。在迭代 22 次后算法收敛，最后的估计值为：
    $$a = 0.891943, b = 2.17039, c = 0.944142$$

    而我们设定的真值为
    $$a = 1, b = 2, c = 1$$
    它们相差不多。


    同时记录了 Ceres 的运行时间，对这样一个 100 个点的优化问题，计算时间约在 1.3 毫秒左右（虚拟机上）。

&emsp;
## 5 后语
Ceres 的优点是提供了自动求导工具，使得我们不必去计算很麻烦的雅可比矩阵。

Ceres 的自动求导是通过模板元实现的，在编译时期就可以完成自动求导工作，不过仍然是数值导数。

