#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../../headers/LinkedList.h"
#include "../../headers/Node.h"

#include "../../headers/Categorie.h"
#include "../../headers/Tranzactie.h"
#include "../../headers/Bon.h"
#include "../../headers/Produs.h"
#include "../../headers/Magazin.h"

using namespace std;

/* Cauta in lista de bonuri un obiect al carui idBon == elem */
Node<Bon>* cautareInBonuri2( Node<Bon> *p, LinkedList<Bon>& listaBonuri, string elem ) {
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
Node<Produs>* cautareInProduse2( LinkedList<Produs>& listaProduse, int elem) {
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


/* A doua liniuta de la taskul 1 va fi prezentata in limbaj c++ mai jos: */
void task1_2( unsigned long long vanzariProduse[], int length2, unsigned long long &suma, LinkedList<Tranzactie> &listaTranzactii, LinkedList<Produs>& listaProduse, LinkedList<Bon> &listaBonuri) {

	ofstream output( "Rezultate.csv", ofstream::app );

	/* Vectorul vanzariProduse are nr de elemente cate produse sunt in lista de produse */

	/* initializare suma vanzarilor total cu 0 */
	suma = 0;

	/* p, k = pointeri la inceputul listelor de tranzactii, respectiv produse */
	Node<Tranzactie> *p = listaTranzactii.front( );
	Node<Produs> *k = listaProduse.front( );
	Node<Bon> *bonulet;
	/* gasitBon, gasitProdus = obiectul listei pe care il cautam */
	Node<Bon>* gasitBon;
	Node<Produs>* gasitProdus;

	/* Nume de variabile suficient de sugestive. Figure it out yourself */
	string idBon;
	int idProdus;
	unsigned long long pret; //valoare;

	/* Initializam vanzariProduse */
	for( int i = 0; i < length2; i++)
		vanzariProduse[ i ] = 0;
	
	/* Parcurgem lista de tranzactii */
	while( p != NULL) {
		/* Extragem idBon din obiectul curent din lista de tranzactii*/
		idBon = p->getValue( ).getIdBon( );

		/* Cautam in lista de bonuri un obiect care sa aiba un idBon corespunzator. aferent, asa cum ne place noua */
		bonulet = listaBonuri.front( );
		while( bonulet != NULL ) {
			gasitBon = cautareInBonuri2( bonulet, listaBonuri, idBon );
			if( gasitBon != NULL ) {
				/* Extragem idProdus din obiectul curent din lista de tranzactii */
				idProdus = gasitBon->getValue( ).getIdProdus( );

				/* Cautam in lista de produse un obiect care sa aiba un idProdus aferent, ca mai sus */
				gasitProdus = cautareInProduse2( listaProduse, idProdus );

				/* Extragem pretul din obiectul gasit mai devreme */
				pret = gasitProdus->getValue( ).getPrice( );
			
				/* Adunam la pretul anterior, pretul corent, la produsul care este pe frecventa */
				vanzariProduse[ idProdus - 1 ] += pret;
			}
			else {
				break;
			}	
			bonulet = gasitBon->getNext( );
		}
		p = p->getNext( );
	}	
		
	output<<"\n\nTask-ul 1_2:\n\n";

	/* Afisare vanzariProduse, parcurgand listaProduse pornind de la k = pointer la inceputul listei si calcularea sumei */
	k = listaProduse.front( );
	while( k != NULL ) {
		output<<"Produsul "<<k->getValue( ).getNumeProdus( )<<" are totalul "<<vanzariProduse[ k->getValue( ).getIdProdus( ) - 1 ]<<" de vanzari\n";	
		suma += vanzariProduse[ k->getValue( ).getIdProdus( ) - 1 ];
		k = k->getNext( );
	}
	output.close();
}