#ifndef __Task3_H_
#define __Task3_H_

#include <iostream>
#include <fstream>
#include <string>

#include "Bon.h"
#include "Tranzactie.h"
#include "LinkedList.h"
#include "InsertionSort.h"


void task3_3 ( LinkedList<Tranzactie> listaTranzactii ) {
	/* Se sorteaza lista de tranzactii in functie de timeStamp-ul fiecarui element */
	InsertionSort( listaTranzactii );

	Node<Tranzactie>* aux = listaTranzactii.front();
	while ( aux != NULL ) {
		cout << aux->getValue().getTimeStamp() << '\n';
		aux = aux->getNext();
	}

}

#endif // __Task3_H_