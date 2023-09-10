

#include <iostream>
using namespace std;

class GeometricCamera
{
public:
    void setParameter(){
        printf("settting parameters...\n");
        printf("mbInit = %s\n", mbInit == true ? "true" : "false");
    }
    const static unsigned int CAM_PINHOLE = 0;
    const static unsigned int CAM_FISHEYE = 1;

protected :
    unsigned int mnType;

private :
    bool mbInit;
};

class Pinhole : private GeometricCamera
{
public:
    void access(){
        printf("public members from base class: \n");
        printf("CAM_PINHOLE = %d\n", CAM_PINHOLE);
        printf("CAM_FISHEYE = %d\n", CAM_FISHEYE);

        printf("protected members from base class: \n");
        printf("Camera model: %s\n", mnType == 0 ? "CAM_PINHOLE" : "CAM_FISHEYE");

        printf("private members from base class: \n");
        // printf("value of mbInit: %s\n", mbInit == 1 ? "true" : "false");
    }
};


int main(int argc, char** argv)
{
    Pinhole cam;
    cam.access();

    return 0;
}