#include <stdio.h>
#include <iostream>

int main() {
    int var[3][3][3];
    int count = 50;
    for(int i=0; i< 3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                var[i][j][k]=count;
                count++;
            }
        }
    }
    printf("Address of var: %p.\n", &var);
    printf("Value of var: %p.\n", var);

    for(int i=0; i<3; i++){
        printf("Value of var[%d]: %p.\n", i, var[i]);
    }



    return 0;
}