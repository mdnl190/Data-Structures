#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template <class T>
class Stack
{
public:
  Stack(); //constructor
  ~Stack(); //destructor
  Stack(const Stack&); //copy constructor

  //getters
  bool empty() const  {return 0 == siz;}
  int size() const {return siz;}
  T peek() const;

  //setters
  Stack<T>& operator=(const Stack&);
  void push(const T&);
  bool pop();
  void clear();

private:
  struct Node
  {
    T value;
    bool inUse;
    Node* next;
  };
  int siz;
  Node* start;
  T dummy;
};

//constructor
template <class T>
Stack<T>::Stack()
{
  start = 0;
  siz = 0;
}

//copy constructor
template <class T>
Stack<T>::Stack(const Stack<T>& a)
{
  start = 0;
  Node* end = 0;
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

//destructor
template <class T>
Stack<T>::~Stack()
{
  while (start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
}

//getters
template <class T>
T Stack<T>::peek() const
{
  if (0 == siz) return (dummy);
  return (start->value);
}

//setters
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& a)
{
  if (this == &a) return (*this);

  // deallocate existing queue
  while (start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }

  // build new stack
  Node* end = 0;
  for (Node* p = a.start; p; p = p->next)
  {
    Node* node = new Node;
    node->value = p->value;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
  }
  siz = a.siz;

  return (*this);
}

template <class T>
void Stack<T>::push(const T& parameter)
{
  Node* node = new Node;
  node->value = parameter;
  node->next = start;
  start = node;
  ++siz;
}

template <class T>
bool Stack<T>::pop()
{
  if (0 == siz) return (false);
  Node* p = start->next;
  delete start;
  start = p;
  --siz;
  return (true);
}

template <class T>
void Stack<T>::clear()
{
  while (start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
  siz = 0;
}

#endif // STACK_H_INCLUDED
