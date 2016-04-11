#include <cstddef>
#include <iostream>
#include <string>

#include "../headers/LinkedList.h"
//#include "../headers/Palet.h"
//#include "../headers/Produs.h"
#include "../headers/Tranzactie.h"

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

  cout << "plm\n";

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
  cout << endl;
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

template <typename T>
void LinkedList<T>::reversePop( LinkedList<T>& result ) {
  if ( this->pFirst == NULL )
    return;

  T value = this->pFirst->getValue();
  this->removeFirst();

  this->reversePop( result );
  
  result.addLast( value );
}







template class LinkedList<int>;
//template class LinkedList<Palet>;
//template class LinkedList<Produs>;
template class LinkedList<Tranzactie>;
// template class LinkedList< Node<int> >;
