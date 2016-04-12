#include<iostream>
#include<fstream>
#include<string>

//#include "task1.1.h"
#include "citireTranzactii.h"
#include "citireBonuri.h"
/*#include "../headers/citirePaleti.h";*/
/*#include "../headers/citireCategorie.h";*/
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
	/* Calculez nr de magazine, tranzactii, produse, bonuri din fiecare lista aferenta */
	int lengthProduse = listaProduse.numberOfNodes( );
	int lengthMagazine = listaMagazine.numberOfNodes( );
	int lengthTranzactii = listaTranzactii.numberOfNodes( );
	int lengthBonuri = listaBonuri.numberOfNodes( );
	int lengthCategorii = listaCategorii.numberOfNodes( );
	/* Declar vectorii vanzariMagazine si Vanzari produse de lungimi lengthMagazine respectiv lengthProduse */
	unsigned long long vanzariProduse[ lengthProduse ], vanzariMagazine[ lengthMagazine ], suma;

	/* Taskul 1_1: */
	//task1_1 ( vanzariMagazine, lengthMagazine, listaTranzactii, listaProduse, listaBonuri, listaMagazine );
	
	/* Taskul 1.2 */
	//task1_2 (vanzariProduse, lengthProduse, suma, listaTranzactii, listaProduse, listaBonuri);

	/* Taskul 1.3 */
	//task1_3 ( suma, lengthTranzactii, listaTranzactii );

	//task1_4 ( listaTranzactii, listaBonuri, listaProduse, listaMagazine, listaCategorii, lengthMagazine, lengthCategorii );

	int nrZile;
	string idBon;

	cout << "Task2_1: Zilele cu cele mai multe produse vandute. Introduceti pentru primele cate zile doriti evidenta\n";
	cin >> nrZile;

	task2_1( listaTranzactii, listaMagazine, listaBonuri, nrZile);

	cout << "Task2_2: Zilele cu cei mai multi cumparatori. Introduceti pentru primele cate zile doriti evidenta\n";
	cin >> nrZile;

	task2_2( listaTranzactii,  listaMagazine, nrZile);

	cout << "Task2_3: Continutul unui bon. Introduceti id-ul bonului\n";
	cin >> idBon;

	task2_3( listaBonuri,  listaProduse, idBon);

	task2_4( listaTranzactii, listaMagazine);

	return 0;
}
