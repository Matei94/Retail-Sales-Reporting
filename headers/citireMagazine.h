#include<fstrem>
#include<sstrem>
#include<string>

#include "Magazin.h"
#include "LinkedList.h"

using namespace std;

void citireMagazine( LinkedList<Magazin>& listaMagazine ){
	ifstream magazine ( "magazine.csv" );
	string linieFisier;
	getline( magazine, linieFisier );
	while ( getline ( magazine, linieFisier ) ){
		listaMagazine.addLast ( Magazin ( linieFisier ) );

	}
	magazine.close();
}
