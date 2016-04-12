#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Categorie.h"
#include "Tranzactie.h"
#include "LinkedList.h"
#include "Bon.h"
#include "Produs.h"
#include "Magazin.h"
#include "Node.h"
#include "functiiTask1.h"
using namespace std;

/* Cauta in lista de bonuri un obiect al carui idBon == elem */
Node<Bon>* cautareinBonuri1( Node<Bon> *p, LinkedList<Bon>& listaBonuri, string elem ) {
	/* p = pointer la inceputul listei de bonuri */
	
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
Node<Produs>* cautareinProduse1( LinkedList<Produs>& listaProduse, int elem) {
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


/* Prima liniuta de la taskul 1 va fi prezentata in limbaj c++ mai jos: */
void task1_1( unsigned long long vanzariMagazine[], int length1, LinkedList<Tranzactie>& listaTranzactii, LinkedList<Produs>& listaProduse, LinkedList<Bon>& listaBonuri, LinkedList<Magazin>& listaMagazine ){

	/* Vectorul vanzariMagazine are nr de elemente cate magazine sunt in lista de magazine */

	/* p, k = pointer la inceputul listei de tranzactii, respectiv magazin */
	Node<Tranzactie> *p = listaTranzactii.front( );
	Node<Magazin>* k = listaMagazine.front( );

	/* gasitBon, gasitProdus, gasitMagazin = obiectul listei pe care il cautam */
	Node<Bon> *gasitBon, *bonulet;
	Node<Produs>* gasitProdus;

	/* Numele urmatoarelor variabile sunt suficient de sugestive... plm */
	int idMagazin, idProdus;
	unsigned long long pret; 
	string idBon;
	
	/* Initializare vector vanzariMagazine */
	for( int i = 0; i < length1; i++ ) {
		vanzariMagazine[ i ] = 0;
	}

	/* Parcurgem lista de tranzactii */
	while( p != NULL ) {
		/* Extragem idBon si idMagazin din obiectul curent din lista de tranzactii */
		idBon = p->getValue( ).getIdBon( );
		idMagazin = p->getValue( ).getIdMagazin( );

		/* Cautam in lista de bonuri, obiecte care sa corespunda id-ului Bon extras anterior*/
		bonulet = listaBonuri.front( );

		/* Parcurgem lista de bonuri */
		while( bonulet != NULL ) {
			gasitBon = cautareinBonuri1( bonulet, listaBonuri, idBon );
			if( gasitBon != NULL ) {
				/* Extragem idProdus din obiectul gasitBon definit anterior */
				idProdus = gasitBon->getValue( ).getIdProdus( );
			
				/* Cautam in lista de produse obiectul care sa aiba idProdus extras anterior */
				gasitProdus = cautareinProduse1( listaProduse, idProdus );

				/* Extragem pretul obiectului respectiv */
				pret = gasitProdus->getValue( ).getPrice( );

				/* Adaugam pretul curent, pretului de pana acum */
				vanzariMagazine[ idMagazin - 1 ] += pret;
			}
			else {
				break;
			}	
			bonulet = gasitBon->getNext( );
		}
		p = p->getNext( );
	}

	/* Afisare vanzariMagazine, parcurgand listaMagazine pornind de la magazinas = pointer la inceputul listei */
	Node<Magazin> *magazinas = listaMagazine.front( );
	while( magazinas != NULL ) {
		cout<<"Magazinul "<<magazinas->getValue( ).getLocatieMagazin( )<<" are totalul "<<vanzariMagazine[ magazinas->getValue( ).getIdMagazin( ) - 1 ]<<" de vanzari\n";
		magazinas = magazinas->getNext( );
	}
}

