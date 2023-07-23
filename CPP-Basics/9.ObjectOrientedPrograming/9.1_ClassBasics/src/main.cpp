#include <iostream>
using namespace std;

#define max(a, b) ((a) > (b)) ? (a) : (b)
#define min(a, b) ((a) < (b)) ? (a) : (b)


class BBox
{
    public :
        ~BBox(){};
        BBox(){};
        BBox(float left, float top, float right, float bottom);

        float left();
        float top();
        float right();
        float bottom();
        float width();
        float height();
        float area();

    public :
        float operator&(const BBox& other);
        float operator|(const BBox& other);
        float operator^(const BBox& other);

    private :
        float m_left;
        float m_top;
        float m_right;
        float m_bottom;
        float m_width;
        float m_height;
        float m_area;
};

BBox::BBox(float _left, float _top, float _right, float _bottom){
    m_left = _left;
    m_top = _top;
    m_right = _right;
    m_bottom = _bottom;
    m_width = width();
    m_height = height();
    m_area = area();
}

float BBox::left(){return m_left;}
float BBox::top(){return m_top;}
float BBox::right(){return m_right;}
float BBox::bottom(){return m_bottom;}

float BBox::width(){
    return m_right - m_left + 1;
}
float BBox::height(){
    return m_bottom - m_top + 1;
}
float BBox::area(){
    return m_height * m_width;
}

float BBox::operator&(const BBox& other)
{
    
    float left   = max(this->m_left, other.m_left);
    float top    = max(this->m_top, other.m_top);
    float right  = min(this->m_right, other.m_right);
    float bottom = min(this->m_bottom, other.m_bottom);
    BBox cross_box(left, top, right, bottom);
    if (cross_box.width() <= 0 or cross_box.height() <= 0)
        return 0;
    return cross_box.area(); 
}

float BBox::operator|(const BBox& other)
{
    float cross_area = *this & other;
    float union_area = this->area()  + other.m_area - cross_area;
    return union_area;
}

float BBox::operator^(const BBox& other)
{
    float cross_area = *this & other;
    float union_area = *this | other;
    return (cross_area / union_area);
}

int main()
{
    BBox b1(10.0, 8.0, 20.0, 28.0);
    BBox b2(15.0, 9.0, 40.0, 20.0);

    cout << (b1 & b2) << endl;
    cout << (b1 | b2) << endl;
    cout << (b1 ^ b2) << endl;

    return 0;
}