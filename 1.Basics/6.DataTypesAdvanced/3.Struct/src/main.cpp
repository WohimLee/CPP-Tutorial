#include <stdio.h>


struct resolution_t{
    unsigned int width;
    unsigned int height;
};


struct Frame{
    resolution_t res;
    unsigned int id;
    unsigned char* data;
};


int main()
{
    int* a;
    Frame* pFrame;
    pFrame->res.width  = 800;
    pFrame->res.height = 800;


    return 0;
}