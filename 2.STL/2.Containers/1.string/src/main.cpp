

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "Hello "; 
    string str1 = str;
    printf("str1 = %s\n", (str1+="World").c_str()); // += const char*
    printf("str1 = %s\n", (str1+='!').c_str()); // += const char

    string str2 = "123456";
    printf("str1 = %s\n", (str1+=str2).c_str()); // += string

    string str3 = str;
    printf("str3 = %s\n", str3.append("0123456789", 5).c_str());

    string str4 = str;
    printf("str4 = %s\n", str4.append("0123456789", 3, 5).c_str());
    return 0;
} 