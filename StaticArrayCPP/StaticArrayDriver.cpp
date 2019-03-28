/*Lab 3a, Static Array Program
Programmer: Mary Latif
Editor(s) used: Visual C++
Compiler(s) used: Visual Studio 2013*/

#include "StaticArray.h"
#include "StaticArray.h"
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

const int SIZE = 14; 

int main()
{
  StaticArray<double, SIZE> myArray;
  vector<int> values;

  //header
  cout << "Lab 3a, Static Array Program \nProgrammer: Mary Latif" << endl << endl;

  //function testing
  {
  //testing the constructor
  cout << "\nTesting the constructor. I expect the size to be 0.";
  cout << "\n\tActual size: " << myArray.size();
  assert(0 == myArray.size());
  cout << "\nI expect the result of myArray.containsKey(7) to be false";
  cout << "\n\tActual result: ";
  myArray.containsKey(7) ? cout << "true" << endl : cout << "false" << endl;
  assert(false == myArray.containsKey(7));

  //testing capacity function
  cout << "\nTesting the capacity funtion. I expect the capacity to be 14";
  cout << "\n\tActual result: " << myArray.capacity() << endl;
  assert(14 == myArray.capacity());

  //testing the overloaded operators
  myArray[7] = 12.3;
  cout << "\nTesting the overloaded operators. Expected result: 12.3";
  cout << "\n\tActual result: " << myArray[7] << endl;
  assert(12.3 == myArray[7]);

  //testing keys function
  myArray[2] = 8.2;
  cout << "\nTesting the keys function. Expected result: 2 7";
  cout << "\n\tActual result: ";
  values = myArray.keys();
  for (int temp : values)
  {
    cout << temp << " ";
  }
  cout << endl;
  assert(7 == values.at(1));

  //testing size function
  cout << "\nTesting size and [] function. I expect the size to be 2";
  cout << "\n\tActual result: " << myArray.size() << endl;
  assert(2 == myArray.size());

  //testing the contains key function
  cout << "\nTesting containsKey function. Expected result of containsKey(2): true";
  cout << "\n\tActual result: ";
  myArray.containsKey(2) ? cout << "true" << endl : cout << "false" << endl;
  assert(true == myArray.containsKey(2));

  //testing the delete key function
  myArray.deleteKey(2);
  cout << "\nTesting deleteKey function. Expected result of containsKey(2): false";
  cout << "\n\tActual result: ";
  myArray.containsKey(2) ? cout << "true" << endl : cout << "false" << endl;
  assert(false == myArray.containsKey(2));

  //testing the clear function
  myArray.clear();
  cout << "\nTesting clear function. Expected restult of containsKey(7): false";
  cout << "\n\tActual result: ";
  myArray.containsKey(7) ? cout << "true" << endl : cout << "false" << endl;
  assert(false == myArray.containsKey(7));
  cout << "I expect the size to go back to 0";
  cout << "\n\tActual result: " << myArray.size() << endl << endl;
  assert(0 == myArray.size());
  }

  myArray[1] = 2.3;
  myArray[4] = 4.5;
  myArray[9] = 7.2;

  // object copy testing
  {
    const StaticArray<double, SIZE> copy = myArray;
    /*for (int c = 0; c < SIZE; c++)
    {
      copy[c] = myArray[c];
    }*/
    cout << "\nObject Copy Testing. I expect the elements 1, 4 and 9 to be: 2.3, 4.5, 7.2";
    cout << "\n\tActual results: " << copy[1] << " " << copy[4] << " " << copy[9] << endl;
    assert(4.5 == copy[4]);
    cout << "\nI expect the size to be 3";
    cout << "\n\tActual result: " << copy.size();
    assert(3 == copy.size());
    cout << "\nI expect the capacity to be 14";
    cout << "\n\tActual result: " << copy.capacity();
    assert(14 == copy.capacity());
    cout << "\nI expect copy[14] to be 0";
    cout << "\n\tActual result: " << copy[14] << endl;
    assert(0 == copy[14]);
  }

  // object assignment testing
  {
    StaticArray<double, SIZE> copy; copy = myArray;
    cout << "\nObject Assignment Testing. I expect the elements 1, 4 and 9 to be: 2.3, 4.5 and 7.2";
    cout << "\n\tActual results: " << copy[1] << " " << copy[4] << " " << copy[9];
    assert(4.5 == copy[4]);
    cout << "\nI expect the size to be 3";
    cout << "\n\tActual result: " << copy.size();
    assert(3 == copy.size());
    cout << "\nI expect the capacity to be 14";
    cout << "\n\tActual result: " << copy.capacity();
    assert(14 == copy.capacity());
    cout << "\nI expect copy[14] to be 0";
    cout << "\n\tActual result: " << copy[14] << endl;
    assert(0 == copy[14]);
  }

  cout << "\n\nPress ENTER to continue...";
  cin.get();
}