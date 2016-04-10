#include "../headers/Tranzactie.h"
#include "../headers/LinkedList.h"
#include "../headers/citireTranzactii.h"
#include "../headers/Node.h"

/* MergeSort for LinkedList */

/* LeftRightSplit() */
template <typename T>
void LinkedList<T>::LeftRightSplit( Node<T>* head, Node<T>** left, Node<T>** right ) {
	/* numberOfNodes = numarul de noduri din lista initiala, data prin head */
	int numberOfNodes = 0;
  	
  	Node<T>* aux = head;
  	/* Numaram nodurile. Csf? N-ai csf... */ 
  	while ( aux != NULL) {
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
  		--mid;
  		*left = head->getNext();
		mid--;
  	}
  	*left->setNext( NULL );
}


/* SortedMerge() */
template <typename T>
Node<T>* LinkedList<T>::SortedMerge( Node<T>* left, Node<T>* right ) {
	Node<T>* result;

	/* Conditiile de oprire: una dintre cele doua subliste este goala */
	if ( left == NULL )
		return right;
	else if ( right == NULL )
		return left;

	/* Se aplica recurenta vietii mele si se compara timestamp-urile */	
	if ( left->getValue().getTimeStamp() <= right->getValue().getTimeStamp() ) {
		result->setValue( left->getValue() );
		result->setNext( SortedMerge( left->getNext(), right ) );
	} else {
		result->setValue( right->getValue() );
		result->setNext( SortedMerge( left, right->getNext() ) );
	}
}


/* MergeSort() */
template <typename T>
void LinkedList<T>::MergeSort( LinkedList<T>& currentList ) {
	Node<T>* head = currentList.front();
	Node<T>* left;
	Node<T>* right;

	/* Conditia de oprire: lista goala sau lista cu un singur element */
	if( (head == NULL) || (head->next == NULL) )
		return;

	/* Impartim listaCurenta in doua subliste: jumatatea stanga( left ) si jumatatea dreapta( righ ) */
	LeftRightSplit( head, &left, &right );

	/* Sortam recursiv cele doua subliste rezultate */
	MergeSort( &left );
	MergeSort( &right );

	/* Rezultatul va fi impreunarea celor doua subliste deja sortate */
	currentList = SortedMerge( left, right );
}

