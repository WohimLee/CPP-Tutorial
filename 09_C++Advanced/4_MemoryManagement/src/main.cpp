#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N (10)

int main()
{
    char* str1 = "abcde";
    char* str2 = (char*)malloc(sizeof(char) * N);
    char* str3 = (char*)memcpy(str2, str1, N);
    printf("str2 = %s\nstr3 = %s\n", str2, str3);
    free(str2);
    str2 = NULL;
    str3 = NULL;

    int var1 = 10;
    int* var2 = (int*)malloc(sizeof(int));
    int* var3 = (int*)memcpy(var2, &var1, 1);
    printf("var2 = %d\nvar3 = %d\n", *var2, *var3);
    free(var2);
    var2 = NULL;
    var3 = NULL;

    return 0;
}