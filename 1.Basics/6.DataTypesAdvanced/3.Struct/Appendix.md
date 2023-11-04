&emsp;
# Appendix - C 语言的 struct

>struct
- 声明必须带上 `struct` 关键字
```c++
#include <stdio.h>

struct msgTemp
{
    char a;
    char b;
    int index;
};

int main(int argc, char** argv)
{
    struct msgTemp msg[5];
    for(int i=0; i<5; i++)
    {
        msg[i].index = i;
        msg[i].a = 10+i;
        msg[i].b = 20+i;
    }
    for(int i=0; i<5; i++)
        printf("msg[%d]: a=%d, b=%d, index=%d\n", 
               i, msg[i].a, msg[i].b, msg[i].index);

    return 0;
}
```


>结合 typedef 使用
- 可以用别名, 且不需要 struct 关键字
```c++
#include <stdio.h>

typedef struct msgTemp
{
    char a;
    char b;
    int index;
}MSG;

int main(int argc, char** argv)
{
    struct msgTemp msg1[5];
    MSG msg2[5]; // 不用 struct 关键字
    for(int i=0; i<5; i++)
    {
        msg1[i].index = i;
        msg1[i].a = 10+i;
        msg1[i].b = 20+i;
    }
    for(int i=0; i<5; i++)
        printf("msg[%d]: a=%d, b=%d, index=%d\n", 
               i, msg1[i].a, msg1[i].b, msg1[i].index);
    return 0;
}
```

>在 struct 内用本身的 struct
- 要加关键字 struct
```c
// 错误使用
typedef struct ArcNode {
    int nAdjNodeIdx;
    ArcNode* pNextArc; // Use 'struct ArcNode' to refer to the type within its own definition.
} ArcNode;

// 正确使用
typedef struct ArcNode {
    int nAdjNodeIdx;
    struct ArcNode* pNextArc; // Use 'struct ArcNode' to refer to the type within its own definition.
} ArcNode;
```