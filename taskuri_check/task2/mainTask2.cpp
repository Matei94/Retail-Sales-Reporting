#include<iostream>
#include<fstream>
#include<string>

#include "citireTranzactii.h"
#include "citireBonuri.h"
#include "citireMagazine.h"
#include "citireProduse.h"
#include "citireCategorie.h"
#include "LinkedList.h"

#include "Task2_1.h"
#include "Task2_2.h"
#include "Task2_3.h"
#include "Task2_4.h"
using namespace std;

int main ( ) {
	/* Parsare fisiere de input */
	LinkedList<Tranzactie> listaTranzactii;
	citireTranzactii( listaTranzactii );

	//listaTranzactii.printList();

	LinkedList<Bon> listaBonuri;
	citireBonuri( listaBonuri );

	LinkedList<Magazin> listaMagazine;
	citireMagazine( listaMagazine );

	LinkedList<Produs> listaProduse;
	citireProduse( listaProduse );	

	LinkedList<Categorie> listaCategorii;
	citireCategorii( listaCategorii );

	int nrZile = 10;
	string idBon = "525943102504051";

	task2_1( listaTranzactii, listaMagazine, listaBonuri, nrZile);

	task2_2( listaTranzactii,  listaMagazine, nrZile);

	task2_3( listaBonuri,  listaProduse, idBon);

	task2_4( listaTranzactii, listaMagazine);

	return 0;
}
