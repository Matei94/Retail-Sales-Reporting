#include <cstddef>
#include <stdio.h>

#include "../headers/LinkedList.h"

using namespace std;

template <typename T>
LinkedList<T>::LinkedList() {
  this->pFirst = NULL;
  this->pLast  = NULL;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& l) {
  this->pFirst = l.pFirst;
  this->pLast  = l.pLast;
}

template <typename T>
void LinkedList<T>::operator=(const LinkedList<T>& l) {
  this->pFirst = l.pFirst;
  this->pLast  = l.pLast;
}

template <typename T>
LinkedList<T>::~LinkedList() {
  Node<T> *aux = pFirst;

  while (aux != NULL) {
    Node<T> *next = aux->getNext();
    delete aux;
    aux = next;
  }
}

template <typename T>
void LinkedList<T>::addFirst(T value) {
  Node<T> *n = new Node<T>(value);

  if (isEmpty()) {
    this->pFirst = n;
    this->pLast  = n;
  } else {
    n->setNext(this->pFirst);
    this->pFirst = n;
  }
}

template <typename T>
void LinkedList<T>::addLast(T value) {
  Node<T> *n = new Node<T>(value);

  if (isEmpty()) {
    this->pFirst = n;
    this->pLast  = n;
  } else {
    this->pLast->setNext(n);
    this->pLast = n;
  }
}

template <typename T>
T LinkedList<T>::removeFirst(){
  struct Node<T>* paux;

  if (pFirst != NULL) {
    paux = pFirst->getNext();
    if (pFirst == pLast) pLast = NULL;
    delete pFirst;
    pFirst = paux;
  }
  else fprintf(stderr, "Error 101 - The list is empty\n"); 
}
/*
template <typename T>
T LinkedList<T>::removeLast(){}

template <typename T>
T LinkedList<T>::removeFirstOccurrence(T value){}

template <typename T>
T LinkedList<T>::removeLastOccurrence(T value){}
*/
template <typename T>
void LinkedList<T>::printList() {
  Node<T> *aux = pFirst;

  while (aux != NULL) {
    cout << aux->getValue() << ", ";
    aux = aux->getNext();
  }
  cout << endl;
}

template <typename T>
bool LinkedList<T>::isEmpty() {
  return pFirst == NULL;
}

template <typename T>
Node<T>* LinkedList<T>::front() {
        return pFirst;
    }

template class LinkedList<int>;