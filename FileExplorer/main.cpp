#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

int main() {
  Node<string>* testNode = new Node<string>("Hello World!\n");
  cout << testNode << ' ' << testNode->getData() << endl;
  delete testNode;

  LinkedList<char>* testList = new LinkedList<char>();
  testList->pushBack('a');
  testList->pushBack('b');
  testList->pushBack('c');
  cout << testList->getHead()->getData() << ' ';
  cout << testList->getTail()->getData() << endl;
  testList->deleteData('a');
  cout << testList->getHead()->getData() << ' ';
  testList->deleteData('c');
  cout << testList->getTail()->getData() << endl;

  LinkedList<char>* bestList = new LinkedList<char>();
  bestList->pushBack('a');
  
  *testList += *bestList;

  cout << testList->getHead()->getData() << ' ';
  cout << testList->getTail()->getData() << endl;
  
  delete bestList;
  delete testList;

  return 0;
}