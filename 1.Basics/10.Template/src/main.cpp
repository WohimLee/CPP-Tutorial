#include <iostream>
using namespace std;

template <class T1>
class Student
{
T1 score[3];
public :
    Student(T1 a, T1 b, T1 c);

    template <typename T2>
    void showinfo(T2 index){
        cout << score[index] << endl;
    };
};

template <class T1>
Student<T1>::Student(T1 a, T1 b, T1 c)
{
    score[0] = a;
    score[1] = b;
    score[2] = c;
}

// // 类外实现也可以, 不建议
// template<class T1>
// template<typename T2>
// void Student<T1>::showinfo(T2 index)
// {
//     cout << score[index] << endl;
// }


int main()
{
    Student<float> s(68.5, 85.4, 90.0);
    s.showinfo(0);
    s.showinfo(1);
    s.showinfo(2);

    return 0;
}