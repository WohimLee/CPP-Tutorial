
#include <stdio.h>

namespace ORB_SLAM2{
    void init(){
        printf("init function in ORB_SLAM2.\n");
    }
}

namespace ORB_SLAM3{
    void init(){
        printf("init function in ORB_SLAM3.\n");
    }
}

int main()
{
    using namespace ORB_SLAM2;
    // using namespace ORB_SLAM3;
    init();
    return 0;
}