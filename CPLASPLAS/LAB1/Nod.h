#ifndef NOD_H
#define NOD_H

template <typename T>
class Nod {
private:
    T data;
    Nod<T> *next;
public:
    Nod(T data) {
        this->data = data;
        this->next = NULL;
    }

    T getData() {
        return this->data;
    }

    Nod<T> *getNext() {
        return this->next;
    }

    void setNext(Nod<T> *next) {
        this->next = next;
    }
};
#endif
