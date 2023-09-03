#ifndef TRACKING_H
#define TRACKING_H


class LocalMapping;
class LoopClosing;
class System;

class Tracking
{  

public:
    Tracking();

    void SetLocalMapper(LocalMapping* pLocalMapper);
    void SetLoopClosing(LoopClosing* pLoopClosing);

public:

    // Tracking states
    enum eTrackingState{
        SYSTEM_NOT_READY=-1,
        NO_IMAGES_YET=0,
        NOT_INITIALIZED=1,
        OK=2,
        LOST=3
    };

    eTrackingState mState;
    // Input sensor
    int mSensor;

protected:

    // Main tracking function. It is independent of the input sensor.
    void Track();

    void CreateNewKeyFrame();

    unsigned int mnLastKeyFrameId;

    //Color order (true RGB, false BGR, ignored if grayscale)
    bool mbRGB;
};

#endif // TRACKING_H