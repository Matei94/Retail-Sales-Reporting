#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Bon.h"
#include "Tranzactie.h"
#include "LinkedList.h"
#include "citireTranzactii.h"
#include "citireBonuri.h"
#include "Task3_3.h"

using namespace std;

int main ( ) {
	/* Parsare fisiere de input */
	LinkedList<Tranzactie> listaTranzactii;
	citireTranzactii( listaTranzactii );	

	LinkedList<Bon> listaBonuri;
	citireBonuri( listaBonuri );		

	task3_3( listaTranzactii );

	return 0;
}