#include <iostream>
#ifndef __SIZE_TYPE__
#define size_t long unsigned int
#endif // __SIZE_TYPE__

template <class T>
class Vector
{
public:
    Vector() : mnSize(0), mnCapacity(1), mpData(new T[mnCapacity]){}
    ~Vector(){
        delete[] mpData;
        mpData = nullptr;
    }

    void push_back(const T& value){
        // 如果存满了, 拓展容量
        if(mnSize == mnCapacity){
            mnCapacity *= 2;
            T* new_data = new T[mnCapacity];
            for (size_t i=0; i < mnSize; i++)
                new_data[i] = mpData[i];
            delete[] mpData;
            mpData = new_data;
        }
        mpData[mnSize++] = value;
    }

    class iterator;
    iterator begin();
    iterator end();

private:
    T* mpData;
    size_t mnSize;
    size_t mnCapacity;
};


template<class T>
class Vector<T>::iterator
{
public:
    iterator(T* ptr) : mpPtr(ptr){};
    // 重载解引用运算符 *
    T& operator*(){
        return *mpPtr;
    }
    // 重载 != 运算符
    bool operator!=(const iterator& other) const {
        return mpPtr != other.mpPtr;
    }
    // // 重载 ++ 运算符
    iterator& operator++(){
        ++mpPtr;
        return *this;
    }
    // iterator operator++(){
    //     ++mpPtr;
    //     return *this;
    // }

private:
    T* mpPtr;
};

// 使用 typename
template<class T>
typename Vector<T>::iterator Vector<T>::begin(){
    return iterator(mpData);
}
// 不使用 typename
template<class T>
typename Vector<T>::iterator Vector<T>::end(){
    return iterator(mpData+mnSize);
}

int main(int argc, char** argv)
{
    Vector<int> vec;
    // vec.push_back(1);
    // vec.push_back(2);
    // vec.push_back(3);
    // vec.push_back(4);

    // for(auto it=vec.begin(); it != vec.end(); ++it)
    //     printf("%d ", *it);
    // printf("\n");
    auto it = vec.begin();
    printf("%p\n", &it);

    auto it_ = ++it;
    printf("%p\n", &it_);


    return 0;
}