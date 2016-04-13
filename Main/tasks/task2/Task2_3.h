#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../../headers/LinkedList.h"

#include "../../headers/Produs.h"
#include "../../headers/Bon.h"

using namespace std;

void task2_3(LinkedList<Bon>& listaBonuri, LinkedList<Produs>& listaProduse, string idBon){
	ofstream output ( "Rezultate.csv", ofstream::app );
	int nrProduse = 0, i;
	Node<Produs>* produs = listaProduse.front();
	string numeProdus;
	while (produs != NULL){
		nrProduse++;
		produs = produs->getNext();
	}
	//In produseCumparate[i] retin de cate ori a fost cumparat produsul cu id-ul i pe bonul dat
	int* produseCumparate = new int[nrProduse + 1];
	for (i = 0; i <= nrProduse; i++){
		produseCumparate[i] = 0;
	}
	Node<Bon>* bon = listaBonuri.front();
	while (bon != NULL){
		if (bon->getValue().getIdBon() == idBon){
			produseCumparate[bon->getValue().getIdProdus()]++;
		}
		bon = bon->getNext();
	}

	output<<"\n\nTask-ul 2_3:\n\n";

	output << "numar id_produs denumire_produs\n";
	for (i = 1; i <= nrProduse; i++){
		if (produseCumparate[i] > 0){
			produs = listaProduse.front();
			while (produs->getValue().getIdProdus() != i){
				produs = produs->getNext();
			}
			output << produseCumparate[i] << " " << produs->getValue().getIdProdus() << " " << produs->getValue().getNumeProdus() << "\n";
		}
	}

	delete[] produseCumparate;

	output.close();
}

