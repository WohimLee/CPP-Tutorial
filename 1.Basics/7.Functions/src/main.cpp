#include <stdio.h>




// long unsigned int len(int array[]){

//     return (long unsigned int)(sizeof(array)/sizeof(array[0]));
// }


void printArray(int array[]){
    printf("sizeof array   : %ld\n", sizeof(array));
    printf("sizeof array[0]: %ld\n", sizeof(array[0]));
}


int main(){
    int array[10];
    for(int i=0; i<10; i++)
        array[i] = 10+i;
    printf("sizeof array   : %ld\n", sizeof(array));
    printf("sizeof array[0]: %ld\n", sizeof(array[0]));

    printArray(array);
}