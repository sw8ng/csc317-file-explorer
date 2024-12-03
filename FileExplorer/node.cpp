#include "node.h"
#include <string>
#include "folder.h"
using namespace std;

template <typename T>
Node<T>::Node(T data) : data(data), next(nullptr), prev(nullptr) {}

template <typename T>
T Node<T>::getData() const {
    return data;
}

template <typename T>
Node<T>* Node<T>::getNext() const {
    return next;
}

template <typename T>
Node<T>* Node<T>::getPrev() const {
    return prev;
}

template <typename T>
void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}

template <typename T>
void Node<T>::setPrev(Node<T>* prev) {
    this->prev = prev;
}

template class Node<File*>;
template class Node<Folder*>;

