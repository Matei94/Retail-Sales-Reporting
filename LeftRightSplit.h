#ifndef __LeftRightSplit_H_
#define __LeftRightSplit_H_

#include <iostream>

#include "LinkedList.h"

using namespace std;

/* LeftRightSplit() -> imparte lista curenta in doua subliste echilibrate: left si right */
template <typename T>
void LeftRightSplit( Node<T>* head, LinkedList<T>& left, LinkedList<T>& right ) {
    int numberOfNodes = head->numberOfNodes();
    int mid = numberOfNodes / 2;

    Node<T>* aux;
    aux = head;
    while ( mid ) {
      --mid;
      left.addLast( aux->getValue() );
      aux = aux->getNext();
    }

    right.pFirst = aux;
}

#endif // __LeftRightSplit_H_