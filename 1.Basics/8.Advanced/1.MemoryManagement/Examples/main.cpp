#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Camera{
    double focal;
    double fx;
    double fy;
    double cx;
    double cy;
};



int main()
{

    int* pInt = new int[5];
    if(pInt) printf("new an int.\n");
    else printf("new failed.\n");

    Camera* pCam = new Camera[5];
    if(pCam) printf("new an pCam.\n");
    else printf("new failed.\n");

    delete[] pInt;
    delete[] pCam;
    pInt = nullptr;
    pCam = nullptr;
    return 0;
}