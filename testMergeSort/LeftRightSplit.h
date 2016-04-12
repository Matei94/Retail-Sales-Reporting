#ifndef __LeftRightSplit_H_
#define __LeftRightSplit_H_

#include <iostream>

#include "LinkedList.h"

using namespace std;

/* LeftRightSplit() -> imparte lista curenta in doua subliste echilibrate: left si right */
template <typename T>
void LeftRightSplit( Node<T>* head, LinkedList<T>& left, LinkedList<T>& right ) {
    int numberOfNodes = 0;
    Node<T> *aux = head;

    while ( aux != NULL ) {
      numberOfNodes++;
      aux = aux->getNext();
    }

    int mid = numberOfNodes / 2;


    aux = head;
    while ( mid ) {
      --mid;
      left.addLast( aux->getValue() );
      aux = aux->getNext();
    }

    right.setFirst( aux );

  Node<T>* h_left = left.front();

  while ( h_left != NULL ) {
    cout << h_left->getValue() << ' ';
    h_left = h_left->getNext();
  }
  cout << '\n';


  Node<T>* h_right = right.front();

  while ( h_left != NULL ) {
    cout << h_left->getValue() << ' ';
    h_left = h_left->getNext();
  }
  cout << '\n';

}

#endif // __LeftRightSplit_H_