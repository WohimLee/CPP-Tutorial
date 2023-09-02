#include <iostream>
using namespace std;

class System
{
public:
    enum eSensor{
        MONOCULAR=0,
        STEREO=1,
        RGBD=2,
        IMU_MONOCULAR=3,
        IMU_STEREO=4,
        IMU_RGBD=5,
    };

public:
    System(){}; // 如果不写, 不能使用 System SLAM;
    System(bool init){};

private:
    eSensor mSensor;
};

int main(int argc, char** argv)
{
    

    return 0;
}