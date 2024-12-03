#ifndef NODE_H
#define NODE_H

#include <string>

template <typename T>
class Node {
private:
    T data;
    Node<T>* next;
    Node<T>* prev;
public:
    Node(T data);
    T getData() const;
    Node<T>* getNext() const;
    Node<T>* getPrev() const;
    void setNext(Node<T>* next);
    void setPrev(Node<T>* prev);

};


#endif