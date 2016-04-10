#include<fstream>
#include<sstream>
#include<string>

#include "Tranzactie.h"
#include "LinkedList.h"

using namespace std;

void citireTranzactii( LinkedList<Tranzactie>& listaTranzactii ){
	/* Deschidem fisirul "tranzactii.csv" din care se vor citi datele */
	ifstream tranzactii ( "tranzactii.csv" );

	/* linieFisier -> stringul in care se citesc liniile din fisierul anterior */
	string linieFisier;

	/* Prima linie este inutila, capul de tabel */
	getline( tranzactii, linieFisier );
	//cout << linieFisier << '\n';

	/* Atat timp cat mai avem linii in fisier, extragem linia si o retinem in stringul aferent */
	while ( getline( tranzactii, linieFisier ) ){
		//cout << linieFisier << '\n';

		/* Adaugam obiectul la finalul listei, dupa ce extragem valorile prin constructorul corespunzator */
		listaTranzactii.addLast ( Tranzactie ( linieFisier ) );

		/*
		cout << listaTranzactii.front()->getValue().getIdTranzactie() << "\n";
		cout << listaTranzactii.front()->getValue().getIdMagazin() << "\n";
		cout << listaTranzactii.front()->getValue().getTimeStamp() << "\n";
		cout << listaTranzactii.front()->getValue().getIdBon() << "\n";
		*/
	}

	cout << "PLM, Codi. Mie-mi merge. \n";

	/* Se inchide fisierul din care am citit */
	tranzactii.close();
}

