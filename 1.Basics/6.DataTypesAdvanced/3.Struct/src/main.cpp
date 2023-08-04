#include <iostream>
#include <string.h>
using namespace std;

struct movies_t
{
    char title[50];
    int year;
};

struct person_t
{
    char name[50];
    char email[50];
    movies_t amovie;
}a, b;


int main()
{
    // a.amovie.title = ;
    a.amovie.year = 10;
    

    
    return 0;
}