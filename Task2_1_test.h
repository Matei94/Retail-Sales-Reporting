#include<stdio.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>

#include "LinkedList.h"

using namespace std;


void task2_1( LinkedList<Tranzactii> totTranzactii, LinkedList<Tranzactii> nrProduse ) { 
	ofstream output("Task2_1.out");

	Tranzactie tranzactie = totTranzactii.front();
	Tranzactie listaNrProduse = nrProduse.front();

	// trebuie umpluta lista totTranzactii cu toate tranzactiile 

	int ok = 1;
	while( tranzactie ) { //parcurgere lista de tranzactii
		if ( timestamp_tranzactie == timestamp_lista ) { // daca se gaseste un timpestamp care mai exista in lista de produse se creste nr de produse 
		
			ok = 0 ;
			nrprodus_lista ++;
		}
		else{ // daca nu , se adauga un nou nod cu timestampul respectiv
			add new node;
			nrProduse = 1;
		}
	}
}
