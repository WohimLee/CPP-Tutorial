&emsp;
# Eigen
- 官方网站：https://eigen.tuxfamily.org/index.php?title=Main_Page
- 官方文档：https://eigen.tuxfamily.org/index.php?title=Main_Page
- gitlab源码：https://gitlab.com/libeigen/eigen

&emsp;
>头文件
```c++
// Eigen 部分
#include <Eigen/Core>
// 稠密矩阵的代数运算（逆，特征值等）
#include <Eigen/Dense>
// 计时器
#include <ctime>
// 宏定义，定义矩阵的 “大小”
#define MATRIX_SIZE 50
```

# 1 基本使用
## 1.1 Eigen::Matrix 声明矩阵
Eigen 以矩阵为基本数据单元。它是一个模板类。它的前三个参数为：
- 数据类型
- 行
- 列

>示例：声明一个 2*3 的 float 矩阵
```c++
Eigen::Matrix<float, 2, 3> matrix_23;
```

同时，Eigen 通过 typedef 提供了许多内置类型，不过底层仍是 `Eigen::Matrix`
- `Vector3d` 列向量：实质上是 `Eigen::Matrix<double, 3, 1>`
- `Matrix3d` 方阵： 实质上是 `Eigen::Matrix<double, 3, 3>`

>示例：声明列向量和方阵
```c++
// 列向量
Eigen::Vector3d vector_31;
Eigen::Vector3d v(1, 0, 0);
// 方阵
Eigen::Matrix3d matrix_33;
```
>示例：声明单位矩阵
```c++
Eigen::Matrix3d matrix = Eigen::Matrix3d::Identity();
```

&emsp;
## 1.2 不确定大小

如果不确定矩阵大小，可以使用动态大小的矩阵。但这两种不能用 `<<` 输入数据
>示例：
```c++
Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic;
// 更简单的
Eigen::MatrixXd matrix_x;
// 这种类型还有很多，我们不一一列举
```

&emsp;
## 1.3 矩阵的操作
>示例：初始化
```c++
int main()
{
    //（1）随机初始化
    Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Random();
    //（2）零初始化
    Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero(); 
    return 0;
}
```

>示例：输入输出数据
```c++
matrix_23 << 1, 2, 3, 4, 5, 6;
// 输出
cout << matrix_23 << endl;
```

>示例：用 () 访问数据
```c++
int main()
{
    Eigen::Matrix<float, 2, 3> matrix;
    matrix << 1,2,3,4,5,6;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << matrix(i, j) << " ";
        cout << endl;       
    }
    return 0;
}
```

&emsp;
## 1.4 矩阵的乘法

>示例：矩阵和向量相乘
```c++
// 矩阵和向量相乘（实际上仍是矩阵和矩阵）
// 但是在这里你不能混合两种不同数据类型的矩阵，像这样是错的
Eigen::Matrix<double, 2, 1> result_wrong_type = matrix_23 * v_3d;
// 应该显式转换
int main()
{

    Eigen::Matrix<float, 2, 3> matrix;
    Eigen::Vector3d vector;
    matrix << 1,2,3,4,5,6;
    vector << 3, 2, 1;
    // 通过 .cast<类型>() 转换为一致的数据类型
    Eigen::Matrix<double, 2, 1> result = matrix.cast<double>() * vector;
    std::cout << result << std::endl;
    return 0;
}
```


>示例：注意维度问题
```c++
// 同样你不能搞错矩阵的维度
// 试着运行下面的语句，看看会报什么错
Eigen::Matrix<double, 2, 3> result_wrong_dimension = matrix.cast<double>() * vector;
```

&emsp;
## 1.5 其它运算
>示例：转置、求和、迹、数乘、逆、行列式
```c++
int main()
{
    Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Random();
    cout << matrix_33 << endl << endl;
    // （1）转置
    cout << matrix_33.transpose() << endl; 
    // （2）各元素和
    cout << matrix_33.sum() << endl; 
    // （3）迹
    cout << matrix_33.trace() << endl; 
    // （4）数乘
    cout << 10*matrix_33 << endl; 
    // （5）逆
    cout << matrix_33.inverse() << endl; 
    // （6）行列式
    cout << matrix_33.determinant() << endl; 
    return 0;
}
```

>示例：求特征值与特征向量
```c++
int main()
{
    Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Random();

    // 实对称矩阵可以保证对角化成功
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d>eigen_solver(matrix_33.transpose()*matrix_33);
    // 特征值
    cout << "Eigen values = " << eigen_solver.eigenvalues() << endl;
    // 特征向量
    cout << "Eigen vectors = " << eigen_solver.eigenvectors() << endl;
    return 0;
}
```

>示例：解方程
```c++
int main()
{
    // 我们求解 matrix_NN * x = v_Nd 这个方程
    // N 的大小在前边的宏里定义，矩阵由随机数生成
    // 直接求逆自然是最直接的，但是求逆运算量大
    Eigen::Matrix< double, MATRIX_SIZE, MATRIX_SIZE > matrix_NN;
    matrix_NN = Eigen::MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
    Eigen::Matrix< double, MATRIX_SIZE, 1> v_Nd;
    v_Nd = Eigen::MatrixXd::Random(MATRIX_SIZE,1);

    clock_t time_stt = clock(); // 计时
    // 直接求逆
    Eigen::Matrix<double,MATRIX_SIZE, 1> x = matrix_NN.inverse()*v_Nd;
    cout << "time use in normal invers is " << 1000* (clock() - time_stt)/(double)CLOCKS_PER_SEC << "ms" << endl;

    // 通常用矩阵分解来求，例如 QR 分解，速度会快很多
    time_stt = clock();
    x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
    cout << "time use in Qr compsition is " << 1000* (clock() - time_stt)/(double)CLOCKS_PER_SEC << "ms" << endl;
    return 0;
}
```

&emsp;
# 2 几何模块

现在，我们来实际演练一下前面讲到的各种旋转表达方式。我们将在 Eigen 中使用四元数、欧拉角和旋转矩阵，演示它们之间的变换方式。我们还会给出一个可视化程序，帮助读者理解这几个变换的关系。

>头文件
```c++
#include <iostream>
#include <cmath>
using namespace std;

#include <Eigen/Core>
// Eigen 几何模块
#include <Eigen/Geometry>
```

Eigen 中对各种形式的表达方式总结如下。请注意每种类型都有`单精度`和`双精度`两种数据类型，而且和之前一样，不能由编译器自动转换。下面以双精度为例，你可以把最后的 `d` 改成 `f`，即得到单精度的数据结构。
- 旋转矩阵（3 × 3）：Eigen::Matrix3d。
- 旋转向量（3 × 1）：Eigen::AngleAxisd
- 欧拉角（3 × 1）：Eigen::Vector3d
- 四元数（4 × 1）：Eigen::Quaterniond
- 欧氏变换矩阵（4 × 4）：Eigen::Isometry3d
- 仿射变换（4 × 4）：Eigen::Affine3d
- 射影变换（4 × 4）：Eigen::Projective3d

&emsp;

Eigen/Geometry 模块提供了各种旋转和平移的表示

## 2.1 声明与定义
>旋转矩阵 $\pmb{R}$
- 3D 旋转矩阵直接使用 Matrix3d 或 Matrix3f
```c++
// 用单位矩阵作初始化
Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
```

&emsp;
>旋转向量 $θ\pmb{n}$
- 使用 AngleAxis, 它底层不直接是 Matrix ，但运算可以当作矩阵（因为重载了运算符）
```c++
// 沿 Z 轴旋转 45 度
Eigen::AngleAxisd rotation_vector(M_PI/4, Eigen::Vector3d(0,0,1)); 
```


&emsp;
>欧式变换矩阵 $\pmb{T}$
- 声明欧氏变换矩阵 $\pmb{T}$ 使用 Eigen::Isometry
```c++
int main(int argc, char** argv)
{
    // 声明旋转向量（角轴，Angle Axis）
    Eigen::AngleAxisd rotation_vector(M_PI/4, Eigen::Vector3d(0,0,1)); 

    // 虽然称为 3d ，实质上是 4＊4 的矩阵 
    Eigen::Isometry3d T = Eigen::Isometry3d::Identity(); 
    // （1）设置旋转向量 rotation_vector 
    T.rotate(rotation_vector); 
    // （2）设置平移向量  (1,3,4)
    T.pretranslate(Eigen::Vector3d(1,3,4)); 
    cout << "Transform matrix = \n" << T.matrix() <<endl;
}
```

>四元数
```c++
Eigen::Quaterniond q;
```


&emsp;
## 2.2 不同表示方式的转换

>$θ\pmb{n}$ 转 $\pmb{R}$
- 用 matrix() 转换成矩阵，也可以用 toRotationMatrix()
```c++
int main(int argc, char** argv)
{
    Eigen::AngleAxisd rotation_vector(M_PI/4, Eigen::Vector3d(0,0,1));
    cout.precision(3);
    // 用 matrix() 转换成矩阵
    cout << "rotation matrix = \n" << rotation_vector.matrix() << endl;
    // 也可以用 toRotationMatrix()
    cout << "rotation matrix = \n" << rotation_vector.toRotationMatrix() << endl;
    return 0;
}
```

&emsp;
>$\pmb{R}$ 转 欧拉角$[r, p, y]^T$
- 用 eulerAngles() 可以将旋转矩阵直接转换成欧拉角
```c++
int main(int argc, char** argv)
{
    // 声明向量 v(1, 0, 0)^T
    Eigen::Vector3d v(1, 0, 0);
    // 声明旋转向量（角轴，Angle Axis）
    Eigen::AngleAxisd rotation_vector(M_PI/4, Eigen::Vector3d(0,0,1)); 
    // Angel Axis 转 Rotation Matrix
    Eigen::Matrix3d rotation_matrix = rotation_vector.toRotationMatrix();
    // Rotation Matrix 转 Euler Angles
    // 2, 1, 0 分别对应 Z Y X，即 yaw pitch roll
    Eigen::Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0);
    cout << "yaw pitch roll = " << euler_angles.transpose() << endl;
    return 0;
}
```
&emsp;
>转四元数
- 可以直接把 $θ\pmb{n}$ （角轴/轴角，Angle Axis）赋值给四元数，反之亦然
```c++
int main(int argc, char** argv)
{
    // 声明向量 v(1, 0, 0)^T
    Eigen::Vector3d v(1, 0, 0);
    // 声明旋转向量（角轴，Angle Axis）
    Eigen::AngleAxisd rotation_vector(M_PI/4, Eigen::Vector3d(0,0,1)); 
    
    Eigen::Quaterniond q = Eigen::Quaterniond(rotation_vector);
    // 请注意 coeffs 的顺序是 (x,y,z,w), w 为实部，前三者为虚部
    cout << "quaternion = \n" << q.coeffs() << endl; 
}
```
- 也可以把 $\pmb{R}$ （旋转矩阵）赋给它
```c++
int main(int argc, char** argv)
{
    // 声明向量 v(1, 0, 0)^T
    Eigen::Vector3d v(1, 0, 0);
    // 声明旋转向量（角轴，Angle Axis）
    Eigen::AngleAxisd rotation_vector(M_PI/4, Eigen::Vector3d(0,0,1)); 
    // Angel Axis 转 Rotation Matrix
    Eigen::Matrix3d rotation_matrix = rotation_vector.toRotationMatrix();
    
    Eigen::Quaterniond q = Eigen::Quaterniond(rotation_matrix);
    cout<<"quaternion = \n"<<q.coeffs() <<endl;
}
```

&emsp;
## 2.3 旋转的表示


>旋转向量 $θ\pmb{n}$
- 用旋转向量 $θ\pmb{n}$ （角轴/轴角，Angle Axis）表示旋转
```c++
int main(int argc, char** argv)
{
    // 声明旋转向量（角轴，Angle Axis）
    Eigen::AngleAxisd rotation_vector(M_PI/4, Eigen::Vector3d(0,0,1)); 
    // 声明向量 v(1, 0, 0)^T
    Eigen::Vector3d v(1, 0, 0);
    Eigen::Vector3d v_rotated = rotation_vector * v;
    cout << "(1, 0, 0) after rotation = " << v_rotated.transpose() << endl;
    return 0;
}
```
>旋转矩阵 $\pmb{R}$
- 用旋转矩阵 $\pmb{R}$ 表示旋转
```c++
int main(int argc, char** argv)
{
    // 声明旋转向量（角轴，Angle Axis）
    Eigen::AngleAxisd rotation_vector(M_PI/4, Eigen::Vector3d(0,0,1)); 
    // 声明向量 v(1, 0, 0)^T
    Eigen::Vector3d v(1, 0, 0);
    
    Eigen::Matrix3d rotation_matrix = rotation_vector.toRotationMatrix();
    Eigen::Vector3d v_rotated = rotation_vector * v;
    cout << "(1, 0, 0) after rotation = " << v_rotated.transpose() << endl;
    return 0;
}
```

>变换矩阵 $T$
- 用变换矩阵进行旋转
```c++
int main(int argc, char** argv)
{
    // 声明向量 v(1, 0, 0)^T
    Eigen::Vector3d v(1, 0, 0);
    // 声明旋转向量（角轴，Angle Axis）
    Eigen::AngleAxisd rotation_vector(M_PI/4, Eigen::Vector3d(0,0,1)); 
    
    // 虽然称为 3d ，实质上是 4＊4 的矩阵 
    Eigen::Isometry3d T = Eigen::Isometry3d::Identity(); 
    // 设置旋转向量 rotation_vector 
    T.rotate(rotation_vector); 
    // 设置平移向量  (1,3,4)
    T.pretranslate(Eigen::Vector3d(1,3,4)); 
    cout << "Transform matrix = \n" << T.matrix() <<endl;
    Eigen::Vector3d v_transformed = T*v; // 相当于 R*v+t
    cout<<"v tranformed = "<<v_transformed.transpose()<<endl;
}
```

&emsp;
>四元数旋转
- 使用四元数旋转一个向量，使用重载的乘法即可，注意数学上是 $\pmb{qvq}^{-1}$
```c++
int main(int argc, char** argv)
{
    // 声明向量 v(1, 0, 0)^T
    Eigen::Vector3d v(1, 0, 0);
    // 声明旋转向量（角轴，Angle Axis）
    Eigen::AngleAxisd rotation_vector(M_PI/4, Eigen::Vector3d(0,0,1)); 
    // Angel Axis 转 Rotation Matrix
    Eigen::Matrix3d rotation_matrix = rotation_vector.toRotationMatrix();

    Eigen::Quaterniond q = Eigen::Quaterniond(rotation_matrix);
    
    Eigen::Vector3d v_rotated = q*v; 
    cout << "(1,0,0) after rotation = " << v_rotated.transpose()<<endl;
}
```
