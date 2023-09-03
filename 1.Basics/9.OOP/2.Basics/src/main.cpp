
#include <iostream>
using namespace std;

#define INIT_SIZE 128

#ifndef _MATH_H_
#define OVERFLOW  -2
#define UNDERFLOW -3
#endif // _MATH_H_

class List
{
public :
    ~List();
    List();
    List(int n);
    // size 加了 const 重载
    int size();
    int size() const;
    // capacity 没加 const 重载
    int capacity();

private :
    void* m_data = nullptr;
    int m_size;
    int m_capacity;
};

List::~List(){
    free(m_data);
    m_size = 0;
    m_capacity = 0;
}


List::List(){
    m_data = malloc(INIT_SIZE*sizeof(int));
    if (!m_data)
        exit(OVERFLOW);
    m_size = 0;
    m_capacity = INIT_SIZE;
}

List::List(int n)
{
    m_data = (int*)malloc(n*sizeof(int));
    if (!m_data)
        exit(OVERFLOW);
    m_size = 0;
    m_capacity = n;
}

int List::size(){
    return this->m_size;
}

int List::size() const{
    return this->m_size;
}

int List::capacity(){
    return this->m_capacity;
}

int main(){
    const List L1; // 加了 const 修饰的实例
          List L2; // 没有加 const 修饰的实例
    // size()有重载，常对象L1可以调用size()
    cout << L1.size() << endl;
    cout << L2.size() << endl;

    // capacity()没有重载，常对象L1无法调用capacity()
    // cout << L1.capacity() << endl; 
    cout << L2.capacity() << endl;

    return 0;
}