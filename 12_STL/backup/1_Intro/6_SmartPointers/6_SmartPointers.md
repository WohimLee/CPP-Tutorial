&emsp;
# Smart Pointers

C++指针，通常叫作原生指针。原生指针可以指向自动变量、静态变量或堆上生成的变量。智能指针是一个可以模仿原生指针的模板类。

原生指针与智能指针很像。但有些情况下，它们有两点差别∶
- 智能指针只能用来保存堆上分配的内存的地址。
- 不能像对原生指针那样，对智能指针进行一些自增或自减这样的算术运算。


对于在自由存储区创建的对象，通常使用智能指针而不是原生指针。智能指针的巨大优势是，不用担心不小心释放了堆内存，因为当不需要时，一个对象的内存会被分配给一个智能指针。智能指针自动释放当对象不再需要时，这意味着消除了内存泄漏的可能性。


可以在容器中使用智能指针，当使用一个类对象时，这一点尤其有用。如果使用一个类的基类作为智能指针的类型参数，可以用它指向一个派生类对象，这保存了一个对象的指针而不是对象，因而能够保持这个对象的多态性。智能指针的模板定义在 memory 头文件中，必须在代码中包含这个头文件来使用它们。在 std 命名空间中定义了三种不同类型的智能指针模板∶

- `unique_ptr<T>`对象就像一个指向类型T的指针，而且 unique_ptr<T>是排他的，这意味着不可能有其他的 unique pt<T>指向同一个地址。一个 unique_ptr<T>对象完全拥有它所指向的内容。不能指定或复制一个 unique ptr<T>对象。可以通过使用一个定义在 utility 头文件中的 std∶∶move（）函数来移出一个 unique ptr<T>对象存储的地址。在进行这个操作之后，之前的 unique ptr<T>变为无效。当需要独占一个对象的所有权时，可以使用 nique_ptr<T>。

- `shared_ptr<T>`对象就像一个指向类型T的指针，和 unique_ptr<T>不同的是，多个
shared_ptr<T可以指向同一个地址，因此 shared ptr<T>允许共享一个对象的所有权。引用计数保存了指向给定地址的 shared ptr<T>的数量，每当一个新的shared ptr<T>指针指向一个特定堆地址时，引用计数就会加 1。当一个shared ptr<T>被释放或者指向了新的地址时，引用计数就会减 1。当没有shared_ptr<T>指向这个地址时，引用计数将会变为0，在堆上为这个对象分配的内存就会自动释放。所有指向同一个地址的 shared ptr<T>都能得到引用计数的值。

- `weak_ptr<T>`可以从一个 shared ptr<T>对象创建，它们指向相同的地址。创建一个 weak ptr<T> 不会增加 shared ptr<T>对象的引用计数，所以它会阻止指向的对象销毁。当最后一个 shared ptr<T> 引用被释放或重新指向一个不同的地址时，它们所指向对象的内存将被释放，即使相关的 weak ptr<T>可能仍然存在。


使用 weak ptr<T> 对象的主要原因是，我们可能在不经意间创建一个循环引用。循环引用从概念上说就是一个 shared_ptr<T> 对象 pA，指向了另一个 shared ptr<T> 对象 pB，在这种情况下，两个对象都不能被释放。在实际中，循环引用的发生要比这个复杂。设计 weak ptr<T> 就是为了避免循环引用的问题。通过使用 weak ptr<T> 指向一个 shared ptr<T> 所指向的对象，就可以避免循环引用，稍后会对此做一些解释。当最后一个 shared ptr<T> 对象析构时，它所指向的对象也析构了，这个时候任何和 shared_ptr<T> 关联的 weak ptr<T> 对象都指向一个无效的对象。


&emsp;
# 1 unique_ptr<T>指针
unique_ptr<T>对象唯一指向了一个对象，所以它独享了这个对象的所有权。当一个unique_ptr<T>对象析构时，它所指向的对象也析构了。当不需要使用多个智能指针，想独享对象的所有权时，可以选择使用这种类型的智能指针。当一个对象被一个 unique ptr<T> 指向时，也可以通过生成一个原生指针来访问对象。

这里有一个使用构造函数生成一个unique ptr<T>对象的示例∶
```cpp
std::unique ptr<std::string> pname Inew std::string ["Algernon"});
```
在堆上生成的字符串对象被传入 unique_ptr<string>构造函数。默认的构造函数会生成一个内部原生指针为空指针的 unique_ptr<T>对象。


一种更好地生成 unique_ptr<T> 对象的方式是使用 make_unique<T>（）函数，这是一个定义在memory头文件中的函数模板∶
```cpp
auto pname = std::make unique<std::string>("Algernon");
```


该函数通过将参数传递给类的构造函数，来生成一个堆上的字符串对象，并且返回一个指向这个对象的指针。可以按照T构造函数的要求，尽可能多地为 make unique<T>O0函数提供参数。下面是一个示例∶

```cpp
auto pstr - std::make unique<std::string>(6,'*');
```

这两个参数会被传入 string 构造函数中，生成一个包含"*****"的对象。可以通过解引用的方式来使用一个对象，就像使用原生指针一样∶
```cpp
std::cout << *pname << std::endl;// Outputs Algernon 
```

可以生成一个指向数组的 unique ptr<T>对象。例如∶
```cpp
size_t len (10);
std::unique_ptr<int[]> pnumbers {new int[len]);
```

这会生成一个 unique ptr 对象，用来指向一个在空闲空间生成的具有 len 个元素的数组，同样也可以调用make unique<T>（函数得到相同的结果∶
```cpp
auto pnumbers = std::make_unique<int[]>(len);
```

同样，也可以生成一个指针，用来指向一个在堆上生成的具有 len 个元素的数组。可以对 unique ptr变量使用索引来访问数组元素。这里展示了如何改变数组的值∶
```cpp
for(size_t i{};i < len;++i)pnumbers[i] = 4*i;
```

这使数组元素的值等于它们所对应索引的平方值。当然，可以使用取下标的方式来输出数组的值∶
```cpp
for(size t il};i <len;++i)std::cout << pnumbers[i] << std::endl;
```


不能以传值的方式将一个 unique ptr<T> 对象传入函数中，因为它们不支持拷贝，必须使用引用的方式。unique ptr<T> 可以作为一个函数的返回值，因为它们不会被拷贝，但是它们必须以隐式移动运算的方式返回。

因为 unique ptr<T> 不能被拷贝，所以只能通过移动或生成它们的方式，在容器中存放unique_ptr<T> 对象。绝不会有两个 unique_ptr-<T> 对象指向同一个对象，shared_ptr<T> 对象就没有这种特性，所以当需要多个指针指向一个对象时，或者当需要拷贝一个存放了智能指针的容器时，可以使用 shared ptr<T> ;否则，就要使用 unique ptr<T>。在一个存放unique_ptrT>类型元素的容器中，可能会需要一个指向可用对象的原生指针。下面的代码演示了如何从 unique_ptr<T>获取一个原生指针∶
```cpp
auto unique p = std::make unique<std::string>(6,'');std::string pstr {unique_p.get());
```
类的 get（）成员函数可以返回一个 unique ptr<T>所包含的原生指针。当需要访问一个对象时，指向它的智能指针被封装在一个类对象中。这时，就需要像上面那样做，这是一个典型的使用场景。因为 unique_ptr<T不能被拷贝，所以不能返回 unique_ptr<T>。

&emsp;
## 1.1 重置 unique_ptr<T>对象
当智能指针析构时，unique_ptr<T>对象所指向的对象也会被析构。调用一个无参unique_ptr<T>对象的 reset））函数可以析构它所指向的对象，unique ptr-<T>对象中的原生指针将会被替换为空指针，这使你能够在任何时候析构智能指针所指向的对象。例如;
auto pname - std::make_unique<std::string>("Algernon");
// Release memory for string object
pname.reset();
也可以将一个新生成的T对象的地址值传给 reset（）函数。智能指针之前所指向的对象会被析构。然后它的地址值被替换为新对象的地址值∶
pname.reset (new std::string{"Fred"》);
pname 之前所指向的字符串对象的内存将会被释放，在内存中生成一个新的字符串对象——"Fred"，然后其地址被 pname 保存。
■警告∶不要将其他 unique_ptr~<T>所指向的一个对象的地址值传给 reset（）。或者去生成一个新的 unique_ptr<T>对象，这种代码也许能通过编译，但是肯定会让程序崩溃。第一个unique_ptr~<T的析构会释放它所指向的对象的内存;第二个智能指针析构时，将会试图再次释放已经释放的内存。
可以调用智能指针的 release（O）函数去释放一个 unique ptr<T>所指向的对象，这样就能够在不释放对象内存的情况下，将指向它的 unique ptr<T内部的原生指针设为空指针。例如∶
auto up name = std;:make unique<std;:string>("Algernon");std::unique_ptr<std::string> up_new_name(up_name.release());


up_name的成员函数 release（O）可以得到一个包含"Algemon"的字符串对象的原生指针，所以在执行完第二行代码时，up new name 会指向原始的那个字符串对象——Algernon"。从unique 指针转移到另一个指针时，也转移了所指向对象的所有关系。
可以通过交换两个 unique ptr<T>指针的方式来交换两个对象∶auto pn1- std::make_unique<std::string>("Jack");auto pn2 = std::make unique<std::string>("Jill");pn1.swap (pn2);
在执行完第二行代码后，pnl会指向字符串"Jil"，pn2指向字符串"Jack"。

&emsp;
## 1.2 比较和检查 unique_ptr<T>对象
STL中非成员函数的模板函数定义了全套的比较运符，用来比较两个 unique ptr<T>对象或者比较一个unique ptr<T>对象和一个空指针（nullptr）。比较两个 unique ptr<T>对象也就是比较它们两个的成员函数 getO）返回的地址值，比较一个unique ptr<T>对象和空指针也就是将智能指针的成员函数 getO）返回的地址和空指针作比较。
unique_ptr<T可以隐式地转换为布尔值。如果一个对象包含一个空指针，将会被转换为 false;否则转换为 true。这就意味着可以使用if语句来检查一个非空的 unique_ptr<T>对象∶
auto up_name- std::make_unique<std::string>("Algernon");std::unique_ptr<std::string> up_new(up_name.release());
// true if not nullptr if(up_new)
std::cout <<"The name is"<< *up new<< std::endl;
// true if nullptr if(!up_name)
std::cout<<"The unique pointer is nullptr"<< std::endl;
当对一个 unique ptr）指针对象调用 reset（）或 release（O时，需要先做这种检查，因为在解引用一个指针时，需要保证它是一个非空的 unique ptr<T>指针。






&emsp;
# 2 shared_ptr<T>指针

可以按如下方式定义一个 shared ptrT>对象∶
```cpp
std::shared_ptr<double> pdata {new double[999.0}};
```
可以通过解引用一个 shared ptr指针，使用它所指向的对象或者修改对象的值∶
```cpp
*pdata = 8888.0;
// Outputs 8888.0
std::cout << *pdata << std::endl;
*pdata = 8889.0;
// Outputs 8889.0
std::cout << *pdata << std::endl;
```
pdata 的定义过程，包含了一个 double 变量的堆内存的分配，以及另一个和智能指针相关的控制块的内存分配，这个控制块记录了智能指针的副本计数。分配堆内存是相当耗时的，可以通过使用一个定义在 memory 头文件中的 make shared<T>0）函数来得到一个shared_ptro对象，这个过程要有效率得多;
auto pdata= std::make_shared<double>(99.0);// Points toa double variable 尖括号中的数据类型指定了生成的变量的类型，函数名后圆括号中间的参数用来初始化生成的变量。
一般来说，make shared<T>（）函数的参数可以是任意数字，实际生成的数字取决于要生成的对象的类型。当需要使用 make shared<T>0）函数在堆上生成一个对象时，如果构造函数有要求的话，可以提供两个或更多个参数，这些参数用逗号隔开。auto 关键字可以使pdata 的数据类型自动地从 make shared<T>O）返回的对象推导出来，所以事实上它是shared_ptr<double>类型。尽管如此，当使用 auto 时，不要使用初始化列表，因为参数的类型会被推导为 std∶∶initializer list。
可以使用一个定义好的指针来初始化另一个 shared_ptr<T>指针∶std::shared ptr<double> pdata2 {pdatal;
pdata2和 pdata指向同一个变量，这会导致引用计数的增加。也可以将一个shared ptr<T>指针赋值给另一个 shared ptr<T>指针∶
std::shared_ptr<double> pdata{ new double{ 999,0 l};
// Pointer contains nullptr
std::shared ptr<double> pdata2;
// Copy pointer - both point to the
pdata2 = pdata;
// same variable // Outputs 999.0
std::cout << *pdata << std::endl;
当然，复制 pdata 会导致引用计数的增加。如果 double 变量使用的内存被释放，那么所有指向它的指针都需要被重置或析构。不能用 shared_ptr<T>指针来保存一个默认生成的数组，但是可以用来保存那些由你自己生成的 array<T>或vector<T>容器对象。
国注意∶你可能会创建一个指向数组的 shared ptr<T>指针，这需要为智能指针提供一个deleter 函数去释放数组的堆内存，具体怎么做超出了本书的讨论范围。
shared_ptrT>和 unique_ptrT>的使用方式相似，通过使用 shared ptrT>的成员函数getO），可以从 shared ptr<T>得到一个原生指针。pdata 可以像先前的章节那样去定义。可以这样写∶
auto pvalue = pdata.get();// pvalue is type double and points to 999.0 当需要使用一个原生指针时，可以像上面那样去使用。
口警告∶只能通过拷贝构造函数或赋值运算符去复制一个shared ptr<T>对象。通过一个由其他指针的getO函数返回的原生指针，来生成一个shared ptr<T>指针。这可能会导致一些意想不到的问题，大多数情况也就意味着程序的崩溃。


&emsp;
## 2.1 重置 shared_ptr<T>对象
如果将一个空指针赋给一个 shared ptr<T>对象，那么它的地址值将会变为空，同样也


会使指针所指向对象的引用计数减1。例如∶
auto pname = std;:make_shared<std::string>("Charles Dlckens");
// Points to a string object
// ...1ots of other stuff happening...
// Reset pname to nullptr pname = nullptr;
以"Charles Dickens"为初始值，生成一个在堆上存放的字符串对象，然后生成一个共享指针来保存这个地址值。最后;用空指针来替换 pname 所保存的值。当然，这时候任何其他保存了字符串对象地址的 shared ptr<T>对象仍然存在，因为引用计数还不等于0。
通过调用 shared ptr<T>对象的无参 reset（O函数，可以得到同样的效果∶
//Reset to nullptr pname.reset();
也可以通过为 reset（）函数传入一个原生指针来改变共享指针指向的对象。例如∶pname.reset <new std::string{"Jane Austen"));// pname points to new strinq 通过 reset（）的参数传入的地址对象，类型必须和之前存放在智能指针中的对象类型一致，或者必须可以隐式转换成之前的类型。


&emsp;
## 2.2 比较和检查 shared_ptr<T>对象
可以使用任意比较运算符来比较两个 shared ptr<T> 保存的地址，或者将一个shared ptr<T>保存的地址和空指针比较。最有用的比较运算符是一和!-，这能够让我们知道两个指针是否指向同一个对象。给定两个shared_ptr<T>对象pA和pB，它们指向同一类型，你能够像下面这样比较它们∶
if((pA == pB) &&(pA != nullptr))
std::cout<< "Both pointers point to the same object.\n";
这两个指针可能相等或者都是空指针，所以这样一种简单的比较并不能充分说明它们都指向同一个元素。像 unique ptr<T>指针对象和 shared ptr<T>指针对象，都可能被隐式转换成布尔值，所以不能像下面这样使用∶
if(pA 5(pA == pB))
std::cout <<" Both pointers point to the same object.\n";
也可以检查 shared_ptr<T>对象是否有任何副本∶
auto pname = std::make shared<std::string>("Charles Dickens");if(pname.unique ())
std::cout<< there is only one..,"<< std::endl;else
std::cout<< there is more than one..."<< std;:endl;
如果对象的实例数是1，uniqueO）成员函数返回 true，否则返回false。也可以知道当前有多个实例∶
if(pname. nique())

std::cout << there is only one..."<< std::endl;else
std::cout<<there are"<<pname.use count()<<"instances."<<std::endl;
成员函数 use count（）返回当前被调用对象的实例个数。如果 shared ptr<T>对象包含的为空指针，那么返回0。









&emsp;
# 3 weak_ptr<T>指针






