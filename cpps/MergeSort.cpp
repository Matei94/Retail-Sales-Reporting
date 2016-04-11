/* MergeSort() */
template <typename T>
Node<T>* LinkedList<T>::MergeSort( ) {
  Node<T>* head = this->front();
  LinkedList<T> left;
  LinkedList<T> right;

  /* Conditia de oprire: lista goala sau lista cu un singur element */
  if( (head == NULL) || (head->getNext() == NULL) )
    return;

  /* Impartim listaCurenta in doua subliste: jumatatea stanga( left ) si jumatatea dreapta( righ ) */
  this->LeftRightSplit( head, left, right );

  /* Sortam recursiv cele doua subliste rezultate */
  left.MergeSort( );
  right.MergeSort( );

  /* Rezultatul va fi impreunarea celor doua subliste deja sortate */
  this->pFirst = SortedMerge( left, right, result ).front();

  return this;
}


/* SortedMerge() */
template <typename T>
LinkedList<T> SortedMerge( LinkedList<T> left, LinkedList<T> right ) {

  /* Conditiile de oprire: una dintre cele doua subliste este goala */
  if ( left.front() == NULL ) {
    //Node<T> *aux = right.front();

/*
    while ( right.front() != NULL ) {
      result.addLast( right.front()->getValue() );
      right.removeFirst();
    }
*/
    cout << "return right\n";

    return right;
  }
  else if ( right.front() == NULL ){
    //Node<T> *aux = left.front();


    /*
    while ( left.front() != NULL ) {
      result.addLast( left.front()->getValue() );
      left.removeFirst();
    }
    */

    cout << "return left\n";

    return left;
  }


  cout << "plm\n";


  /* Se aplica recurenta vietii mele si se compara timestamp-urile */ 
  if ( left.front()->getValue() <= right.front()->getValue() ) {
    
    T value = left.front()->getValue();
    left.removeFirst();

    return addNodeToList( value, SortedMerge( left, right ) );

    cout << "m-am intors din left\n";

    //result->setValue( left->getValue() );
    //result->setNext( SortedMerge( left->getNext(), right ) );
  } else {
    
    T value = right.front()->getValue();
    right.removeFirst();
    
    return addNodeToList( value, SortedMerge( left, right ) );

    cout << "m-am intors din right\n";

    //result->setValue( right->getValue() );
    //result->setNext( SortedMerge( left, right->getNext() ) );
  }
}




