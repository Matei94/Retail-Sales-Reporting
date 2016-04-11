#ifndef __SortedMerge_H_
#define __SortedMerge_H_

#include <iostream>

#include "LinkedList.h"

using namespace std;

/*
template <typename T>
LinkedList<T> addNodeToList( T value, LinkedList<T> list ) {
  list.addFirst( value );
  return list;
}
*/


/* SortedMerge() */
template <typename T>
void SortedMerge( LinkedList<T>& left, LinkedList<T>& right, LinkedList<T>& result ) {

  /* Conditiile de oprire: una dintre cele doua subliste este goala */
  if ( left.front() == NULL ) {
    //Node<T> *aux = right.front();
 
    while ( right.front() != NULL ) {
      result.addLast( right.front()->getValue() );
      right.removeFirst();
    }
    //cout << "return right\n";

    return;
  }
  else if ( right.front() == NULL ){
    //Node<T> *aux = left.front();

    while ( left.front() != NULL ) {
      result.addLast( left.front()->getValue() );
      left.removeFirst();
    }
    //cout << "return left\n";

    return;
  }


  cout << "plm\n";


  /* Se aplica recurenta vietii mele si se compara timestamp-urile */ 
  if ( left.front()->getValue() <= right.front()->getValue() ) {
    
    T value = left.front()->getValue();
    left.removeFirst();
    result.addLast( value );

    SortedMerge( left, right, result );

    //result.addFirst( value );

    cout << "plm_left\n";

    Node<T> *aux = result.front();

/*
    while ( aux != NULL ) {
      cout << aux->getValue() << ' ';
      aux = aux->getNext();
    }
*/

    //result->setValue( left->getValue() );
    //result->setNext( SortedMerge( left->getNext(), right ) );
  } else {
    
    T value = right.front()->getValue();
    right.removeFirst();
    
    SortedMerge( left, right, result );

    result.addFirst( value );

    cout << "plm_right\n";

    //result->setValue( right->getValue() );
    //result->setNext( SortedMerge( left, right->getNext() ) );
  }

}

#endif // __SortedMerge_H_