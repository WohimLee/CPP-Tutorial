

#include <iostream>

template <class T>
class Student
{
public:
    Student(T a, T b, T c){
        score[0]=a;
        score[1]=b;
        score[2]=c;
    }

    template <typename T2>
    void showinfo(T2 index){
        printf("score[%d]=%f\n", index, score[index]);
    }

private:
    T score[3];
};


int main(int argc, char** argv)
{
    Student<float> s(55.5, 66.6, 77.7);
    s.showinfo(0);
    s.showinfo(1);
    s.showinfo(2);

    return 0;
}