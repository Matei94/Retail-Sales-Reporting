#include<fstream>
#include<sstream>

using namespace std;

void citireTranzactii( LinkedList<Tranzactie>& listaTranzactii ){
	string linieFisier;
	getline( tranzactii, linieFisier );
	while ( getline( tranzactii, linieFisier ) ){
		listaTranzactii.addLast ( Tranzactie ( linieFisier ) );
	}
}
