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

using namespace std;

/* Cauta in lista de bonuri un obiect al carui idBon == elem */
Node<Bon>* cautareInBonuri( Node<Bon> *p, LinkedList<Bon>& listaBonuri, string elem ) {
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
/* Cauta in lista de Categorii un obiect al carui idCategorie == elem */
Node<Categorie>* cautareInCategorii( LinkedList<Categorie>& listaCategorii, int elem) {
	/* p = pointer la inceputul listei de categorii */
	Node<Categorie> *p = listaCategorii.front( );

	/* Parcurgem lista de categorii, pana nu mai putem, cum s-ar zice */
	while( p != NULL) {
		/* Daca se gaseste obiectul cautat, se returneaza pointerul aferent */
		if( p->getValue( ).getIdCategorie( ) == elem ) {
				return p;
		}
		p = p->getNext( );
	}
	return NULL;
}
