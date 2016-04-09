#include <cstddef>
#include <stdio.h>

#include "LinkedList.h"
#include "Bon.h"
#include "Magazin.h"
#include "Produs.h"
#include "Tranzactie.h"
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
  struct listElem<T> *aux = pFirst;

  while (aux != NULL) {
    struct listElem<T> *next = aux->next;
    delete aux;
    aux = next;
  }
}

template <typename T>
void LinkedList<T>::addFirst(T value) {
  struct listElem<T> *n;
  n->info = value;

  if (isEmpty()) {
    this->pFirst = n;
    this->pLast  = n;
  } else {
    n->next = this->pFirst;
    this->pFirst = n;
  }
}

template <typename T>
void LinkedList<T>::addLast(T value) {
  struct listElem<T> *n;
  n->info = value;

  if (isEmpty()) {
    this->pFirst = n;
    this->pLast  = n;
  } else {
    this->pLast->next = n;
    this->pLast = n;
  }
}

template <typename T>
T LinkedList<T>::removeFirst(){
  struct listElem<T> *paux;

  if (pFirst != NULL) {
    paux = pFirst->next;
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
bool LinkedList<T>::isEmpty() {
  return pFirst == NULL;
}

template <typename T>
listElem<T>* LinkedList<T>::front() {
        return pFirst;
    }

template <typename T>
int LinkedList<T>::numberOfNodes() {
  int count = 0;
  struct listElem<T> *aux = pFirst;
  if (isEmpty()) {
    return 0;    
  }
  while ( aux != NULL) {
    count++;
    aux = aux->next;
  }
  return count;
}
template class LinkedList<int>;
template class LinkedList<Bon>;
template class LinkedList<Magazin>;
template class LinkedList<Produs>;
template class LinkedList<Tranzactie>;
// template class LinkedList< Node<int> >;

