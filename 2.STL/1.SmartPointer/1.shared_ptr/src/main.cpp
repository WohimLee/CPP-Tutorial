#include <memory>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <opencv2/core>
using namespace std;


class Config
{
public:
    cv::FileStorage mFile;
private:
    static std::shared_ptr<Config> mConfig;
    
}

int main()
{
    shared_ptr<string> p1;        // 指向 string
    shared_ptr<list<int>> p2;     // 指向 int 的 list
    shared_ptr<vector<float>> p3; // 指向 float 的 vector
}