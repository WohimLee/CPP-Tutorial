#include <iostream>
using namespace std;

struct
{
    char title[50];
    char author[50];
    union{
        float dollars;
        int yens;
    }price;
}book1;

struct 
{
    char title[50];
    char author[50];
    union{
        float dollars;
        int yens;
    };
}book2;


int main()
{

    cout << book1.title << endl;
    cout << book1.author << endl;
    cout << book2.title << endl;
    cout << book2.author << endl;

    cout << book1.price.dollars << endl;
    cout << book1.price.yens << endl;


    cout << book2.dollars << endl;
    cout << book2.yens << endl;

    
    

    return 0;
}


