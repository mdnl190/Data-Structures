//#include "Stack.h"
#include "stack.h"
#include <iostream>
#include <cassert>
using namespace std;

int main ()
{
  Stack<int> myStack;

  //function testing
  {
    //constructor/size test
    cout << "Testing the constructor & size getter. I expect the size to be 0." << endl;
    cout << "\tActual size: " << myStack.size() << endl << endl;
    assert(0 == myStack.size());

    //push/peek test
    myStack.push(4);
    cout << "Testing push & peek. I expect to have pushed 4 on top of the stack." << endl;
    cout << "\tActual value: " << myStack.peek() << endl << endl;
    assert (4 == myStack.peek());

    //empty test
    cout << "Testing empty function. I expect the result to be false." << endl;
    cout << "\t Actual value: ";
    myStack.empty()? cout << "true": cout << "false";
    cout << endl << endl;
    assert(false == myStack.empty());

    //push/pop/peek/size test
    myStack.push(7);
    myStack.push(15); //stack should = 4, 7, 15
    myStack.pop(); //stack should = 4,7 and siz should be 2
    cout << "Testing pop. After popping, I expect the top value to be 7 and size to be 2." << endl;
    cout << "\tActual value: " << myStack.peek() << ", size: " << myStack.size() << endl << endl;
    assert(7 == myStack.peek() && 2 == myStack.size());

    //clear test
    myStack.clear();
    cout << "Testing clear function. I expect the size to be 0 and empty() to be true." << endl;
    cout << "\tActual size: " << myStack.size() << ", empty: ";
    myStack.empty()? cout << "true": cout << "false";
    cout << endl << endl;
    assert (0 == myStack.size() && true == myStack.empty());
  }

  Stack<float> yoStack;
  yoStack.push(2.3);
  yoStack.push(4.5);
  yoStack.push(7.2);

  // object copy testing
  {
    Stack<float> copy(yoStack);
    cout << "\nObject Copy Testing. I expect the top element to be 7.2" << endl;
    cout << "\tActual value: " << copy.peek() << endl;
    assert(7.0 < copy.peek() && 7.5 > copy.peek());
    cout << "I expect the size to be 3";
    cout << "\tActual result: " << copy.size() << endl << endl;
    assert(3 == copy.size());
  }

  // object assignment testing
  {
    Stack<float> copy; copy = yoStack;
    cout << "Object Assignment Testing. I expect the top element to be 7.2" << endl;
    cout << "\tActual value: " << copy.peek() << endl;
    assert(7.0 < copy.peek() && 7.5 > copy.peek());
    cout << "I expect the size to be 3";
    cout << "\tActual result: " << copy.size() << endl << endl;
    assert(3 == copy.size());
  }

  cout << "\n\nPress ENTER to continue...";
  cin.get();
}
