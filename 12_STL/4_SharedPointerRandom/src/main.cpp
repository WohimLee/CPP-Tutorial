#include <memory>
#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <random>
using namespace std;




int main()
{
    uniform_int_distribution<unsigned> u(0, 9);
    default_random_engine e;
    for (int i = 0; i < 10; ++i)
        cout << u(e) << " ";
    cout << endl;
    
    return 0;
}