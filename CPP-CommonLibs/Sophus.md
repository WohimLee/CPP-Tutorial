# Sophus

`Sophus` 是 Strasdat 维护的李代数库

最早提出李代数的是 Sophus Lie，这个库就以他的名字命名了。

Sophus 库支持 $SO(3)$ 和 $SE(3)$，此外还含有二维运动 $SO(2)$, $SE(2)$ 以及相似变换 $Sim(3)$ 的内容。

它是直接在 Eigen 基础上开发的，我们不需要要安装额外的依赖库。可以直接从 github 上获取 Sophus。由于历史原因，Sophus 早期版本只提供了双精度的李群/李代数类。

后续版本改写成了模板类。模板类的 Sophus 中可以使用不同精度的李群/李代数，但同时增加了使用难度。

以下使用 `非模板的 Sophus 库`。如果准备使用 github 上的 Sophus，请确保使用的是非模板的版本。你可以输入以下命令获得非模板类的 Sophus：

```shell
git clone https://github.com/strasdat/Sophus.git
cd Sophus
git checkout a621ff
```


>头文件
```c++
#include <iostream>
#include <cmath>
using namespace std;

#include <Eigen/Core>
// Eigen 几何模块
#include <Eigen/Geometry>

#include "sophus/so3.h"
#include "sophus/se3.h"
```

&emsp;
## 1 李代数 $\mathfrak{so}(3)$

>构造 $SO(3)$
```c++
int main(int argc, char** argv)
{
    // 定义旋转矩阵 R: 沿 Z 轴转 90 度的旋转矩阵
    Eigen::Matrix3d R = Eigen::AngleAxisd(M_PI/2, Eigen::Vector3d(0,0,1)).toRotationMatrix();
    // （1）从旋转矩阵构造 Sophus::SO(3)
    Sophus::SO3 SO3_R(R); 
    // （2）从旋转向量构造 Sophus::SO(3)
    Sophus::SO3 SO3_v(0, 0, M_PI/2); 
    // （3）从四元数构造 Sophus::SO(3)
    Eigen::Quaterniond q(R); 
    Sophus::SO3 SO3_q(q);

    // 输出 SO(3) 时，以 so(3) 形式输出
    cout << "SO(3) from matrix: "     << SO3_R << endl;
    cout << "SO(3) from vector: "     << SO3_v << endl;
    cout << "SO(3) from quaternion :" << SO3_q << endl;

    return 0;
}
```
&emsp;
>对数映射获得李代数
$$ SO(3) \stackrel{对数映射}{\longrightarrow} \mathfrak{so}(3)$$

```c++
int main(int argc, char** argv)
{
    // 定义旋转矩阵 R: 沿 Z 轴转 90 度的旋转矩阵
    Eigen::Matrix3d R = Eigen::AngleAxisd(M_PI/2, Eigen::Vector3d(0,0,1)).toRotationMatrix();
    // 从旋转矩阵构造 Sophus::SO(3)
    Sophus::SO3 SO3_R(R); 

    // 使用对数映射获得它的李代数
    Eigen::Vector3d so3 = SO3_R.log();
    cout << "so3 = " << so3.transpose() << endl;

    return 0;
}
```
- 为什么没有指数映射？
    - 指数映射只是一个满射。
    - 这意味着每个 $SO(3)$ 中的元素，都通过对数映射可以找到一个 $\mathfrak{so}(3)$ 元素与之对应；但是可能存在多个 $\mathfrak{so}(3)$ 中的元素，对应到同一个 $SO(3)$。


&emsp;
>向量 $\pmb{a} \rightarrow$ 反对称矩阵 $\pmb{A}$
$$\pmb{a}^{∧} = \pmb{A}$$
```c++
int main(int argc, char** argv)
{
    // 定义旋转矩阵 R: 沿 Z 轴转 90 度的旋转矩阵
    Eigen::Matrix3d R = Eigen::AngleAxisd(M_PI/2, Eigen::Vector3d(0,0,1)).toRotationMatrix();
    // 从旋转矩阵构造 Sophus::SO(3)
    Sophus::SO3 SO3_R(R); 
    // 使用对数映射获得它的李代数
    Eigen::Vector3d so3 = SO3_R.log();

    // hat 为向量到反对称矩阵
    cout << "so3 hat = " << Sophus::SO3::hat(so3) << endl;

    return 0;
}
```

&emsp;
>反对称矩阵 $\pmb{A}\rightarrow$ 向量 $\pmb{a}$ 
$$\pmb{A}^{\vee} = \pmb{a} $$

```c++
int main(int argc, char** argv)
{
    // 定义旋转矩阵 R: 沿 Z 轴转 90 度的旋转矩阵
    Eigen::Matrix3d R = Eigen::AngleAxisd(M_PI/2, Eigen::Vector3d(0,0,1)).toRotationMatrix();
    // 从旋转矩阵构造 Sophus::SO(3)
    Sophus::SO3 SO3_R(R); 
    // 使用对数映射获得它的李代数
    Eigen::Vector3d so3 = SO3_R.log();

    // 相对的， vee 为反对称到向量
    cout << "so3 hat vee = " << Sophus::SO3::vee(Sophus::SO3::hat(so3)).transpose() << endl;

    return 0;
}
```

&emsp;
>增量扰动模型的更新
```c++
int main(int argc, char** argv)
{
    // 定义旋转矩阵 R: 沿 Z 轴转 90 度的旋转矩阵
    Eigen::Matrix3d R = Eigen::AngleAxisd(M_PI/2, Eigen::Vector3d(0,0,1)).toRotationMatrix();
    // 从旋转矩阵构造 Sophus::SO(3)
    Sophus::SO3 SO3_R(R); 

    // 增量扰动模型的更新
    // 设置更新量
    Eigen::Vector3d update_so3(1e-4, 0, 0); 
    // 左乘更新
    Sophus::SO3 SO3_updated = Sophus::SO3::exp(update_so3)*SO3_R; 
    cout<<"SO3 updated = "<<SO3_updated<<endl;

    return 0;
}
```

&emsp;
## 2 李代数 $\mathfrak{se}(3)$
>构造 $SE(3)$
```c++
int main(int argc, char** argv)
{
    // 定义变换矩阵 T(R, t)
    // （1）定义旋转矩阵 R: 沿 Z 轴转 90 度的旋转矩阵
    Eigen::Matrix3d R = Eigen::AngleAxisd(M_PI/2, Eigen::Vector3d(0,0,1)).toRotationMatrix();
    // （2）定义平移向量 t: 沿 X 轴平移1
    Eigen::Vector3d t(1,0,0); 

    // 构造 SE(3) 
    // （1）从 R,t 构造SE(3)
    Sophus::SE3 SE3_Rt(R, t); 
    // （2）从 q,t 构造SE(3)
    Eigen::Quaterniond q(R); 
    Sophus::SE3 SE3_qt(q,t); 

    cout << "SE3 from R,t= " << endl << SE3_Rt << endl;
    cout << "SE3 from q,t= " << endl << SE3_qt << endl;

    return 0;
}
```

&emsp;
>对数映射获得
$$ SE(3) \stackrel{对数映射}{\longrightarrow} \mathfrak{se}(3)$$

```c++
int main(int argc, char** argv)
{
    // 定义变换矩阵 T(R, t)
    // （1）定义旋转矩阵 R: 沿 Z 轴转 90 度的旋转矩阵
    Eigen::Matrix3d R = Eigen::AngleAxisd(M_PI/2, Eigen::Vector3d(0,0,1)).toRotationMatrix();
    // （2）定义平移向量 t: 沿 X 轴平移1
    Eigen::Vector3d t(1,0,0); 

    // 从 R,t 构造SE(3)
    Sophus::SE3 SE3_Rt(R, t); 

    // 李代数 se(3) 是一个六维向量，方便起见先 typedef 一下
    typedef Eigen::Matrix<double,6,1> Vector6d;
    Vector6d se3 = SE3_Rt.log();
    cout << "se3 = " << se3.transpose() << endl;
    // 观察输出，会发现在 Sophus 中， se(3) 平移在前，旋转在后。与我们的书是一致的。

    return 0;
}
```

&emsp;
>向量 $\phi \rightarrow$ 反对称矩阵 $\pmb{\Phi}$
$$\mathfrak{so}(3) = \{ \phi \in \mathbb{R}^{3\times 3}， \pmb{\Phi} = \phi^{\wedge} \in \mathbb{R}^{3\times 3}\}$$


```c++
int main(int argc, char** argv)
{
    // 定义变换矩阵 T(R, t)
    // （1）定义旋转矩阵 R: 沿 Z 轴转 90 度的旋转矩阵
    Eigen::Matrix3d R = Eigen::AngleAxisd(M_PI/2, Eigen::Vector3d(0,0,1)).toRotationMatrix();
    // （2）定义平移向量 t: 沿 X 轴平移1
    Eigen::Vector3d t(1,0,0); 

    // 从 R,t 构造SE(3)
    Sophus::SE3 SE3_Rt(R, t); 

    // 通过对数映射获得李代数
    // 李代数 se(3) 是一个六维向量，方便起见先 typedef 一下
    typedef Eigen::Matrix<double,6,1> Vector6d;
    Vector6d se3 = SE3_Rt.log();

    // hat 为 se3 到反对称矩阵运算
    
    cout << "se3 hat = " << endl << Sophus::SE3::hat(se3) << endl;

    return 0;
}
```

&emsp;
>反对称矩阵 $\pmb{A}\rightarrow$ 向量 $\pmb{a}$ 
$$\pmb{A}^{\vee} = \pmb{a} $$

```c++
int main(int argc, char** argv)
{
    // 定义变换矩阵 T(R, t)
    // （1）定义旋转矩阵 R: 沿 Z 轴转 90 度的旋转矩阵
    Eigen::Matrix3d R = Eigen::AngleAxisd(M_PI/2, Eigen::Vector3d(0,0,1)).toRotationMatrix();
    // （2）定义平移向量 t: 沿 X 轴平移1
    Eigen::Vector3d t(1,0,0); 

    // 从 R,t 构造SE(3)
    Sophus::SE3 SE3_Rt(R, t); 

    // 通过对数映射获得李代数
    // 李代数 se(3) 是一个六维向量，方便起见先 typedef 一下
    typedef Eigen::Matrix<double,6,1> Vector6d;
    Vector6d se3 = SE3_Rt.log();

    // vee 为 反对称矩阵到 se3 的运算
    cout << "se3 hat vee = " << Sophus::SE3::vee(Sophus::SE3::hat(se3)).transpose() << endl;

    return 0;
}
```

