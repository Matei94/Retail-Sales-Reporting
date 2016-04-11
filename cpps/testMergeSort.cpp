#include <iostream>

#include "../headers/citireTranzactii.h"
#include "../headers/LinkedList.h"
#include "../headers/Tranzactie.h"

using namespace std;

int main( ) {
	
	LinkedList<int> listaTranzactii, result;
	//citireTranzactii( listaTranzactii );
	//listaTranzactii.MergeSort();


	listaTranzactii.addFirst( 3 );
	listaTranzactii.addFirst( 2 );
	listaTranzactii.addFirst( 1 );

	listaTranzactii.reversePop( result );

	Node<int> *aux = result.front();
	while ( aux != NULL ) {
		cout << aux->getValue() << " ";	
	}

	//listaTranzactii.printList();

	return 0;
}