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
#include "citireCategorie.h"
#include "LinkedList.h"
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
	/* Calculez nr de magazine, tranzactii, produse, bonuri din fiecare lista aferenta */
	int lengthProduse = listaProduse.numberOfNodes( );
	int lengthMagazine = listaMagazine.numberOfNodes( );
	int lengthTranzactii = listaTranzactii.numberOfNodes( );
	int lengthBonuri = listaBonuri.numberOfNodes( );
	int lengthCategorii = listaCategorii.numberOfNodes( );
	/* Declar vectorii vanzariMagazine si Vanzari produse de lungimi lengthMagazine respectiv lengthProduse */
	int vanzariProduse[ lengthProduse ], vanzariMagazine[ lengthMagazine ], suma;

	/* Taskul 1_1: */
	task1_1 ( vanzariMagazine, lengthMagazine, listaTranzactii, listaProduse, listaBonuri, listaMagazine );
	
	/* Taskul 1.2 */
	task1_2 (vanzariProduse, lengthProduse, suma, listaTranzactii, listaProduse, listaBonuri);

	/* Taskul 1.3 */
	task1_3 ( suma, lengthTranzactii, listaTranzactii );

	task1_4 ( listaTranzactii, listaBonuri, listaProduse, listaCategorii, lengthMagazine, lengthCategorii );

	return 0;
}
