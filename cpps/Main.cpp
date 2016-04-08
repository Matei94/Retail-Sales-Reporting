/*
 * Placeholder pentru Main. Feel free to modify.
*/

#include <fstream>

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
	listaTranzactii = LinkedList<Tranzactie>();
	citireTranzactii( listaTranzactii );

	listaPaleti = LinkedList<Palet>();
	citirePaleti( listaPaleti );

	listaBonuri = LinkedList<Bon>();
	citireBonuri( listaBonuri );

	listaCategorii = LinkedList<Categorie>();
	citireCategorii( listaCategorii );

	listaMagazine = LinkedList<Magazin>();
	citireMagazine( listaMagazine );

	listaProduse = LinkedList<Produs>();
	citireProduse( listaProduse );	


	// TODO 1: Cerinta 1
	// TODO 2: Cerinta 2
	// TODO 3: Cerinta 3
	// etc.

	return 0;
}
