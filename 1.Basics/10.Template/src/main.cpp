
#include <iostream>

#ifndef __SIZE_TYPE__
#define size_t long unsigned int
#endif // __SIZE_TYPE__

template<class T>
class Vector
{
public:
    Vector() : mnSize(0), mnCapacity(1), mpData(new T[mnCapacity]){};
    ~Vector(){
        delete[] mpData;
        mpData = nullptr;
    }
    void push_back(T value){
        if(mnSize == mnCapacity){
            mnCapacity *= 2;
            new_data = new T[mnCapacity];
            for(size_t i=0; i < mnSize; i++)
                new
        }
        mpData[mnSize++] = value;
    }
private:
    T* mpData;
    size_t mnSize;
    size_t mnCapacity
};



int main(int argc, char** argv)
{
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);



    return 0;
}