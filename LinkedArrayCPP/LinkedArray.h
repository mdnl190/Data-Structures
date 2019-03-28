/*Lab 6a, Linked List Program
Programmer: Mary Latif
Editor(s) used: Code::Blocks 13.12
Compiler(s) used: GNU GCC Compiler*/
#ifndef LINKEDARRAY_H_INCLUDED
#define LINKEDARRAY_H_INCLUDED
#include <vector>
using namespace std;

const int INIT_SIZE = 0;

template <class T>
class LinkedArray
{
public:
  LinkedArray(int c = INIT_SIZE);     //constructor
  ~LinkedArray();                     //destructor
  LinkedArray(const LinkedArray<T>&); //copy constructor

  //setters
  T& operator[] (int);
  LinkedArray<T>& operator= (const LinkedArray<T>&);
  bool deleteKey (int);
  void clear ();
  vector<int> keys();

  //getters
  int size()            const { return (siz); }
  int capacity()        const { return (cap); }
  T operator[](int)     const;
  bool containsKey(int) const;

private:
  struct Node
  {
    T value;
    bool inUse;
    Node* next;
  };
  //data members
  Node *start, *end, *lastP;
  int lastIndex;
  int cap;
  int siz;
  T dummy;
};

//constructor
template <class T>
LinkedArray<T>::LinkedArray(int c)
{
  siz = 0, cap = c, lastIndex = -1;
  start = 0, end = 0, lastP = 0;

  for (int i = 0; i < c; i++)
  {
      //add a node
      Node* node = new Node;
      node->inUse = false;
      node->next = 0;
      if (end) end->next = node;
      else start = node;
      end = node;
  }
}

//destructor
template <class T>
LinkedArray<T>::~LinkedArray()
{
  if (siz != 0)
  {
    Node* p;
    while (start)
    {
      p = start->next;
      delete start;
      start = p;
    }
    end = 0;
  }
}

//copy constructor
template <class T>
LinkedArray<T>::LinkedArray(const LinkedArray<T>& a)
{
  start = 0;
  end = 0;
  siz = a.siz;
  cap = a.cap;
  for (Node* p = a.start; p; p = p->next)
  {
    Node* node = new Node;
    node->value = p->value;
    node->inUse = p->inUse;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
  }
}

//setters
template <class T>
T& LinkedArray<T>::operator[](int index)
{
  if (index < 0) {return (dummy);}
  else if (index >= cap)
  {
    //add n nodes
    int n = index - cap + 1;
    while (n != 0)
    {
      Node* node = new Node;
      node->inUse = false;
      node->next = 0;
      if (end) end->next = node;
      else start = node;
      end = node;
      cap++;
      n--;
    }
  }

  //get value at index
    Node*p = start;
    int i = 0;

  //If the last index is before the index, then start at the last index
    if(lastIndex >= 0 && lastIndex <= index)
    {
        i = lastIndex;
        p = lastP;
    }

  //traverse through linked array until p is the node at the index
    for ( ; p; p = p->next, i++)
    {
      if(i == index) { break; }
    }
  //make the lastIndex the index we accessed and lastP the current node
    lastIndex = index;
    lastP = (Node*)p;
  //if this node was untouched before, make inUse true and add one to the size
    if (p->inUse == false)
      {
        p->inUse = true;
        siz++;
      }
    return ( p->value );
}

template <class T>
LinkedArray<T>& LinkedArray<T>::operator= (const LinkedArray<T>& a)
{
  if (this == &a) { return (*this); }

  // deallocate all nodes
  if (siz != 0)
  {
    Node* p;
    while (start)
    {
      p = start->next;
      delete start;
      start = p;
    }
    end = 0;
  }

  // build new linked array
  start = 0;
  end = 0;
  siz = a.siz;
  cap = a.cap;
  for (Node* p = a.start; p; p = p->next)
  {
    Node* node = new Node;
    node->value = p->value;
    node->inUse = p->inUse;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
  }

  return (*this);
}

template <class T>
bool LinkedArray<T>::deleteKey(int index)
{
  if (index < 0 || index >= cap) {return (false);}
  else
  {
    //traverse to index node
    int i = 0;
    Node* p = start;
    for ( ; p; p = p->next, i++)
    {
      if (i == index) { break; }
    }

    //p now points to the correct node
    if (p)
      if (p->inUse) {--siz;}
    p->inUse = false;
  }

  return (true);
}

template <class T>
void LinkedArray<T>::clear()
{
  for (Node* p = start; p; p = p->next)
  {
    p->inUse = false;
  }

  siz = 0;
  lastIndex = -1;
  lastP = 0;
}

template <class T>
vector<int> LinkedArray<T>::keys()
{
  vector<int> result;
  const Node*p = start;
  int i = 0;
  for ( ; p; p = p->next, i++)
  {
      if (p->inUse == true) {result.push_back(i);}
  }
  return (result);
}

//getters
template <class T>
T LinkedArray<T>::operator[](int index) const
{
  if (index < 0 || index >= cap) { return (dummy); }

  //index is valid, return value at index
    const Node*p = start;
    int i = 0;

  //If the last index is before the index, then start at the last index
    if(lastIndex >= 0 && lastIndex <= index)
    {
        i = lastIndex;
        p = lastP;
    }
  //traverse through linked array until p is the node at the index
    for ( ; p; p = p->next, i++)
    {
      if(i == index) { break; }
    }
  //make the lastIndex the index we accessed and lastP the current node
    lastIndex = index;
    lastP = (Node*)p;

    return ( p->data );
}

template <class T>
bool LinkedArray<T>::containsKey(int index) const
{
  if (index < 0 || index >= cap) { return (false); }

  //traverse to index node
  int i = 0;
  Node* p = start;
  for ( ; p; p = p->next, i++)
  {
    if (i == index){ break; }
  }

  //p now points to the correct node
  if (p) { return (p->inUse); }
  else { return (false); }
}


#endif // LINKEDARRAY_H_INCLUDED
