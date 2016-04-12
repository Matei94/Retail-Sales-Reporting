#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Categorie.h"
#include "Tranzactie.h"
#include "LinkedList.h"
#include "Bon.h"
#include "Produs.h"
#include "Magazin.h"
#include "Node.h"
using namespace std;

/* Taskul 1_3: */
void task1_3( unsigned long long suma, int length, LinkedList<Tranzactie> &listaTranzactii ) {
	double valoare_cos_mediu;
	cout<<suma<<" "<<length<<endl;
	/* cosul mediu este raportul dintre suma totala aflata de la task 1_2 si numarul de tranzactii */
	valoare_cos_mediu = double( suma )/double( length );

	/* Afisare valoarea cosului mediu */
	cout<<valoare_cos_mediu<<endl;	
}