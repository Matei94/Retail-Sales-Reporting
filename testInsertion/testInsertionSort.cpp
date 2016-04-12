#include <iostream>

#include "LinkedList.h"
#include "Node.h"

int main() {

	LinkedList<int> lista;

	lista.addLast( 1 );
	lista.addLast( 4 );
	lista.addLast( 2 );
	lista.addLast( 3 );

	Node<int> *aux = lista.front();
	while ( aux != NULL ) {
		cout << aux->getValue() << ' ';
		aux = aux->getNext();
	}
	cout << '\n';

	lista.InsertionSort();

	aux = lista.front();
	while ( aux != NULL ) {
		cout << aux->getValue() << ' ';
		aux = aux->getNext();
	}
	cout << '\n';

	return 0;
}