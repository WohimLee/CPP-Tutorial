
#include <stdio.h>

int main ()
{
  int rows = 800;
  int cols = 600;

  for(int i=0; i < rows; i++){
    for(int j=0; j < cols; j++){
      printf("Pixel coordinates: (%d, %d)\n", i, j);
    }
  }
return 0;
} 