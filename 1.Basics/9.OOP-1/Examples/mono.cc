
#include <stdio.h>
#include "Map.h"
#include "System.h"
#include "Tracking.h"
#include "LocalMapping.h"
#include "LoopClosing.h"


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
    System(){}; // 因为有了其它构造函数, 必须自己写默认构造函数
    System(const eSensor sensor):
    mSensor(sensor), mbReset(false), mbResetActiveMap(false),
    mbActivateLocalizationMode(false), mbDeactivateLocalizationMode(false), mbShutDown(false)
    {
        printf("System constructor with initialization.\n");
        printf("mbReset: %s\n", mbReset == true ? "True" : "False");
        printf("mbResetActiveMap: %s\n", mbResetActiveMap == true ? "True" : "False");
        printf("mbActivateLocalizationMode: %s\n", mbActivateLocalizationMode == true ? "True" : "False");
        printf("mbDeactivateLocalizationMode: %s\n", mbDeactivateLocalizationMode == true ? "True" : "False");
        printf("mbShutDown: %s\n", mbShutDown == true ? "True" : "False");
    }

private:
    eSensor mSensor;
    bool mbReset;
    bool mbResetActiveMap;
    bool mbActivateLocalizationMode;
    bool mbDeactivateLocalizationMode;
    bool mbShutDown;

};

int main(int argc, char** argv){
    System SLAM1; // 如果补上默认构造函数, 这里会报错
    System SLAM2(System::MONOCULAR);

    return 0;
}

