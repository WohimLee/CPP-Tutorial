# 枚举（enumerations）

- 枚举可以用来生成一些任意类型的数据
- 枚举数据类型在编译时是被编译为整型数值的
  - 这个数值可以自己指定
  - 如果没有指定常量，枚举中第一个列出的可能值为 0，后面的每一个值为前面一个值加1



>定义语法
```c++
enum name{
    value1, // 注意是逗号, 不是分号
    value2,
    value3,
    ...
    ...
}obj;
```

注意：
- 这里没有使用任何基本数据类型
- name: 是新的数据类型，没有基于任何已存在的数据类型
- obj: 可以取花括号内任何一个值

>Example
- enum 大量与 switch...case 结合使用
```c++
#include <iostream>
using namespace std;

// Input sensor
enum eSensor{
    MONOCULAR=0,
    STEREO=1,
    RGBD=2
};

// L-norms for normalization
enum LNorm
{
    L1,
    L2
};

/// Scoring type
enum ScoringType
{
  L1_NORM,
  L2_NORM,
  CHI_SQUARE,
  KL,
  BHATTACHARYYA,
  DOT_PRODUCT,
};

int main()
{
    eSensor cam = MONOCULAR;

    printf("Initializing SLAM...\n");
    switch(cam){
        case MONOCULAR:
            printf("Constructing MONOCULAR object.\n");
            break;
        case STEREO:
            printf("Constructing STEREO object.\n");
            break;
        case RGBD:
            printf("Constructing RGBD object.\n");
            break;
        default:
            printf("Unknown Camera Sensor.\n");
    }

    return 0;
}
```




