/*
 * Placeholder pentru Main. Feel free to modify.
*/

#include <fstream>

#include "../headers/citireTranzactii.h";

using namespace std;

int main(int argc, char **argv)
{
	/* Fisierele de input */
	ifstream bonuri;
	ifstream categorii;
	ifstream magazine;
	ifstream paleti;
	ifstream produse;
	ifstream tranzactii ( "tranzactii.csv" );
	listaTranzactii = LinkedList<Tranzactie>();
	citireTranzactii( listaTranzactii );



	// TODO 1: Cerinta 1
	// TODO 2: Cerinta 2
	// TODO 3: Cerinta 3
	// etc.

	return 0;
}
