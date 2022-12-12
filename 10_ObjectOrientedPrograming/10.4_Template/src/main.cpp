

#include <iostream>
using namespace std;


template <class T1>
class Student
{
    T1 score[3];
    public :
        Student(T1 a, T1 b, T1 c);
        T1 getAverage();

        template <typename T2>
        void showinfo(T2 index);
};

template <class T1>
Student<T1>::Student(T1 a, T1 b, T1 c){
    score[0] = a;
    score[1] = b;
    score[2] = c;
}

template <class T1>
T1 Student<T1>::getAverage(){
    return (score[0] + score[1] + score[2])/3;
}

template <class T1>
template<typename T2>
void Student<T1>::showinfo(T2 index){
    cout << score[index] << endl;
}


int main()
{
    Student<float> s(70.5, 85.5, 90.0);
    s.showinfo(0);
    s.showinfo(1);
    s.showinfo(2);

    cout << "The average: " << s.getAverage() << endl;
    return 0;
}































