#include <iostream>
#include <string>
#include <fstream>

#include "headers/Produs.h"
#include "headers/Palet.h"
#include "headers/ArrayList.h"
#include "headers/LinkedList.h"
#include "headers/Hashtable.h"

#define NR_SLOTS 30

using namespace std;

void citirePaleti( LinkedList<Palet>& listaPaleti ){
    ifstream paleti ( "paleti.csv" );
    string linieFisier;
    getline( paleti, linieFisier );
    while ( getline( paleti, linieFisier ) ){
            listaPaleti.addLast ( Palet ( linieFisier ) );
    }
    paleti.close();
}

void citireProduse( LinkedList<Produs>& listaProduse ){
	ifstream produse ( "produse.csv" );
	string linieFisier;
	getline( produse, linieFisier );
	while ( getline( produse, linieFisier ) ){
		listaProduse.addLast ( Produs ( linieFisier ) );
	}
	produse.close();
}

void task3 ( LinkedList<Produs>& listaProduse, LinkedList<Palet>& listaPaleti ){
	Node<Produs> *numarare = listaProduse.front();
	int nrproduse = 0;

	while( numarare != NULL ){
		numarare = numarare->getNext();
		nrproduse++;
	}
	
	Hashtable<int,Pereche> hashmap = Hashtable<int,Pereche>( nrproduse );

	ArrayList<Palet> slots = ArrayList<Palet>( NR_SLOTS );

	int contorIndex [ NR_SLOTS + 1 ] = { 0 };
	
	Node<Palet> *parcurgere = listaPaleti.front();
	Pereche pair;

	while( parcurgere != NULL ) {

		pair.idSlot = parcurgere->getValue().getIdSlot();
		pair.indexSlot = 0; 
		slots.push( pair.idSlot, parcurgere->getValue() );
		contorIndex[ pair.idSlot ]++; 
		pair.indexSlot = contorIndex[ pair.idSlot ];
		hashmap.Insert( parcurgere->getValue().getProdType(), pair );
		parcurgere = parcurgere->getNext();
	}
	hashmap.printTable();
	
	for( int i = 1; i <= NR_SLOTS; i++ ) {
		cout<<"slotul "<<i<<": "<<endl;
		while( !slots.isEmpty(i) ){
			Palet prost = slots.pop(i);
			cout<<prost.getIdPalet()<<" "<<prost.getProdType()<<" "<<prost.getNumberOfItems()<<' '<<prost.getIdSlot()<<endl;
		}
	}
}

int main (){

	LinkedList<Palet> listaPaleti;
	citirePaleti( listaPaleti );

	LinkedList<Produs> listaProduse;
	citireProduse( listaProduse );

	task3( listaProduse, listaPaleti );	
/*
	ArrayList<Palet> slots = ArrayList<Palet>( NR_SLOTS );
	Node<Palet> *aux = listaPaleti.front();
	slots.push(1,aux->getValue());
	cout<<slots.peek(1).getIdPalet()<<' '<<slots.peek(1).getProdType()<<' '<<slots.peek(1).getNumberOfItems()<<' '<<slots.peek(1).getIdSlot()<<endl;
	aux = aux->getNext();
	slots.push(1,aux->getValue());
	cout<<slots.peek(1).getIdPalet()<<' '<<slots.peek(1).getProdType()<<' '<<slots.peek(1).getNumberOfItems()<<' '<<slots.peek(1).getIdSlot()<<endl;
	aux = aux->getNext();
	slots.push(1,aux->getValue());
	cout<<slots.peek(1).getIdPalet()<<' '<<slots.peek(1).getProdType()<<' '<<slots.peek(1).getNumberOfItems()<<' '<<slots.peek(1).getIdSlot()<<endl;
	aux = aux->getNext();
	slots.push(1,aux->getValue());
	cout<<slots.peek(1).getIdPalet()<<' '<<slots.peek(1).getProdType()<<' '<<slots.peek(1).getNumberOfItems()<<' '<<slots.peek(1).getIdSlot()<<endl;
*/

	/*
	for (int i = 1; i <= NR_SLOTS; ++i)
	{
		for (int j = 0; j <= 10; j++)
		{
			slots.push(i,j);
		}
	}
	for (int i = 1; i <= NR_SLOTS; ++i)
	{
		for (int j = 0; j <= 10; j++)
			cout<<slots.pop(i)<<' ';
		cout<<endl;
	}*/

	cout<<endl;
	return 0 ;
}