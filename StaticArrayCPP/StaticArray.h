/*Lab 3a, Static Array Program
Programmer: Mary Latif
Editor(s) used: Visual C++
Compiler(s) used: Visual Studio 2013*/

#ifndef StaticArray_h
#define  StaticArray_h
#include <vector>
using namespace std;

template <class T, int CAPACITY>
class StaticArray
{ 
public:
    //constructor
  StaticArray();
    //getters
  int capacity()        const { return (CAPACITY); }  
  int size()            const { return (siz); }
  T operator[](int)     const;    
  bool containsKey(int) const;
  vector<int> keys()    const;
   //setters
  T& operator[](int);          
  void deleteKey(int);
  void clear();
  
private:
  T data[CAPACITY];
  bool inUse[CAPACITY];
  T dummy;
  int siz;
};

//constructer
template <class T, int CAPACITY>
StaticArray <T, CAPACITY>::StaticArray()
{
  for (int c = 0; c < CAPACITY; c++)
  {
    inUse[c] = false;
  }
  
  dummy = 0, siz = 0;
}

//overloaded operators
template <class T, int CAPACITY>
T StaticArray <T, CAPACITY>::operator[](int index) const
{
  T result = dummy;

  if (index >= 0 && index < CAPACITY) result = data[index];

  return (result);
}

template <class T, int CAPACITY>
T& StaticArray <T, CAPACITY>::operator[] (int index)
{
  if (index >= 0 && index < CAPACITY)
  {
    if (false == inUse[index]) siz++;
    inUse[index] = true;
    return (data[index]);
  }
  else return (dummy);
}

//checks if the element of the array is in use
template <class T, int CAPACITY>
bool StaticArray <T, CAPACITY>::containsKey(int index) const
{
  bool result;

  if (index < 0 || index >= CAPACITY) result = false;
  else result = inUse[index];

  return (result);
}

//resets the inUse to false of whatever element chosen
template <class T, int CAPACITY>
void StaticArray <T, CAPACITY>::deleteKey(int index)
{
  if (index >= 0 && index < CAPACITY) inUse[index] = false;
}

//turns all inUse back to false and resets siz
template <class T, int CAPACITY>
void StaticArray <T, CAPACITY>::clear()
{
  for (int c = 0; c < CAPACITY; c++)
  {
    inUse[c] = false;
    siz = 0;
  }
}

//returns a vector with all used elements locations
template <class T, int CAPACITY>
vector<int> StaticArray<T, CAPACITY>::keys() const
{
  vector<int> result;

  for (int c = 0; c < CAPACITY; c++)
  {
    if (inUse[c]) result.push_back(c);
  }

  return (result);
}
#endif