#include<fstream>
#include<sstream>
#include<string>

#include "Magazin.h"
#include "LinkedList.h"

using namespace std;

void citireMagazine( LinkedList<Magazin>& listaMagazine ){
	/* Deschidem fisirul "magazine.csv" din care se vor citi datele */
	ifstream magazine ( "magazine.csv" );

	/* linieFisier -> stringul in care se citesc liniile din fisierul anterior */
	string linieFisier;

	/* Prima linie este inutila, capul de tabel */
	getline( magazine, linieFisier );

	/* Atat timp cat mai avem linii in fisier, extragem linia si o retinem in stringul aferent */
	while ( getline ( magazine, linieFisier ) ){
		/* Adaugam obiectul la finalul listei, dupa ce extragem valorile prin constructorul corespunzator */
		listaMagazine.addLast ( Magazin ( linieFisier ) );
	}

	/* Se inchide fisierul din care am citit */
	magazine.close();
}

