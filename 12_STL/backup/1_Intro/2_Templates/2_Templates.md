&emsp;
# Template

- 模板是一组函数或类的参数实现。
- 编译器能够在需要使用函数或类模板时，用模板生成一个具体的函数或类的定义，也可以定义参数化类型的模板。

- 模板并不是可执行代码，而是用于生成代码的蓝图或配方。
- 如果一个模板从来没有被使用过，那么它将会被编译器忽略，不会生成可执行代码。
- 一个没有被使用的模板可能会包含一些编程错误，并且包含这个模板的程序仍然可以编译和运行。
- 当模板用于生成代码时，也就是当它被编译时，模板中的错误才会被编译器标识出来。

- 从模板生成的函数或类的定义是模板的实例或实例化。

- 模板的参数值通常是数据类型
    ```cpp
    template <typename T> T& larger (T& a,T& b)
    {
        return \a > b ? a:b;
    }
    ```
    这是一个可以比较两个参数值大小且返回较大参数值的函数的模板，使用这个模板的唯一限制是参数值的类型必须是可以用 > 比较的。类型参数 T 决定了具体创建什么样的模板实例。当使用 larger（）时，编译器可以从提供的参数中推断出具体的参数类型，即使是隐式提供。

    当函数的两个输入参数类型不同时，需要明确指出模板类型参数。例如，如果编写语句 larger（2, 3.5），编译器在推断T的类型时，就会产生多义性——T可以是 int，也可以是 double，这样使用就会产生错误消息。如果将 larger（2, 3.5）写为 larger<double>（2, 3.5），就可以消除这个问题。





&emsp;
>示例，模板类

```cpp
template <typename T> 
class Array
{
    private :
        T* element;   // Array of type T
        size_t count; // Number of array elements
    public :
        explicit Array(size_t arraySize);  // Constructor
        Array(const Array& other);         // CopyConstructor
        Array(Array&& other);              // MoveConstructor
        virtual ~Array();                  // Destructor
        T& operator[](size_t index) const; // Subscript operator
        const T& operator[](size_t index) const; // Subscript operator-const

        Array& operator = (const Array& rhs); // Assignment operator
        Array& operator = (Array&& rhs);      // Move assignment operator
        size_t size(){return count;}          // Accessor for count
};
```


size t类型别名定义在 cstddef 头文件中，表示无符号整型。

上面的代码是元素类型为 T 的数组模板。如果愿意，可以这样隐式地定义数组 Array<T>。在模板定义的外面——外部成员函数的定义中，必须这样写 Array<T>。赋值操作符允许将一个 Array<T>对象赋值给另一个对象，这个操作在普通数组中是无法完成的。如果想禁用这个功能，仍然需要声明 operator=O为模板的成员函数。如果不这样做，编译器会自动为模板实例生成一个默认的 public类型的赋值操作函数。为了阻止这种情况发生，应该按照如下方式进行定义;
```cpp
Array& operator=(const Array& rhs)=delete;// No assignment operator 
```

一般来说，如果想定义任何拷贝构造函数或移动构造函数、拷贝赋值运算符或移动赋值运算符以及析构函数，都需要定义这5个类成员，或者用 deleted指定你不想要的成员。

■ 注意∶实现了移动构造函数和移动赋值运算符的类都有移动语义。

size（）成员函数在类模板中默认以内联的方式实现，所以不再需要外部定义。类模板成员函数的外部定义是放在头文件中的模板，通常和类模板在一个头文件中。一个成员函数甚至可以不依赖类型参数T，如果 sizeO）在类模板中没有定义，那么 sizeO将需要一个模板定义。定义了成员函数的模板的类型参数列表必须和类模板的类型参数列表相同，下面介绍如何定义构造函数∶
```cpp
template <typename T> // This is a function template with parameter T
Array<T>::Array(size_t arraySize) try : elements {new T[arraySize]}, count {arraySize}
{}
catch(const std::exception& e)
{
 st::cerr << "Memory allocation failure in Array constructor." << std::endl;
 rethrow e;
}
```
为元素分配内存的操作可能会抛出一个异常，所以构造函数是一个 try 代码块，这能捕获到异常，处理必须被重新抛出的异常——如果不重新抛出那些 catch 语句块中的异常，那么它会被重新抛出。在构造函数名称的限定中，模板类型参数T是必要的，因为它将函数模板的定义和类模板关联起来了。需要注意的是，对于成员函数，不必使用 typename 这个关键字，它仅用于模板的参数列表中。

当然，可以以内联的方式为类模板的成员函数指定一个外部模板。例如，下面的代码将展示 Array模板的拷贝构造函数可能的定义方式∶

```cpp
template <typename T>
inline Array<T>::Array(const Array& other)
try : elements {new T[other.count]}, count {other.count}
{
 for (size_t i {}; i < count; ++i)
 elements[i] = other.elements[i];
}
catch (std::bad_alloc&)
{
 std::cerr << "memory allocation failed for Array object copy." << std:: endl;
}
```
这就假定T类型适用于赋值运算符，在使用它之前，你不会看到模板的代码，也不会意识到赋值运算符上的依赖。这说明除了先前提到的那些动态分配内存的类的其他成员，定义一个赋值运算符是多么重要。
■注意∶当指定一个模板的参数时，class 和 tyname 关键字是可以互换使用的。因此，当定义一个模板时，可以写作 template<typename T>或 template<class T>。因为T不必是类类型，所以本书更喜欢选择使用 typename，因为当T参数既可以是基本类型，也可以是类类型时，这种表达看起来更直观。
编译器因为一个特定类型对象的定义，实例化了一个类模板。这里有一个示例∶
Array<int> data {40};
每个类模板类型参数都需要一个实参，除非有默认实参。当这条语句被编译时，发生了三件事;因为 Array<int>类的定义被创建，所以确定了参数类型;因为必须调用构造函数去生成一个对象，所以生成了构造函数的定义;析构函数也被生成用来销毁对象。这就是编译器创建和释放一个数据对象所做的全部事情，也是这个时候从模板生成的唯一代码。通过用int 替换模板中的T，生成了类的定义，这非常巧妙。编译器只编译程序使用的成员函数，所以不需要得到模板参数被替换的完整类。基于数据对象被定义的规则，可以这样定义类∶

```cpp
class Array<int>
{
private:
 int* elements;
 size_t count;
public:
 explicit Array(size_t arraySize);
 virtual ~Array();
};
```

可以看到，只有构造函数和析构函数这两个成员函数。编译器不会创建任何和生成对象实例无关的东西，也不会包含程序中没有用到的模板代码。
可以为模板定义别名，当使用STL 时，这一点非常有用。这里有一个为模板定义别名的示例∶
template<typename T> using ptr = std::shared_ptr<T>;
这个模板定义ptr<T>作为智能指针模板类型 std∶shared ptr<T>的别名，这样的话就可以在代码中用ptr<std∶string>代替std∶shared_ptr~<std∶string>，这显然更简洁，更容易阅读。下面使用 using，代码会更加简化∶
using std::string;
现在就可以在代码中用ptr<string>代替 std∶shared_ptr<std∶string>，模板的类型别名能使代码更容易阅读，也更方便编写。





