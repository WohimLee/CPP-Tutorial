#include <stdio.h>

void printMessage(){
  printf("Enter your message here...");
}

int add(int a, int b){
  return a + b;
};

float minus(float a, float b){
  printf("a - b = %f\n", a-b);
  // 无 return
}

int main()
{
  int a = 10;
  int b = 20;

  int res1    = add(a, b);
  float res2  = add(a, b);
  double res3 = add(a, b);
  printf("res1: %d\n", res1);
  printf("res2: %f\n", res2);
  printf("res3: %lf\n", res3);
  return 0;
}