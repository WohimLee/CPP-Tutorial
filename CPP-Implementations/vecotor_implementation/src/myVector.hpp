#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP
#include <stdio.h>

// ===================== myVector 类 ===================== //
template<class T>
class myVector
{
public:
/* ---------- 构造函数 ---------- */

	myVector(); // 默认构造
	explicit myVector(int num);  // 构造 num 个元素的 vector
	myVector(const myVector& v); // 拷贝构造
	myVector<T>& operator=(const myVector<T>& v); // 赋值构造
	~myVector();

/* -------- 迭代器iterator ------- */

	class iterator;
	iterator begin();
	iterator end();

	const iterator begin() const;
	const iterator end()   const;


/* ----------- 容量相关 ------------*/

	bool empty() const;
	int capacity();
	int size();
	void reserve(int newCapacity);
	

/* -------------- 增 ------------- */

	void push_back(const T& num);

/* -------------- 删 ------------- */

	void clear();
	void pop_back();

/* -------------- 改 ------------- */

	void resize(int newsize, T val);
	void shrink_to_fit();

/* -------------- 查 ------------- */

	T& at(int i);
	const T& at(int i) const;

	T& operator[](int i);
	const T& operator[](int i) const;

	T& front();
	const T& front() const;

	T& back();
	const T& back() const;

	T* data();
	const T* data() const;

private:
	int mSize;
	int mCapacity;
	T* mData;

};

// ===================== 迭代器iterator类 ===================== //
template <class T>
class myVector<T>::iterator
{
public:
	iterator(T* p);
	
	// ++p，--p的操作，注意不是 p++，p--
	iterator& operator++(int);
	iterator& operator--(int);

	// 判断相等或不等
	bool operator==(const iterator& p) const;
	bool operator!=(const iterator& p) const;

	// 解引用
	T& operator*();

private:
	T* mCurrent;
};



#include "myVector.cpp"

#endif // MYVECTOR_HPP