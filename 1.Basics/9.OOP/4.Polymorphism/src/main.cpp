#include <iostream>

class Vector2D 
{
public:
    Vector2D(float x = 0, float y = 0) : x(x), y(y) {}

    Vector2D& operator+=(const Vector2D& other) {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(this->x + other.x, this->y + other.y);
    }

    void data() const {
        printf("x=%-9f, y=%f\n", x, y);
    }

private:
    float x, y;
};

int main() {
    Vector2D vec1(1.0f, 2.0f);
    Vector2D vec2(3.0f, 4.0f);
    Vector2D vec3(5.0f, 7.0f);
    
    vec1 += vec2;
    printf("vec1: ");
    vec1.data(); // Output: X: 4.0, Y: 6.0

    vec1 += vec2 += vec3;
    printf("vec1: ");
    vec1.data(); // Output: X: 4.0, Y: 6.0

    return 0;
}
