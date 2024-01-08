#ifndef LINKEDIST.H
#define LINKEDIST.H
#include "Nod.h"

template <typename T>
class LinkedList {
private:
    Nod<T> *head;
    int size;
public:
    LinkedList() {
        this->head = NULL;
        this->size = 0;
    }

    bool isEmpty();

    bool add(T data);

    bool remove(T data);

    bool contains(T data);

    void print();
};

#endif 
