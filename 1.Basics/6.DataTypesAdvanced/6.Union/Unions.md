
# *联合（Union）

联合（Union）使得同一段内存可以按照不同的数据类型来访问，数据实际是存储在同一个位置的。它的声命和使用看起来与 struct 很像，但实际功能完全不同

union 中的所有被声明的元素占据同一段内存空间，其大小取决于声明中最长的元素的大小
```c++
// |-------||-------||-------||-------|
// |-------|
union name{
    type1 element1;
    type2 element2;
    type3 element3;
    ...
}obj;
```
>Example 1
- 颜色转换
```c++
typedef union {
    struct {
        unsigned char r; // 1 Bytes
        unsigned char g; // 1 Bytes
        unsigned char b; // 1 Bytes
        unsigned char a; // 1 Bytes
    } channels;
    unsigned int value; // 4 Bytes RGBA
} Color;

int main() {
    Color color;
    
    // Manipulate the color as individual channels
    color.channels.r = 255;
    color.channels.g = 128;
    color.channels.b = 64;
    color.channels.a = 255;
    
    // Output the color as individual channels
    printf("Red: %d, Green: %d, Blue: %d, Alpha: %d\n",
        color.channels.r, color.channels.g, color.channels.b, color.channels.a);
    
    // Output the color as a single 32-bit value
    printf("Color as an integer: 0x%x\n", color.value);

    return 0;
}
```


&emsp;
>Example 2
- 快速计算 $\frac{1}{\sqrt{x}}$ 的近似值, 高性能
```c++
int main()
{
    float x = 2;
    float xhalf = 0.5f * x;
    union{
        float x;
        int i;
    }u;
    u.x = x;
    u.i = 0x5f3759df - (u.i >> 1);
    // Newton-Raphson 算法
    u.x = u.x * (1.5f - xhalf * u.x * u.x);
    u.x = u.x * (1.5f - xhalf * u.x * u.x);

    return 0;
}
```


