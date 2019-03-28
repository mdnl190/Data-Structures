/*Lab 6a, Linked List Program
Programmer: Mary Latif
Editor(s) used: Code::Blocks 13.12
Compiler(s) used: GNU GCC Compiler*/
#include "LinkedArray.h"
#include "LinkedArray.h"
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int main()
{
  LinkedArray <double> myArray;
  LinkedArray <int> yoArray(20);
  vector<int> values;

  //header
  cout << "Lab 6a, Linked Array Program \nProgrammer: Mary Latif" << endl;
  cout << "Editor(s) used: Code::Blocks 13.12\nCompiler(s) used: GNU GCC Compiler\n" << endl;

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
    cout << "\nTesting the capacity function. I expect the capacity to be 0";
    cout << "\n\tActual result: " << myArray.capacity() << endl;
    assert(0 == myArray.capacity());
    cout << "\nTesting the capacity function pt 2. I expect the capacity to be 20";
    cout << "\n\tActual result: " << yoArray.capacity() << endl;
    assert(20 == yoArray.capacity());

    //testing the overloaded operators
    myArray[11] = 12.3;
    cout << "\nTesting the overloaded operators. Expected result: 12.3";
    cout << "\n\tActual result: " << myArray[11] << endl;
    assert(12.3 == myArray[11]);
    cout << "\n\tI expect the capacity to be 12";
    cout << "\n\tActual result: " << myArray.capacity() << endl;
    assert(12 == myArray.capacity());

    //testing keys function
    myArray[2] = 8.2;
    cout << "\nTesting the keys function. Expected result: 2 11";
    cout << "\n\tActual result: ";
    values = myArray.keys();
    for (int temp : values)
    {
      cout << temp << " ";
    }
    cout << endl;
    assert(11 == values.at(1));

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
    cout << "\nTesting clear function. Expected result of containsKey(7): false";
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
    LinkedArray<double> copy(myArray);
    cout << "\nObject Copy Testing. I expect the elements 1, 4 and 9 to be: 2.3, 4.5, 7.2";
    cout << "\n\tActual results: " << copy[1] << " " << copy[4] << " " << copy[9] << endl;
    assert(4.5 == copy[4]);
    cout << "\nI expect the size to be 3";
    cout << "\n\tActual result: " << copy.size();
    assert(3 == copy.size());
    cout << "\nI expect the capacity to be 12";
    cout << "\n\tActual result: " << copy.capacity() << endl;
    assert(12 == copy.capacity());
  }

  // object assignment testing
  {
    LinkedArray<double> copy; copy = myArray;
    cout << "\nObject Assignment Testing. I expect the elements 1, 4 and 9 to be: 2.3, 4.5 and 7.2";
    cout << "\n\tActual results: " << copy[1] << " " << copy[4] << " " << copy[9];
    assert(4.5 == copy[4]);
    cout << "\nI expect the size to be 3";
    cout << "\n\tActual result: " << copy.size();
    assert(3 == copy.size());
    cout << "\nI expect the capacity to be 12";
    cout << "\n\tActual result: " << copy.capacity();
    assert(12 == copy.capacity());
  }

  cout << "\n\nPress ENTER to continue...";
  cin.get();
}
