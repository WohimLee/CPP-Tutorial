#include <iostream>
using namespace std;

enum months_t
{
    January = 1,
    February,
    March,
    April,
    May,
    June, 
    July,
    August,
    September,
    October,
    November,
    December
}m;

enum weekday {Sun=7, Mon=1, Tue, Wed, Thu, Fri, Sat};


enum color_set {RED, BLUE, WHITE, BLACK}; 


int main()
{
    color_set c;
    cout << c << endl;

    c = BLUE;
    cout << c << endl;
    return 0;
}