
&emsp;
# emplace_back()
## 1 emplace_back()用法
- 功能：和 push_back() 相同，都是在 vector 容器的尾部添加一个元素。

>emplace_back函数原型：
```c++
template <class... Args>  
void emplace_back (Args&&... args);
```

>示例
```c++
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> values{};    
    values.emplace_back(1);    
    values.emplace_back(2);    
    for (int i = 0; i < values.size(); i++) {
            cout << values[i] << " ";    
    }    
    return 0;
}
```

&emsp;
## 2 emplace_back() 和 push_back()的区别
### （1）考虑是否原地构造
- push_back()：向容器中加入一个右值元素(临时对象)时，首先会调用构造函数构造这个临时对象，然后需要调用拷贝构造函数将这个临时对象放入容器中。原来的临时变量释放。这样造成的问题就是临时变量申请资源的浪费。

- emplace_back()：引入了右值引用，转移构造函数，在插入的时候直接构造，只需要构造一次即可。

- 也就是说，两者的底层实现的机制不同。push_back() 向容器尾部添加元素时，首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素）；而 emplace_back() 在实现时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程。

>示例
```c++
#include <vector> 
#include <iostream> 
using namespace std;
class testDemo
{
public:
    testDemo(int num):num(num){
        std::cout << "调用构造函数" << endl;
    }
    testDemo(const testDemo& other) :num(other.num) {
        std::cout << "调用拷贝构造函数" << endl;
    }
    testDemo(testDemo&& other) :num(other.num) {
        std::cout << "调用移动构造函数" << endl;
    }
private:
    int num;
};

int main()
{
    cout << "emplace_back:" << endl;
    std::vector<testDemo> demo1;
    demo1.emplace_back(2);  

    cout << "push_back:" << endl;
    std::vector<testDemo> demo2;
    demo2.push_back(2);
}
```
- push_back() 在底层实现时，会优先选择调用移动构造函数，如果没有的话，则直接在容器的末尾构造对象，这样就省去了拷贝的过程。
- 显然完成同样的操作，push_back() 的底层实现过程比 emplace_back() 更繁琐，换句话说，emplace_back() 的执行效率比 push_back() 高。

&emsp;
### （2）考虑尾插左值和右值

```c++
#include <vector> 
#include <iostream> 
using namespace std;
class testDemo
{
public:
    testDemo(int num):num(num){
        std::cout << "调用构造函数" << endl;
    }
    testDemo(const testDemo& other) :num(other.num) {
        std::cout << "调用拷贝构造函数" << endl;
    }
    testDemo(testDemo&& other) :num(other.num) {
        std::cout << "调用移动构造函数" << endl;
    }
private:
    int num;
};

int main()
{  
    testDemo t1(2);
    cout << "emplace_back:" << endl;
    std::vector<testDemo> demo1;
    demo1.emplace_back(t1);  
    //demo1.emplace_back(move(t1));  

    cout << "push_back:" << endl;
    std::vector<testDemo> demo2;
    demo2.push_back(t1);
    //demo1.push_back(move(t1));  
}
```

- push_back 可以接收左值也可以接受右值，接收左值时使用拷贝构造，接收右值时使用移动构造
- emplace_back 接收右值时调用类的移动构造
- emplace_back 接收左值时，实际上的执行效果是先对传入的参数进行拷贝构造，然后使用拷贝构造后的副本，也就是说，emplace_back在接收一个左值的时候其效果和push_back一致！所以在使用emplace_back 时需要确保传入的参数是一个右值引用，如果不是，请使用std::move()进行转换


