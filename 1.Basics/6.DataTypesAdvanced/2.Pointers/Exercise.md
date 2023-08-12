&emsp;
# Exercise

1. GPU 的 CUDA Cores 和 Tensor Cores

    <div align=center>
        <image src="imgs/nvidia-ampere-ga100-block-diagram.jpg" width=>
    </div>


&emsp;

2. 确定调用的 CUDA Core 的位置
    <div align=center>
        <image src="imgs/gpu.png" width=>
    </div>
- Grid dim=(2, 9)
- Block dim=(14, 5)
- 求: 如果是按行排列的规则, 第 [1, 6] 个 block, 第 [10, 3] 个 thread 排第几？