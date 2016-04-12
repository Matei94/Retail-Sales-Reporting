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
Node<Bon>* cautareInBonuri4( Node<Bon> *p, LinkedList<Bon>& listaBonuri, string elem ) {
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
Node<Produs>* cautareInProduse4( LinkedList<Produs>& listaProduse, int elem) {
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
Node<Magazin>* cautareInMagazin4( LinkedList<Magazin>& listaMagazine, int elem) {
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
Node<Categorie>* cautareInCategorii4( LinkedList<Categorie>& listaCategorii, int elem) {
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


void task1_4( LinkedList<Tranzactie> &listaTranzactii, LinkedList<Bon> &listaBonuri, LinkedList<Produs> &listaProduse,  LinkedList<Magazin> &listaMagazine, LinkedList<Categorie>& listaCategorii, int nrMagazine, int nrCategorii ){
	/* Formam o matrice a care are nr de linii = numarul de magazine si nr coloane = nr de categorii */
	Node <Tranzactie> *tranzactie = listaTranzactii.front();
	Node <Magazin> *gasitMagazin;
	Node <Categorie> *categorie = listaCategorii.front();
	Node <Bon> *p, *BonCautat;
	Node <Categorie> *gasitCategorie;
	int idMagazin ;
	string idBon; 
	/* Initializare matrice */
	unsigned long long a[ nrMagazine ][ nrCategorii ];
	 int i, j;
	 for( i = 0; i < nrMagazine; ++i ) {
	 	for( j = 0; j < nrCategorii; ++j ) {
	 		a[ i ][ j ] = 0;
	 	}
	 }

	while( tranzactie != NULL ) {

		//Retinem idMagazin si idBon aferente tranzactiei
		idMagazin = tranzactie->getValue().getIdMagazin();
		idBon = tranzactie->getValue().getIdBon();
		
		/*O sa avem mai multe produse pe un bon...Deci trebuie sa cautam toate aparitiile lui bon 
		  in bonuri si sa le prelucram*/
		/* Incepem de la front */
		p = listaBonuri.front( );
		while( p != NULL ) {
			
			/* BonCautat e un pointer la Bonul cu id-ul idbon */
			BonCautat = cautareInBonuri4( p, listaBonuri, idBon );
			if( BonCautat != NULL ) {
			
				/* IdprodusCautat e id-ul produsului din bonul BonCautat cu care mergem in Produse sa ii vedem categoria*/
				int IdProdusCautat = BonCautat->getValue().getIdProdus();
				int IdCategorieProdusCautat = cautareInProduse4( listaProduse, IdProdusCautat)->getValue( ).getIdCategorie( );
			
				/* Incrementam in matricea a la linia si coloana corespunzatoare, aferenta, cum ne place noua */
				a[ idMagazin - 1 ][ IdCategorieProdusCautat - 1 ] ++;
			}
			else {
				break;
			}	
			p = BonCautat->getNext( );
		}

		/* Avansam in listaTranzactii */
		tranzactie = tranzactie->getNext( );
	}
	
	for( i = 0 ; i < nrMagazine; ++i) {
		for( j = 0; j < nrCategorii; ++j ) {
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}		
	/* Gasim categoria cea mai vanduta pt fiecare magazin: calculam maximul pe fiecare linie din matricea a */
	int CategorieMaxima;
	unsigned long long maxim;
	for( i = 0; i < nrMagazine; ++i) {
		CategorieMaxima = 0;
		maxim = 0;
		gasitMagazin = cautareInMagazin4( listaMagazine, i + 1 );
		for( j = 0; j < nrCategorii; ++j ) {
			if( a[ i ][ j ] > maxim ) {
				CategorieMaxima = j;
				maxim = a[ i ][ j ];

			}

		}
		gasitCategorie = cautareInCategorii4( listaCategorii, CategorieMaxima + 1 );

		cout<< "magazinul "<< gasitMagazin->getValue( ).getLocatieMagazin( )<<" are categoria cea mai vanduta "<<gasitCategorie->getValue( ).getNumeCategorie( )<<endl;
	}	

}