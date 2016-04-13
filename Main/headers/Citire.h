#ifndef __Citire_H_
#define	__Citire_H_

#include <fstream>
#include <sstream>
#include <string>

#include "LinkedList.h"

#include "Categorie.h"
#include "Produs.h"
#include "Magazin.h"
#include "Tranzactie.h"
#include "Palet.h"
#include "Bon.h"

using namespace std;

void citireBonuri( LinkedList<Bon>& listaBonuri ){
	
	ifstream bonuri ( "/home/codis/Retail-Sales-Reporting/Main/csv/bonuri.csv" );
	string linieFisier;
    getline( bonuri, linieFisier );
    while ( getline( bonuri, linieFisier ) ){
    	listaBonuri.addLast ( Bon ( linieFisier ) );
    }
    bonuri.close();
	
}

void citireProduse( LinkedList<Produs>& listaProduse ){
	/* Deschidem fisirul "produse.csv" din care se vor citi datele */
	ifstream produse ( "/home/codis/Retail-Sales-Reporting/Main/csv/produse.csv" );

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


void citirePaleti( LinkedList<Palet>& listaPaleti ){
        ifstream paleti ( "/home/codis/Retail-Sales-Reporting/Main/csv/paleti.csv" );
        string linieFisier;
        getline( paleti, linieFisier );
        while ( getline( paleti, linieFisier ) ){
                listaPaleti.addLast ( Palet ( linieFisier ) );
        }
        paleti.close();
}

void citireMagazine( LinkedList<Magazin>& listaMagazine ){
	/* Deschidem fisirul "magazine.csv" din care se vor citi datele */
	ifstream magazine ( "/home/codis/Retail-Sales-Reporting/Main/csv/magazine.csv" );

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


void citireCategorii( LinkedList<Categorie>& listaCategorii ){
	ifstream categorii ( "/home/codis/Retail-Sales-Reporting/Main/csv/categorii.csv" );
	string linieFisier;
	getline( categorii, linieFisier );
	while ( getline( categorii, linieFisier ) ){
		listaCategorii.addLast ( Categorie( linieFisier ) );
	}
	categorii.close();
}

void citireTranzactii( LinkedList<Tranzactie>& listaTranzactii ){
	/* Deschidem fisirul "tranzactii.csv" din care se vor citi datele */
	ifstream tranzactii ( "/home/codis/Retail-Sales-Reporting/Main/csv/tranzactii.csv" );

	/* linieFisier -> stringul in care se citesc liniile din fisierul anterior */
	string linieFisier;

	/* Prima linie este inutila, capul de tabel */
	getline( tranzactii, linieFisier );

	/* Atat timp cat mai avem linii in fisier, extragem linia si o retinem in stringul aferent */
	while ( getline( tranzactii, linieFisier ) ){
		/* Adaugam obiectul la finalul listei, dupa ce extragem valorile prin constructorul corespunzator */
		listaTranzactii.addLast ( Tranzactie ( linieFisier ) );
	}

	/* Se inchide fisierul din care am citit */
	tranzactii.close();
}

#endif /* __Citire_H_ */
