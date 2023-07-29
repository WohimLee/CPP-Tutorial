#include <iostream>
#include <list>
using namespace std;

void printList(const list<int>&l)
{
    for (const auto& item : l)
        cout << item << " ";
    cout << endl;
}



int main()
{
    list<int> L1;
    L1.push_back(1);
    L1.push_back(7);
    L1.push_back(5);
    L1.push_back(10);

    printList(L1);

    
    return 0;
}
















