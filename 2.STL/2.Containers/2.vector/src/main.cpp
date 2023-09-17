#include <iostream>
#include <vector>
using namespace std;


void printVector(vector<int>& v){
    for(vector<int>::iterator it=v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
}

int main(){

    vector<int> vec;
    for(int i=0; i<10; i++)
        vec.push_back(i+5);
    
    printVector(vec);

    vec.pop_back();
    printVector(vec);

    vec.insert(vec.begin(), 100);
    printVector(vec);

    vec.erase(vec.begin());
    printVector(vec);

    vec.erase(vec.begin(), vec.end());
    printVector(vec);

    vec.clear();
    printVector(vec);

    return 0;
}