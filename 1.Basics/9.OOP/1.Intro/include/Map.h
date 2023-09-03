#ifndef MAP_H
#define MAP_H

namespace ORB_SLAM2
{

class MapPoint;
class KeyFrame;

class Map
{
public:

    void AddKeyFrame(int KF);
    void AddMapPoint(int MP);
    void EraseMapPoint(int MP);
    void EraseKeyFrame(int KF);
};

} //namespace ORB_SLAM
#endif // MAP_H