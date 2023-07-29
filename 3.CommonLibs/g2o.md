# g2o

g2o（General Graphic Optimization，G2O） 是一个在 SLAM 领域广为使用的优化库。它是一个基于图优化的库。图优化是一种将 `非线性优化` 与 `图论` 结合起来的理论。

<div align="center">
    <image src="./imgs/g2o-3.png" width =>
    <h4>g2o 库的框架</h>
</div>

Solver 含有两个部分：
- BlockSolver: 用于计算迭代过程中最关键的一步 $𝐻Δ𝑥=−𝑏$
    - LinearSolver: 线性方程的求解器，求解 $𝐻Δ𝑥=−𝑏$
        - PCG
        - CSparse
        - Choldmod
- SparseBlockMatrix: 用于计算稀疏的雅可比和海塞；

>g2o 选择优化方法一共需要三个步骤：
1. 选择 LinearSolver（线性方程求解器）
2. 选择 BlockSolver 
3. 选择 OptimizationWithHessian（迭代策略），从GN, LM, Doglog中选

&emsp;
## 1 图优化理论简介

图优化，是把优化问题表现成图（Graph）的一种方式。这里的图是图论意义上的图。

一个图由若干个`顶点（Vertex）`，以及连接着这些节点的`边（Edge）`组成
- 顶点: `优化变量`
- 边: `误差项`

于是，对任意一个上述形式的非线性最小二乘问题，我们可以构建与之对应的一个图。 
<div align="center">
    <image src="./imgs/g2o-1.png" width = 500>
</div>

以上图为例：
- 图优化的顶点
    - 三角形：相机位姿节点
    - 圆形：路标点
- 图优化的边
    - 蓝色线：运动模型
    - 红色虚线：观测模型

&emsp;
## 2 例子：使用g2o拟合曲线
假设有一条满足以下方程的曲线：

$$y = exp(ax^2 + bx +c) + w$$

其中 $a, b, c$ 为曲线的参数，$w$ 为高斯噪声。现在，假设我们有 $N$ 个关于 $x, y$ 的观测数据点，想根据这些数据点求出曲线的参数。那么，可以求解下面的最小二乘问题以估计曲线参数：

$$\min_{a,b,c} \frac{1}{2} \sum\limits^N_{i=1} 
||y_i - exp(ax^2_i + bx_i + c)||^2$$

待估计的变量是 $a, b, c$

将曲线拟合问题抽象成图优化。这个过程中，只要记住节点为优化变量，边为误差项即可。

<div align="center">
    <image src="./imgs/g2o-2.png" width = 500>
</div>
&emsp;


在曲线拟合问题中，整个问题只有一个顶点：曲线模型的参数 a, b, c；而每个带噪声的数据点，构成了一个个误差项，也就是图优化的边，所以我们就只能把它画成自己连到自己的样子了。事实上，图优化中一条边可以连接一个、两个或多个顶点，这主要反映在每个误差与多少个优化变量有关。


>g2o 的一般步骤
1. 定义顶点和边的类型
2. 构建图
3. 选择优化算法
4. 调用 g2o 进行优化，返回结果





&emsp;
## 代码

>头文件
```c++
#ifndef G2O_APPLICATION_HPP
#define G2O_APPLICATION_HPP

#include <iostream>
#include <g2o/core/base_vertex.h>
#include <g2o/core/base_unary_edge.h>
#include <g2o/core/block_solver.h>
#include <g2o/core/optimization_algorithm_levenberg.h>
#include <g2o/core/optimization_algorithm_gauss_newton.h>
#include <g2o/core/optimization_algorithm_dogleg.h>
#include <g2o/solvers/dense/linear_solver_dense.h>
#include <Eigen/Core>
#include <opencv2/core/core.hpp>
#include <cmath>
#include <chrono>
using namespace std;

// 曲线模型的顶点，模板参数：优化变量维度和数据类型
class CurveFittingVertex: public g2o::BaseVertex<3, Eigen::Vector3d>
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    virtual void setToOriginImpl() // 重置
    {
    _estimate << 0,0,0;
    }

    virtual void oplusImpl( const double* update ) // 更新
    {
    _estimate += Eigen::Vector3d(update);
    }
    // 存盘和读盘：留空
    virtual bool read( istream& in ) {}
    virtual bool write( ostream& out ) const {}
};

// 误差模型 模板参数：观测值维度，类型，连接顶点类型
class CurveFittingEdge: public g2o::BaseUnaryEdge<1,double,CurveFittingVertex>
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    CurveFittingEdge( double x ): BaseUnaryEdge(), _x(x) {}
    // 计算曲线模型误差
    void computeError()
    {
    const CurveFittingVertex* v = static_cast<const CurveFittingVertex*> (_vertices[0]);
    const Eigen::Vector3d abc = v->estimate();
    _error(0,0) = _measurement - std::exp( abc(0,0)*_x*_x + abc(1,0)*_x + abc(2,0) ) ;
    }
    virtual bool read( istream& in ) {}
    virtual bool write( ostream& out ) const {}
public:
    double _x; // x 值， y 值为 _measurement
};

#endif
```

&emsp;
>库
```c++
g2o_core g2o_types_slam3d g2o_solver_csparse g2o_stuff g2o_csparse_extension

路径: /home/liheqian/datav/3rdparty/sourcecode/g2o/lib/
```


&emsp;
>主函数
```c++
#include "6.4_g2o_application.hpp"

int main(int argc, char** argv)
{
    //（1）生成实际的 y=exp(ax^2+bx+c) 曲线数据数据
    double a=1.0, b=2.0, c=1.0; // 真实参数值
    int N=100; // 数据点
    double w_sigma=1.0; // 噪声Sigma值
    cv::RNG rng; // OpenCV随机数产生器

    vector<double> x_data, y_data; // 数据
    cout<<"generating data: "<<endl;
    for ( int i=0; i<N; i++ )
    {
        double x = i/100.0;
        x_data.push_back ( x );
        y_data.push_back (
        exp ( a*x*x + b*x + c ) + rng.gaussian ( w_sigma )
        );
        cout<<x_data[i]<<" "<<y_data[i]<<endl;
    }

    // （2）构建图优化，先设定g2o
    // 矩阵块：每个误差项优化变量维度为 3 ，误差值维度为 1
    typedef g2o::BlockSolver< g2o::BlockSolverTraits<3,1> > Block;
    // 线性方程求解器：稠密的增量方程
    Block::LinearSolverType* linearSolver = new g2o::LinearSolverDense<Block::PoseMatrixType>();
    // 矩阵块求解器
    // 原代码错误: Block* solver_ptr = new Block( linearSolver ); 
    Block* solver_ptr = new Block( std::unique_ptr<Block::LinearSolverType>(linearSolver) );

    // （）选择 GN, LM 或 DogLeg 算法
    // a. LM 算法
    // 原代码错误: g2o::OptimizationAlgorithmLevenberg* solver = new g2o::OptimizationAlgorithmLevenberg( solver_ptr );
    g2o::OptimizationAlgorithmLevenberg* solver = new g2o::OptimizationAlgorithmLevenberg(std::unique_ptr<Block>(solver_ptr) );
    // b. GN 算法
    // g2o::OptimizationAlgorithmGaussNewton* solver = new g2o::OptimizationAlgorithmGaussNewton(std::unique_ptr<Block>(solver_ptr));
    // c. DogLeg 算法
    // g2o::OptimizationAlgorithmDogleg* solver = new g2o::OptimizationAlgorithmDogleg(std::unique_ptr<Block>(solver_ptr));

    g2o::SparseOptimizer optimizer; // 图模型
    optimizer.setAlgorithm( solver ); // 设置求解器
    optimizer.setVerbose( true ); // 打开调试输出

    // 往图中增加顶点
    CurveFittingVertex* v = new CurveFittingVertex();
    v->setEstimate( Eigen::Vector3d(0,0,0) );
    v->setId(0);
    optimizer.addVertex( v );

    // 往图中增加边
    for ( int i=0; i<N; i++ )
    {
        CurveFittingEdge* edge = new CurveFittingEdge( x_data[i] );
        edge->setId(i);
        edge->setVertex( 0, v ); // 设置连接的顶点
        edge->setMeasurement( y_data[i] ); // 观测数值
        // 信息矩阵：协方差矩阵之逆
        edge->setInformation( Eigen::Matrix<double,1,1>::Identity()*1/(w_sigma*w_sigma) );
        optimizer.addEdge( edge );
    }

    // 执行优化
    cout<<"start optimization"<<endl;
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    optimizer.initializeOptimization();
    optimizer.optimize(100);
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>( t2-t1 );
    cout<<"solve time cost = "<<time_used.count()<<" seconds. "<<endl;

    // 输出优化值
    Eigen::Vector3d abc_estimate = v->estimate();
    cout<<"estimated model: "<<abc_estimate.transpose()<<endl;
 
    return 0;
}
```



