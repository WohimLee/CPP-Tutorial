#include <iostream>


int main() {
    float focal = 0.5;
    float Xreal = 2;
    float Yreal = 4;
    float Zreal = 6;
    
    float xCam = focal * Xreal / Zreal;
    float yCam = focal * Yreal / Zreal;
    printf("像平面x方向坐标:%.3f\n", xCam);
    printf("像平面y方向坐标:%.3f\n", yCam);

    return 0;
    return 0;
}