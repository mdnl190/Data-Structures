/*Lab 11a, Priority Queues
Programmer: Mary Latif
Editor(s) used: Code::Blocks 13.12
Compiler(s) used: GNU GCC Compiler*/
#ifndef PriorityQueue_h
#define PriorityQueue_h
#include <algorithm>
using namespace std;

template <class T>
class PriorityQueue
{
public:
  PriorityQueue(int = 2);                 //constructor
  PriorityQueue(const PriorityQueue<T>&); //copy constructor
  ~PriorityQueue();                       //destructor

  //setters
    void enqueue(const T&);
    T& front() {return data[0];}
    T& back() {return data[siz - 1];}
    T dequeue();
    void clear();
    PriorityQueue<T>& operator=(const PriorityQueue<T>&);
  //getters
    int size()      const {return siz;}
    int capacity()  const {return cap;}
    bool empty()    const {return 0 == siz;}
private:
  void changeCap(int);
  T* data;
  int siz; int cap;
};

//constructor
template <class T>
PriorityQueue<T>::PriorityQueue(int x)
{
  cap = x; siz = 0;
  if(cap <= 0) data = 0;
  else data = new T[cap];
}

//copy constructor
template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& a)
{
  cap = a.capacity();
  siz = a.size();
  data = 0;
  if (cap > 0)
  {
    data = new T[cap];
    for (int i = 0; i < cap; i++) data[i] = a.data[i];
  }
}

//destructor
template <class T>
PriorityQueue<T>::~PriorityQueue()
{
  delete [] data;
  siz = 0;
}

//setters
template <class T>
void PriorityQueue<T>::enqueue(const T& x)
{
  int index = siz; //set index = size
  if (index >= cap) changeCap(cap*2); //if index >= capacity, double the capacity
  data[index] = x; //copy new value into array at index

  while(true) //start loop
  {
    int parentIndex = (index + 1)/2 - 1; //parentIndex = (index+1)/2 - 1
    if(parentIndex < 0) break; //if parentIndex < 0, exit loop
    if(data[parentIndex] >= data[index]) break; //if value at parentIndex >= value at index, exit loop
    swap(data[parentIndex], data[index]); //swap values at parentIndex and index
    index = parentIndex; //set index = parentIndex
  } //repeat to top of loop
  siz++; //increment size
}

template <class T>
T PriorityQueue<T>::dequeue()
{
  int left = 0, right = 0, i = 0, parentIndex = 0; //set index to zero
  T value = data[0]; //save value at index 0 to return at end

  while (true) //start loop
  {
    left = 2*i + 1; //index of left child = 2*index+1
    right = 2*i + 2; //index of right child = 2*index+2
    if (left >= siz) break; //if left child index >= size, exit loop
    if (left == siz - 1 || data[left] >= data[right]) //if left child index = size-1 OR value of left child >= value of right child
    {
      data[i] = data[left]; //set value at index to value of left child
      i = left; //set index = index of left child
    }
    else
    {
      data[i] = data[right]; //set value at index to value of right child
      i = right; //set index = index of right child
    }
  } //end loop

  siz--; //decrement size
  if (siz < cap/4) changeCap(cap/2); //if size < capacity/4, halve the capacity
  data[i] = data[siz]; //copy value at size into array at index

  while (true) //start loop
  {
    parentIndex = (i + 1)/2 - 1; //parentIndex = (index+1)/2 - 1
    if(parentIndex < 0) break; //if parentIndex < 0, exit loop
    if(data[parentIndex] >= data[i]) break; //if value at parentIndex >= value at index, exit loop
    swap (data[parentIndex], data[i]); //swap values at parentIndex and index
    i = parentIndex; //set index = parentIndex
  } //repeat to top of loop

  return value; //return saved value
}

template <class T>
void PriorityQueue<T>::clear()
{
  delete [] data;
  siz = 0; cap = 2;
  data = new T[cap];
}

template <class T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& a)
{
  if (this != &a)
  {
    delete [] data;
    data = 0;
    cap = a.capacity();
    data = new T[cap];
    for (int i = 0; i < cap; i++) data[i] = a.data[i];
    siz = a.size();
  }

  return *this;
}

//private
template <class T>
void PriorityQueue<T>::changeCap(int newCap)
{
  int x;
  T* newData = new T[newCap];
  newCap > cap? x = cap: x = newCap;

  for (int i = 0; i < x; i++) newData[i] = data[i];

  delete [] data;
  data = newData;
  cap = newCap;
}

#endif // PriorityQueue_h
