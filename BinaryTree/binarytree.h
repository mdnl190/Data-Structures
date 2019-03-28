#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include <iostream>

template <class T>
class BinaryTree
{
private:
  struct node{
    T data;
    node* left;
    node* right;
  }; node *root;

  int size;
  int getHeight(node*) const;
  void clear(node*);
  void preOrderTraverse(const node*);
  void inOrderTraverse(const node*);
  void postOrderTraverse(const node*);
  node* findParent(node*, const T&) const;
  T& traverse(node*, const T&) const;

public:
  BinaryTree() {root = nullptr; size = 0;}
  ~BinaryTree() {clear(root);}

  bool isEmpty() const {return root == nullptr;}
  int getHeight() const {return getHeight(root);}
  int getNumberOfNodes() const {return size;}
  T getRootData() const {return root->data;}
  void add(T);
  bool remove(T);
  void clear() {clear(root); root = nullptr;}
  T& contains(const T&) const;
  void preOrderTraverse() {preOrderTraverse(root);}
  void inOrderTraverse() {inOrderTraverse(root);}
  void postOrderTraverse() {postOrderTraverse(root);}
};


template <class T>
int BinaryTree<T>::getHeight(node* p) const
{
  if (p == nullptr) return 0;
  int leftHeight = getHeight(p->left);
  int rightHeight = getHeight(p->right);
  if (leftHeight < rightHeight) return 1 + rightHeight;
  else return 1 + leftHeight;
}


template <class T>
void BinaryTree<T>::add(T value)
{
  node* newNode = new node;
  newNode->data = value;
  newNode->left = newNode->right = nullptr;
  if (!root) root = newNode;
  else
  {
    node* nodePtr = root;
    while (true)
    {
      if (value <= nodePtr->data)
      {
        if (nodePtr->left) nodePtr = nodePtr->left;
        else
        {
          nodePtr->left = newNode;
          break;
        }
      }
      else
      {
        if (nodePtr->right) nodePtr = nodePtr->right;
        else
        {
          nodePtr->right = newNode;
          break;
        }
      }
    }
  }
  size++;
}
template <class T>
typename BinaryTree<T>::node* BinaryTree<T>::findParent(node* n, const T& value) const {
  if (!n)
    return nullptr;
  if (value < n->data) {
    if (n->left && n->left->data == value)
      return n;
    return findParent(n->left, value);
  }
  if (n->right && n->right->data == value)
    return n;
  return findParent(n->right, value);
}

template <class T>
bool BinaryTree<T>::remove(T value)
{
  node* p = new node; node* c = new node;
  bool left;
  if (root->data == value) {
    p = nullptr;
    c = root;
    left = false;
  }
  else
  {
    p = findParent(root, value);
    if (p == nullptr) return 0;
    left = p->left && p->left->data == left;
    c = left ? p->left : p->right;
  }
  if (!c->left && !c->right)
  {
    if (!p)root = nullptr;
    else if (left) p->left = nullptr;
    else p->right = nullptr;
    delete c;
  }
  else if (c->left && !c->right)
  {
    if (!p) root = c->left;
    if (left) p->left = c->left;
    else p->right = c->left;
    delete c;
  }
  else if (!c->left && c->right)
  {
    if (!p) root = c->right;
    else if (left) p->left = c->right;
    else p->right = c->right;
    delete c;
  }
  else
  {
    node* par = c;
    node* right = c->right;
    while(right->left)
    {
      par = right;
      right = right->left;
    }
    c->data = right->data;
    if (par == c) c->right = right->right;
    else par->left = right->right;
    delete right;
  }
  size--;
}

template <class T>
void BinaryTree<T>::clear(node* p)
{
  if (p)
  {
    clear(p->left);
    clear(p->right);
    delete p;
  }
  size = 0;
}

template <class T>
T& BinaryTree<T>::traverse(node* p, const T& value) const
{
  if (!p) throw "Error: Node not found.";
  if (value == p->data) return p->data;
  if (value <= p->data) return traverse(p->left, value);
  return traverse(p->right, value);
}

template <class T>
T& BinaryTree<T>::contains(const T &value) const
{
  return traverse(root, value);
}

template <class T>
void BinaryTree<T>::preOrderTraverse(const node* myNode)
{
  if (myNode)
  {
    std::cout << myNode->data << " ";
    preOrderTraverse(myNode->left);
    preOrderTraverse(myNode->right);
  }
}

template <class T>
void BinaryTree<T>::inOrderTraverse(const node* myNode)
{
  if (myNode)
  {
    inOrderTraverse(myNode->left);
    std::cout << myNode->data << " ";
    inOrderTraverse(myNode->right);
  }
}

template <class T>
void BinaryTree<T>::postOrderTraverse(const node* myNode)
{
  if (myNode)
  {
    postOrderTraverse(myNode->left);
    postOrderTraverse(myNode->right);
    std::cout << myNode->data << " ";
  }
}

#endif // BINARYTREE_H_INCLUDED
