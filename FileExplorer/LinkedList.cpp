#include <string>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

template <typename T>
LinkedList<T>::LinkedList() {
  head = NULL;
  tail = NULL;
  size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){
  Node<T>* current = (*this).head;          
  while (current != nullptr) {
    Node<T>* nextNode = (*current).getNext();
    delete current;
    current = nextNode;
  }
  this->head = NULL;
  this->tail = NULL;
  this->size = 0;
}

template <typename T>
void LinkedList<T>::pushBack(T data) {
  Node<T> *pushNode = new Node<T>(data);
  if (this->getHead() == NULL){
    this->head = pushNode;
    this->tail = pushNode;
  }
  else{
    this->getTail()->setNext(pushNode);
    pushNode->setPrev(this->getTail());
    this->tail = pushNode;
  }
  this->size = this->size + 1;
}

template <typename T>
void LinkedList<T>::deleteData(T data) {
  Node<T>* currNode = this->getHead();
  while (currNode != NULL) {
    if (currNode->getData() == data) {
      if (currNode == this->getHead()) this->head = this->getHead()->getNext();
      else currNode->getPrev()->setNext(currNode->getNext());
      
      if (currNode == this->getTail()) this->tail = this->getTail()->getPrev();
      else currNode->getNext()->setPrev(currNode->getPrev());
      
      delete currNode;
      this->size = this->size - 1;
      return;
    }
    else currNode = currNode->getNext();
  }
}

template <typename T>
Node<T>* LinkedList<T>::getHead() const{
  return this->head;
}

template <typename T>
Node<T>* LinkedList<T>::getTail() const{
  return this->tail;
}

template <typename T>
void LinkedList<T>::operator+=(LinkedList &rhs) {
   (*this).getTail()->setNext(rhs.getHead());
   rhs.getHead()->setPrev((*this).getTail());

   (*this).tail = rhs.getTail();

   (*this).size = ((*this).size + rhs.size);

   rhs.head = NULL;
   rhs.tail = NULL;
   rhs.size = 0;
}

template class LinkedList<int>;
template class LinkedList<string>;
template class LinkedList<char>;
template class LinkedList<double>;