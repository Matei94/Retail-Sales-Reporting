#include <iostream>

//#include "../headers/citireTranzactii.h"
#include "../headers/LinkedList.h"
#include "../headers/SortedMerge.h"
//#include "../headers/Tranzactie.h"

using namespace std;

int main( ) {
	
	LinkedList<int> listaTranzactii;
	LinkedList<int> res_ma_ta;
	LinkedList<int> left;
	LinkedList<int> right;
	LinkedList<int> ma_ta;

	//citireTranzactii( listaTranzactii );
	//listaTranzactii.MergeSort();


	listaTranzactii.addLast( 5 );
	listaTranzactii.addLast( 4 );
	listaTranzactii.addLast( 3 );
	listaTranzactii.addLast( 2 );
	listaTranzactii.addLast( 1 );
	listaTranzactii.addLast( 0 ); 


	listaTranzactii.MergeSort();

/*
	Node<int> *aux = listaTranzactii.front();

	while ( aux != NULL ) {
		cout << aux->getValue() << " ";
		aux = aux->getNext();
	}
	cout << '\n';


	listaTranzactii.reversePop( res_ma_ta );

	cout << res_ma_ta.numberOfNodes() << '\n';

	aux = res_ma_ta.front();

	while ( aux != NULL ) {
		cout << aux->getValue() << ' ';
		aux = aux->getNext();
	}
	cout << '\n';



	res_ma_ta.LeftRightSplit( res_ma_ta.front(), left, right );

	aux = left.front();
	while ( aux != NULL ) {
		cout << aux->getValue() << " ";	
		aux = aux->getNext();
	}
	cout << '\n';

	aux = right.front();
	while ( aux != NULL ) {
		cout << aux->getValue() << " ";	
		aux = aux->getNext();
	}
	cout << '\n';



	SortedMerge( left, right, ma_ta );

	aux = ma_ta.front();
	while ( aux != NULL ) {
		cout << aux->getValue() << " ";	
		aux = aux->getNext();
	}
	cout << '\n';	
*/

	return 0;
}