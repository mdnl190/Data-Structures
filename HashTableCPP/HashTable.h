/*Lab 10a, Hash Table Program
Programmer: Mary Latif
Editor(s) used: Code::Blocks 13.12
Compiler(s) used: GNU GCC Compiler*/
#ifndef HashTable_h
#define HashTable_h

#include <algorithm>
#include <list>
#include <vector>
using namespace std;

template <class T, class U, int CAPACITY>
class HashTable
{
public:
  //constructor
  HashTable(int(*)(const U&));
  //getters
  int capacity()      const {return 0.8 * CAPACITY;}
  int size()          const {return siz;}
  bool containsKey(const U&) const;
  T operator[](const U&)     const;
  vector<U>keys()            const;
  //setters
  void clear();
  void deleteKey(const U&);
  T& operator[](const U&);

private:
  struct Node
  {
    T value; U key;
    void operator=(const U& val){value = val;}
    bool operator==(const Node& node)const{return (key == node.key);}
  };
  int getWrappedIndex(const U&);
  int(*hashCode)(const U&);
  list<Node> data[CAPACITY];
  int siz;
  T dummy;
};

  //constructor
  template <class T,class U,int CAPACITY>
  HashTable<T,U,CAPACITY>::HashTable(int(*x)(const U& y)) {siz = 0; hashCode = x;}

  //getters
  template <class T, class U,int CAPACITY>
  bool HashTable<T,U,CAPACITY>::containsKey(const U& index) const
  {
    typename list<Node>::const_iterator it;
    Node temp;

    int wi = hashCode(index) % CAPACITY;
    if(wi < 0) wi += CAPACITY;
    temp.key = index;

    it = find(data[wi].begin(), data[wi].end(), temp);
    if(it == data[wi].end()) return (false);
    return (true);
  }

  template <class T, class U, int CAPACITY>
  T HashTable<T,U,CAPACITY>::operator[](const U& index) const
  {
    typename list<Node>::const_iterator it;
    Node temp;

    int wi = hashCode(index) % CAPACITY;
    if(wi < 0) wi += CAPACITY;
    temp.key = index;

    it = find(data[wi].begin(), data[wi].end(), temp);
    if(it == data[wi].end()) return (temp.value);
    return (it->value);
  }

  template <class T, class U, int CAPACITY>
  vector<U>HashTable<T,U,CAPACITY>::keys() const
  {
    vector<U> result;
    typename list<Node>::const_iterator it;

    for(int i = 0; i < CAPACITY; i++)
      for(it = data[i].begin(); it != data[i].end(); it++) result.push_back(it->key);

    return (result);
  }

  //setters
  template<class T, class U, int CAPACITY>
  void HashTable<T,U,CAPACITY>::clear()
  {
    for(int i = 0; i < CAPACITY; i++) data[i].clear();
    siz = 0;
  }

  template<class T, class U, int CAPACITY>
  void HashTable<T,U,CAPACITY>::deleteKey(const U& index)
  {
    typename list<Node>::iterator it;
    Node temp;

    int wi = hashCode(index) % CAPACITY;
    if(wi < 0) wi += CAPACITY;
    temp.key = index;

    it = find(data[wi].begin(), data[wi].end(), temp);
    if(it != data[wi].end()) data[wi].erase(it); --siz;
  }

  template <class T, class U, int CAPACITY>
  T& HashTable<T,U,CAPACITY>::operator[](const U& index)
  {
    typename list<Node>::iterator it;
    Node temp;

    int wi = hashCode(index) % CAPACITY;
    if(wi < 0) wi += CAPACITY;
    temp.key = index;

    it = find(data[wi].begin(), data[wi].end(), temp);
    if(it == data[wi].end())
    {
      data[wi].push_back(temp); siz++;
      return (data[wi].back().value);
    }
    return (it->value);
  }

#endif // HashTable_h
