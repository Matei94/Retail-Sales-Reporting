#include<fstream>
#include<sstream>
#include<string>

#include "Produs.h"
#include "LinkedList.h"

using namespace std;

void citireProduse( LinkedList<Produs>& listaProduse ){
	/* Deschidem fisirul "produse.csv" din care se vor citi datele */
	ifstream produse ( "produse.csv" );

	/* linieFisier -> stringul in care se citesc liniile din fisierul anterior */
	string linieFisier;

	/* Prima linie este inutila, capul de tabel */
	getline( produse, linieFisier );

	/* Atat timp cat mai avem linii in fisier, extragem linia si o retinem in stringul aferent */
	while ( getline( produse, linieFisier ) ){
		/* Adaugam obiectul la finalul listei, dupa ce extragem valorile prin constructorul corespunzator */
		listaProduse.addLast ( Produs ( linieFisier ) );
	}

	/* Se inchide fisierul din care am citit */
	produse.close();
}

