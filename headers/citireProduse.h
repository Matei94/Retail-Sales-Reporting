#include<fstream>
#include<sstream>

#include "Produs.h"
#include "LinkedList.h"

using namespace std;

void citireTranzactii( LinkedList<Tranzactie>& listaTranzactii ){
	ifstream produse ( "produse.csv" );
	string linieFisier;
	getline( produse, linieFisier );
	while ( getline( produse, linieFisier ) ){
		listaProduse.addLast ( Produs ( linieFisier ) );
	}
	tranzactii.close();
}
