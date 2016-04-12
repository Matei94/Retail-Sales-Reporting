#include <cstddef>
#include <stdio.h>
#include "Tranzactie.h"
#include "LinkedList.h"
#include "Produs.h"
#include "Magazin.h"
#include "Bon.h"
#include "Categorie.h"

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


/* MergeSort for LinkedList */

/* LeftRightSplit() */
//template <typename T>
//void LinkedList<T>::LeftRightSplit( Node<T>* head, Node<T>** left, Node<T>** right ) {
  /* numberOfNodes = numarul de noduri din lista initiala, data prin head */
/*  int numberOfNodes = 0;
    
    Node<T>* aux = head;
    /* Numaram nodurile. Csf? N-ai csf... */ 
/*    while ( aux != NULL) {
      numberOfNodes++;
      aux = aux->getNext();
    }
    int mid = numberOfNodes / 2;
    aux = head;
    while ( mid ) {
      --mid;
      aux = aux->getNext();
    }
    *right = aux;
    *left = head; 
    while ( mid - 1 ) {
      *left = head->getNext();
    }
    *left->setNext( NULL );
}
*/
/* SortedMerge() */
/*template <typename T>
Node<T>* LinkedList<T>::SortedMerge( Node<T>* left, Node<T>* right ) {
  Node<T>* result;
  /* Conditiile de oprire: una dintre cele doua subliste este goala */
 /* if ( left == NULL )
    return right;
  else if ( right == NULL )
    return left;
  /* Se aplica recurenta vietii mele si se compara timestamp-urile */ 
 /* if ( left->getValue().getTimeStamp() <= right->getValue().getTimeStamp() ) {
    result->setValue( left->getValue() );
    result->setNext( SortedMerge( left->getNext(), right ) );
  } else {
    result->setValue( right->getValue() );
    result->setNext( SortedMerge( left, right->getNext() ) );
  }
}
/* MergeSort() */
/*template <typename T>
Node<T>* LinkedList<T>::MergeSort( ) {
  Node<T>* head = this->front();
  Node<T>* left;
  Node<T>* right;
  /* Conditia de oprire: lista goala sau lista cu un singur element */
 /* if( (head == NULL) || (head->next == NULL) )
    return;
  /* Impartim listaCurenta in doua subliste: jumatatea stanga( left ) si jumatatea dreapta( righ ) */
 // LeftRightSplit( head, &left, &right );

  /* Sortam recursiv cele doua subliste rezultate */
 // left.MergeSort( );
 // right.MergeSort( );

  /* Rezultatul va fi impreunarea celor doua subliste deja sortate */
 // return SortedMerge( left, right );


template class LinkedList< Tranzactie >;
template class LinkedList< Produs >;
template class LinkedList< Bon >;
template class LinkedList< Magazin >;
template class LinkedList<Categorie>;

// template class LinkedList< Node<int> >;