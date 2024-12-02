#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "Node.h"

template <typename T>
class LinkedList{
private:
  Node<T>* head;
  Node<T>* tail;
  unsigned int size;
public:
  LinkedList();
  ~LinkedList();
  void push_back(T data);
  void deleteData(T data);
  Node<T>* getHead() const;
  Node<T>* getTail() const;
  void operator+=(LinkedList &rhs);
};

#endif