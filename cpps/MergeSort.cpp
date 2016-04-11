/* SortedMerge() */
template <typename T>
void LinkedList<T>::SortedMerge( LinkedList<T> left, LinkedList<T> right, LinkedList<T>& result ) {

  /* Conditiile de oprire: una dintre cele doua subliste este goala */
  if ( left.front() == NULL ) {
    right.reversePop( result );
  }
  else if ( right.front() == NULL ){
    left.reversePop( result );
  }

  /* Se aplica recurenta vietii mele si se compara timestamp-urile */ 
  if ( left.front()->getValue().getTimeStamp() >= right.front()->getValue().getTimeStamp() ) {
    
    T value = left.front()->getValue();
    left.removeFirst();
    this->SortedMerge( left, right, result );
    result.addLast( value );

    //result->setValue( left->getValue() );
    //result->setNext( SortedMerge( left->getNext(), right ) );
  } else {
    
    T value = right.front()->getValue();
    right.removeFirst();
    this->SortedMerge( left, right, result );
    result.addLast( value );

    //result->setValue( right->getValue() );
    //result->setNext( SortedMerge( left, right->getNext() ) );
  }
}


/* MergeSort() */
template <typename T>
LinkedList<T> LinkedList<T>::MergeSort( ) {
  Node<T>* head = this->front();
  LinkedList<T> left;
  LinkedList<T> right;

  /* Conditia de oprire: lista goala sau lista cu un singur element */
  if( (head == NULL) || (head->next == NULL) )
    return;

  /* Impartim listaCurenta in doua subliste: jumatatea stanga( left ) si jumatatea dreapta( righ ) */
  LeftRightSplit( head, left, right );

  /* Sortam recursiv cele doua subliste rezultate */
  left.MergeSort( );
  right.MergeSort( );

  /* Rezultatul va fi impreunarea celor doua subliste deja sortate */
  this->SortedMerge( left, right, result );

  return result;
}


/* LeftRightSplit() */
template <typename T>
void LinkedList<T>::LeftRightSplit( Node<T>* head, LinkedList<T>& left, LinkedList<T>& right ) {
    int numberOfNodes = this->numberOfNodes();
    int mid = numberOfNodes / 2;

    Node<T>* aux;
    aux = head;
    while ( mid ) {
      --mid;
      aux = aux->getNext();
    }
    right.pFirst = aux;

    left.pFirst = head; 
    aux = head;
    while ( mid - 1 ) {
      --mid;
      aux = aux->getNext();
    }
    left.pLast = aux;
    left.pLast->setNext( NULL );
}
