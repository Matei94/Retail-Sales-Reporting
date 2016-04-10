#include<iostream>
#include<fstream>
#include<string>

#include "task1.1.h"
#include "citireTranzactii.h"
#include "citireBonuri.h"
/*#include "../headers/citirePaleti.h";*/
/*#include "../headers/citireCategorie.h";*/
#include "citireMagazine.h"
#include "citireProduse.h"

using namespace std;

int main ( ) {
	/* Parsare fisiere de input */
	LinkedList<Tranzactie> listaTranzactii;
	citireTranzactii( listaTranzactii );

	LinkedList<Bon> listaBonuri;
	citireBonuri( listaBonuri );

	LinkedList<Magazin> listaMagazine;
	citireMagazine( listaMagazine );


	LinkedList<Produs> listaProduse;
	citireProduse( listaProduse );	
	
	task1_1 ( listaTranzactii, listaProduse, listaBonuri, listaMagazine );
	
	task1_2 ( listaTranzactii, listaProduse, listaBonuri);
	
	return 0;
}
