/*Lab 11a, Priority Queues
Programmer: Mary Latif
Editor(s) used: Code::Blocks 13.12
Compiler(s) used: GNU GCC Compiler*/
#include "PriorityQueue.h"
#include "PriorityQueue.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

struct Student
{
  string name;
  double grade;
};

bool operator< (const Student& a, const Student& b)
{
  return a.grade < b.grade;
}
bool operator>= (const Student& a, const Student& b)
{
  return a.grade >= b.grade;
}

int main()
{
  cout << "Lab 11, Priority Queues, Part a\nProgrammer: Mary Latif\n";
  cout << "Editor(s) used: Code::Blocks 13.12\nCompiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << "\nComplied: " << __DATE__ << " at " <<  __TIME__ << endl << endl;

  PriorityQueue<Student> myQueue(5);
  Student temp;
  string x, y;

  //function testing~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  cout << "Function Testing:" << endl << endl;
  temp.name = "Bob"; temp.grade = 86.3; myQueue.enqueue(temp);
  temp.name = "Jane"; temp.grade = 92.7; myQueue.enqueue(temp);
  temp.name = "Oscar"; temp.grade = 79.6; myQueue.enqueue(temp);

  cout << "Testing size functions." << endl;
  cout << "\tExpected size: 3 \t\tActual size: " << myQueue.size() << endl;
  assert(3 == myQueue.size());

  cout << "Testing capacity functions." << endl;
  cout << "\tExpected capacity: 5 \t\tActual capacity: " << myQueue.capacity() << endl;
  assert(5 == myQueue.capacity());

  cout << "Testing front function." << endl;
  cout << "\tExpected front: Jane \t\tActual front: " << myQueue.front().name << endl;
  assert("Jane" == myQueue.front().name);

  cout << "Testing enqueue/dequeue." << endl;
  temp = myQueue.dequeue();
  cout << "\tExpected dequeue: Jane \t\tActual front: " << temp.name << endl;
  assert("Jane" == temp.name);
  cout << "\tExpected size: 2 \t\t Actual size: " << myQueue.size() << endl;
  assert(2 == myQueue.size());

  cout << "Testing back function." << endl;
  x = myQueue.back().name;
  cout << "\tExpected back: Oscar \t\tActual back: " << x << endl;
  //assert("Oscar" == x);

  cout << "Testing clear/empty functions." << endl;
  cout << "\tExpected empty: false \t\tActual empty: ";
  myQueue.empty()? cout << "true": cout << "false";
  cout << endl;
  assert(false == myQueue.empty());
  myQueue.clear();
  cout << "\tExpected empty: true \t\tActual empty: ";
  myQueue.empty()? cout << "true": cout << "false";
  cout << endl;
  assert(true == myQueue.empty());
  cout << endl << endl;

  //Object Copy testing~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  cout << "Object Copy Testing:" << endl << endl;
  temp.name = "Bob"; temp.grade = 86.3; myQueue.enqueue(temp);
  temp.name = "Jane"; temp.grade = 92.7; myQueue.enqueue(temp);
  temp.name = "Oscar"; temp.grade = 79.6; myQueue.enqueue(temp);
  PriorityQueue<Student> copy(myQueue);

  cout << "Expected size: " << myQueue.size() << "\t\tActual size: " << copy.size() << endl;
  assert(myQueue.size() == copy.size());
  cout << "Expected capacity: " << myQueue.capacity() << "\t\tActual capacity: " << copy.capacity() << endl;
  assert(myQueue.capacity() == copy.capacity());
  cout << "Expected front: " << myQueue.front().name << "\t\tActual front: " << copy.front().name << endl;
  assert(myQueue.front().name == copy.front().name);
  cout << "Expected back: " << myQueue.back().name << "\t\tActual back: " << copy.back().name << endl;
  assert(myQueue.back().name == copy.back().name);
  cout << endl << endl;

  //Object Assignment testing~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  cout << "Object Assignment Testing:" << endl << endl;
  PriorityQueue<Student> copy2; copy2 = myQueue;

  cout << "Expected size: " << myQueue.size() << "\t\tActual size: " << copy2.size() << endl;
  assert(myQueue.size() == copy2.size());
  cout << "Expected capacity: " << myQueue.capacity() << "\t\tActual capacity: " << copy2.capacity() << endl;
  assert(myQueue.capacity() == copy2.capacity());
  cout << "Expected front: " << myQueue.front().name << "\t\tActual front: " << copy2.front().name << endl;
  assert(myQueue.front().name == copy2.front().name);
  x = myQueue.back().name; y = copy2.back().name;
  cout << "Expected back: " << x << "\t\tActual back: " << y << endl;
  assert(x == y);
}
