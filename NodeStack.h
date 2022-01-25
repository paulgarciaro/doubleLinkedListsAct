#ifndef _NODESTACK_H_
#define _NODESTACK_H_

#include<iostream>

template <class T>
class NodeStack {
public:
    T data;
    NodeStack<T>* next;
    NodeStack();
    NodeStack(T);
};

template<class T>
NodeStack<T>::NodeStack(){
    next = NULL;
}
template<class T>
NodeStack<T>::NodeStack(T val){
    data = val;
    next = NULL;
}

#endif // _NODESTACK_H_