#ifndef LOCALMAPPING_H
#define LOCALMAPPING_H

#include <stdio.h>

class LocalMapping
{
public:
    void InsertKeyFrame();

};

void LocalMapping::InsertKeyFrame(){
    printf("Call InsertKeyFrame function.\n");
}



#endif // LOCALMAPPING_H