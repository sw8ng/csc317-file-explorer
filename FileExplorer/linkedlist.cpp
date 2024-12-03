#include <string>
#include "linkedList.h"
#include "node.h"
#include "folder.h"
#include "file.h"
using namespace std;

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) : head(nullptr), tail(nullptr), size(0) {
    Node<T>* currNode = list.getHead();
    while (currNode != nullptr) {
        this->push_back(currNode->getData());
        currNode = currNode->getNext();
    }
}


template <typename T>
LinkedList<T>::~LinkedList() {
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
    if (this->head == nullptr) {
        this->head = pushNode;
        this->tail = pushNode;
    }
    else {
        this->tail->setNext(pushNode);
        pushNode->setPrev(this->tail);
        this->tail = pushNode;
    }
    this->size++;
}


template <typename T>
void LinkedList<T>::deleteData(T data) {
    if (this->head == nullptr) {
        return;
    }
    Node<T>* currNode = this->head;
    while (currNode != nullptr) {
        if (currNode->getData() == data) {
            if (currNode == this->head) {
                this->head = this->head->getNext();
                if (this->head != nullptr) {
                    this->head->setPrev(nullptr);
                }
            }
            else if (currNode == this->tail) {
                this->tail = this->tail->getPrev();
                if (this->tail != nullptr) {
                    this->tail->setNext(nullptr);
                }
            }
            else {
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
Node<T>* LinkedList<T>::getHead() const {
    return this->head;
}

template <typename T>
Node<T>* LinkedList<T>::getTail() const {
    return this->tail;
}

template<typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const {

    if (this->size != rhs.size) return false;

    Node<T>* thisNode = this->head;
    Node<T>* rhsNode = rhs.head;

    while (thisNode != nullptr) {
        if (thisNode->getData() != rhsNode->getData()) { 
            return false;
        }
        thisNode = thisNode->getNext();
        rhsNode = rhsNode->getNext();
    }

    return true;
}

template <typename T>
void LinkedList<T>::operator+=(LinkedList<T>& list) {
    if (list.head == nullptr) {
        return;
    }
    if (this->head == nullptr) {
        this->head = list.head;
        this->tail = list.tail;
        this->size = list.size;

        list.head = nullptr;
        list.tail = nullptr;
        list.size = 0;
        return;
    }
    this->tail->setNext(list.head);
    list.head->setPrev(this->tail);
    this->tail = list.tail;
    this->size += list.size;

    list.head = nullptr;
    list.tail = nullptr;
    list.size = 0;
}

template<typename T>
int LinkedList<T>::getSize() const {
return size; }

template class LinkedList<File*>;
template class LinkedList<Folder*>;

