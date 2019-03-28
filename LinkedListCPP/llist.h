#ifndef LLIST_H_INCLUDED
#define LLIST_H_INCLUDED
#include <vector>
using namespace std;

template <class T>
class LinkedList
{
public:
  LinkedList();                     //constructor
  ~LinkedList();                    //destructor
  LinkedList(const LinkedList<T>&); //copy constructor

  //setters
  void pop_back();
  void pop_front();
  void push_back(T);
  void push_front(T);
  void reverse();
  void erase (int);
  void erase (int, int);
  void insert(int, T);
  void merge(LinkedList);

  //getters
  T& back()    const;
  T& front()   const;
  bool empty() const { return (siz == 0); }
  int size()   const { return (siz); }

private:
  struct Node
  {
    T value;
    Node* next;
  };
  //data members
  Node *start, *end;
  int siz;
  T dummy;
};

//constructor
template <class T>
LinkedList<T>::LinkedList()
{
  siz = 0;
  start = NULL, end = NULL;
}

//destructor
template <class T>
LinkedList<T>::~LinkedList()
{
  if (siz != 0)
  {
    Node* p = new Node;
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
LinkedList<T>::LinkedList(const LinkedList<T>& a)
{
  start = 0;
  end = 0;
  siz = a.siz;
  for (Node* p = a.start; p; p = p->next)
  {
    Node* node = new Node;
    node->value = p->value;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
  }
}

//setters
template<class T>
void LinkedList<T>::pop_back()
{
  if(start != NULL)
  {
    Node *end = start;
    while(end->next != NULL) end = end->next;
    delete end;
  }
  siz--;
}

template<class T>
void LinkedList<T>::pop_front()
{
  if (start != NULL)
  {
    Node *temp = start;
    start = start->next;
    delete temp;
    siz--;
   }
}

template<class T>
void LinkedList<T>::push_back(T x)
{
  Node *temp = new Node; Node* p = new Node;
  temp->value = x; temp->next = NULL;
  p = start;
  while (p->next != NULL)
    p = p->next;

  temp->next = NULL;
  p->next = temp;
  siz++;
}

template<class T>
void LinkedList<T>::push_front(T x)
{
  Node *temp = new Node; Node* p = new Node;
  temp->value = x;
  if (start == NULL)
  {
    start = temp;
    start->next = NULL;
    siz ++;
  }
  else
  {
    p = start;
    start = temp;
    start->next = p;
    siz++;
  }
}

template<class T>
void LinkedList<T>::reverse()
{
  Node* p1 = new Node; Node* p2 = new Node; Node* p3 = new Node;
  if (start == NULL || start->next == NULL) return;

  p1 = start;
  p2 = p1->next;
  p3 = p2->next;
  p1->next = NULL;
  p2->next = p1;
  while (p3 != NULL)
  {
    p1 = p2;
    p2 = p3;
    p3 = p3->next;
    p2->next = p1;
  }
  start = p2;
}

template<class T>
void LinkedList<T>::erase(int index)
{
  if (index >= 0 && index < siz)

  {
    //traverse to index node
    int i = 0;
    Node* p = start; Node* before = new Node;
    for ( ; p; p = p->next, i++)
    {
      if (i == index - 1) {before = p;}
      if (i == index) { break; }
    }
    before->next = p->next;
    delete p;
    siz--;
  }
}

template<class T>
void LinkedList<T>::erase(int beg, int finish)
{
  Node *p = new Node; Node *p1 = new Node; Node *p2 = new Node;
  p = start;
  for (int i = 0; i < siz; i++, p = p->next)
  {
    if (i == beg) { p1 = p; }
    if (i > beg) {siz--;}
    if (i == finish) {p2 = p; break;}
  }

  p1->next = p2;
}

template<class T>
void LinkedList<T>::insert(int index, T x)
{
  int counter = 0;
  Node* temp; temp->value = x; temp->next = NULL;
  Node* ptr = new Node;
  Node* p = start;
  while (p != NULL)
  {
    p = p->next;
    counter++;
  }
  if (index == 1)
  {
    if (start == NULL)
    {
      start = temp;
      start->next = NULL;
    }
    else
    {
      ptr = start;
      start = temp;
      start->next = ptr;
    }
  }
  else if (index > 1  && index <= counter)
      {
        p = start;
        for (int i = 1; i < index; i++)
        {
          ptr = p;
          p = p->next;
        }
        ptr->next = temp;
        temp->next = p;
      }
}

template<class T>
void LinkedList<T>::merge(LinkedList list2)
{
  siz += list2.siz;
  Node* p = end;
  p->next = list2.start; end = list2.end;
}

//getters
template<class T>
T& LinkedList<T>::back() const
{
  Node* p = end;
  T& result = p->value;
  return (result);
}


template<class T>
T& LinkedList<T>::front() const
{
  Node* p = start;
  T& result = p->value;
  return (result);
}

#endif // LLIST_H_INCLUDED
