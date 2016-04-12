#include<fstream>
#include<sstream>
#include<string>

#include "Bon.h"
#include "LinkedList.h"

using namespace std;

void citireBonuri( LinkedList<Bon>& listaBonuri ){
	/* Deschidem fisirul "bonuri.csv" din care se vor citi datele */
	ifstream bonuri( "bonuri.csv" );
	
    /* linieFisier -> stringul in care se citesc liniile din fisierul anterior */
	string linieFisier;
    
    /* Prima linie este inutila, capul de tabel */
	getline( bonuri, linieFisier );

    /* Atat timp cat mai avem linii in fisier, extragem linia si o retinem in stringul aferent */
	while ( getline( bonuri, linieFisier ) ){
       /* Adaugam obiectul la finalul listei, dupa ce extragem valorile prin constructorul corespunzator */
	   listaBonuri.addLast ( Bon ( linieFisier ) );
	}

    /* Se inchide fisierul din care am citit */
	bonuri.close();	
}

