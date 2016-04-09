#include<iostream>
#include<fstream>
#include<sstream>
#include "Tranzactie.h"
#include "LinkedList.h"
#include "Bon.h"
#include "Produs.h"
#include "Magazin.h"
#include "hashtable.h"
#include<string>

using namespace std;

#define Vmax 1000



int customHash(string key) {
    int hkey = 0;
    for (int i = 0; i < key.length(); i++)
        hkey = (hkey * 31 + key[i]) % Vmax;
    return hkey;
}

list_elem<Bon>* cautareInBonuri( LinkedList<Bon> listaBonuri, string elem ) {
	struct list_elem<Bon> *p = listaBonuri.front( );
	while( p != NULL) {
		if( p->info.getIdBon() == elem ){
				return p;
		}
		p = p->next;
	}
	return NULL;
}

list_elem<Produs>* cautareInProduse( LinkedList<Produs> listaProduse, int elem) {
	struct list_elem<Produs> *p = listaProduse.front( );
	while( p != NULL) {
		if( p->info.getIdProdus( ) == elem ) {
				return p;
		}
		p = p->next;
	}
	return NULL;
}
/*list_elem<Produs>* cautareInProduse2( linked_list<Produs> listaProduse, int elem) {
	struct list_elem<Produs> *p = listaProduse.front( );
	while( p != NULL) {
		if( string::compare( p->info.getId( ), elem  ) {
				return p;
		}
	}
	return NULL;
}*/

list_elem<Magazin>* cautareInMagazin( LinkedList<Magazin> listaMagazine, int elem) {
	struct list_elem<Magazin> *p = listaMagazine.front( );
	while( p != NULL) {
		if( p->info.getIdMagazin( ) == elem ) {
				return p;
		}
		p = p->next;
	}
	return NULL;
}

void task1_1( LinkedList<Tranzactie> listaTranzactii, LinkedList<Produs> listaProduse, LinkedList<Bon> listaBonuri, LinkedList<Magazin> listaMagazine ){
	Hashtable<string, int> vanzariMagazine = Hashtable<string, int>( Vmax, customHash);
	struct list_elem<Tranzactie> *p = listaTranzactii.front( );
	struct list_elem<Bon>* gasitBon;
	struct list_elem<Produs>* gasitProdus;
	struct list_elem<Magazin>* k = listaMagazine.front( );
	struct list_elem<Magazin>* gasitMagazin;
	int id_magazin, id_produs, pret; //valoare;
	string id_bon;
	while( k != NULL ) {
		vanzariMagazine.put(k->info.getLocatieMagazin( ),'0');
		k = k-> next;	
	}
	while( p != NULL ) {
		id_bon = p->info.getIdBon( );
		id_magazin = p->info.getIdMagazin( );
		gasitMagazin = cautareInMagazin( listaMagazine, id_magazin );
		gasitBon = cautareInBonuri( listaBonuri, id_bon );
		id_produs = gasitBon->info.getIdProdus( );
		gasitProdus = cautareInProduse( listaProduse, id_produs );
		pret = gasitProdus->info.getPrice( );
		//valoare = vanzariMagazine.get( gasitMagazin->info.getLocatieMagazin( ) );
	//	valoare += pret;
		vanzariMagazine[gasitMagazin->info.getLocatieMagazin( )] +=pret;
		p = p->next;
	}
}

void task1_2( LinkedList<Tranzactie> listaTranzactii, LinkedList<Produs> listaProduse, LinkedList<Bon> listaBonuri) {
	Hashtable<string, int> vanzariProduse = Hashtable<string, int>( Vmax, customHash);
	struct list_elem<Tranzactie> *p = listaTranzactii.front( );
	struct list_elem<Bon>* gasitBon;
	struct list_elem<Produs>* gasitProdus;
	struct list_elem<Produs>* k = listaProduse.front( );
	string id_bon;
	int id_produs, pret; //valoare;
	while( k != NULL ) {
		vanzariProduse.put(k->info.getNumeProdus( ),'0');
		k = k-> next;	
	}
	while( p != NULL) {
		id_bon = p->info.getIdBon( );
		gasitBon = cautareInBonuri( listaBonuri, id_bon );
		id_produs = gasitBon->info.getIdProdus( );
		gasitProdus = cautareInProduse( listaProduse, id_produs );
		pret = gasitProdus->info.getPrice( );
		//valoare = vanzariProduse.get(gasitProdus->info.getNumeProdus( ) ) ;
		//valoare +=pret;
		vanzariProduse[gasitProdus->info.getNumeProdus( )] +=pret;
		p = p->next;
	} 
}
