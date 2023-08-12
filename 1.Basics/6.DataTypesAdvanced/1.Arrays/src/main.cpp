#include <stdio.h>
#include <iostream>
#include <cmath>

int main() {
  
    float v[3] = {1, 2, 3};
    // float w[3] = {1, 2, 3};
    float u[3];
    float sum=0;

    for(int i=0; i<3; i++)
        sum += v[i]*v[i];
    
    printf("res: %f\n", sqrt(sum));
    return 0;
}