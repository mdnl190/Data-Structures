#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

template <class T>
class Queue
{
public:
  Queue();              //constructor
  Queue(const Queue&);  //copy constructor
  ~Queue();             //destructor

  //getters
  bool empty () const {return (0 == start);}
  int size()    const {return siz;}
  T peek()      const;

  //setters
  bool pop();
  void push(const T&);
  void clear();
  Queue<T>& operator=(const Queue<T>&);

private:
  struct Node
  {
    T value;
    bool inUse;
    Node* next;
  };
  Node* start;
  Node* end;
  int siz;
  T dummy;
};

//constructor
template <class T>
Queue<T>::Queue()
{
  start = 0;
  end = 0;
  siz = 0;
}

//copy constructor
template <class T>
Queue<T>::Queue(const Queue<T>& a)
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

//destructor
template <class T>
Queue<T>::~Queue()
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
T Queue<T>::peek() const
{
  if (0 == start) return dummy;
  return (start->value);
}

//setters
template <class T>
bool Queue<T>::pop()
{
  if (0 == start) return false;
  Node* p = start->next;
  delete start;
  start = p;
  if (start == 0) end = 0;
  --siz;
  return true;
}

template <class T>
void Queue<T>::push(const T& parameter)
{
  Node* node = new Node;
  node->value = parameter;
  node->next = 0;
  if (end) end->next = node;
  else start = node;
  end = node;
  ++siz;
}

template <class T>
void Queue<T>::clear()
{
  while (start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
  end = 0;
  siz = 0;
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& a)
{
  if (this == &a) return *this;

  // deallocate existing queue
  while (start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }

  // build new queue
  end = 0;
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

  return *this;
}

#endif // QUEUE_H_INCLUDED
