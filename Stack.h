#ifndef _STACK_H_
#define _STACK_H_

#include <climits>
#include "NodeStack.h"

template <class T>
class Stack {
private:
    NodeStack<T>* top;
    int numElements;

public:
    Stack();
    ~Stack();
    int getNumElements();
    void printStack();

    void push(T value);
    T pop();
    T getTop();
    bool isEmpty();


};

template<class T>
Stack<T>::Stack() {
    top = NULL;
    numElements = 0;
}

template<class T>
Stack<T>::~Stack() {
    NodeStack<T> *p, *q;
    p = top;
    while (p != NULL) {
        q = p->next;
        delete p;
        p = q;
    }
    top = NULL;
    numElements = 0;
}

template<class T>
int Stack<T>::getNumElements() {
    return numElements;
}
template<class T>
void Stack<T>::printStack() {
    NodeStack<T> *ptr = top;
    while (ptr != NULL) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

template<class T>
void Stack<T>::push(T value) {
    NodeStack<T> *newNode = new NodeStack<T>(value);
    newNode->next = top;
    top = newNode;
    numElements++;
}

template<class T>
T Stack<T>::pop() {
    T value = -1;
    if (top != NULL) {
        NodeStack<T> *p = top;
        value = top->data;
        top = p->next;
        delete p;
        numElements--;
    }
    return value;
}

template<class T>
T Stack<T>::getTop() {
    T value = -1;
    if (top != NULL) {
        value = top->data;
    }
    return value;
}

template<class T>
bool Stack<T>::isEmpty() {
    bool result = false;
    if (top == NULL)
        result = true;
    return result;
}
#endif // _STACK__H__