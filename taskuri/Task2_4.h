#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

#include "LinkedList.h"

#include "Magazin.h"
#include "Tranzactie.h"

using namespace std;

void task2_4(LinkedList<Tranzactie> listaTranzactii, LinkedList<Magazin> listaMagazine){
	ofstream output ("Task2_4.out");
	Node<Tranzactie>* tranzactie = listaTranzactii.front();
	int nrMagazine = 0, i;
	Node<Magazin>* magazin = listaMagazine.front();
	while (magazin != NULL){
		nrMagazine++;
		magazin = magazin->getNext();
	}

	int* cumparatori;
	cumparatori = new int[nrMagazine + 1];

	for (i = 0; i <= nrMagazine; i++){
		cumparatori[i] = 0;
	}

	while (tranzactie != NULL){
		cumparatori[tranzactie->getValue().getIdMagazin()]++;
		tranzactie = tranzactie->getNext();
	}

	output << "id_magazin,clienti_pe_saptamana,beneficiari_pe_saptamana\n";

	for (i = 1; i <= nrMagazine; i++){
		output << i << "," << cumparatori[i] / 52 << "," << cumparatori[i] / 52 / 2 << "\n";
	}

	output.close();
}
