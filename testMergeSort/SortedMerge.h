#ifndef __SortedMerge_H_
#define __SortedMerge_H_

#include <iostream>

#include "LinkedList.h"

using namespace std;


/* SortedMerge() */
template <typename T>
void SortedMerge( LinkedList<T>&left, LinkedList<T> right, LinkedList<T>& result ) {

  /* Conditiile de oprire: una dintre cele doua subliste este goala */
  if ( left.front() == NULL ) {
    //Node<T> *aux = right.front();
 
    result = right;

 /*
    while ( right.front() != NULL ) {
      result.addLast( right.front()->getValue() );
      right.removeFirst();
    }
  */
    //cout << "return right\n";

    return;
  }
  else if ( right.front() == NULL ){
    //Node<T> *aux = left.front();

    result = left;

/*
    while ( left.front() != NULL ) {
      result.addLast( left.front()->getValue() );
      left.removeFirst();
    }
    //cout << "return left\n";
  */

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
  } else {
    
    T value = right.front()->getValue();
    right.removeFirst();
    result.addLast( value );
    
    SortedMerge( left, right, result );
  }

}

#endif // __SortedMerge_H_