#ifndef NODE_H
#define NODE_H

#include <string>

template <typename T> class Node {
private:
  T data;
  Node* next;
  Node* previous;

public:
  Node(T data);
  T getData() const;
  Node* getPrev() const;
  Node* getNext() const;
  void setPrev(Node* prev);
  void setNext(Node* next);
};


template <typename T>
bool operator==(const Node<T>&lhs, const Node<T>& rhs);

#endif