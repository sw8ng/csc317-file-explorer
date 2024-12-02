#include <string>
#include "linkedList.h"
#include "Node.h"
using namespace std;

template <typename T>
LinkedList<T>::LinkedList() {
  head = nullptr;
  tail = nullptr;
  size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){
  Node<T>* current = this->head;          
  while (current != nullptr) {
    Node<T>* nextNode = current->getNext();
    delete current;
    current = nextNode;
  }
  this->head = nullptr;
  this->tail = nullptr;
  this->size = 0;
}

template <typename T>
void LinkedList<T>::push_back(T data) {
  Node<T>* pushNode = new Node<T>(data);
  if (this->getHead() == NULL){
    this->head = pushNode;
    this->tail = pushNode;
  }
  else{
    this->getTail()->setNext(pushNode);
    pushNode->setPrev(this->getTail());
    this->tail = pushNode;
  }
  this->size++;
}

template <typename T>
void LinkedList<T>::deleteData(T data) {
  if(this->getHead() == nullptr){
    return;
  }
  Node<T>* currNode = this->getHead();
  while (currNode != nullptr) {
    if (currNode->getData() == data) {
      if (currNode == this->getHead()) {
        this->head = this->getHead()->getNext();
        if(this->head != nullptr){
          this->head->setPrev(nullptr);
        }
      }else if (currNode == this->getTail()){
        this->tail = this->getTail()->getPrev();
        if(this->tail != nullptr){
          this->tail->setNext(nullptr);
        }
      }else{
        currNode->getPrev()->setNext(currNode->getNext());
        currNode->getNext()->setPrev(currNode->getPrev());
      }
      delete currNode;
      this->size--;
      return;
    }
  currNode = currNode->getNext();
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
  if(rhs.head ==nullptr){
    return;
  }
  if(this->head == nullptr){
    this->head = rhs.head;
    this->tail = rhs.tail;
    this->size = rhs.size;

    rhs.head = nullptr;
    rhs.tail = nullptr;
    rhs.size = 0;
    return;
  }
   this->getTail()->setNext(rhs.getHead());
   rhs.getHead()->setPrev(this->getTail());

   this->tail = rhs.getTail();

   this->size += rhs.size;

   rhs.head = nullptr;
   rhs.tail = nullptr;
   rhs.size = 0;
}


template class LinkedList<int>;
template class LinkedList<string>;
template class LinkedList<char>;
template class LinkedList<double>;
 
