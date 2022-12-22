#include <iostream>
#include <fstream>
using namespace std;

void load_mnist_labels(const string& file){

    ifstream in(file, ios::binary | ios::in);

    if(!in.is_open()){
        printf("Open File Failed!");
    }

    int header[2];
    in.read((char*)header, sizeof(header));
    cout << header[0] << endl;

}

int main()
{
    string labels = "/datav/MyLesson/2_Cpp/3_CC++_Programing_Basics/5_InputOutput/workspace/t10k-labels-idx1-ubyte";
    load_mnist_labels(labels);

    return 0;
}