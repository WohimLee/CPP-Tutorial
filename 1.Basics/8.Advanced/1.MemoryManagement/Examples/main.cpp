#include <stdio.h>

struct Camera{
    double focal;
    double fx;
    double fy;
    double cx;
    double cy;
};

int main()
{
    int* pInt = new int;
    if(pInt) printf("new an array: int[5].\n");
    else printf("new failed.\n");


    Camera* pCam = new Camera[5];
    if(pCam) printf("new an array: Camera[5].\n");
    else printf("new failed.\n");

    delete pInt;
    delete[] pCam;

    return 0;
}