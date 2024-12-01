#include "Node.h"
#include <string>
using namespace std;

template <typename T>
Node<T>::Node(T data) {
  this->data = data;
}

template <typename T>
T Node<T>::getData() const{
  return this->data;
}

template <typename T>
Node<T>* Node<T>::getNext() const{
  return this->next;
}

template <typename T>
Node<T>* Node<T>::getPrev() const{
  return this->previous;
}

template <typename T>
void Node<T>::setNext(Node* next){
  this->next = next;
}

template <typename T>
void Node<T>::setPrev(Node* prev){
  this->previous = prev;
}

template class Node<int>;
template class Node<string>;
template class Node<char>;
template class Node<double>;