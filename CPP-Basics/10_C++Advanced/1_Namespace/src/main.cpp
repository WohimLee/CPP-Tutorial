#include <iostream>
// using namespace std;
namespace xxx = std;

int main()
{
    std::cout << "Hello" << std::endl;

    xxx::cout << "Hello" << xxx::endl;

    return 0;
}