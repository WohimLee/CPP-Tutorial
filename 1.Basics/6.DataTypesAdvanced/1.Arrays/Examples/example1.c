
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    char a[10] = "Hello";
    char* b = "Hello";
    if (strcmp(a, b) == 0) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    return 0;
}