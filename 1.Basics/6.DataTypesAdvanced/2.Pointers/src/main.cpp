#include <stdio.h>

// int main(int argc, char *argv[])
int main(int argc, char** argv)
{
    int array[] = {1, 2, 3, 4, 5};

    int (&refArray)[5] = array;
    // 错误语法: 
    // int &refArray[5]  = array; 必须带括号
    // int (&refArray)[] = array; 元素数必须一致

    printf("value of array   : %p\n", array);
    printf("value of refArray: %p\n", refArray);

    return 0;
}