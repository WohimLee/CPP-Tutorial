#include <stdio.h>
#include <iostream>

int main() {
  
    int aaabbb[3][2][2] = {0,1,2,3,4,5,6,7,8,9,10,11};
    // int* ptr = (int*)array;
    // printf("value of ptr[11]: %d\n", ptr[11]);
    for (int i=0; i<3; i++){
        for (int j=0; j<2; j++){
            for (int k=0; k<2; k++)
            {
                printf("%d ", aaabbb[i][j][k]);
            }
        }
    }
    printf("\n");


    return 0;
}