#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../../headers/Node.h"
#include "../../headers/LinkedList.h"

#include "../../headers/Categorie.h"
#include "../../headers/Tranzactie.h"
#include "../../headers/Bon.h"
#include "../../headers/Produs.h"
#include "../../headers/Magazin.h"
using namespace std;

/* Taskul 1_3: */
void task1_3( unsigned long long suma, int length, LinkedList<Tranzactie> &listaTranzactii ) {
	ofstream output( "Rezultate.csv", ofstream::app );
	double valoare_cos_mediu;
	/* cosul mediu este raportul dintre suma totala aflata de la task 1_2 si numarul de tranzactii */
	valoare_cos_mediu = double( suma )/double( length );

	output<<"\n\nTask-ul 1_3:\n\n";

	/* Afisare valoarea cosului mediu */
	output<<"Valoarea cosului mediu: "<<valoare_cos_mediu<<"\n";	

	output.close();
}