#ifndef NODE_H
#define NODE_H

#include <string>

template <typename T> class Node {
private:
  T data;
  Node *next;
  Node *previous;

public:
  Node(T data);
  T getData() const;
  Node *getPrev() const;
  Node *getNext() const;
  void setPrev(Node *prev);
  void setNext(Node *next);
};

bool operator==(const Node&lhs, const Node& rhs);

bool operator==(const Node&rhs, const Node&lhs);


#endif