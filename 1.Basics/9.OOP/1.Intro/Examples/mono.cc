
#include <iostream>


class LocalMapping
{
public:
    void Run();
};

void LocalMapping::Run(){
    printf("Call function: LocalMapping::Run()\n");
}

int main(int argc, char** argv)
{
    LocalMapping mapper;
    mapper.Run();

    return 0;
}
