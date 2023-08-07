#include <iostream>
using namespace std;

typedef enum {
    // Not apply any rotation
    ROTATION_IGNORE = -1,
    // 0 degree rotation (natural orientation)
    ROTATION_0   = 0,
    // 90 degree rotation (natural orientation)
    ROTATION_90  = 1,
    // 180 degree rotation (natural orientation)
    ROTATION_180 = 2,
    // 270 degree rotation (natural orientation)
    ROTATION_270 = 3
}ScreenRotation;

int main()
{
    ScreenRotation camera_rotation;
    camera_rotation = ROTATION_0;

    printf("Call function, set ScreenRotation: %d\n", camera_rotation);

    return 0;
}