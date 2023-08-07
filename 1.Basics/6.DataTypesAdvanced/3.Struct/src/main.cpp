#include <stdio.h>

struct Camera{
    double focal=500;
    double fx;
    double fy;
    double cx;
    double cy;
}cam1, *pCam2;

int main()
{
    Camera* pCam3;
    pCam3 = &cam1;

    pCam3->fx = 500;
    pCam3->fy = 500;
    (*pCam3).cx = 320;
    (*pCam3).cy = 240;

    printf("cam1.fx = %lf\n", cam1.fx);
    printf("cam1.fy = %lf\n", cam1.fy);
    printf("cam1.cx = %lf\n", cam1.cx);
    printf("cam1.cy = %lf\n", cam1.cy);

    return 0;
}