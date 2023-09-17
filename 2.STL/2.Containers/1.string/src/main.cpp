
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "hello STL";

    printf("%s\n", str.substr(1, 3).c_str());

    return 0;
} 