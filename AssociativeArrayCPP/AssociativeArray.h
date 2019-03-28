/*Lab 9a, Associative Array Program
Programmer: Mary Latif
Editor(s) used: Code::Blocks 13.12
Compiler(s) used: GNU GCC Compiler*/
#ifndef AssociativeArray_h
#define AssociativeArray_h
#include <vector>
using namespace std;

template <class T, class U>
class AssociativeArray
{
public:
  AssociativeArray(int c = INIT_CAP);         //constructor
  AssociativeArray(const AssociativeArray<T,U>&);  //copy constructor
  ~AssociativeArray();                        //destructor
  //getters
  int capacity()      const {return cap;}
  int size()          const {return siz;}
  bool containsKey(U) const;
  T operator[](U)     const;
  //setters
  void clear();
  void deleteKey(U);
  T& operator[](U);
  AssociativeArray<T,U>& operator=(const AssociativeArray<T,U>&);
  vector<U>keys();

private:
  static const int INIT_CAP = 0;
  struct Node
  {
    T value;
    U key;
    bool inUse;
    Node* next;
  };
  Node *start, *end;
  int cap, siz;
  T dummy;
};

//constructor
template <class T, class U>
AssociativeArray<T,U>::AssociativeArray(int c)
{
  //initialize variables
  cap   = c, siz = 0;
  start = 0, end = 0;
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

//copy constructor
template <class T, class U>
AssociativeArray<T,U>::AssociativeArray(const AssociativeArray<T,U>& a)
{
  //copy data members
  start = 0;
  end = 0;
  siz = a.siz;
  cap = a.cap;
  for (Node* p = a.start; p; p = p->next)
  {
    Node* node  = new Node;
    node->value = p->value;
    node->key   = p->key;
    node->inUse = p->inUse;
    node->next  = 0;
    if (end) end->next = node;
    else start  = node;
    end = node;
  }
}

//destructor
template <class T, class U>
AssociativeArray<T,U>::~AssociativeArray()
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

//getters
template <class T, class U>
bool AssociativeArray<T,U>::containsKey(U index) const
{
  //traverse to index node
  bool check = false;
  int i = 0;
  Node* p = start;
  for ( ; p; p = p->next, i++)
  {
    if (p->key == index){ check = true; break; }
  }

  //p now points to the correct node
  if (p && check) return (p->inUse);
  return (false);
}

template <class T, class U>
vector<U> AssociativeArray<T,U>::keys()
{
  vector<U> result;
  const Node*p = start;
  int i = 0;
  for ( ; p; p = p->next, i++)
  {
      if (p->inUse == true) {result.push_back(p->key);}
  }
  return (result);
}

template <class T, class U>
T AssociativeArray<T,U>::operator[](U index) const
{
  const Node*p = start;
  int i = 0;
  for ( ; p; p = p->next, i++)
  {
      if (p->inUse == true && p->key == index) {return p->value;}
  }
  return (dummy);
}

//setters
template <class T, class U>
void AssociativeArray<T,U>::clear()
{
  for (Node* p = start; p; p = p->next)
  {
    p->inUse = false;
  }

  siz = 0;
}

template <class T, class U>
void AssociativeArray<T,U>::deleteKey(U index)
{
  //traverse to index node
  int i = 0;
  Node* p = start;
  for ( ; p; p = p->next, i++)
  {
    if (p->key == index && p->inUse == true){p->inUse = false; --siz;}
  }
}

template <class T, class U>
T& AssociativeArray<T,U>::operator[](U index)
{
  int i = 0;
  Node* p = start;
  for ( ; p; p = p->next, i++)
  {
    if (p->inUse == true && p->key == index) return p->value;
  }

  for (i = 0, p = start; p; p = p->next, i++)
  {
    if (p->inUse == false)
    {
      p->key = index;
      p->inUse = true;
      siz++;
      return p->value;
    }
  }

  Node* node = new Node;
  node->inUse = true;
  node->key = index;
  node->next = 0;
  if (end) end->next = node;
  else start = node;
  end = node;
  cap++; siz++;
  return (end->value);
}

template <class T, class U>
AssociativeArray<T,U>& AssociativeArray<T,U>::operator=(const AssociativeArray<T,U>& a)
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

  //assignment
  start = 0;
  end = 0;
  siz = a.siz;
  cap = a.cap;
  for (Node* p = a.start; p; p = p->next)
  {
    Node* node  = new Node;
    node->value = p->value;
    node->inUse = p->inUse;
    node->key   = p->key;
    node->next  = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
  }

  return (*this);
}

#endif // AssociativeArray_h

