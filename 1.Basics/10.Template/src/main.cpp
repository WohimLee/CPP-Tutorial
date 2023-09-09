#include <iostream>

template <class T, int N>
class Array {
public:
    T arr[N];  // Array of N elements of type T

    void fill(const T& value) {
        for(int i = 0; i < N; ++i) {
            arr[i] = value;
        }
    }

    void print() const {
        for(int i = 0; i < N; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << '\n';
    }
};

int main() {
    Array<int, 5> intArray;
    intArray.fill(10);
    intArray.print();  // Output: 10 10 10 10 10 

    Array<double, 3> doubleArray;
    doubleArray.fill(3.14);
    doubleArray.print();  // Output: 3.14 3.14 3.14 

    return 0;
}
