
#include <string>
#include <memory>

int main()
{

    std::unique_ptr<std::string> pname{new std::string {"Algernon"}};

    return 0;
}



