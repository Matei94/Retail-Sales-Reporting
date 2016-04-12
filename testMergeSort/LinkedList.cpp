#include <cstddef>
#include <iostream>
#include <string>
#include <stdio.h>
#include <ostream>
#include <fstream>

#include "LinkedList.h"
#include "SortedMerge.h"
#include "LeftRightSplit.h"
//#include "../headers/Palet.h"
//#include "../headers/Produs.h"
//#include "../headers/Tranzactie.h"

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

  if ( isEmpty() ) {
    this->pFirst = n;
    this->pLast  = n;
  } else {
    this->pLast->setNext(n);
    this->pLast = n;
  }
}

template <typename T>
void LinkedList<T>::removeFirst() {
  struct Node<T>* paux;

  if (pFirst != NULL) {
    paux = pFirst->getNext();
    if (pFirst == pLast) 
        pLast = NULL;
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

/*
template <typename T>
void LinkedList<T>::printList() {
  Node<T> *aux = pFirst;

  while (aux != NULL) {
    cout << aux->getValue() << ", ";
    aux = aux->getNext();
  }
  cout << '\n';
}
*/

template <typename T>
bool LinkedList<T>::isEmpty() {
  return pFirst == NULL;
}

template <typename T>
Node<T>* LinkedList<T>::front() {
  return pFirst;
}

template <typename T>
int LinkedList<T>::numberOfNodes() {
  int count = 0;
  Node<T> *aux = pFirst;

  while ( aux != NULL ) {
    count++;
    aux = aux->getNext();
  }

  return count;
}

template <typename T>
void LinkedList<T>::setFirst( Node<T> *first ) {
  this->pFirst = first;
}

template <typename T>
void LinkedList<T>::setLast( Node<T> *last ) {
  this->pLast = last;
}

/* MergeSort for LinkedList */

/* reversePop() -> returneaza in lista result, in ordine inversa, elementele listei curente */
template <typename T>
void LinkedList<T>::reversePop( LinkedList<T>& result ) {
  Node<T> *aux = pFirst;

  while ( aux != NULL ) {
    T val = aux->getValue();
    aux = aux->getNext();
    result.addFirst( val );
  }

}

/* MergeSort() */
template <typename T>
void LinkedList<T>::MergeSort( ) {
  Node<T>* head = this->front();
  LinkedList<T> left;
  LinkedList<T> right;
  LinkedList<T> result;

  /* Conditia de oprire: lista goala sau lista cu un singur element */
  if( (head == NULL) || (head->getNext() == NULL) )
    return;

/*
  cout << "MergeSort\n";

  Node<T>* h_left = this->front();

  while ( h_left != NULL ) {
    cout << h_left->getValue() << ' ';
    h_left = h_left->getNext();
  }
  cout << '\n';  
*/

  /* Impartim listaCurenta in doua subliste: jumatatea stanga( left ) si jumatatea dreapta( right ) */
  LeftRightSplit( this->front(), left, right );


  /* Sortam recursiv cele doua subliste rezultate */
  left.MergeSort( );
  right.MergeSort( );

  /* Rezultatul va fi impreunarea celor doua subliste deja sortate */
  SortedMerge( left, right, result);

  this->pFirst = result.pFirst;
  this->pLast = result.pLast;
}

template class LinkedList<int>;
//template class LinkedList<Palet>;
//template class LinkedList<Produs>;
//template class LinkedList<Tranzactie>;
// template class LinkedList< Node<int> >;
