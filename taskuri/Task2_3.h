#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include "../headers/LinkedList.h"

using namespace std;

void task2_3(LinkedList<Bon> listaBonuri, LinkedList<Produs> listaProduse, string idBon){
	ofstream output ("Task2_3.out");
	int nrProduse = 0, i;
	Produs* produs = listaProduse.front();
	string numeProdus;
	while (produs != NULL){
		nrProduse++;
		produs = produs->getNext();
	}
	//In produseCumparate[i] retin de cate ori a fost cumparat produsul cu id-ul i pe bonul dat
	int* produseCumparate = new int[nrProduse + 1];
	Bon* bon = listaBonuri.front();
	while (bon != NULL){
		if (bon.getIdBon() == idBon){
			produseCumparate[bon.getIdProdus()]++;
		}
		bon = bon->getNext();
	}

	output << "Pe bonul cu id-ul " << idBon << " au fost cumparate:\n";
	for (i = 1; i <= nrProduse; i++){
		if (produseCumparate[i] > 0){
			produs = listaProduse.front();
			while (produs.getIdProdus() != i){
				produs = produs->getNext();
			}
			cout << produseCumparate[i] << " X " << produs.getNumeProdus() << "\n";
		}
	}

	output.close();
}
