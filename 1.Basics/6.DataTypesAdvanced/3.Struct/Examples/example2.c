
#include <stdio.h>

typedef struct msgTemp
{
    char a;
    char b;
    int index;
}MSG;

int main(int argc, char** argv)
{
    struct msgTemp msg1[5];
    MSG msg2[5]; // 不用 struct 关键字
    for(int i=0; i<5; i++)
    {
        msg1[i].index = i;
        msg1[i].a = 10+i;
        msg1[i].b = 20+i;
    }
    for(int i=0; i<5; i++)
        printf("msg[%d]: a=%d, b=%d, index=%d\n", 
               i, msg1[i].a, msg1[i].b, msg1[i].index);

    return 0;
}