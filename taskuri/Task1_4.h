#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


#include "Tranzactie.h"
#include "LinkedList.h"
#include "Bon.h"
#include "Produs.h"
#include "Magazin.h"
#include "Hashtable.h"
#include "Node.h"
/*
#include <BABY>
#include <BAAAABY>
*/

using namespace std;

// Sarumana mult Roxana :x :)). Copyright se stie

/* Cauta in lista de bonuri un obiect al carui idBon == elem incepand cu pozitia p*/
Node<Bon>* cautareInBonuri( Node<Bon> *p, LinkedList<Bon>& listaBonuri, string elem ) {
	
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



void task1_4(LinkedList<Tranzactie> listaTranzactii, LinkedList<Bon> listaBonuri, LinkedList<Produs> listaProduse,  LinkedList<Magazin> listaMagazine){
	ofstream output ("Task1_4.out");
	Node <Tranzactie> *tranzactie = listaTranzactii.front();
	int nrMagazine = 0, nrCategorii = 0;
	Node <Magazin> *magazin = listaMagazine.front();
	Node <Categorie> *categorie = listaCategorie.front();

	while (magazin != NULL){
		nrMagazine++;
		magazin = magazin->getNext();
	}
	while (categorie != NULL){
		nrCategorii++;
		categorie = categorie->getNext();
	}
	int a[nrMagazine + 1][nrCategorii + 1] = {0};
/* Conform celorlalte functii create pana acum, noi avem o lista cu fiecare chesie. O lista de produse, o lista 
de tranzactii, etc*/
	while (tranzactie != NULL) {
		//Retinem idMagazin si idBon aferente tranzactiei
		string idMagazin = tranzactie->getValue().getIdMagazin();
		string idBon = tranzactie->getValue().getIdBon();
		/*O sa avem mai multe produse pe un bon...Deci trebuie sa cautam toate aparitiile lui bon 
		  in bonuri si sa le prelucram*/
		/* Incepem de la front */
		Node<Bon> *p = listaBonuri.front( );
		while (p != NULL) {
			/* Boncautat e un pointer la Bonul cu id-ul idbon */
			Node<Bon> *Boncautat = cautareInBonuri (p, listaBonuri, idBon);
			/* IdprodusCautat e id-ul produsului din bonul Boncautat cu care mergem in Produse sa ii vedem categoria*/
			int IdprodusCautat = Boncautat->getValue().getIdProdus();
			int IdcategorieprodusCautat = cautareInProduse (listaProduse, IdprodusCautat);
			/* Incrementam in matricea a la linia si coloana corespunzatoare, aferenta, cum ne place noua */
			a[idMagazin][IdcategorieprodusCautat]++;
			/* Il vacem pe p ca fiind Boncautat->Next pentru a afla urmatoarea aparitie a Bon */
			p = Boncautat->getNext();
		}
		/* Avansam in listaTranzactii */
		tranzactie = tranzactie->getNext();
	}
	/* Gasim maximul */
	int categoriemaxima = 0;
	for (i = 0; i < nrMagazine; i++)
		for (j = 0; j < nrCategorii; j++)
			if (a[i][j] > max)
				max = a[i][j];
	
	/* Afisam coordonatele tuturor elementelor egale cu maxim */
	for (i = 0; i < nrMagazine; i++)
		for (j = 0; j < nrCategorii; j++)
			if (a[i][j] == max)
				cout << "In magazinul "<<i<<" se vinde cel mai bine "<<j<<endl;

}