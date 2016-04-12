#include <iostream>
#include <string>
#include <fstream>

#include "headers/Produs.h"
#include "headers/LinkedList.h"
#include "headers/Hashtable.h"

using namespace std;


/*	
  numeProdusCautat - numele produsului pe care il primim ca parametru 
  hashmap - hashtable-ul pe care lucram
  listaProduse - lista produselor citite din fisier
  contorIndex - vectorul ce retine capacitatea fiecarui slot/ fiecarei stive de paleti 
*/
void task3_2 ( string numeProdusCautat, Hashtable< int, Pereche > hashmap, LinkedList<Produs> listaProduse, int contorIndex[] ) {
	/* parcurgere - pointerul cu care se va parcurge lista de produse, in cautarea elementului care are numeProd == numeProdusCautat */
	Node<Produs> *parcurgere = listaProduse.front();

	int idProdus = -1;


	/* Se parcurge lista de produse */
	while ( parcurgere != NULL ) {
		/* Se extrage numele produsului elementului curent din lista */
		string numeProdus = parcurgere->getValue().numeProd();
		/* Daca se gaseste elementul cautat, se tine idProdus, echivalentul lui prodType in clasa Palet */
		if ( numeProdus == numeProdusCautat ) {
			idProdus = parcurgere->getValue().idProdus();
			break;
		}
		/* Se muta pointerul de parcurgere asupra urmatorului element din lista */
		parcurgere = parcurgere->getNext();
	}

	/* Daca tipul de produs cautat nu a fost gasit, se afiseaza un mesaj de eroare, in caz contrar: */
	if ( idProdus == -1 ) {
		fprintf(stderr, "Error 302 - The product you were looking for was not found.\n")
		return;
	} else {
		
	}
}