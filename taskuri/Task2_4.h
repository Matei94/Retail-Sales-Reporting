#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

#include "../headers/LinkedList.h"

using namepsace std;

void task2_4(LinkedList<Tranzactie> listaTranzactii, LinkedList<Magazin> listaMagazine){
	ofstream output ("Task2_4.out");
	Tranzactie* tranzactie = listaTranzactii.front();
	int nrMagazine = 0, i;
	Magazin* magazin = listaMagazine.front();
	while (magazin != NULL){
		nrMagazine++;
		magazin = magazin->getNext();
	}

	int* cumparatori;
	cumparatori = new int*[nrMagazine + 1];

	while (tranzactie != NULL){
		cumparatori[tranzactie.getIdMagazin()]++;
		tranzactie = tranzactie->getNext();
	}

	output << "In anul 2016, numarul mediu de clienti pe zi pentru fiecare magazin a fost:\n";

	for (i = 1; i <= nrMagazine; i++){
		output << "Magazinul " << i << ": " << cumparatori[i] / 366 << " clienti pe zi\n";
	}

	output << "In cazul deschiderii unei noi case, aproximativ jumatate din clienti ar folosi acea casa.\n";
	output << "Numarul mediu de clienti pe zi care ar folosi a doua casa in fiecare magazin este:\n";

	for (i = 1; i <= nrMagazine; i++){
		output << "Magazinul " << i << ": " << cumparatori[i] / 366 / 2 << " clienti pe zi\n";
	}

	output.close();
}
