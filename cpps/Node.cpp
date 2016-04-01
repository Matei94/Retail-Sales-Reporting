#include <cstddef>

#include "../headers/Node.h"

template <typename T>
Node<T>::Node() {
  this->value = 0;
  this->next = NULL;
}

template <typename T>
Node<T>::Node(T value) {
  Node<T>();
  this->value = value;
}

template <typename T>
Node<T>::Node(const Node<T>& n) {
  this->value = n.value;
  this->next  = n.next;
}

template <typename T>
void Node<T>::operator=(const Node<T>& n) {
  this->value = n.value;
  this->next  = n.next;
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
void Node<T>::setNext(Node<T>* n) {
  this->next = n;
}



//!!!!! AICI TREBUIE ADAUGAT CE O SA FOLOSIM, CE TIPURI DE DATE

template class Node<int>;
template class Node<float>;
