#include <iostream>

#include "../headers/citireTranzactii.h"
#include "../headers/LinkedList.h"
#include "../headers/Tranzactie.h"

using namespace std;

int main( ) {
	
	LinkedList<Tranzactie> listaTranzactii;
	citireTranzactii( listaTranzactii );

	listaTranzactii.MergeSort();

	//listaTranzactii.printList();

	return 0;
}