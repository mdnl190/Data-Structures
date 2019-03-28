/*Lab 4b, Dynamic Array Program
Programmer: Mary Latif
Editor(s) used: Visual C++
Compiler(s) used: Visual Studio 2013*/

#ifndef DynamicArray_h
#define DynamicArray_h
#include <vector>
using namespace std;

template <class T>
class DynamicArray
{
public:
  DynamicArray(int c = INIT_CAP);       //constructor
  ~DynamicArray();                      //destructor
  DynamicArray(const DynamicArray<T>&); //copy constructor

  //getters
  int capacity()        const { return (cap); }
  int size()            const { return (siz); }
  T operator[](int)     const;
  bool containsKey(int) const;
  vector<int> keys()    const;
  //setters
  T& operator[](int);
  void deleteKey(int);
  void clear();
  DynamicArray<T>& operator=(const DynamicArray<T>&);

private:
  static const int INIT_CAP = 10;
  T* data;
  bool* inUse;
  T dummy;
  int cap;
  int siz;
};

//constructor
template <class T>
DynamicArray<T>::DynamicArray(int c)
{
  cap = c, dummy = 0, siz = 0;;
  data = new T [cap];
  inUse = new bool [cap];
  for (int c = 0; c < cap; c++)
  {
    inUse[c] = false;
  }
}

//destructor
template <class T>
DynamicArray<T>::~DynamicArray()
{
  delete[] data;
  delete[] inUse;
}

//copy constructor
template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& a)
{
  cap = a.cap;
  siz = a.siz;
  data = new T [cap];
  inUse = new bool [cap];
  for (int c = 0; c < cap; c++)
  {
    data[c] = a.data[c];
    inUse[c] = a.inUse[c];
  }
}

//getters
template <class T>
T DynamicArray<T>::operator[] (int index) const
{
  T result;
  if (index < 0 || index >= cap) result = dummy;
  else result = data[index];
  return (result);
}

template <class T>
bool DynamicArray<T>::containsKey(int index) const
{
  bool result = false;
  if (inUse[index] == true) result = true;
  return (result);
}

template <class T>
vector<int> DynamicArray<T>::keys() const
{
  vector<int> result;
  for (int c = 0; c < cap; c++)
  {
    if (inUse[c] == true) result.push_back(c);
  }
  return (result);
}

//setters
template <class T>
T& DynamicArray<T>::operator[](int index)
{
  if (index < 0) return (dummy);
  else
  {
    if (index >= cap)
    {
      //make larger data array
      T* tempValues = new T[index + 1]; 

      for (int c = 0; c < cap; c++)
      {
        //copy current values in new, larger array
        tempValues[c] = data[c]; 
      }
      //delete old array that is too small
      delete[] data; 
      //replace array with a pointer to the new array
      data = tempValues; 

      //make larger bool array
      bool* tempInUse = new bool[index + 1]; 
      for (int c = 0; c < cap; c++)
      {
        //copy old inUse bool values into new, larger array
        tempInUse[c] = inUse[c]; 
      }

      for (int c = cap; c <= index; c++)
      {
        //initialize new additional elements to false
        tempInUse[c] = false; 
      }

      //delete old inUse array
      delete[] inUse; 
      //replace array with a pointer to the larger array
      inUse = tempInUse;

      //change the capacity variable to be larger
      cap = index + 1;
    }

    //if previously untouches, increase size and make inUse true
    if (inUse[index] == false)
    {
      siz++;
      inUse[index] = true;
    }

    return (data[index]);
  }
}

template <class T>
void DynamicArray<T>::deleteKey(int index)
{
  if (index >= 0 && index < cap)
  {
    inUse[index] = false;
  }
}

template <class T>
void DynamicArray<T>::clear()
{
  for (int c = 0; c < cap; c++)
  {
    inUse[c] = false;
  }
  siz = 0, dummy = 0;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& a)
{
  if (this == &a) return (*this);
  else
  {
    //delete first object
    delete[] data;
    delete[] inUse;

    //copy contents of the other object into the first one
    cap = a.cap;
    siz = a.siz;
    data = new T[cap];
    inUse = new bool[cap];
    for (int c = 0; c < cap; c++)
    {
      data[c] = a.data[c];
      inUse[c] = a.inUse[c];
    }

    return (*this);
  }
}

#endif
