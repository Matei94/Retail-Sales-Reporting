#include <iostream>
#include <fstream>
#include <string>

#include "Tranzactie.h"
#include "LinkedList.h"
#include "Produs.h"
#include "Magazin.h"
#include "Bon.h"

using namespace std;

void citireProduse( LinkedList<Produs>& listaProduse ){
	ifstream produse ( "produse.csv" );
	string linieFisier;
	getline( produse, linieFisier );
	cout<<linieFisier;
	while ( getline( produse, linieFisier ) ){
		listaProduse.addLast ( Produs ( linieFisier ) );
	}
	produse.close();
}

void citireTranzactii( LinkedList<Tranzactie>& listaTranzactii ){
	/* Deschidem fisirul "tranzactii.csv" din care se vor citi datele */
	ifstream tranzactii ( "tranzactii.csv" );

	/* linieFisier -> stringul in care se citesc liniile din fisierul anterior */
	string linieFisier;

	/* Prima linie este inutila, capul de tabel */
	getline( tranzactii, linieFisier, '\n');
	cout<<linieFisier;


	/* Atat timp cat mai avem linii in fisier, extragem linia si o retinem in stringul aferent */
	while ( getline( tranzactii, linieFisier ) ){

		/* Adaugam obiectul la finalul listei, dupa ce extragem valorile prin constructorul corespunzator */
		listaTranzactii.addLast ( Tranzactie ( linieFisier ) );
	}

	/* Se inchide fisierul din care am citit */
	tranzactii.close();
}

void citireMagazine( LinkedList<Magazin>& listaMagazine ){
	ifstream magazine ( "magazine.csv" );
	string linieFisier;
	getline( magazine, linieFisier );
	cout<<linieFisier;
	while ( getline ( magazine, linieFisier ) ){
		listaMagazine.addLast ( Magazin ( linieFisier ) );

	}
	magazine.close();
}

void citireBonuri( LinkedList<Bon>& listaBonuri ){
	/* Deschidem fisirul "bonuri.csv" din care se vor citi datele */
	ifstream bonuri ( "bonuri.csv" );
	
    /* linieFisier -> stringul in care se citesc liniile din fisierul anterior */
	string linieFisier;
    
    /* Prima linie este inutila, capul de tabel */
	getline( bonuri, linieFisier );
	cout<<linieFisier;

    /* Atat timp cat mai avem linii in fisier, extragem linia si o retinem in stringul aferent */
	while ( getline( bonuri, linieFisier ) ){
	   /* Adaugam obiectul la finalul listei, dupa ce extragem valorile prin constructorul corespunzator */
	   listaBonuri.addLast ( Bon ( linieFisier ) );
	}

    /* Se inchide fisierul din care am citit */
	bonuri.close();	
}



int main (){

	LinkedList<Produs> listaProduse;
	citireProduse( listaProduse );

/*	cout<<listaProduse.front()->getValue().getIdProdus()<<endl;
	cout<<listaProduse.front()->getValue().getIdCategorie()<<endl;
	cout<<listaProduse.front()->getValue().getPrice()<<endl;
	cout<<listaProduse.front()->getValue().getNumeProdus()<<endl;

	cout<<listaProduse.front()->getNext()->getValue().getIdProdus()<<endl;
	cout<<listaProduse.front()->getNext()->getValue().getIdCategorie()<<endl;
	cout<<listaProduse.front()->getNext()->getValue().getPrice()<<endl;
	cout<<listaProduse.front()->getNext()->getValue().getNumeProdus()<<endl;
	cout<<"gheroghe"<<endl;
*/
	LinkedList<Bon> listaBonuri;
	citireBonuri( listaBonuri );
/*
	cout<<listaBonuri.front()->getValue().getIdBon()<<endl;
	cout<<listaBonuri.front()->getValue().getIdProdus( )<<endl;
*/
	LinkedList<Magazin> listaMagazine;
	citireMagazine( listaMagazine );
/*
	cout<<listaMagazine.front()->getValue().getIdMagazin( )<<endl;
	cout<<listaMagazine.front()->getValue().getLocatieMagazin( )<<endl;
*/

	LinkedList<Tranzactie> listaTranzactii;
	citireTranzactii( listaTranzactii );
	/*
	cout<<listaTranzactii.front()->getValue().getIdTranzactie()<<endl;
	cout<<listaTranzactii.front()->getValue().getIdMagazin( )<<endl;
	cout<<listaTranzactii.front()->getValue().getTimeStamp( )<<endl;
	cout<<listaTranzactii.front()->getValue().getIdBon( )<<endl;
*/
	return 0;
}