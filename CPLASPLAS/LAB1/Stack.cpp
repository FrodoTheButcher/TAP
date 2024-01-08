#include "Stack.h"
#include <iostream>
using namespace std;

template <typename T>
Stack<T>::Stack() {
    this->top=-1;
}

template <typename T>
bool Stack<T>::isEmpty() {
    return top == -1;
}

template <typename T>
bool Stack<T>::isFull() {
    return top == MAX_SIZE - 1;
}

template <typename T>
bool Stack<T>::push(T value) {
    if (isFull()) {
        throw invalid_argument("Size is full");
    }
    data[++top] = value;
    return true;
}

template <typename T>
bool Stack<T>::pop() {
    if (isEmpty()) {
        throw invalid_argument("No elements to delete");
    }
    --top;
    return true;
}

template <typename T>
T Stack<T>::peek(){
    if (isEmpty()) {
       return NULL;
    }
    return data[top];
}

template <typename T>
void Stack<T>::print() {
    if (isEmpty()) 
        return;
    for (int i = 0; i <= top; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

