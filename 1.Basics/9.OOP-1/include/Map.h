#ifndef MAP_H
#define MAP_H

#include <stdio.h>
class Map
{
public:
    Map(){
        printf("Map constructor Map().\n");
    };
    Map(int initKFid){
        printf("Map constructor Map(int initKFid).\n");
    };
};

#endif // MAP_H