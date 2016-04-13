#ifndef __Task3_H_
#define __Task3_H_

#include <iostream>
#include <fstream>
#include <string>

#include "../../headers/Bon.h"
#include "../../headers/Tranzactie.h"
#include "../../headers/LinkedList.h"
#include "../../headers/InsertionSort.h"
#include "../../headers/Produs.h"
#include "../../headers/Hashtable.h"

#define NR_MAGAZINE 5

using namespace std;

void task3_3 ( LinkedList<Tranzactie>& listaTranzactii, LinkedList<Bon>& listaBonuri, int nrProduse, Hashtable<int, int>& hashCantitati, LinkedList<Produs>& listaProduse ) {

	ofstream output ( "Rezultate.csv", ofstream::app );

	/* Se sorteaza lista de tranzactii in functie de timeStamp-ul fiecarui element */
	InsertionSort( listaTranzactii );


	/* cantMagActuala - "vector" de frecventa ce retine cantitatea de produse de tip j, care se gaseste in magazinul cu id-ul i */
	int cantMag[NR_MAGAZINE + 3][nrProduse + 3];
	/* cantMag - acelasi lucru, dar vorbim despre cantitatea initiala, de la aprovizionare */
	int cantMagActuala[NR_MAGAZINE + 3][nrProduse + 3];


	/* Se initializeaza cele doua matrice, cu elementele din hashtableul hashCantitati */
	for ( int i = 1; i <= NR_MAGAZINE; ++i ) {
		for ( int j = 1; j <= nrProduse; ++j ) {
			hashCantitati.getLast( j, cantMag[i][j] );
			hashCantitati.getLast( j, cantMagActuala[i][j] );
		}
	}

	/* gasitPalet - retine daca a avut sau nu loc gasirea paletului in sloturi */
	bool gasitPalet = true;

	output << "\n\nTask-ul 3_3:\n\n";

	/* Se parcurge lista de tranzactii cu un iterator */
	Node<Tranzactie> *itTran = listaTranzactii.front();
	while ( itTran != NULL && gasitPalet ) {

		/* currentTransaction - retine valoarea elementului curent din lista */
		Tranzactie currentTransaction = itTran->getValue();

		/* Se extrage id-ul bonului tranzactiei curente */
		string idBon = currentTransaction.getIdBon();

		/* Se extrage id-ul magazinului tranzactiei curente */
		int idMagazin = currentTransaction.getIdMagazin();

		/* Se parcurge lista de bonuri in cautarea idBon-ului extras anterior */
		Node<Bon> *itBon = listaBonuri.front();
		while ( itBon != NULL ) {

			/* Daca se gaseste bonul cautat */
			if ( idBon == itBon->getValue().getIdBon() ) {
				
				/* Se extrage idProdus-ul aferent bonului curent */
				int idProdus = itBon->getValue().getIdProdus();

				/* Se scade stocul actual corespunzator tipului de produs din magazinul respectiv */
				--cantMagActuala[ idMagazin ][ idProdus ];

				/* Se verifica daca este necesara o reaprovizionare */
				if ( cantMagActuala[ idMagazin ][ idProdus ] <= cantMag[ idMagazin ][ idProdus ] / 10 ) {

					/* cantitate - cantitatea paletului ce va fi extras din stiva */
					int cantitate = 0;

					/* Se cauta paletul in stiva */
					gasitPalet = hashCantitati.getLast( idProdus, cantitate );

					/* Daca nu se gaseste paletul, mission accomplished sau failed. Depinde cum o iei... */
					if ( !gasitPalet ) {
						/* numeProdus - numele produsului a carui comanda nu se mai poate onora */
						string numeProdus;

						/* Se parcurge lista de produse, ca sa facem match-ul dintre idProd si numeProdus */
						Node<Produs> *itProd = listaProduse.front();
						while ( itProd != NULL ) {
							/* Daca se descopera ce nume are produsul: */
							if ( itProd->getValue().getIdProdus() == idProdus )
								numeProdus = itProd->getValue().getNumeProdus();

							itProd = itProd->getNext();
						}

						output << "Comanda nu a putut fi onorata! Nu mai exista niciun palet ce contine " << numeProdus << " in depozit. Ne pare rau!\n";

						break;
					}

					/* Se updateaza fiecare cantitate */
					cantMag[ idMagazin ][ idProdus ] = cantMagActuala[ idMagazin ][ idProdus ] + cantitate;
					cantMagActuala[ idMagazin ][ idProdus ] += cantitate;

				} 

				/* Am gasit, deci nu cautam mai departe. Ne intoarcem in lista de tranzactii. Adev! */
				break;
			}

			/* daca nu, se cauta mai departe */
			itBon = itBon->getNext();
		}

		/* Se muta pointerul asupra urmatorului element din lista de Tranzactii */
		itTran = itTran->getNext();
	}

	output.close();
}

#endif // __Task3_H_

