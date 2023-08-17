
#include <stdio.h>
#include "System.h"
#include "Tracking.h"
#include "LocalMapping.h"
#include "LoopClosing.h"

int main(int argc, char** argv){

    LocalMapping mapper;
    mapper.InsertKeyFrame();

    return 0;
}

