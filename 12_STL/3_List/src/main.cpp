#include <iostream>
#include <list>
using namespace std;

void printList(const list<int>&l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    list <int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    l1.push_back(50);
    l1.push_back(10);
    l1.push_back(10);
    l1.push_back(10);
    l1.push_back(10);

    printList(l1);
    l1.remove(10);
    printList(l1);


}