//#include "Queue.h"
#include "queue.h"
#include <iostream>
#include <cassert>
using namespace std;

int main ()
{
  Queue<int> myQueue;

  //function testing
  {
    //constructor/size test
    cout << "Testing the constructor & size getter. I expect the size to be 0." << endl;
    cout << "\tActual size: " << myQueue.size() << endl << endl;
    assert(0 == myQueue.size());

    //push/peek test
    myQueue.push(4);
    cout << "Testing push & peek. I expect to have pushed 4 on the Queue." << endl;
    cout << "\tActual value: " << myQueue.peek() << endl << endl;
    assert (4 == myQueue.peek());

    //empty test
    cout << "Testing empty function. I expect the result to be false." << endl;
    cout << "\t Actual value: ";
    myQueue.empty()? cout << "true": cout << "false";
    cout << endl << endl;
    assert(false == myQueue.empty());

    //push/pop/peek/size test
    myQueue.push(7);
    myQueue.push(15); //queue should = 4, 7, 15
    myQueue.pop(); //queue should = 7, 15 and siz should be 2
    cout << "Testing pop. After popping, I expect the first value to be 7 and size to be 2." << endl;
    cout << "\tActual value: " << myQueue.peek() << ", size: " << myQueue.size() << endl << endl;
    assert(7 == myQueue.peek() && 2 == myQueue.size());

    //clear test
    myQueue.clear();
    cout << "Testing clear function. I expect the size to be 0 and empty() to be true." << endl;
    cout << "\tActual size: " << myQueue.size() << ", empty: ";
    myQueue.empty()? cout << "true": cout << "false";
    cout << endl << endl;
    assert (0 == myQueue.size() && true == myQueue.empty());
  }

  Queue<float> yoQueue;
  yoQueue.push(2.3);
  yoQueue.push(4.5);
  yoQueue.push(7.2);

  // object copy testing
  {
    Queue<float> copy(yoQueue);
    cout << "\nObject Copy Testing. I expect the first element to be 2.3" << endl;
    cout << "\tActual value: " << copy.peek() << endl;
    assert(2.0 < copy.peek() && 2.5 > copy.peek());
    cout << "I expect the size to be 3";
    cout << "\tActual result: " << copy.size() << endl << endl;
    assert(3 == copy.size());
  }

  // object assignment testing
  {
    Queue<float> copy; copy = yoQueue;
    cout << "Object Assignment Testing. I expect the top element to be 2.3" << endl;
    cout << "\tActual value: " << copy.peek() << endl;
    assert(2.0 < copy.peek() && 2.5 > copy.peek());
    cout << "I expect the size to be 3";
    cout << "\tActual result: " << copy.size() << endl << endl;
    assert(3 == copy.size());
  }

  cout << "\n\nPress ENTER to continue...";
  cin.get();
}
