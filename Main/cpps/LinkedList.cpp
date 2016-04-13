#include <cstddef>
#include <stdio.h>

#include "../headers/LinkedList.h"

#include "../headers/Tranzactie.h"
#include "../headers/Palet.h"
#include "../headers/Produs.h"
#include "../headers/Magazin.h"
#include "../headers/Bon.h"
#include "../headers/Categorie.h"

using namespace std;


template <typename T>
LinkedList<T>::LinkedList() {
  this->pFirst = NULL;
  this->pLast  = NULL;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& l) {
  if (l.pFirst == NULL) {
    this->pFirst = NULL;
    this->pLast = NULL;
    return;
  }

  // cu asta ne plimbam in l
  Node<T> *iterator = l.pFirst;

  // primul element din noua lista
  this->pFirst = new Node<T>(*iterator);

  // cu asta ne plimbam in lista noua;
  Node<T> *current = this->pFirst;

  // avansam
  iterator = iterator->getNext();

  // copia nodului la care pointeaza iterator
  Node<T> *copy;
  while (iterator != NULL) {
    copy = new Node<T>(*iterator);
    current->setNext(copy);
    current = copy;
    iterator = iterator->getNext();
  }

  // setam pLast
  this->pLast = copy;
}

template <typename T>
void LinkedList<T>::operator=(const LinkedList<T>& l) {
  if (l.pFirst == NULL) {
    this->pFirst = NULL;
    this->pLast = NULL;
    return;
  }

  // cu asta ne plimbam in l
  Node<T> *iterator = l.pFirst;

  // primul element din noua lista
  this->pFirst = new Node<T>(*iterator);

  // cu asta ne plimbam in lista noua;
  Node<T> *current = this->pFirst;

  // avansam
  iterator = iterator->getNext();

  // copia nodului la care pointeaza iterator
  Node<T> *copy;
  while (iterator != NULL) {
    copy = new Node<T>(*iterator);
    current->setNext(copy);
    current = copy;
    iterator = iterator->getNext();
  }

  // setam pLast
  this->pLast = copy;
}

template <typename T>
LinkedList<T>::~LinkedList() {
  Node<T> *aux;
  Node<T> *next;
  aux = pFirst;

  while (aux != NULL) {
    next = aux->getNext();
    delete aux;
    aux = next;
  }

  pFirst = pLast = NULL;
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
void LinkedList<T>::removeFirst(){
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
/*template <typename T>
void LinkedList<T>::printList() {
  Node<T> *aux = pFirst;
  while (aux != NULL) {
    cout << aux->getValue() << ", ";
    aux = aux->getNext();
  }
  cout << endl;
}*/

template <typename T>
bool LinkedList<T>::isEmpty() {
  return pFirst == NULL;
}

template <typename T>
Node<T>* LinkedList<T>::last() {
  return pLast;
}

template <typename T>
Node<T>* LinkedList<T>::front() {
        return pFirst;
    }

template <typename T>
int LinkedList<T>::numberOfNodes() {
  int count = 0;
  Node<T> *aux = pFirst;
  
  /*
  If-ul asta-i degeaba. count e deja 0, iar daca nu intra in while, se returneaza count = 0, ceea ce-i super.
  if (isEmpty()) {
    return 0;    
  }
  */

  while ( aux != NULL) {
    count++;
    aux = aux->getNext();
  }
  return count;
}

template <typename T>
void LinkedList<T>::insertElement( T value, Node<T> *position ) {
  Node<T> *next = position->getNext();
  Node<T> *element = new Node<T>(value);

  position->setNext( element );
  element->setNext( next );
}

template class LinkedList<int>;
template class LinkedList<string>;
template class LinkedList<Palet>;
template class LinkedList< Tranzactie >;
template class LinkedList< Produs >;
template class LinkedList< Bon >;
template class LinkedList< Magazin >;
template class LinkedList<Categorie>;