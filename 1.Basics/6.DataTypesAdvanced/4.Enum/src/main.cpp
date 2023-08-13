#include <iostream>
using namespace std;

enum eSensor{
    MONOCULAR=0,
    STEREO=1,
    RGBD=2
};




int main()
{
    eSensor cam = MONOCULAR;

    switch(cam){
        case MONOCULAR:
            printf("Constructing MONOCULAR object.\n");
            break;
        case STEREO:
            printf("Constructing STEREO object.\n");
            break;
        case RGBD:
            printf("Constructing RGBD object.\n");
            break;
        default:
            printf("Unknow Camera Sensor.\n");
    }

    return 0;
}