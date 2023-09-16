
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1 = "abcdefga";
    cout << str1.find("bc") << endl;
    cout << str1.rfind('a') << endl;
    cout << str1.replace(2, 3, "88") << endl;
} 