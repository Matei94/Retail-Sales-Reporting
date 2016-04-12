#include <iostream>
#include <string>
#include <fstream>

#include "headers/Produs.h"
#include "headers/Palet.h"
#include "headers/ArrayList.h"
#include "headers/LinkedList.h"
#include "headers/Hashtable.h"
#include "Task3_1.h"
#include "Task3_2.h"

#define NR_SLOTS 30

using namespace std;

/* functia de citire pentru paleti */
void citirePaleti( LinkedList<Palet>& listaPaleti ){
    ifstream paleti ( "paleti.csv" );
    string linieFisier;
    getline( paleti, linieFisier );
    while ( getline( paleti, linieFisier ) ){
            listaPaleti.addLast ( Palet ( linieFisier ) );
    }
    paleti.close();
}

/* functia de citire pentru produse */
void citireProduse( LinkedList<Produs>& listaProduse ){
	ifstream produse ( "produse.csv" );
	string linieFisier;
	getline( produse, linieFisier );
	while ( getline( produse, linieFisier ) ){
		listaProduse.addLast ( Produs ( linieFisier ) );
	}
	produse.close();
}

/* task3 */
void task3 ( LinkedList<Produs>& listaProduse, LinkedList<Palet>& listaPaleti ){
	/* nrProduse = numarul de produse din listaProduse / citite din fisier */
	Node<Produs> *numarare = listaProduse.front();
	int nrProduse = 0;

	while( numarare != NULL ){
		numarare = numarare->getNext();
		nrProduse++;
	}
	
	/* hashmap - hashtable cu nrProduse bucketuri, avand cheia de tip int si valoarea de tip Pereche (simuleaza un vector de frecventa, de fapt)*/
	Hashtable<int,Pereche> hashmap = Hashtable<int,Pereche>( nrProduse );

	/* slots - vector de NR_SLOTS LinkedList-uri */
	//ArrayList<Palet> slots = ArrayList<Palet>( NR_SLOTS );

	/* contorIndex - retine indexul curent al fiecarui Slot */
	int contorIndex [ NR_SLOTS + 1 ] = { 0 };
	
	/* parcurgere - pointer la inceputul listei de paleti */
	Node<Palet> *parcurgere = listaPaleti.front();
	/* pair - structura definita in Hashtable.h */
	Pereche pair;

	/* Se parcurge lista de paleti, atat timp cat exista elemente */
	while( parcurgere != NULL ) {

		/* pair.idSlot - Retine valoarea idSlot-ului elementului curent din lista */
		pair.idSlot = parcurgere->getValue().getIdSlot();
		/* Se insereaza in vectorul slots, la indexul pair.idSlot, elementul din lista curenta */ 
		//slots.push( pair.idSlot, parcurgere->getValue() );
		/* Se incrementeaza indexul curent aferent slotului pe care se lucreaza acum, semn ca s-a mai introdus un palet in slotul curent */
		contorIndex[ pair.idSlot ]++; 
		/* Se retine si in elementul curent, indexul la care a fost inserat */
		pair.indexSlot = contorIndex[ pair.idSlot ];
		/* Se insereaza in hashtable, in bucketul "parcurgere->getValue().getProdType()", elementul "pair" */
		hashmap.Insert( parcurgere->getValue().getProdType(), pair );
		/* Mutam pointerul asupra elementului urmator din lista */
		parcurgere = parcurgere->getNext();
	}
	task3_1( listaProduse, hashmap, "bicycle" );

	task3_2( listaProduse, hashmap, contorIndex, "bicycle" );

	//hashmap.printTable();
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