&emsp;
# Intro - 编译安装

## 1 安装git
```shell
apt update  # 只检查，不更新（已安装的软件包是否有可用的更新，给出汇总报告）
apt upgrade # 更新已安装的软件包
apt install -y git
```

&emsp;
## 2 下载 OpenCV 源码
（1）检查是否安装git命令，没有安装的用下面命令安装
```c++
apt update && apt upgrade && install -y git
```
（2）用git命令下载OpenCV
```c++
git clone https://gitee.com/yxd.osc.com/opencv.git
```

（3）安装software-properties-common
```c++
sudo apt install -y -f software-properties-common
```

&emsp;
## 3 安装依赖项
>libjasper1 libjasper-dev
```c++
add-apt-repository "deb http://security.ubuntu.com/ubuntu \
xenial-security main"
sudo add-apt-repository "deb http://security.ubuntu.com/ubuntu xenial-security main"
sudo apt update
sudo apt install -y libjasper1 libjasper-dev
```

直接执行下面这个，其它都弄到这里了
```c++
sudo apt install -y build-essential \
cmake libgtk2.0-dev pkg-config libavcodec-dev \
libavformat-dev libswscale-dev \
python3-dev python3-numpy libtbb2 libtbb-dev libjpeg-dev \
libpng-dev libdc1394-22-dev
```

&emsp;
## 4 生成安装文件(时间比较久)

到包含CMakeList.txt文件的目录下执行建build文件夹
```c++
mkdir build
cd build
```
执行
```shell
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=[自定义最终安装路径] ..
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/home/shenlan/3rdParty/opencv-3.4.8 ..
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/home/shenlan/3rdParty/eigen-3.1.0 ..
```
在build文件夹下执行
```shell
make -j7
```


&emsp;
## 5 安装OpenCV
在build目录下执行，这个时候最终目录才会出现lib include 等
```shell
make install
```


&emsp;
## 6 导入动态链接库到系统
echo命令，将 [自定义安装目录]/lib 导入动态链接库
```shell
/bin/bash -c 'echo "[自定义安装目录]/lib" > /etc/ld.so.conf.d/opencv.conf'
```

>ldconfig的主要用途
```c++
默认搜寻/lilb和/usr/lib，以及配置文件/etc/ld.so.conf内所列的目录下的库文件。ldconfig通常在系统启动时运行，而当用户安装了一个新的动态链接库时，就需要手工运行这个命令
```

>ldconfig需要注意的地方
1. 往/lib和/usr/lib里面加东西，是不用修改/etc/ld.so.conf文件的，但是添加完后需要调用下ldconfig，不然添加的library会找不到。
2. 如果添加的library不在/lib和/usr/lib里面的话，就一定要修改/etc/ld.so.conf文件，往该文件追加library所在的路径，然后也需要重新调用下ldconfig命令。比如在安装MySQL的时候，其库文件/usr/local/mysql/lib，就需要追加到/etc/ld.so.conf文件中。命令如下：
```shell
# echo "/usr/local/mysql/lib" >>/etc/ld.so.conf
# ldconfig -v | grep mysql
3、如果添加的library不在/lib或/usr/lib下，但是却没有权限操作写/etc/ld.so.conf文件的话，这时就需要往export里写一个全局变量LD_LIBRARY_PATH，就可以了。

