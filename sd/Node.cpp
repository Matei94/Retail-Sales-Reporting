#include <cstddef>

#include "Node.h"
#include "Tranzactie.h"
#include "Bon.h"
#include "Produs.h"
#include "Magazin.h"
#include "Categorie.h"

using namespace std;

template <typename T>
Node<T>::Node() {
  this->value = T();
  this->next = NULL;
}

template <typename T>
Node<T>::Node(T value) {
  //Node<T>(); NU E BINE! 

  this->value = value;
  this->next = NULL;
}

template <typename T>
Node<T>::Node(const Node<T>& nod) {
  this->value = nod.value;
  this->next  = nod.next;
}

template <typename T>
void Node<T>::operator=(const Node<T>& nod) {
  this->value = nod.value;
  this->next  = nod.next;
}

template <typename T>
Node<T>::~Node() {
  /* Do nothing */
}

template <typename T>
T Node<T>::getValue() {
  return this->value;
}

template <typename T>
Node<T> *Node<T>::getNext() {
  return this->next;
}

template <typename T>
void Node<T>::setValue(T newValue) {
  this->value = newValue;
}

template <typename T>
void Node<T>::setNext(Node<T>* nod) {
  this->next = nod;
}



//!!!!! AICI TREBUIE ADAUGAT CE O SA FOLOSIM, CE TIPURI DE DATE

template class Node<Tranzactie>;
template class Node<Produs>;
template class Node<Magazin>;
template class Node<Bon>;
template class Node<Categorie>;

//template class Node< struct elemInfo<string, int> >;
