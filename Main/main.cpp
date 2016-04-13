#include <iostream>
#include <string>
#include <fstream>

#include "headers/Citire.h"

#include "headers/Produs.h"
#include "headers/Palet.h"
#include "headers/Bon.h"
#include "headers/Tranzactie.h"
#include "headers/Magazin.h"
#include "headers/Categorie.h"

#include "headers/LinkedList.h"
#include "headers/Hashtable.h"

#include "tasks/task1/task1_1.h"
#include "tasks/task1/task1_2.h"
#include "tasks/task1/task1_3.h"
#include "tasks/task1/task1_4.h"
#include "tasks/task1/task1_5.h"
#include "tasks/task2/Task2_1.h"
#include "tasks/task2/Task2_2.h"
#include "tasks/task2/Task2_3.h"
#include "tasks/task2/Task2_4.h"
#include "tasks/task3/Task3_1.h"
#include "tasks/task3/Task3_2.h"
#include "tasks/task3/Task3_3.h"
#include "tasks/task3/Task3.h"

#define NR_SLOTS 30
#define NR_MAGAZINE 5

using namespace std;

int main (){

	LinkedList<Palet> listaPaleti;
	citirePaleti( listaPaleti );

	LinkedList<Produs> listaProduse;
	citireProduse( listaProduse );

	LinkedList<Tranzactie> listaTranzactii;
	citireTranzactii( listaTranzactii );

	LinkedList<Bon> listaBonuri;
	citireBonuri( listaBonuri );

	LinkedList<Magazin> listaMagazine;
	citireMagazine( listaMagazine );

	LinkedList<Categorie> listaCategorii;
	citireCategorii( listaCategorii );

	int lengthProduse = listaProduse.numberOfNodes( );
	int lengthMagazine = listaMagazine.numberOfNodes( );
	int lengthTranzactii = listaTranzactii.numberOfNodes( );
	int lengthBonuri = listaBonuri.numberOfNodes( );
	int lengthCategorii = listaCategorii.numberOfNodes( );

	unsigned long long vanzariProduse[ lengthProduse ], vanzariMagazine[ lengthMagazine ], suma;

	int varianta;

	cout << "Alegeti un exemplu default { 1, 2, 3 } sau citire manuala { orice }" << endl;
	cin >> varianta;

	string produs;
	int nrZile;
	string idBon;

	switch( varianta ) {
	
		case 1:

			produs = "bicycle";
			nrZile = 10;
			idBon = "525943102504051";

			break;

		case 2:

			produs = "hoodie";
			nrZile = 1;
			idBon = "726353876048707";

			break;

		case 3:

			produs = "swimming nose clips";
			nrZile = 5;
			idBon = "90641122897547";

			break;

		default:

				cout << "Citire nume produs: " << endl;
				cin >> produs;

				cout << "Citire numar de zile: " << endl;
				cin >> nrZile;

				cout << "Citire id-ul unui bon: " << endl;
				cin >> idBon;

			break;

	}

	/* Taskul 1_1: */
	task1_1 ( vanzariMagazine, lengthMagazine, listaTranzactii, listaProduse, listaBonuri, listaMagazine );
	
	/* Taskul 1.2 */
	task1_2 ( vanzariProduse, lengthProduse, suma, listaTranzactii, listaProduse, listaBonuri);

	/* Taskul 1.3 */
	task1_3 ( suma, lengthTranzactii, listaTranzactii );

	/* Taskul 1.4 */
	task1_4 ( listaTranzactii, listaBonuri, listaProduse, listaMagazine, listaCategorii, lengthMagazine, lengthCategorii );
	
	/* Taskul 1_5 */
	task1_5 ( listaProduse, listaBonuri, listaTranzactii, lengthProduse, lengthBonuri );

	/* Taskul 2_1 */
	task2_1( listaTranzactii, listaMagazine, listaBonuri, nrZile);
	
	/* Taskul 2_2 */
	task2_2( listaTranzactii,  listaMagazine, nrZile);
	
	/* Taskul 2_3 */
	task2_3( listaBonuri,  listaProduse, idBon);
	
	/* Taskul 2_4 */
	task2_4( listaTranzactii, listaMagazine);
	
	/* Taskul 3 */
	task3( listaProduse, listaPaleti, listaTranzactii, listaBonuri, produs );	

	return 0 ;
}