
#include <stdio.h>
#include <iostream>

using namespace std;

int main ()
{
  char choice;
  cout << "Enter A, B or C: ";
  cin >> choice;
  switch(choice)
  {
    case 'A':
      cout << "You entered A." << endl;
      break;
    case 'B':
      cout << "You entered B." << endl;
      break;
    case 'C':
      cout << "You entered C." << endl;
      break;
    default:
      cout << "not A, B or C." << endl;
  }
  return 0;
} 