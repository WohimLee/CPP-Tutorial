#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
using namespace std;
class Tracking;
class LocalMapping;
class LoopClosing;

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
public:
    // void TrackMonocular(); // 没有实现
    // void TrackMonocular(){}; // 空实现
    void TrackMonocular(){
        printf("Call function: void TrackMonocular()\n");
    }; // 具体实现

private:
    eSensor mSensor;
    bool mbReset;
    bool mbResetActiveMap;
    bool mbActivateLocalizationMode;
    bool mbDeactivateLocalizationMode;
    bool mbShutDown;

};
#endif // SYSTEM_H