#include <stdio.h>

int main(){

   printf("%-*s: %d Bytes\n", 13, "int", sizeof(int));
   printf("%-*s: %d Bytes\n", 13, "char", sizeof(char));
   printf("%-*s: %d Bytes\n", 13, "float", sizeof(float));
   printf("%-*s: %d Bytes\n\n", 13, "double", sizeof(double));

   printf("%-*s: %d Bytes\n", 13, "char", sizeof(char));
   printf("%-*s: %d Bytes\n", 13, "signed char", sizeof(signed char));
   printf("%-*s: %d Bytes\n\n", 13, "unsigned char", sizeof(unsigned char));

   printf("%-*s: %d Bytes\n", 12, "int", sizeof(int));
   printf("%-*s: %d Bytes\n", 12, "signed int", sizeof(signed int));
   printf("%-*s: %d Bytes\n\n", 12, "unsigned int", sizeof(unsigned int));

   printf("%-*s: %d Bytes\n", 18, "short int", sizeof(short int));
   printf("%-*s: %d Bytes\n", 18, "signed short int", sizeof(signed short int));
   printf("%-*s: %d Bytes\n\n", 18, "unsigned short int", sizeof(unsigned short int));

   printf("%-*s: %d Bytes\n", 17, "long int", sizeof(long int));
   printf("%-*s: %d Bytes\n", 17, "signed long int", sizeof(signed long int));
   printf("%-*s: %d Bytes\n\n", 17, "unsigned long int", sizeof(unsigned long int));

   return 0;
}