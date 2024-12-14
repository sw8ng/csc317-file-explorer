#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "Node.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    LinkedList();
    LinkedList(const LinkedList<T>& list);
    ~LinkedList();

    void push_back(T data);
    void deleteData(T data);
    Node<T>* getHead() const;
    Node<T>* getTail() const;
    bool operator==(const LinkedList<T>& rhs) const;
    void operator+=(LinkedList<T>& list);

    int getSize() const;
};

#endif