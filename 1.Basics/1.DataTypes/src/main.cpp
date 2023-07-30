#include <stdio.h>

int main(){

   printf("%-*s: %d Bytes\n", 10, "int*", sizeof(int*));
   printf("%-*s: %d Bytes\n", 10, "char*", sizeof(char*));
   printf("%-*s: %d Bytes\n", 10, "float*", sizeof(float*));
   printf("%-*s: %d Bytes\n", 10, "double*", sizeof(double*));
   printf("%-*s: %d Bytes\n\n", 10, "long int*", sizeof(long int*));
   printf("%-*s: %d Bytes\n", 10, "short int*", sizeof(short int*));

   return 0;
}