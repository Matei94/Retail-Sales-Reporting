#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


#include "Tranzactie.h"
#include "LinkedList.h"
#include "Bon.h"
#include "Produs.h"
#include "Magazin.h"
#include "Hashtable.h"
#include "Node.h"


using namespace std;

void task1_4(LinkedList<Tranzactie> listaTranzactii, LinkedList<Bon> listaBonuri, LinkedList<Produs> listaProduse,  LinkedList<Magazin> listaMagazine){
	ofstream output ("Task1_4.out");
	Tranzactie* tranzactie = listaTranzactii.front();
	int nrMagazine = 0, nrCategorii = 0;
	Magazin* magazin = listaMagazine.front();
	Categorie* categorie = listaCategorie.front();

	while (magazin != NULL){
		nrMagazine++;
		magazin = magazin->getNext();
	}
	while (categorie != NULL){
		nrCategorii++;
		categorie = categorie->getNext();
	}
	int a[nrMagazine + 1][nrCategorii + 1] = {0};
