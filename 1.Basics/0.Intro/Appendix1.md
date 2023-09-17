&emsp;
# VSCODE 下 Debug 设置

总共需要 2 个文件
- task.json: 在 launch 前需要执行的编译任务
- launch.json: 用来读取可执行文件

>注意
- 编译的时候必须加 `-g` 选项, 否则不会有调试信息

&emsp;
## 1 task.json
>调出 `task.json` 文件
- Terminal -> Config Task -> Create tasks file from template -> Others
<div align=center>
    <image src="imgs/task.png" width=>
</div>

&emsp;
>task.json 配置
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "make",
            "type": "shell",      // 用 shell 终端
            "command": "make run" // 在 shell 下执行的命令
        }
    ]
}
```


&emsp;
## 2 launch.json
>调出 launch.json 文件
- Run -> Add Configuration...

>配置 launch.json 文件
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name" : "Debug",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/workspace/exec", // 二进制文件所在位置
            "args": [],
            "preLaunchTask": "make", // 必须跟 task.json 的 label 一样
            "cwd": "${workspaceFolder}",
        }
    ]
}
```

