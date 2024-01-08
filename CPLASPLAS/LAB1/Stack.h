#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
private:
    int MAX_SIZE = 100;
    T data[MAX_SIZE];
    int top;

public:
    Stack();

    bool isEmpty();

    bool isFull();

    bool push(T value);

    bool pop();

    T peek();

    void print();
};
#endif // STACK_H
