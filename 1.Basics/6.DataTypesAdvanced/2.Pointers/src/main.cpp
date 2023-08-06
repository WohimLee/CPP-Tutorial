#include <iostream>
using namespace std;


int main()
{
    int a  = 10;
    char b = 'x';

    int* pInt   = &a;
    char* pChar = &b;

    // 增加 4 (字节数)
    printf("%-17s: %p\n", "value of pInt", pInt);
    printf("%-17s: %p\n", "value of pInt+=1", pInt+=1);
    printf("%-17s: %p\n", "value of ++pInt", ++pInt);
    printf("%-17s: %p\n", "value of pInt+1", pInt+1); // 不推荐

    printf("\n");

    // 减少 1 (字节数)
    printf("%-18s: %p\n", "value of pChar", pChar);
    printf("%-18s: %p\n", "value of pChar+=1", pChar-=1);
    printf("%-18s: %p\n", "value of ++pCnt", --pChar);
    printf("%-18s: %p\n", "value of pCnt+1", pChar-1); // 不推荐


    return 0;
}