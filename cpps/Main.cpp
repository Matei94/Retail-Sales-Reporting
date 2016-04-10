/*
 * Placeholder pentru Main. Feel free to modify.
*/

#include <fstream>

#include "../headers/Tranzactie.h"
#include "../headers/LinkedList.h"
#include "../headers/Bon.h"
#include "../headers/Produs.h"
#include "../headers/Magazin.h"
#include "../headers/Hashtable.h"
#include "../headers/Node.h"

#include "../headers/citireTranzactii.h"
#include "../headers/citireBonuri.h"
#include "../headers/citirePaleti.h"
#include "../headers/citireCategorie.h"
#include "../headers/citireMagazine.h"
#include "../headers/citireProduse.h"
#include "../taskuri/Task2_2.h"
#include "../taskuri/Task2_3.h"

using namespace std;

int main(int argc, char **argv)
{
	/* Parsare fisiere de input */
	LinkedList<Tranzactie> listaTranzactii = LinkedList<Tranzactie>();
	citireTranzactii( listaTranzactii );

	LinkedList<Palet> listaPaleti = LinkedList<Palet>();
	citirePaleti( listaPaleti );

	LinkedList<Bon> listaBonuri = LinkedList<Bon>();
	citireBonuri( listaBonuri );

	LinkedList<Categorie> listaCategorii = LinkedList<Categorie>();
	citireCategorii( listaCategorii );

	LinkedList<Magazin> listaMagazine = LinkedList<Magazin>();
	citireMagazine( listaMagazine );

	LinkedList<Produs> listaProduse = LinkedList<Produs>();
	citireProduse( listaProduse );

	Hashtable<long,Tranzactie> HTranzactie = Hashtable<long,Tranzactie>(VMAX, Hash_long);
	Hashtable<long,Bonuri> HBonuri = Hashtable<long,Bonuri>(VMAX, Hash_long);



	// TODO 1: Cerinta 1
	// TODO 2: Cerinta 2
	// TODO 3: Cerinta 3
	// etc.

	return 0;
}
