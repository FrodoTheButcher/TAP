#include <iostream>
#include "Lista.h"
using namespace std;

template <typename T>
LinkedList<T>::LinkedList() {
    this->head = NULL;
    this->size = 0;
}

template <typename T>
bool LinkedList<T>::isEmpty() {
    return this->size == 0;
}

template <typename T>
bool LinkedList<T>::add(T data) {
    Nod<T> *newNod = new Nod<T>(data);
    if (isEmpty()) {
        this->head = newNod;
        this->size++;
        return true;
    }
    Nod<T> *current = this->head;
    while (current->getNext() != NULL) {
        current = current->getNext();
    }
    current->setNext(newNod);
    this->size++;
    return true;
}

template <typename T>
bool LinkedList<T>::remove(T data) {
    if (isEmpty()) {
        return false;
    }
    Nod<T> *current = this->head;
    Nod<T> *previous = NULL;
    while (current != NULL) {
        if (current->getData() == data) {
            if (previous == NULL) {
                this->head = current->getNext();
            } else {
                previous->setNext(current->getNext());
            }
            this->size--;
            return true;
        }
        previous = current;
        current = current->getNext();
    }
    return false;
}

template <typename T>
bool LinkedList<T>::contains(T data) {
    if (isEmpty()) {
        return false;
    }
    Nod<T> *current = this->head;
    while (current != NULL) {
        if (current->getData() == data) {
            return true;
        }
        current = current->getNext();
    }
    return false;
}

template <typename T>
void LinkedList<T>::print() {
    if (isEmpty()) {
        return;
    }
    Nod<T> *current = this->head;
    while (current != NULL) {
        cout << current->getData() << " ";
        current = current->getNext();
    }
    cout << endl;
}