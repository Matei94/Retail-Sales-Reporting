#include<fstream>
#include<sstream>
#include<string>

#include "Tranzactie.h"
#include "LinkedList.h"

using namespace std;

void citireTranzactii( LinkedList<Tranzactie>& listaTranzactii ){
	ifstream tranzactii ( "tranzactii.csv" );
	string linieFisier;
	getline( tranzactii, linieFisier );
	while ( getline( tranzactii, linieFisier ) ){
		listaTranzactii.addLast ( Tranzactie ( linieFisier ) );
	}
	tranzactii.close();
}
