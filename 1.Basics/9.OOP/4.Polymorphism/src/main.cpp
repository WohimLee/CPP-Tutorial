
#include <iostream>

class Calculator {
public:
    int add(int a, int b) {
        printf("Call function: int add(int a, int b);\n");
        return a + b;
    }

    double add(double a, double b) {
        printf("Call function: double add(double a, double b);\n");
        return a + b;
    }

    int add(int a, int b, int c) {
        printf("Call function: int add(int a, int b, int c);\n");
        return a + b + c;
    }
};

int main() {
    Calculator calculator;
    calculator.add(1, 2);     // Calls the first add method
    calculator.add(1.1, 2.2); // Calls the second add method
    calculator.add(1, 2, 3);  // Calls the third add method

    return 0;
}