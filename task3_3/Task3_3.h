#ifndef __Task3_H_
#define __Task3_H_

#include <iostream>
#include <fstream>
#include <string>

#include "Bon.h"
#include "Tranzactie.h"
#include "LinkedList.h"
#include "InsertionSort.h"

#define 

using namespace std;

void task3_3 ( LinkedList<Tranzactie> listaTranzactii, LinkedList<Bon> listaBonuri, int nrProduse,  ) {
	/* Se sorteaza lista de tranzactii in functie de timeStamp-ul fiecarui element */
	InsertionSort( listaTranzactii );


	/* cantMagActuala - "vector" de frecventa ce retine cantitatea de produse de tip j, care se gaseste in magazinul cu id-ul i */
	unsigned int cantMag[NR_MAGAZINE + 3][nrProduse + 3] = { 0 };
	/* cantMag - acelasi lucru, dar vorbim despre cantitatea initiala, de la aprovizionare */
	unsigned int cantMagActuala[NR_MAGAZINE][nrProduse] = { 0 };


	/* Se initializeaza cele doua matrice, cu elementele din hashtableul hashCantitati */
	for ( int i = 1; i <= NR_MAGAZINE; ++i ) {
		for ( int j = 1; j <= nrProduse; ++j ) {
				
		}
	}


	/* Se parcurge lista de tranzactii cu un iterator */
	Node<Tranzactie> *itTran = listaTranzactii.front();

	while ( itTran != NULL ) {

		/* currentTransaction - retine valoarea elementului curent din lista */
		Tranzactie currentTransaction = itTran->getValue();

		/* Se extrage id-ul bonului tranzactiei curente */
		string idBon = currentTransaction.getIdBon();

		/* Se parcurge lista de bonuri in cautarea idBon-ului extras anterior */
		Node<Bon> *itBon = listaBonuri.front();

		while ( itBon != NULL ) {

			/* Daca se gaseste bonul cautat */
			if ( idBon == itBon.getIdBon() ) {
				/* Se extrage idProdus-ul aferent bonului curent */
				int idProdus = itBon.getIdProdus();


				break;
			}

			/* daca nu, se cauta mai departe */
			itBon = itBon->getNext();
		}

		/* Se muta pointerul asupra urmatorului element din lista de Tranzactii */
		itTran = itTran->getNext();
	}

}

#endif // __Task3_H_