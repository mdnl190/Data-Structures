#include <iostream>
#include <cassert>
#include "llist.h"
#include "llist.h"

using namespace std;

int main()
{
  LinkedList<int> mylist;
  mylist.push_front(2);
  mylist.push_front(4);
  mylist.push_back(6);
  cout << "I expect the elements to be 4 2 6\n\tActual: ";
  cout << mylist.front() << " "; mylist.pop_front();
  cout << mylist.front() << " "; mylist.pop_front();
  cout << mylist.front() << " "; mylist.pop_front();

  cout << "\nI expect my list to be empty.\n\tActual: ";
  mylist.empty()? cout << "true": cout << "false";

  mylist.push_front(2);
  mylist.push_front(4);
  mylist.push_back(6);
  mylist.reverse();

  cout << "\nI expect the elements to be 6 2 4\n\tActual: ";
  cout << mylist.front() << " "; mylist.pop_front();
  cout << mylist.front() << " "; mylist.pop_front();
  cout << mylist.front() << " "; mylist.pop_front();

  mylist.push_front(2);
  mylist.push_front(4);
  mylist.push_back(6);

  cout << "\nI expect my list not to be empty.\n\tActual: ";
  mylist.empty()? cout << "true": cout << "false";
}
