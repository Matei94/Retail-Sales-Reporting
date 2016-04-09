#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

#include "Tranzactie.h"
#include "LinkedList.h"
#include "Bon.h"
#include "Produs.h"
#include "Magazin.h"
#include "hashtable.h"


using namespace std;

#define Vmax 1000


/* Functia de Hash */
int customHash(string key) {
    int hkey = 0;
    for (int i = 0; i < key.length(); i++)
        hkey = (hkey * 31 + key[i]) % Vmax;
    return hkey;
}

/* Cauta in lista de bonuri un obiect al carui idBon == elem */
listElem<Bon>* cautareInBonuri( LinkedList<Bon> listaBonuri, string elem ) {
	/* p = pointer la inceputul listei de bonuri */
	struct listElem<Bon> *p = listaBonuri.front( );
	
	/* Atat timp cat exista elemente in lista, se parcurge :)) */
	while( p != NULL) {
		/* Daca se gaseste obiectul cautat, se returneaza pointerul aferent */
		if( p->info.getIdBon() == elem ){
				return p;
		}
		p = p->next;
	}
	return NULL;
}


/* Cauta in lista de Produse un obiect al carui idProdus == elem */
listElem<Produs>* cautareInProduse( LinkedList<Produs> listaProduse, int elem) {
	/* p = pointer la inceputul listei de produse */
	struct listElem<Produs> *p = listaProduse.front( );

	/* Parcurgem lista de produse, pana nu mai putem, cum s-ar zice */
	while( p != NULL) {
		/* Daca se gaseste obiectul cautat, se returneaza pointerul aferent */
		if( p->info.getIdProdus( ) == elem ) {
				return p;
		}
		p = p->next;
	}
	return NULL;
}


/* Cauta in lista de magazine un obiect al carui idMagazin == elem */
listElem<Magazin>* cautareInMagazin( LinkedList<Magazin> listaMagazine, int elem) {
	/* p = pointer la inceputul listei de magazine */
	struct listElem<Magazin> *p = listaMagazine.front( );
	
	/* Parcurgem lista de magazine, pana nu se mai poate */
	while( p != NULL) {
		/* Daca se gaseste obiectul cautat, se returneaza pointerul aferent */
		if( p->info.getIdMagazin( ) == elem ) {
				return p;
		}
		p = p->next;
	}
	return NULL;
}


/* Prima liniuta de la taskul 1 va fi prezentata in limbaj c++ mai jos: */
void task1_1( LinkedList<Tranzactie> listaTranzactii, LinkedList<Produs> listaProduse, LinkedList<Bon> listaBonuri, LinkedList<Magazin> listaMagazine ){
	/* Hash-ul aferent are cheia = locatia magazinului, iar valoarea = suma vanzarilor magazinului respectiv */
	Hashtable<string, int> vanzariMagazine = Hashtable<string, int>( Vmax, customHash);

	/* p, k = pointer la inceputul listei de tranzactii, respectiv magazin */
	struct listElem<Tranzactie> *p = listaTranzactii.front( );
	struct listElem<Magazin>* k = listaMagazine.front( );

	/* gasitBon, gasitProdus, gasitMagazin = obiectul listei pe care il cautam */
	struct listElem<Bon>* gasitBon;
	struct listElem<Produs>* gasitProdus;
	struct listElem<Magazin>* gasitMagazin;

	/* Numele urmatoarelor variabile sunt suficient de sugestive... plm */
	int idMagazin, idProdus, pret; 
	string idBon;
	
	/* Initializarea hashtable-ului */
	while( k != NULL ) {
		vanzariMagazine.put(k->info.getLocatieMagazin( ),'0');
		k = k->next;	
	}

	/* Parcurgem lista de tranzactii */
	while( p != NULL ) {
		/* Extragem idBon si idMagazin din obiectul curent din lista de tranzactii */
		idBon = p->info.getIdBon( );
		idMagazin = p->info.getIdMagazin( );

		/* Cautam in lista de magazine, respectiv in lista de bonuri, obiecte care sa corespunda id-urilor extrase anterior */
		gasitMagazin = cautareInMagazin( listaMagazine, idMagazin );
		gasitBon = cautareInBonuri( listaBonuri, idBon );

		/* Extragem idProdus din obiectul gasitBon definit anterior */
		idProdus = gasitBon->info.getIdProdus( );
		
		/* Cautam in lista de produse obiectul care sa aiba idProdus extras anterior */
		gasitProdus = cautareInProduse( listaProduse, idProdus );

		/* Extragem pretul obiectului respectiv */
		pret = gasitProdus->info.getPrice( );

		/* Adaugam pretul curent, pretului de pana acum */
		vanzariMagazine[ gasitMagazin->info.getLocatieMagazin( ) ] +=pret;
		//int valoare = vanzariMagazine.get( gasitMagazin->info.getLocatieMagazin( ) );
		//vanzariMagazine.put( gasitMagazin->info.getLocatieMagazin(), valoare + pret );

		p = p->next;
	}
}


/* A doua liniuta de la taskul 1 va fi prezentata in limbaj c++ mai jos: */
void task1_2( LinkedList<Tranzactie> listaTranzactii, LinkedList<Produs> listaProduse, LinkedList<Bon> listaBonuri) {
	/* Hash-ul aferent are cheia = numele produsului, iar valoarea = suma vanzarilor magazinului respectiv */
	Hashtable<string, int> vanzariProduse = Hashtable<string, int>( Vmax, customHash);

	/* p, k = pointeri la inceputul listelor de tranzactii, respectiv produse */
	struct listElem<Tranzactie> *p = listaTranzactii.front( );
	struct listElem<Produs> *k = listaProduse.front( );

	/* gasitBon, gasitProdus = obiectul listei pe care il cautam */
	struct listElem<Bon>* gasitBon;
	struct listElem<Produs>* gasitProdus;

	/* Nume de variabile suficient de sugestive. Figure it out yourself */
	string idBon;
	int idProdus, pret; //valoare;

	/* Initializam hash-ul */
	while( k != NULL ) {
		vanzariProduse.put(k->info.getNumeProdus( ),'0');
		k = k-> next;	
	}

	/* Parcurgem lista de tranzactii */
	while( p != NULL) {
		/* Extragem idBon din obiectul curent din lista de tranzactii*/
		idBon = p->info.getIdBon( );

		/* Cautam in lista de bonuri un obiect care sa aiba un idBon corespunzator. aferent, asa cum ne place noua */
		gasitBon = cautareInBonuri( listaBonuri, idBon );

		/* Extragem idProdus din obiectul curent din lista de tranzactii */
		idProdus = gasitBon->info.getIdProdus( );

		/* Cautam in lista de produse un obiect care sa aiba un idProdus aferent, ca mai sus */
		gasitProdus = cautareInProduse( listaProduse, idProdus );

		/* Extragem pretul din obiectul gasit mai devreme */
		pret = gasitProdus->info.getPrice( );

		/* Adunam la pretul anterior, pretul corent, la produsul care este pe frecventa */
		vanzariProduse[gasitProdus->info.getNumeProdus( )] +=pret;
		//int valoare = vanzariProduse.get( gasitProdus->info.getNumeProdus( ) );
		//vanzariProduse.put( gasitProdus->info.getNumeProdus( ), valoare + pret );

		p = p->next;
	} 
}
