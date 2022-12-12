
# 结构体
&emsp;&emsp;
# 1 结构体定义
- 一个结构体是组合到同一定义下的一组不同类型的数据，各个数据类型的长度可能不同。

>结构体定义
```c++
struct struct_name {
    type1 element1;
    type2 element2;
    type3 element3;
    ...
    ...
}obj1, obj2;
```
- name（可选）结构体名
- objs（可选）实例化对象
- 花括号（{}）内是结构体内的元素

&emsp;&emsp;如果结构的定义包括参数model_name（可选），该参数即成为一个与该结构等价的有效的类型名称，例如：

>示例
```c++
#include <iostream>
using namespace std;

struct List{
    int* elem;
    int length;
	int size;
}list1, list2;

// // 不写obj
// struct List{
//     int* elem;
//     int length;
// 	int size;
// };

// // 不写struct_name
// struct{
//     int* elem;
//     int length;
// 	int size;
// }list1, list2;

int main()
{
    List l1; // 可以当做是一种类型使用
    
}
```

&emsp;&emsp;一旦被定义，List 就成为一个新的有效数据类型名称，可以像其它基本数据类型（如int、char或short）一样，被用来声明该数据类型的对象（object）变量。


&emsp;&emsp;如果在定义结构的同时声明结构的对象，参数 model name （这个例子中的 products）将变为可选项。但是如果没有 model name，我们将不能在后面的程序中用它来声明更多此类结构的对象。

&emsp;&emsp;struct_name 是一个类型，对象 obj1, obj2... 是变量




&emsp;&emsp;
# 2 使用结构体
访问结构体的属性：
```
obj.attribute
```
>示例，一个结构体的例子
```c++
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
 

struct movies_t {
    char title[50];
    int year;
}mine, yours;

void printmovie(movies_t movie);

int main() {
    char buffer[50];
    strcpy(mine.title, "2001 A Space Odyssey");
    mine.year = 1968;
    cout << "Enter title: ";
    cin.getline(yours.title, 50);
    cout << "Enter year: ";
    cin.getline(buffer, 50);
    yours.year = atoi(buffer);
    cout << "My favourite movie is:\n ";
    printmovie(mine);
    cout << "And yours:\n";
    printmovie(yours);
    return 0;
}

void printmovie(movies_t movie) {
    cout << movie.title;
    cout << " (" << movie.year << ")\n";
}
```


&emsp;&emsp;
# 3 结构体数组

&emsp;&emsp;当需要使用大量相同的结构体变量时，可使用结构体定义数组，该数组包含与结构体相同的数据结构所组成的连续存储空间。如下例∶
```c++
struct student stu_a[50]; //声明长度为50 的结构体数组 stu_a
```
引用结构体数组中元素的一般形式为∶
```c++
结构体数组名[n].成员名
```

>示例
```c++
#include <stdio.h>

using namespace std;

int main()
{
    struct student
    {
        char name[50];
        long no;
        float score[4];
    };

    struct student stu_a[2] =  {"Tom",20090001,87.5,70.5,93,91,
    "Jerry",20090002,90,78.5,83.5,66}; 

    // cout << stu_a[0].name << endl;
    // cout << stu_a[1].name << endl;

    for(int i = 0; i < 2; i++)
        printf("%s %ld %5.2f %5.2f %5.2f %5.2f\n",
                stu_a[i].name, //引用结构体数组元素的成员
                stu_a[i].no, 
                stu_a[i].score[0], //成员是数组，引用其中元素
                stu_a[i].score[1], 
                stu_a[i].score[2], 
                stu_a[i].score[3]);

    return 0;
}
```
&emsp;&emsp;程序中声明了结构体数组 stu_a[]，并在声明时用数据为其初始化。然后用printf[]函数将结构体数组中的数据输出。





&emsp;&emsp;
# 4 结构体指针

&emsp;&emsp;就像其他数据类型一样，结构也可以有指针。其规则同其它基本数据类型一样：指针必须被声明为一个指向结构的指针：
```c++
struct movies_t{
    char title[50];
    int year;
};
movies_t amovie;
movies_t * pmovie;
```
- amovie是一个结构类型movies_t的对象
- pmovie是一个指向结构类型movies_t的对象的指针

所以，同基本数据类型一样，一下表达式是正确的：
```c++
pmovie = &amovie;
```

下面的例子引入了一种新的操作符
>示例，结构指针的例子
```c++
#include <iostream>
using namespace std;
#include <stdlib.h>
struct movies_t {
    char title[50];
    int year;
};

int main() {
    char buffer[50];

    movies_t amovie;
    movies_t * pmovie;
    pmovie = & amovie;

    cout << "Enter title: ";
    cin.getline(pmovie->title, 50);
    cout << "Enter year: ";

    cin.getline(buffer, 50);
    pmovie->year = atoi(buffer);

    cout << "\nYou have entered:\n";
    cout << pmovie->title;
    cout << " (" << pmovie->year << ")\n";

    return 0;
}
```
&emsp;&emsp;上面代码中引入了一个重要的操作符：->。这是一个引用操作符，常与结构或类的指针一起使用，以便引用其中的成员元素，这样就可以避免使用很多括号。

例如，我们用：
```c++
pmovie->title
```
来代替
```c++
(*pmovie).title
```

&emsp;&emsp;以上两种表达式pmovie->title和(*pmovie).title都是合法的，都表示取指针pmovie所指向的结构的元素title的值。



&emsp;
# 5 结构体嵌套
&emsp;&emsp;结构可以嵌套使用，即一个结构的元素本身又可以是另一个结构类型，例如：
```c++
struct movies_t{
    char title[50];
    int year;
}

struct friends_t {
    char name [50];
    char email [50];
    movies_t favoreite_movie;
}charlie, maria;
friend_t * pfrends = &charlie;
```
&emsp;&emsp;因此，在有以上声明之后，我们可以使用下面的表达式：
```c++
charlie.name
maria.favourite_movie.title
charlie.favourite_movie.year
pfriends->favourite_movie.year
```
&emsp;&emsp;以上最后两个表达式等价。

&emsp;&emsp;这里的结构的概念与C语言中结构的概念是一样的。然而，在C++中，结构的概念已经被扩展到与类（class）相同的程度，只是它所有的元素都是公开的（public）。


