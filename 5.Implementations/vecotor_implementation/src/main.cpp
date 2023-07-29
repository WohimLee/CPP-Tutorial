#include <vector>
#include <iostream>
#include <stdio.h>
#include "myVector.hpp"
using namespace std;

void printVector(myVector<int>& v)
{
    for (myVector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }cout << endl;
}

int main(int argc, char** argv)
{
    myVector<int> v1;

    for(int i=0; i<10; i++)
        v1.push_back(i);
    
    printVector(v1);

    printf("v1.at(5) = %d.\n", v1.at(5));
    printf("v1[5] = %d.\n\n", v1[5]);

    printf("*(v1.begin()) = %d.\n", *(v1.begin()));
    printf("*(v1.end()) = %d.\n\n", *(v1.end()));

    printf("v1.size() = %d.\n",v1.size());
    v1.resize(15, 888);
    printf("v1.size() after resize() = %d.\n\n",v1.size());

    printf("v1.capacity() = %d.\n", v1.capacity());
    v1.reserve(20);
    printf("v1.capacity() after reserve() = %d.\n\n", v1.capacity());

    printf("v1.front() = %d.\n", v1.front());
    printf("v1.back() = %d.\n", v1.back());
 

    return 0;
}