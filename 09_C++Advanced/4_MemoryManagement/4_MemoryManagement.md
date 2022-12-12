
# 内存管理


&emsp;
# 1 动态内存分配
&emsp;&emsp;到目前为止，我们的程序中只用了声明变量、数组和其他对象（objects）所必需的内存空间，这些内存空间的大小都在程序执行之前就已经确定了。但如果我们需要内存大小为一个变量，其数值只有在程序运行时（runtime）才能确定，例如有些情况下需要根据用户输入来决定必需的内存空间，就要用到动态分配内存（dynamic memory），为此C++ 集成了操作符 new 和 delete。

&emsp;
# 2 操作符new和new[]


&emsp;&emsp;操作符new的作用是动态分配内存。new后面跟一个数据类型，并跟一对可选的方括号（[]），里面要为要求的元素数。它返回一个指向内存块开始位置的指针。其形式为：
```c++
pointer = new type
```
或者
```c++
pointer = new type[elements]
```
- 第一个表达式用来给一个单元素的数据类型分配内存
- 第二个表达式用来给一个数组分配内存。

>例如：
```c++
int *bobby;
bobby = new int[5];
```

&emsp;&emsp;在这个例子里，操作系统分配了可存储 5 个整型（int）元素的内存空间，返回指向这块空间开始位置的指针并将它赋给 bobby。因此，现在 bobby 指向一块可存储 5 个整型元素的合法的内存空间


&emsp;&emsp;动态内存分配通常由操作系统控制，在多任务的环境中，它可以被多个应用（appliations）共享，因此内存有可能被用完。如果这种情况发生，操作系统分配不了 new 所需的内存，一个无效指针（null pointer）将被返回。所以，建议在使用 new 之后总是检查返回的指针是否为空（null），如下例所示∶

```c++
int *bobby;
bobby = new int[5];
if(bobby == NULL){
    error assigning memory. Take measures.
}
```

&emsp;
# 3 操作符delete

&emsp;&emsp;既然动态分配的内花线是在程序运行的某一具体阶段才有用，那么一旦它不再被需要时就应该被释放，以便给后面的内存申请使用。操作符 delete 因此而产生，它的形式是∶
```c++
delete pointer;
```
或
```c++
delete[]pointer;
```

- 第一种表达形式用来删除给单个元素分配的内存
- 第二种表达形式用来删除多元素（数组）的内存分配。
- 在多数编译器中两种表达式等价，使用没有区别， 虽然它们实际上是两种不同的操作，需要考虑操作符重载（overloading）。

>示例，delete[]的例子
```c++
#include <iostream>
using namespace std;
#include <stdlib.h>

int main() {
    char input[100];
    int i, n;
    long* l;
    cout << "How many numbers do you want to type in? ";
    cin.getline(input, 100); 
    i = atoi(input);
    l = new long[i];
    if (l == NULL) exit(1);
    for (n = 0; n < i; n++) {
        cout << "Enter number: ";
        cin.getline(input, 100);
        l[n] = atol(input);
    }
    cout << "You have entered: ";
    for (n = 0; n < i; n++) 
        cout << l[n] << ", ";
    cout << endl;
    delete[] l;
    return 0;
}
```

&emsp;&emsp;这个简单的例子可以记下用户想输入任意多个数字，它的实现归功于变动态系统申请用户要输入的数字所需的空间。

&emsp;&emsp;NULL 是 C++库中定义的一个常量，专门设计用来指代空指针的。如果这个常量没有被预先定义，你可以自己定以它为0∶
```c++
#define NULL 0;
```

&emsp;&emsp;在检查指针的时候，`0` 和 `NULL` 并没有区别。但用NULL 来表示空指针更为常用，并且更易懂。原因是指针很少被用来比较大小或被直接赋予一个除0以外的数字常量，使用 NULL，这一赋值行为就被符号化了。

&emsp;&emsp;C++11加入了 `nullptr`，可以保证在任何情况下都代表空指针，建议以后还是都用 nullptr 替代 NULL ，而NULL就当做0使用。




&emsp;
# 4 ANSI-C中的动态内存管理


&emsp;&emsp;操作符 new 和 delete 仅在 C++中有效，而在C语言中没有效。在C语言中，为了动态分配内存，我们必须求助于函数库 stdlib.h。因为该函数库在 C+中仍然有效，并且在一些现存的程序中仍然使用，所以下面将学习一些关于这个函数库中的函数的用法。

&emsp;
## （1）函数 malloc
&emsp;&emsp;这是给指针动态分配内存的通用函数。它的原型是∶ 
```c++
void* malloc(size_t nbytes);
```

&emsp;&emsp;其中，nbytes 是我们想要给指针分配的内存字节数。这个函数返回一个 void*类型的指针，因此需要用类型转换（type cast）来把它转换成目标指针所需要的数据类型，例如∶ 
```c++
char * ronny;
ronny = (char*) malloc(10);
```
&emsp;&emsp;这个例子将一个指向 10个字节可用空间的指针赋给 ronny。当我们想给一组除 char 以外的类型（不是1字节长度的）的数值分配内存的时候，我们需要用元素数乘以每个元素的长度来确定所需内存的大小。用sizeof可以达到这个目的
```c++
int *bobby;
bobby = (int*)malloc(5 * sizeof(int));
```
&emsp;&emsp;这一小段代码将一个指向可存储 5个int型整数的内存块的指针赋给 bobby，它的实际长度可能是2、4或更多字节数，取决于程序是在什么操作系统下被编译的。


>示例 cudaMalloc模拟
```c++
#include <stdlib.h>
#include <stdio.h>

#ifndef _MATH_H_
#define OVERFLOW  -2
#define UNDERFLOW -3
#define ERROR 0
#endif 
typedef int cudaError_t;

cudaError_t normalMalloc(void* ptr, size_t size)
{
    // void* ptr = ptr
    ptr = (int*)malloc(size);
    if (!ptr)
        exit(OVERFLOW);
    printf("normalMalloc success!\n")
    return 0;
}

cudaError_t cudaMalloc(void** devPtr, size_t size)
{
    // 内部做了：void** devPtr = (void**)&dev_ptr
    // *devPtr = address on device
    *devPtr = malloc(10);
    if (!(*devPtr))
        exit(OVERFLOW);
    printf("cudaMalloc success!\n")
    return 0;
}

int main()
{
    int* ptr;
    int* dev_ptr;
    normalMalloc(ptr, sizeof(int));
    cudaMalloc((void**)&dev_ptr, sizeof(int));

    return 0;
}
```

&emsp;
## （2）函数calloc
&emsp;&emsp;calloc 与 malloc 在操作上非常相似，它们主要的区别是在原型上∶ 
```c++
void *calloc(size_t nelements, size_t size);
```

&emsp;&emsp;因为它接收 2个参数而不是1个。这两个参数相乘被用来计算所需内存块的总长度。通常第一个参数 nelements是元素的个数，第二个参数 size被用来表示每个元素的长度。例如，我们可以像下面这样用 alloc 定义 bobby∶
```c++
int *bobby;
bobby = (int *)calloc(5, sizeof(int));
```

>示例 List.cpp
```c++
#include <stdlib.h>
#include <stdio.h>
#include "List.hpp"

Status init(List *L)
{
	(*L).elem = (ListElem_t*)calloc(INIT_SIZE, sizeof(ListElem_t));
	if(!(*L).elem)
		exit(OVERFLOW); 		// 分配内存失败

	(*L).size = 0;				// 初始化列表长度为0
	(*L).capacity = INIT_SIZE;	// 列表初始内存分配量
    printf("Initialize Success!\n");

	return OK;				    // 初始化成功	
} 
```

&emsp;
## （3）函数realloc
&emsp;&emsp;这个函数用来改变已经被分配给一个指针的内存的长度。
```c++ 
void* realloc(void *pointer, size_t size);
```

- pointer 用来传递一个已经被分配内存的指针或一个空指针
- size 用案指明新的内存长度。

&emsp;&emsp;这个函数给指针分配 size 字节的内存。这个函数可能需要改变内存块的地址，以便能够分配足够的内存来满足新的长度要求。在这种情况下，指针当前所指的内存中的数据内容将会被复制到新的地址中，以保证现存数据不会丢失。函数返回新的指针地址。如果新的内存尺寸不能够被满足，函数将会返回一个空指针，但原来参数中的指针 pointer 及其内容保持不变。

>示例 List.hpp
```c++
#ifndef LIST_HPP
#define LIST_HPP

#define	TRUE		1			//真 
#define	FALSE		0			//假
#define YES			1			//是
#define NO          0			//否 
#define	OK			1			//通过
#define	ERROR		0			//错误
#define SUCCESS		1			//成功 
#define UNSUCCESS	0			//失败 
#define	INFEASIBLE	-1			//不可行

#ifndef _MATH_H_ 				//系统中已有此状态码定义，要避免冲突 
#define	OVERFLOW	-2			//堆栈上溢
#define UNDERFLOW	-3			//堆栈下溢
#endif 

#ifndef NULL
#define NULL ((void*)0)
#endif

// 状态码识别类型
typedef int Status;

#define INIT_SIZE 10
#define INCRETMENT 10

typedef int ListElem_t;

typedef struct 
{
    ListElem_t* elem;
    int size;     // 列表长度
    int capacity; // 列表容量
}List;

// 初始化空列表
Status init(List* L);
Status insert(List *L, int i, ListElem_t e);

#endif
```

>示例 List.cpp
```c++
#include <stdlib.h>
#include <stdio.h>
#include "List.hpp"

Status init(List *L)
{
	(*L).elem = (ListElem_t*)malloc(INIT_SIZE*sizeof(ListElem_t));
	if(!(*L).elem)
		exit(OVERFLOW); 		// 分配内存失败

	(*L).size = 0;				// 初始化列表长度为0
	(*L).capacity = INIT_SIZE;	// 列表初始内存分配量
    printf("Initialize Success!\n");

	return OK;				    // 初始化成功	
} 

Status insert(List* L, int i, ListElem_t e)
{
	ListElem_t *newbase; 
	ListElem_t *p, *q;

	if(i<0 || i>(*L).size+1) // 只能在 [0, List.size] 之间插入
		return ERROR;		 // i值不合法

	if((*L).size >= (*L).capacity)	// 若存储空间已满，需开辟新空间 
	{
		newbase = (ListElem_t*)realloc((*L).elem, ((*L).capacity+INCRETMENT)*sizeof(ListElem_t));
		if(!newbase)
			exit(OVERFLOW);

		(*L).elem = newbase;
		(*L).capacity += INCRETMENT;
        printf("------Realloc Memory------\n");
	}
	
	q = &(*L).elem[i];				// q为插入位置 
	
	for(p=&(*L).elem[(*L).size-1]; p>=q; --p)
		*(p+1) = *p;				// 插入位置及之后的元素右移 
	
	*q = e;							// 插入e 
    printf("Insert %d\n", e);
	(*L).size++;					// 表长增1

	return OK; 
}
```

>示例 main.cpp
```c++
#include <iostream>
#include "List.hpp"
using namespace std;

void printList(List* L)
{
    for(int i = 0; i < (*L).size; ++i)
    {
        printf("%d ", (L->elem)[i]);
    }
    printf("\n");
}

int main()
{
    List L;
    init(&L);
    insert(&L, 0, 0);
    insert(&L, 1, 1);
    insert(&L, 2, 2);
    insert(&L, 3, 3);
    insert(&L, 4, 4);
    insert(&L, 5, 5);
    insert(&L, 6, 6);
    insert(&L, 7, 7);
    insert(&L, 8, 8);
    insert(&L, 9, 9);
    insert(&L, 10, 10);
    insert(&L, 11, 11);

    printList(&L);

    return 0;
}
```

&emsp;
## （4）函数 free
&emsp;&emsp;这个函数用来释放被前面 malloc、calloc 或 realloc 所分配的内存块。
```c++
void free(void* pointer);
```
&emsp;&emsp;注意∶这个函数只能被用来释放由函数 malloc、calloc 和 realloc 所分配的空间。


>示例 List.hpp
```c++
#ifndef LIST_HPP
#define LIST_HPP

#define	TRUE		1			//真 
#define	FALSE		0			//假
#define YES			1			//是
#define NO          0			//否 
#define	OK			1			//通过
#define	ERROR		0			//错误
#define SUCCESS		1			//成功 
#define UNSUCCESS	0			//失败 
#define	INFEASIBLE	-1			//不可行

#ifndef _MATH_H_ 				//系统中已有此状态码定义，要避免冲突 
#define	OVERFLOW	-2			//堆栈上溢
#define UNDERFLOW	-3			//堆栈下溢
#endif 

#ifndef NULL
#define NULL ((void*)0)
#endif

// 状态码识别类型
typedef int Status;

#define INIT_SIZE 10
#define INCRETMENT 10

typedef int ListElem_t;

typedef struct 
{
    ListElem_t* elem;
    int size;     // 列表长度
    int capacity; // 列表容量
}List;

// 初始化空列表
Status init(List* L);
Status insert(List *L, int i, ListElem_t e);
void destroy(List *L);
#endif
```

>示例 List.cpp
```c++
#include <stdlib.h>
#include <stdio.h>
#include "List.hpp"

Status init(List *L)
{
	(*L).elem = (ListElem_t*)malloc(INIT_SIZE*sizeof(ListElem_t));
	if(!(*L).elem)
		exit(OVERFLOW); 		// 分配内存失败

	(*L).size = 0;				// 初始化列表长度为0
	(*L).capacity = INIT_SIZE;	// 列表初始内存分配量
    printf("Initialize Success!\n");

	return OK;				    // 初始化成功	
} 

Status insert(List* L, int i, ListElem_t e)
{
	ListElem_t *newbase; 
	ListElem_t *p, *q;

	if(i<0 || i>(*L).size+1) // 只能在 [0, List.size] 之间插入
		return ERROR;		 // i值不合法

	if((*L).size >= (*L).capacity)	// 若存储空间已满，需开辟新空间 
	{
		newbase = (ListElem_t*)realloc((*L).elem, ((*L).capacity+INCRETMENT)*sizeof(ListElem_t));
		if(!newbase)
			exit(OVERFLOW);

		(*L).elem = newbase;
		(*L).capacity += INCRETMENT;
        printf("------Realloc Memory------\n");
	}
	
	q = &(*L).elem[i];			// q为插入位置 
	
	for(p=&(*L).elem[(*L).size-1]; p>=q; --p)
		*(p+1) = *p;			// 插入位置及之后的元素右移 
	
	*q = e;						// 插入e 
    printf("Insert %d\n", e);
	(*L).size++;				// 表长增1

	return OK; 
}

void destroy(List *L)
{
    free((*L).elem);

    (*L).elem = NULL;
    (*L).size = 0;
    (*L).capacity = 0;
}
```

>示例 main.cpp
```c++
#include <iostream>
#include "List.hpp"
using namespace std;

void printList(List* L)
{
    for(int i = 0; i < (*L).size; ++i)
    {
        printf("%d ", (L->elem)[i]);
    }
    printf("\n");
}

int main()
{
    List L;
    init(&L);
    insert(&L, 0, 0);
    insert(&L, 1, 1);
    insert(&L, 2, 2);
    insert(&L, 3, 3);
    insert(&L, 4, 4);
    insert(&L, 5, 5);
    insert(&L, 6, 6);
    insert(&L, 7, 7);
    insert(&L, 8, 8);
    insert(&L, 9, 9);
    insert(&L, 10, 10);
    insert(&L, 11, 11);

    printList(&L);

    destroy(&L);
    printf("Size of L: %d\n", L.size);
    printf("Capacity of L: %d\n", L.capacity);

    return 0;
}
```


&emsp;
## （5）函数 memcpy
- memcpy() 并不关心被复制的数据类型，只是逐字节地进行复制，这给函数的使用带来了很大的灵活性，可以面向任何数据类型进行复制
>头文件
```c++
#include <string.h>
```

>函数原型
```c++
void* memcpy (void* dest, const void* src, size_t num);
```
- 功能:
    - 复制 src 所指的内存内容的前 num 个字节到 dest 所指的内存地址上
- 返回值:
    - 返回指向 dest 的指针，注意返回的指针类型是 void*，使用时一般要进行强制类型转换
- 注意: 
    - dest 指针要分配足够的空间，也即大于等于 num 的空间。如果没有分配足够空间，会出现错误

>示例
```c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N (10)

int main()
{
    char* str1 = "abcde";
    char* str2 = (char*)malloc(sizeof(char) * N);
    char* str3 = (char*)memcpy(str2, str1, N);
    printf("str2 = %s\nstr3 = %s\n", str2, str3);
    free(str2);
    str2 = NULL;
    str3 = NULL;

    int var1 = 10;
    int* var2 = (int*)malloc(sizeof(int));
    int* var3 = (int*)memcpy(var2, &var1, 1);
    printf("var2 = %d\nvar3 = %d\n", *var2, *var3);
    free(var2);
    var2 = NULL;
    var3 = NULL;

    return 0;
}
```

&emsp;
## （6）函数 memset
>头文件
```c++
#include <string.h>
```

>函数原型
```c++
void* memset(void* str, int c, size_t n)
```
- 功能
    - 复制字符 c（一个无符号字符）到参数 str 所指向的字符串的前 n 个字符
- 参数
    - str 指向要填充的内存块
    - c 该值以 int 形式传递，但是函数在填充内存块时是使用该值的无符号字符形式
    - n 要被设置为该值的字符数
- 返回值
    - 该值返回一个指向存储区 str 的指针

>示例
```c++
#include <stdio.h>
#include <string.h>
 
int main ()
{
   char str[50];
 
   strcpy(str,"This is string.h library function");
   printf("%s\n", str);
 
   memset(str,'$',7);
   printf("%s\n", str);
   
   return(0);
}
```



