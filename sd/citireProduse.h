#include<fstream>
#include<sstream>
#include<string>
#include "Produs.h"
#include "LinkedList.h"

using namespace std;

void citireProduse( LinkedList<Produs>& listaProduse ){
	ifstream produse ( "produse.csv" );
	string linieFisier;
	getline( produse, linieFisier );
	while ( getline( produse, linieFisier ) ){
		listaProduse.addLast ( Produs ( linieFisier ) );
	}
	produse.close();
}

