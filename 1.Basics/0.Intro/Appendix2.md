&emsp;
# Appendix
VSCODE 下, 如果没有找到头文件, 或者是使用其他库的时候, 没有提示函数, 这个时候可以配置 c_cpp_properties.json 文件
>如何调出 c_cpp_properties.json
- 随便打开一个 .cpp 文件
- 右下角点击 Linux
- 点击 Edit Configurations(JSON)

```json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "/usr/local/cuda-10.1/include/**",
                "/datav/lean/opencv4.5.1/include/opencv4/**",
                "/datav/lean/tensorRT6.0.1.5_cuda10.1_cudnn7.6.0.3/include/**"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "gnu11",
            "cppStandard": "gnu++14",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}
```