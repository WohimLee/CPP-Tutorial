
#include <stdio.h>

int main()
{
    float focal = 0.5; // 500mm
    float alpha = 100;
    float beta  = 100;

    // Intrisic Parameters 相机内参
    float fx    = alpha * focal;
    float fy    = beta  * focal;
    float cx    = 0.32; // 320mm
    float cy    = 0.24; // 240mm

    float Xreal = 2; // m
    float Yreal = 4; // m
    float Zreal = 6; // m

    int u = fx * Xreal/Zreal + cx;
    int v = fy * Yreal/Zreal + cy;

    printf("Point in 3D space: (X,Y,Z) = (%f, %f, %f)\n", Xreal, Yreal, Zreal);
    printf("Pixel coordinates: (u,v) = (%d, %d)\n", u, v);
    return 0;
}