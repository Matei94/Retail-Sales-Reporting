#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Tranzactie.h"
#include "LinkedList.h"
#include "Bon.h"
#include "Produs.h"
#include "Magazin.h"
#include "Node.h"

using namespace std;

#define Vmax 1000


/* Functia de Hash 
int customHash(string key) {
    int hkey = 0;
    for (int i = 0; i < key.length(); i++)
        hkey = (hkey * 31 + key[i]) % Vmax;
    return hkey;
}*/

/* Cauta in lista de bonuri un obiect al carui idBon == elem */
Node<Bon>* cautareInBonuri( LinkedList<Bon>& listaBonuri, string elem ) {
	/* p = pointer la inceputul listei de bonuri */
	Node<Bon> *p = listaBonuri.front( );
	
	/* Atat timp cat exista elemente in lista, se parcurge :)) */
	while( p != NULL) {
		/* Daca se gaseste obiectul cautat, se returneaza pointerul aferent */
		if( p->getValue( ).getIdBon() == elem ){
				return p;
		}
		p = p->getNext( );
	}
	return NULL;
}


/* Cauta in lista de Produse un obiect al carui idProdus == elem */
Node<Produs>* cautareInProduse( LinkedList<Produs>& listaProduse, int elem) {
	/* p = pointer la inceputul listei de produse */
	Node<Produs> *p = listaProduse.front( );

	/* Parcurgem lista de produse, pana nu mai putem, cum s-ar zice */
	while( p != NULL) {
		/* Daca se gaseste obiectul cautat, se returneaza pointerul aferent */
		if( p->getValue( ).getIdProdus( ) == elem ) {
				return p;
		}
		p = p->getNext( );
	}
	return NULL;
}


/* Cauta in lista de magazine un obiect al carui idMagazin == elem */
Node<Magazin>* cautareInMagazin( LinkedList<Magazin>& listaMagazine, int elem) {
	/* p = pointer la inceputul listei de magazine */
	Node<Magazin> *p = listaMagazine.front( );
	
	/* Parcurgem lista de magazine, pana nu se mai poate */
	while( p != NULL) {
		/* Daca se gaseste obiectul cautat, se returneaza pointerul aferent */
		if( p->getValue( ).getIdMagazin( ) == elem ) {
				return p;
		}
		p = p->getNext( );
	}
	return NULL;
}


/* Prima liniuta de la taskul 1 va fi prezentata in limbaj c++ mai jos: */
void task1_1( LinkedList<Tranzactie>& listaTranzactii, LinkedList<Produs>& listaProduse, LinkedList<Bon>& listaBonuri, LinkedList<Magazin>& listaMagazine ){

	/* Vectorul vanzariMagazine are nr de elemente cate magazine sunt in lista de magazine */
	int length1 = listaMagazine.numberOfNodes( );
	int vanzariMagazine[ length1 ];

	/* p, k = pointer la inceputul listei de tranzactii, respectiv magazin */
	Node<Tranzactie> *p = listaTranzactii.front( );
	Node<Magazin>* k = listaMagazine.front( );

	/* gasitBon, gasitProdus, gasitMagazin = obiectul listei pe care il cautam */
	Node<Bon>* gasitBon;
	Node<Produs>* gasitProdus;
	Node<Magazin>* gasitMagazin;

	/* Numele urmatoarelor variabile sunt suficient de sugestive... plm */
	int idMagazin, idProdus, pret; 
	string idBon;
	
	/* Initializarea vectorului vanzariMagazine */
	while( k != NULL ) {
		vanzariMagazine[ k->getValue( ).getIdMagazin( ) - 1 ] = 0;
	//	cout<<vanzariMagazine[ k->info.getValue( ).getIdMagazin - 1 ]<<endl;
		k = k->getNext( );	
	}

	/* Parcurgem lista de tranzactii */
	while( p != NULL ) {
		/* Extragem idBon si idMagazin din obiectul curent din lista de tranzactii */
		idBon = p->getValue( ).getIdBon( );
		idMagazin = p->getValue( ).getIdMagazin( );

		/* Cautam in lista de magazine, respectiv in lista de bonuri, obiecte care sa corespunda id-urilor extrase anterior */
		gasitMagazin = cautareInMagazin( listaMagazine, idMagazin );
		gasitBon = cautareInBonuri( listaBonuri, idBon );

		/* Extragem idProdus din obiectul gasitBon definit anterior */
		idProdus = gasitBon->getValue( ).getIdProdus( );
		
		/* Cautam in lista de produse obiectul care sa aiba idProdus extras anterior */
		gasitProdus = cautareInProduse( listaProduse, idProdus );

		/* Extragem pretul obiectului respectiv */
		pret = gasitProdus->getValue( ).getPrice( );

		/* Adaugam pretul curent, pretului de pana acum */
		vanzariMagazine[ idMagazin - 1 ] += pret;

		p = p->getNext( );
	}

	/* Afisare vanzariMagazine, parcurgand listaMagazine pornind de la k = pointer la inceputul listei */
	k = listaMagazine.front( );
	while( k != NULL ) {
		cout<<"Magazinul "<<k->getValue( ).getLocatieMagazin( )<<" are totalul "<<vanzariMagazine[ k->getValue( ).getIdMagazin( ) - 1 ]<<" de vanzari\n";
		k = k->getNext( );
	}
}


/* A doua liniuta de la taskul 1 va fi prezentata in limbaj c++ mai jos: */
void task1_2( LinkedList<Tranzactie>&listaTranzactii, LinkedList<Produs>& listaProduse, LinkedList<Bon> &listaBonuri) {

	/* Vectorul vanzariProduse are nr de elemente cate produse sunt in lista de produse */
	int length2 = listaProduse.numberOfNodes( );
	int vanzariProduse[ length2 ];	


	/* p, k = pointeri la inceputul listelor de tranzactii, respectiv produse */
	Node<Tranzactie> *p = listaTranzactii.front( );
	Node<Produs> *k = listaProduse.front( );

	/* gasitBon, gasitProdus = obiectul listei pe care il cautam */
	Node<Bon>* gasitBon;
	Node<Produs>* gasitProdus;

	/* Nume de variabile suficient de sugestive. Figure it out yourself */
	string idBon;
	int idProdus, pret; //valoare;

	/* Initializam vanzariProduse */
	while( k != NULL ) {
		vanzariProduse[k->getValue( ).getIdProdus( ) - 1] = 0;
		k = k-> getNext( ); 	
	}

	/* Parcurgem lista de tranzactii */
	while( p != NULL) {
		/* Extragem idBon din obiectul curent din lista de tranzactii*/
		idBon = p->getValue( ).getIdBon( );

		/* Cautam in lista de bonuri un obiect care sa aiba un idBon corespunzator. aferent, asa cum ne place noua */
		gasitBon = cautareInBonuri( listaBonuri, idBon );

		/* Extragem idProdus din obiectul curent din lista de tranzactii */
		idProdus = gasitBon->getValue( ).getIdProdus( );

		/* Cautam in lista de produse un obiect care sa aiba un idProdus aferent, ca mai sus */
		gasitProdus = cautareInProduse( listaProduse, idProdus );

		/* Extragem pretul din obiectul gasit mai devreme */
		pret = gasitProdus->getValue( ).getPrice( );
		//elemInfo<string, int> ceva;
		//ceva.key = gasitProdus->info.getNumeProdus( );
		//ceva.value = pret;
		/* Adunam la pretul anterior, pretul corent, la produsul care este pe frecventa */
		vanzariProduse[ idProdus -1 ] += pret;
		p = p->getNext( );
	} 
	/* Afisare vanzariProduse, parcurgand listaProduse pornind de la k = pointer la inceputul listei */
	k = listaProduse.front( );
	while( k != NULL ) {
		cout<<"Produsul "<<k->getValue( ).getNumeProdus( )<<" are totalul "<<vanzariProduse[ k->getValue( ).getIdProdus( ) - 1 ]<<" de vanzari\n";
		k = k->getNext( );
	}


}
