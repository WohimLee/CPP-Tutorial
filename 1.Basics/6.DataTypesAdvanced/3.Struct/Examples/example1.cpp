#include <stdio.h>
#include <stdlib.h>

struct Camera{
    double focal=500;
    double fx;
    double fy;
    double cx;
    double cy;
};

int main()
{
    // Camera* pCam = new Camera;
    Camera* pCam;
    pCam = (struct Camera*)malloc(sizeof(struct Camera));
    if(pCam == NULL) return -1;

    pCam->fx = 500;
    pCam->fy = 500;
    (*pCam).cx = 320;
    (*pCam).cy = 240;

    printf("cam1.fx = %lf\n", pCam->fx);
    printf("cam1.fy = %lf\n", pCam->fy);
    printf("cam1.cx = %lf\n", pCam->cx);
    printf("cam1.cy = %lf\n", pCam->cy);

    // delete pCam;
    free(pCam);
    return 0;
}