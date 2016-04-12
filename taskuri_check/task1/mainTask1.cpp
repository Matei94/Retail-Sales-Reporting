#include <iostream>
#include <fstream>
#include <string>

#include "citireTranzactii.h"
#include "citireBonuri.h"
#include "citireMagazine.h"
#include "citireProduse.h"
#include "citireCategorie.h"
#include "LinkedList.h"
#include "Node.h"
#include "Bon.h"
#include "Categorie.h"
#include "Produs.h"
#include "Magazin.h"
#include "Tranzactie.h"
#include "task1_1.h"
#include "task1_2.h"
#include "task1_3.h"
#include "task1_4.h"

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
	unsigned long long vanzariProduse[ lengthProduse ], vanzariMagazine[ lengthMagazine ], suma;

	/* Taskul 1_1: */
	cout<<"\n\nTask-ul 1_1:\n\n";
	task1_1 ( vanzariMagazine, lengthMagazine, listaTranzactii, listaProduse, listaBonuri, listaMagazine );
	
	/* Taskul 1.2 */
	cout<<"\n\nTask-ul 1_2:\n\n";
	task1_2 (vanzariProduse, lengthProduse, suma, listaTranzactii, listaProduse, listaBonuri);

	/* Taskul 1.3 */
	cout<<"\n\nTask-ul 1_3:\n\n";
	task1_3 ( suma, lengthTranzactii, listaTranzactii );

	/* Taskul 1.4 */
	cout<<"\n\nTask-ul 1_4:\n\n";
	task1_4 ( listaTranzactii, listaBonuri, listaProduse, listaMagazine, listaCategorii, lengthMagazine, lengthCategorii );

	return 0;
}
