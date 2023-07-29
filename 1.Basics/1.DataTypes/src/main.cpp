#include<iostream>
#include<string>
#include <bitset>
using namespace std;


int main(){

   short s = 35;
   // 按 8 位输出
   cout << bitset<8>(s) << endl;

   return 0;
}