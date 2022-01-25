#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

#include <climits>
#include "Node.h"
#include "Stack.h"
#include "Registro.h"
#include "dateTime.h"



template <class T>
class DoubleLinkedList {
  private:
    Node<T>* head;
    Node<T>* tail;
    int numElements;

  public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    int getNumElements();
    void printList();
    void addFirst(T value);
    void addLast(T value);
    bool deleteData(T value);
    bool deleteAt(int position);
    T getData(int position);
    int findData(T value);//
    void updateAt(int position, T newValue);//
    void updateData(T oldValue, T newValue);//
    Node<T>* getHead();//
    void clear();//
    void duplicate();
    void removeDuplicates();
    void deleteNode(Node<T> * del);
    void getReversedSublist(int start, int end, DoubleLinkedList<T> &other);
    void operator=(DoubleLinkedList<T> &);
    T operator[](const int position);
    void insertAfter(Node<T>*prev, T data);
    void quickSort();
    void _quickSort(Node<T>* l, Node<T> *h);
    Node<T>* partition(Node<T> *l, Node<T> *h);
    void swap(T *a, T *b);
    void iterativeQuickSort();
};

//Complejidad O(1)
template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
    head = NULL;
    tail = NULL;
    numElements = 0;
}

//Complejidad O(n)
template<class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
  Node<T> *p, *q;
  p = head;
  while (p != NULL) {
    q = p->next;
    delete p;
    p = q;
  }
  head = NULL;
  tail = NULL;
  numElements = 0;
}

//Complejidad O(1)
template<class T>
int DoubleLinkedList<T>::getNumElements() {
  return numElements;
}

//Complejidad O(n)
template<class T>
void DoubleLinkedList<T>::printList() {
  Node<T> *ptr = head;
  while (ptr != NULL) {
    std::cout << ptr->data << " ";
    ptr = ptr->next;
  }
  std::cout << std::endl;
}

//Complejidad O(1)
template<class T>
void DoubleLinkedList<T>::addFirst(T value) {
  Node<T> *newNode = new Node<T>(value);
  // Si la lista esta vacia 
  if (head == NULL) {
    head = newNode;
    tail = newNode;
  }
  else {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  numElements++;
}

//Complejidad O(1)
template<class T>
void DoubleLinkedList<T>::addLast(T value) {
  // La lista esta vacia
  if (head == NULL) {
    addFirst(value);
  }
  else {
    Node<T> *newNode = new Node<T>(value);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    numElements++;
  }    
}

//Complejidad O(n)
template<class T>
bool DoubleLinkedList<T>::deleteData(T value) {
  Node<T> *p, *q;
  p = head;
  q = NULL;
  // Si la lista esta vacia 
  if (p == NULL) {
    return false;
  }
  else {
    // buscar value en la lista
    while (p != NULL && p->data != value) {
      q = p;
      p = p->next;
    }
    // Si no existe value en la lista
    if (p == NULL)
      return false;
    // Si debe borrarse el primer elemento
    if (p->prev == NULL) {
      head = p->next;
      if (head != NULL)
        head->prev = NULL;
    }
    else if (p->next == NULL) { 
      // Si debe borrarse el último elemento
      q->next = NULL;
      tail = q;
    }
    else {
      // Cualquier otro elemento entre la lista 
      q->next = p->next;
      p->next->prev = q;
    }
    delete p;
    numElements--;
    return true;
  }
}

//Complejidad O(n)
template<class T>
bool DoubleLinkedList<T>::deleteAt(int position) {
  if (position < 0 || position >= numElements) {
    std::cout << "Indice fuera de rango" << std::endl;
    return false;
  }
  else if (position == 0) { // Si debe borrarse el primer elemento
    Node<T> *p = head;
    // Si la lista contiene solo un nodo
    if (head != NULL && head->next == NULL) {
      head = NULL;
      tail = NULL;  
    }
    else {
      head = p->next;
      head->prev = NULL;
    }
    delete p;
    numElements--;
    return true; 
  }
  else { 
    Node<T> *p = head, *q = NULL;
    int index = 0;
    while (index != position) {
      q = p;
      p = p->next;
      index++;
    }
    // Si debe borrarse el último elemento
    if (p->next == NULL) {
      q->next = NULL;
      tail = q;
    }
    else { // Cualquier otro elemento entre la lista 
      q->next = p->next;
      p->next->prev = q;
    }
    delete p;
    numElements--;
    return true;
  }
}

//Complejidad O(n)
template<class T>
T DoubleLinkedList<T>::getData(int position) {
  if (position < 0 || position >= numElements) {
    std::cout << "Indice fuera de rango" << std::endl;
    return -1;
  }
  else {
    if (position == 0)
      return head->data;
    Node<T> *p = head;
    int index = 0;
    while (p != NULL) {
      if (index == position)
        return p->data;
      index++;
      p = p->next;
    }
    return -1;
  }
}

//Complejidad O(n)
template <class T>
int DoubleLinkedList<T>::findData(T value){
  Node<T> *p = head;
  int position, i;
  for(i = 0; i<numElements; i++){
    if((p->data) == (value)){
      position = i;
      return position;
    }
    p = p->next;
  }
  return -1;
}

//Complejidad O(n)
template <class T>
void DoubleLinkedList<T>::updateAt(int position, T newValue){
  Node<T> *p = head;
  int i;
  if(position>=numElements){
    std::cout << "Out of range" << std::endl;
  }else{
    for(i=0; i<numElements; i++){
      if(i == position){
        p->data = newValue;
        }
      p = p->next;
      }
  }
}

//Complejidad O(n)
template <class T>
void DoubleLinkedList<T>::updateData(T oldValue, T newValue){
  Node<T> *p = head;
  for(int i=0; i<numElements; i++){
    if(p->data == oldValue){
      p->data = newValue;
    }
    p = p->next;
  }
}

//Complejidad O(1)
template <class T>
Node<T>* DoubleLinkedList<T>::getHead(){
  return head;
}

//Complejidad O(n)
template <class T>
void DoubleLinkedList<T>::clear(){
  Node<T> *p, *q;
  p = head;
  while (p != NULL) {
    q = p->next;
    delete p;
    p = q;
  }
  head = NULL;
  tail = NULL;
  numElements = 0;
}

/*template <class T>
void DoubleLinkedList<T>::sort(){
}*/

//Complejidad O(1)
template <class T>
void DoubleLinkedList<T>::insertAfter(Node<T>* prev, 
T newData) {
    if (prev == NULL) {
        std::cout << "the given previous node cannot be NULL" << std::endl;
        return;
    }
    Node<T> *newNode = new Node<T>(newData); 
    newNode->next = prev->next;
    prev->next = newNode;
    newNode->prev = prev;
    if (newNode->next != NULL)
      newNode->next->prev = newNode;
}

//Complejidad O(n)
template <class T>
void DoubleLinkedList<T>::duplicate(){
  Node<T> *ptr = head;
  if (ptr == NULL){
    std::cout << "La lista está vacía" << std::endl;
  }else {
    while (ptr != NULL) {
      insertAfter(ptr, ptr->data);
      numElements++;
      ptr = ptr->next->next;    
    }
  }
}

/*
  El código de la siguiente función está basado en el que se encuentra en: https://www.geeksforgeeks.org/remove-duplicates-unsorted-doubly-linked-list/
  solamente cambian algunas variables y métodos que fueron adaptados a nuestro código.
*/

//Complejidad O(1)
template <class T>
void DoubleLinkedList<T>::deleteNode(Node<T> *del) {
    Node<T> *p = head; 
    // base case
    if (p == NULL || del == NULL)
        return;
    // If node to be deleted is head node
    if (p == del)
        p = del->next;
    // Change next only if node to be deleted
    // is NOT the last node
    if (del->next != NULL)
        del->next->prev = del->prev;
    // Change prev only if node to be deleted
    // is NOT the first node
    if (del->prev != NULL)
        del->prev->next = del->next;
    // Finally, free the memory occupied by del
    delete del;
    numElements--;
}

//Complejidad O(n^2)
template <class T>
void DoubleLinkedList<T>::removeDuplicates() {
    Node<T> *p = head;
    Node<T> *ptr1, *ptr2, *next;
    // if DLL is empty or if it contains only
    // a single node
    if (p == NULL || p->next == NULL)
      return;
    // pick elements one by one
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next) {
      ptr2 = ptr1->next;
        // Compare the picked element with the
        // rest of the elements
        while (ptr2 != NULL) {
            // if duplicate, then delete it
            if (ptr1->data == ptr2->data) {
                // store pointer to the node next to 'ptr2'
                next = ptr2->next;
                // delete node pointed to by 'ptr2'
                deleteNode(ptr2); 
                // update 'ptr2'
                ptr2 = next;
            }
            // else simply move to the next node
            else
                ptr2 = ptr2->next;
        }
    }
}
//link: https://www.geeksforgeeks.org/reverse-sublist-linked-list/

//Complejidad O(n)
template <class T>
T DoubleLinkedList<T>::operator[](const int position){
  T valor;
  try{
    if(position < 0 || position >= numElements){
      throw std::out_of_range("Elemento fuera de rango");
    }
    if (position == 0){
      return head->data;
      }
    Node<T> *p = head;
    int index = 0;
    while (p != NULL) {
      if (index == position)
        return p->data;
      index++;
      p = p->next;
    }
    return valor;
  }catch(const std::out_of_range &oor){
      std::cerr << "Error: " << oor.what() << std::endl;
      return valor;
  }
}

//Complejidad O(n)
template<class T>
void DoubleLinkedList<T>::operator=(DoubleLinkedList<T> &other) {
  this -> clear();
  Node<T> *p = other.getHead();
  while(p != NULL){//Complejidad O(n)
    this -> addLast(p->data);//Complejidad O(1)
    p = p->next; //O(1)
  }
}

//Complejidad O(n)
template <class T>
void DoubleLinkedList<T>::getReversedSublist(int start, int end, DoubleLinkedList<T> &other){
  if(end<start || start<0 || end > this->numElements){
    std::cout << "Límites erróneos o fuera de rango, intente con otros límites"<<std::endl;
  }else{
    Stack<T> list;
    Node<T> * p = head;
    int counter=0;
    while(counter<start){
      p=p->next;
      counter++;
    }
    while(counter<=end){
      if(p!=NULL){
      list.push(p->data);
      p = p->next;
      counter++;
      }else{
        break;
      }
    }
    
    counter = end - start;
    for(int i = 0; i<counter; i++){
      other.addLast(list.pop());
    }
  }
}

//Complejidad O(1)
template <class T>
void DoubleLinkedList<T>::swap (T * a, T * b ){ 
  T t = *a; *a = *b; *b = t; 
}

//Complejidad O(n)
template <class T>
Node<T>* DoubleLinkedList<T>::partition(Node<T> *l, Node<T> *h){
    // set pivot as h element
    T x = h->data;
 
    // similar to i = l-1 for array implementation
    Node<T> *i = l->prev;
 
    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (Node<T> *j = l; j != h; j = j->next)
    {
        if (j->data.getFecha() < x.getFecha() || j->data.getFecha() == x.getFecha() ){
            // Similar to i++ for array
            i = (i == NULL)? l : i->next;
 
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL)? l : i->next; // Similar to i++
    swap(&(i->data), &(h->data));
    return i;
}
 
/* A recursive implementation
of quicksort for linked list */

template <class T>
void DoubleLinkedList<T>::_quickSort(Node<T>* l, Node<T> *h){
    if (h != NULL && l != h && l != h->next)
    {
        Node<T> *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}


// The main function to sort a linked list.
// It mainly calls _quickSort()
template <class T>
void DoubleLinkedList<T>::quickSort(){
    Node<T> *p = head;
    // Find last node
    Node<T> *t = tail;
    // Call the recursive QuickSort
    _quickSort(p, t);
}

#endif