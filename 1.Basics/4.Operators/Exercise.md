&emsp;
# Exercise - 相机模型

这个模型有很多种，其中最简单的称为`针孔模型`。针孔模型是很常用，而且有效的模型，它描述了一束光线通过针孔之后，在针孔背面投影成像的关系


&emsp;
## 1 蜡烛投影
在一个暗箱的前方放着一支点燃的蜡烛，蜡烛的光透过暗箱上的一个小孔投影在暗箱的后方平面上，并在这个平面上形成了一个倒立的蜡烛图像。在这个过程中，小孔模型能够把三维世界中的蜡烛投影到一个二维成像平面


&emsp;
## 2 针孔相机模型建模

<div align="center">
    <image src="./imgs/cameraModel.png" width=500 >
</div>


现在来对这个简单的针孔模型进行几何建模。设：
- $O_{xyz}$ 为相机坐标系
  - $O$ 为摄像机的光心，也是针孔模型中的针孔
  - [right, down, forward]，让 $z$ 轴指向相机前方，$x$ 向右，$y$ 向下（不同的软件有自己的定义）
- 现实世界的空间点 $P$，经过小孔 $O$ 投影之后，落在物理成像平面 $O'_{x'y'z'}$ 上，像点为 $P'$
  - $P$ 的坐标: $[X, Y, Z]^T$
  - $P'$的坐标: $[X', Y', Z']^T$
- 并且设物理成像平面到小孔的距离为 $f$（焦距）


那么，根据三角形相似关系，有：
$$\frac{Z}{f} = -\frac{X}{X'} = -\frac{Y}{Y'} $$

其中负号表示成的像是倒立的。为了简化模型，我们把可以成像平面对称到相机前方，和三维空间点一起放在摄像机坐标系的同一侧。这样做可以把公式中的负号去掉，使式子更加简洁：

$$\frac{Z}{f} = \frac{X}{X'} = \frac{Y}{Y'} $$


整理得：
$$\begin{cases}X' = f\frac{X}{Z}\\ 
\\ Y' = f\frac{Y}{Z} \end{cases}$$

```c++
#include <stdio.h>

int main()
{
    float focal = 0.5; // 500mm
    float Xreal = 2; // m
    float Yreal = 4; // m
    float Zreal = 6; // m

    float Xproj = focal * Xreal / Zreal;
    float Yproj = focal * Yreal / Zreal;

    printf("Point in 3D space: (X,Y,Z) = (%f, %f, %f)\n", Xreal, Yreal, Zreal);
    printf("Project to: (X',Y,focal) = (%f, %f, %f)\n", Xproj, Yproj, focal);

    return 0;
}
```


&emsp;
## 3 从物体到像素
在相机中，我们最终获得的是图片上一个个的像素，这需要在成像平面上对像进行采样和量化

为了描述传感器将感受到的光线转换成图像像素的过程，我们设在物理成像平面上固定着一个像素平面 `o-u-v`。我们在像素平面得到了 $P'$ 的像素坐标：$[u, v]^T$。

像素坐标系通常的定义方式是：原点 $o'$ 位于图像的左上角，$u$ 轴向右与 $x$ 轴平行，$v$ 轴向下与 $y$ 轴平行。像素坐标系与成像平面之间，相差了
- 一个缩放
    - 设像素坐标在 $u$ 轴上缩放了 $α$ 倍
    - 在 $v$ 上缩放了 $β$ 倍
- 一个原点的平移：设原点平移了 $[c_x, c_y]^T$

那么，$P'$ 的坐标与像素坐标 $[u, v]^T$ 的关系为：

$$\begin{cases} u = \alpha X' + c_x \\
v = \beta Y' + c_y\end{cases}$$

```c++
#include <stdio.h>

int main()
{
    float focal = 0.5; // 500mm
    float alpha = 100;
    float beta  = 100;
    float cx    = 0.32; // 320mm
    float cy    = 0.24; // 2400mm

    float Xreal = 2; // m
    float Yreal = 4; // m
    float Zreal = 6; // m

    float Xproj = focal * Xreal / Zreal;
    float Yproj = focal * Yreal / Zreal;

    int u = alpha * Xproj + cx;
    int v = beta  * Yproj + cy;


    printf("Point in 3D space: (X,Y,Z) = (%f, %f, %f)\n", Xreal, Yreal, Zreal);
    printf("Project to: (X',Y,focal) = (%f, %f, %f)\n", Xproj, Yproj, focal);
    printf("Pixel coordinates: (u,v) = (%d, %d)\n", u, v);
    return 0;
}
```


&emsp;
## 4 合并简化
将式子：
$$\begin{cases}X' = f\frac{X}{Z}\\ 
\\ Y' = f\frac{Y}{Z} \end{cases}$$

代入
$$\begin{cases} u = \alpha X' + c_x \\
v = \beta Y' + c_y\end{cases}$$
并把 $\alpha f$ 合并成 $f_x$，把 $\beta f$ 合并成 $f_y$，得：

$$\begin{cases} u = f_x \frac{X}{Z} + c_x \\
v = f_y \frac{Y}{Z}  + c_y\end{cases}$$

- $X，Y，Z$：相机坐标的 $X，Y，Z$（深度 depth）
- $f_x，f_y$：缩放系数和焦距的乘积
- $c_x，c_y$：中心偏移量
- $u，v$：像素坐标
```c++
#include <stdio.h>

int main()
{
    float focal = 0.5; // 500mm
    float alpha = 100;
    float beta  = 100;

    // Intrisic Parameters 相机内参
    float fx    = alpha * focal;
    float fy    = beta  * focal;
    float cx    = 0.32; // 320mm
    float cy    = 0.24; // 240mm

    float Xreal = 2; // m
    float Yreal = 4; // m
    float Zreal = 6; // m

    int u = fx * Xreal/Zreal + cx;
    int v = fy * Yreal/Zreal + cy;

    printf("Point in 3D space: (X,Y,Z) = (%f, %f, %f)\n", Xreal, Yreal, Zreal);
    printf("Pixel coordinates: (u,v) = (%d, %d)\n", u, v);
    return 0;
}
```
