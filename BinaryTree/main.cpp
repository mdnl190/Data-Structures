#include <iostream>
#include "binarytree.h"
#include "binarytree.h"

using namespace std;

int main()
{
  BinaryTree<int> myTree;
  myTree.add(14);
  myTree.add(7);
  myTree.add(21);

  cout << "Expected size: 3   Actual Size: " << myTree.getNumberOfNodes() << endl;
  cout << "\nExpected nodes: 7 14 21    Actual: "; myTree.inOrderTraverse();
  cout << "\nExpected nodes: 14 7 21    Actual: "; myTree.preOrderTraverse();
  cout << "\nExpected nodes: 7 21 14    Actual: "; myTree.postOrderTraverse();

  myTree.remove(14);
  cout << "\n\nExpected nodes: 7 21   Actual: "; myTree.inOrderTraverse();
  cout << "\n\nExpected height: 2   Actual: " << myTree.getHeight() << endl;

  cout << "\nExpected that 7 is in the binary tree.   Actual: " << myTree.contains(7) << endl;

  myTree.clear();
  cout << "\nI expect the tree to be empty after clearing.    Actual: ";
  myTree.isEmpty()? cout << "true" << endl: cout << "false" << endl;
  cout << "I expect the size to be 0.    Actual: " << myTree.getNumberOfNodes() << endl;

}
