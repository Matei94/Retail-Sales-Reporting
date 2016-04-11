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

#define Vmax 1000


/* Functia de Hash 
int customHash(string key) {
    int hkey = 0;
    for (int i = 0; i < key.length(); i++)
        hkey = (hkey * 31 + key[i]) % Vmax;
    return hkey;
}*/

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
	int idMagazin, idProdus, pret; 
	string idBon;
	
	/* Initializare vector vanzariMagazine */
	vanzariMagazine[ length1 ] = 0;

	/* Parcurgem lista de tranzactii */
	while( p != NULL ) {
		/* Extragem idBon si idMagazin din obiectul curent din lista de tranzactii */
		idBon = p->getValue( ).getIdBon( );
		idMagazin = p->getValue( ).getIdMagazin( );

		/* Cautam in lista de bonuri, obiecte care sa corespunda id-ului Bon extras anterior*/
		bonulet = listaBonuri.front( );

		/* Parcurgem lista de bonuri */
		while( bonulet != NULL ) {
			gasitBon = cautareInBonuri( bonulet, listaBonuri, idBon );
			if( gasitBon != NULL ) {
				/* Extragem idProdus din obiectul gasitBon definit anterior */
				idProdus = gasitBon->getValue( ).getIdProdus( );
			
				/* Cautam in lista de produse obiectul care sa aiba idProdus extras anterior */
				gasitProdus = cautareInProduse( listaProduse, idProdus );

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


/* A doua liniuta de la taskul 1 va fi prezentata in limbaj c++ mai jos: */
void task1_2( unsigned long long vanzariProduse[], int length2, unsigned long long &suma, LinkedList<Tranzactie> &listaTranzactii, LinkedList<Produs>& listaProduse, LinkedList<Bon> &listaBonuri) {

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
	int idProdus, pret; //valoare;

	/* Initializam vanzariProduse */
	vanzariProduse[ length2 ] = { 0 };

	/* Parcurgem lista de tranzactii */
	while( p != NULL) {
		/* Extragem idBon din obiectul curent din lista de tranzactii*/
		idBon = p->getValue( ).getIdBon( );

		/* Cautam in lista de bonuri un obiect care sa aiba un idBon corespunzator. aferent, asa cum ne place noua */
		bonulet = listaBonuri.front( );
		while( bonulet != NULL ) {
			gasitBon = cautareInBonuri( bonulet, listaBonuri, idBon );
			if( gasitBon != NULL ) {
				/* Extragem idProdus din obiectul curent din lista de tranzactii */
				idProdus = gasitBon->getValue( ).getIdProdus( );

				/* Cautam in lista de produse un obiect care sa aiba un idProdus aferent, ca mai sus */
				gasitProdus = cautareInProduse( listaProduse, idProdus );

				/* Extragem pretul din obiectul gasit mai devreme */
				pret = gasitProdus->getValue( ).getPrice( );
			
				/* Adunam la pretul anterior, pretul corent, la produsul care este pe frecventa */
				vanzariProduse[ idProdus -1 ] += pret;
			}
			else {
				break;
			}	
			bonulet = gasitBon->getNext( );
		}
		p = p->getNext( );
	}	
			
	/* Afisare vanzariProduse, parcurgand listaProduse pornind de la k = pointer la inceputul listei si calcularea sumei */
	k = listaProduse.front( );
	while( k != NULL ) {
		cout<<"Produsul "<<k->getValue( ).getNumeProdus( )<<" are totalul "<<vanzariProduse[ k->getValue( ).getIdProdus( ) - 1 ]<<" de vanzari\n";	
		suma += vanzariProduse[ k->getValue( ).getIdProdus( ) - 1 ];
		k = k->getNext( );

	}
}


/* Taskul 1_3: */
void task1_3( unsigned long long suma, int length, LinkedList<Tranzactie> &listaTranzactii ) {
	double valoare_cos_mediu;
	cout<<suma<<" "<<length<<endl;
	/* cosul mediu este raportul dintre suma totala aflata de la task 1_2 si numarul de tranzactii */
	valoare_cos_mediu = double( suma )/double( length );

	/* Afisare valoarea cosului mediu */
	cout<<valoare_cos_mediu<<endl;	
}

void task1_4( LinkedList<Tranzactie> &listaTranzactii, LinkedList<Bon> &listaBonuri, LinkedList<Produs> &listaProduse,  LinkedList<Magazin> &listaMagazine, LinkedList<Categorie>& listaCategorii, int nrMagazine, int nrCategorii ){
	/* Formam o matrice a care are nr de linii = numarul de magazine si nr coloane = nr de categorii */
	Node <Tranzactie> *tranzactie = listaTranzactii.front();
	Node <Magazin> *gasitMagazin;
	Node <Categorie> *categorie = listaCategorii.front();
	Node <Bon> *p, *BonCautat;
	Node <Categorie> *gasitCategorie;

	/* Initializare matrice */
	int a[ nrMagazine ][ nrCategorii ] = { 0 };
	while( tranzactie != NULL ) {

		//Retinem idMagazin si idBon aferente tranzactiei
		int idMagazin = tranzactie->getValue().getIdMagazin();
		string idBon = tranzactie->getValue().getIdBon();
		
		/*O sa avem mai multe produse pe un bon...Deci trebuie sa cautam toate aparitiile lui bon 
		  in bonuri si sa le prelucram*/
		/* Incepem de la front */
		p = listaBonuri.front( );
		while( p != NULL ) {
			
			/* BonCautat e un pointer la Bonul cu id-ul idbon */
			BonCautat = cautareInBonuri( p, listaBonuri, idBon );
			if( BonCautat != NULL ) {
			
				/* IdprodusCautat e id-ul produsului din bonul BonCautat cu care mergem in Produse sa ii vedem categoria*/
				int IdProdusCautat = BonCautat->getValue().getIdProdus();
				int IdCategorieProdusCautat = cautareInProduse( listaProduse, IdProdusCautat)->getValue( ).getIdCategorie( );
			
				/* Incrementam in matricea a la linia si coloana corespunzatoare, aferenta, cum ne place noua */
				a[ idMagazin ][ IdCategorieProdusCautat ] ++;
			}
			else {
				break;
			}	
			p = BonCautat->getNext( );
		}

		/* Avansam in listaTranzactii */
		tranzactie = tranzactie->getNext( );
	}

	/* Gasim categoria cea mai vanduta pt fiecare magazin: calculam maximul pe fiecare linie din matricea a */
	int CategorieMaxima, i, j, maxim;
	for( i = 0; i < nrMagazine; ++i) {
		CategorieMaxima = 0;
		maxim = 0;
		gasitMagazin = cautareInMagazin( listaMagazine, i + 1 );
		for( j = 0; j < nrCategorii; ++j ) {
			if( a[ i ][ j ] > CategorieMaxima ) {
				CategorieMaxima = j;
				maxim = a[ i ][ j ];

			}

		}
		gasitCategorie = cautareInCategorii( listaCategorii, CategorieMaxima );

		cout<< "magazinul "<< gasitMagazin->getValue( ).getLocatieMagazin( )<<" are categoria cea mai vanduta "<<gasitCategorie->getValue( ).getNumeCategorie( )<<endl;
	}	

}