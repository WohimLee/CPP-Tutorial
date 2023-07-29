#include "myVector.hpp"


// ===================== myVector 类 ===================== //

/* ---------- 构造函数 ---------- */

template<class T>
myVector<T>::myVector() 
    : mSize(0), mCapacity(0), mData(nullptr){}

template<class T>
inline myVector<T>::myVector(int num)
    :mSize(num), mCapacity(num), mData(new T[num])
{
    for(int i=0; i<mSize; ++i)
        mData[i] = T();
}

template<class T>
inline myVector<T>::myVector(const myVector& v) 
    : mSize(v.mSize), mCapacity(v.mCapacity)
{
    
    for(int i=0; i<mSize; ++i)
        mData[i] = v.mData[i];
}

template<class T>
inline myVector<T>& myVector<T>::operator=(const myVector<T>& v)
{
    if(this == &v) return *this;

    if(v.mSize <= mCapacity){
        for(int i=0; i<v.mSize; ++i){
            mData[i] = v.mData[i];
        }
        mSize = v.mSize;
        return *this;
    }
    delete[] mData;
    T* p = new T[v.mSize];
    for(int i=0; i<v.mSize; ++i)
        p[i] = v.mData[i];

    mSize = v.mSize;
    mCapacity = v.mCapacity;
    mData = p;

    return *this;
}

template<class T>
myVector<T>::~myVector(){
    mSize = 0;
    mCapacity = 0;
    delete mData;
}

/* -------- 迭代器iterator ------- */

template<class T>
inline typename myVector<T>::iterator myVector<T>::begin(){
    return myVector<T>::iterator(&mData[0]);
}

template<class T>
inline const typename myVector<T>::iterator myVector<T>::begin() const{
    return myVector<T>::iterator(&mData[0]);
}

template<class T>
inline typename myVector<T>::iterator myVector<T>::end(){
    if(mSize == 0)
        return begin();
    return myVector<T>::iterator(&mData[mSize-1]);
}

template<class T>
inline const typename myVector<T>::iterator myVector<T>::end() const{
    if(mSize == 0)
        return begin();
    return myVector<T>::iterator(&mData[mSize-1]);
}

/* ----------- 容量相关 ------------*/

template<class T>
inline bool myVector<T>::empty() const{
    return (mSize == 0);
}

template<class T>
inline int myVector<T>::capacity(){
    return mCapacity;
}

template<class T>
inline int myVector<T>::size(){
    return mSize;
}

template<class T>
inline void myVector<T>::reserve(int newCapacity){
    if(newCapacity <= mCapacity)
        printf("reserve() 不支持改小或者等于原来的 mCapacity.\n");
    T* pNewData = new T[newCapacity];
    for(int i=0; i< mSize; ++i)
        pNewData[i] = mData[i];
    delete[] mData;
    mCapacity = newCapacity;
    mData = pNewData;
}

/* -------------- 增 ------------- */

template<class T>
inline void myVector<T>::push_back(const T& num){
    if(mCapacity == 0)
        reserve(5);
    else if(mSize >= mCapacity)
        reserve((mCapacity+5));

    mData[mSize] = num;
    mSize+=1;
}

/* -------------- 删 ------------- */

template<class T>
void myVector<T>::clear(){
    mSize = 0;
    mCapacity = 0;
}

template<class T>
void myVector<T>::pop_back(){
    if(mSize <= 0){
        printf("已经没有元素了.\n");
        return;
    }
    mSize--;
    mCapacity--;
}
/* -------------- 改 ------------- */

template<class T>
inline void myVector<T>::resize(int newsize, T value){
    
    reserve(newsize);
    for(int i = mSize; i < newsize; ++i)
        mData[i] = value;
    mSize = newsize;
}

/* -------------- 查 ------------- */

template<class T>
inline T& myVector<T>::at(int i){
    if(i<0 || i>mSize){
        printf("Out of range.\n");
    }
    return mData[i];
}

template<class T>
inline const T& myVector<T>::at(int i) const {
    if(i<0 || i>mSize){
        printf("Out of range.\n");
    }
    return mData[i];
}

template<class T>
inline T& myVector<T>::operator[](int i){
    if(i<0 || i>mSize){
        printf("Out of range.\n");
    }
    return mData[i];
}

template<class T>
inline const T& myVector<T>::operator[](int i) const {
    if(i<0 || i>mSize){
        printf("Out of range.\n");
    }
    return mData[i];
}

template<class T>
inline T& myVector<T>::front(){
    return mData[0];
}

template<class T>
inline const T& myVector<T>::front() const {
    return mData[0];
}

template<class T>
inline T& myVector<T>::back(){
    return mData[mSize-1];
}

template<class T>
inline const T& myVector<T>::back() const {
    return mData[mSize-1];
}

template<class T>
inline T* myVector<T>::data(){
    return mData;
}

template<class T>
inline const T* myVector<T>::data() const {
    return mData;
}


// ===================== 迭代器iterator类 ===================== //

/* ---------- 构造函数 ---------- */

template<class T>
myVector<T>::iterator::iterator(T* p) : 
    mCurrent(p){}

/* ---------- 运算符重载 ---------- */

template<class T>
typename myVector<T>::iterator& myVector<T>::iterator::operator++(int){
    mCurrent++;
    return *this;
}

template<class T>
typename myVector<T>::iterator& myVector<T>::iterator::operator--(int){
    mCurrent--;
    return *this;
}

template<class T>
bool myVector<T>::iterator::operator==(const iterator& p) const {
    return this->mCurrent == p.mCurrent;
}

template<class T>
bool myVector<T>::iterator::operator!=(const iterator& p) const{
    return this->mCurrent != p.mCurrent;
}

/* ---------- 解引用 ---------- */

template<class T>
T& myVector<T>::iterator::operator*(){
    return *mCurrent;
}