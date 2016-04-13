#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "../../headers/LinkedList.h"
#include "../../headers/Node.h"

#include "../../headers/Produs.h"
#include "../../headers/Bon.h"
#include "../../headers/Tranzactie.h"


using namespace std;

/* Functie care initializeaza un vector cu 0 */
void initializareZero(int *v, int n) {
	for (int i = 0; i < n; i++) {
		v[i] = 0;
	}
}

void task1_5( LinkedList<Produs> &listaProduse, LinkedList<Bon> &listaBonuri, LinkedList<Tranzactie> &listaTranzactii, int numarProduse, int numarLiniiBonuri ) {
                
    ofstream output( "Rezultate.csv", ofstream::app );

    /* Alocare matrice */ 
	int matrice[ numarProduse ][ numarProduse ];                       

    /* pointerBon este pointer la inceputul listei de Bonuri */
	Node<Bon> *pointerBon = listaBonuri.front();
    
    /* prod1 si prod1 sunt poineri la inceputul listei de produse. Avem de ei la afisare la final */
    Node<Produs> *prod1 = listaProduse.front(), *prod2 = listaProduse.front();

    /* Pointer la inceputul listei de tranzactii */
    Node<Tranzactie> *pointerTranzactie = listaTranzactii.front();

    /* produseBon retine toate id-urile produselor de pe cate un bon;
    final este o matrice care tine evidenta perechilor de produse corespunzatoare maximelor din matrice */
    int produseBon[50], final[2][10];

    /* id1 si id2 le folosim pt a parcurge vectorul de produse din acelasi bon si a genera toate combinatiile posibile de perechi 
        id1max si id2max reprezinta id-urile produselor din perechile cu frecventa maxima
        ok = semafor (semnafor), plm */
    int id1, id2, id1max, id2max, ok;

    /* indice ProduseBon este un contor pt numarul de produse din vectorul anterior amintit, maxim = nr maxim de aparitii al perechilor de produse */
    int indiceProduseBon, i, j, maxim = 0;

    /* Avem novoie de o matrice pentru a contoriza prezenta fiecarei perechi de produse de pe fiecare bon 
     Initial avem 0 peste tot */
    for ( i = 0; i < numarProduse;i++) {
        for (j = 0; j < numarProduse;j++) {
            matrice[i][j] = 0;
        }
    }
    /* Parcurgem lista de tranzactii si pentru fiecare idBon, parcurgem fisierul de bonuri,
    pentru a gasi toate produsele de pe fiecare bon in parte
    Cat timp nu am ajuns la sfarsitul listei de tranzactii */
    while (pointerTranzactie != NULL) {
    	indiceProduseBon = 0;
        pointerBon = listaBonuri.front();

        /*  Cat timp nu am ajuns la sfarsitul listei de bonuri */
    	while (pointerBon != NULL) {

            /* Cand gasim produse de pe acelasi bon, le memoram intr-un vector */
    		if (pointerTranzactie->getValue().getIdBon() == pointerBon->getValue().getIdBon()) {
                ok = 1;

                /* Este posibil ca pe acelasi bon sa avem produse identice, deci introducem id-ul unui
                    produs numai daca nu exista in vector */
                for (int coco = 0; coco <= indiceProduseBon; coco++) {
    			    if (produseBon[ coco ] == pointerBon->getValue().getIdProdus()) {
                        ok = 0;
                    }
                }
                if (ok == 1) {  
                    produseBon[indiceProduseBon] = pointerBon->getValue().getIdProdus();
                	indiceProduseBon++;
                }
    		}
            /* Mergem mai departe in lista de bonuri */
    		pointerBon = pointerBon->getNext();
    	}
        /* Pentru un vector de produse de pe acelasi bon, facem combinari de numarProduse luate cate 2 */
        for (i = 0; i < indiceProduseBon; i++) {
                id1 = produseBon[i];

            for (j = i + 1;j < indiceProduseBon; j++) {
                id2 = produseBon[j]; 
                
                /* Id-urile produselor sunt intregi de la 1 la numarProduse.
                 Deci crestem pe pozitia corespunzatoare in matrice cu 1 */
                matrice[id1-1][id2-1]++;
                matrice[id2-1][id1-1]++;
                
                /* In acelasi timp cautam numarul maxim de aparitii al perechilor de produse */
                if( matrice[id2-1][id1-1] > maxim) {
                    maxim = matrice[id2-1][id1-1];    
                }
                
            }
        }

        /* Dupa ce nu mai avem nevoie de produsele de pe un bon, le stergem */
        initializareZero(produseBon, indiceProduseBon);

        /* Mergem mai departe in lista de tranzactii */
    	pointerTranzactie = pointerTranzactie->getNext();

    }
    /* Pentru un numar maxim de aparitii al perechilor de produse, consideram o matrice cu 2 linii pentru
    a memora id-urile produselor din fiecare pereche care apar de 'maxim' ori. */
    int k = 0;
    for (i = 1; i < numarProduse; i++) {
        for (j = 0; j < i; j++) {
            if (matrice[i][j] == maxim) {
                final[0][k] = i + 1;
                final[1][k] = j + 1;
                k++;
            }
        }
   }
   
   output<<"\n\nTask-ul 1_5:\n\n";

    /* Afisarea numelor produselor corespunzatoare id-urilor gasite */
    output<<"Cele mai vandute perechi sunt:"<<"\n";
    for (int k2 = 0; k2 < k; k2++) {

        /* Pentru perechea de id-uri vom cauta in lista de produse numele acestora si le afisam */
        while ( prod1->getNext() != NULL) {
            if( prod1->getValue().getIdProdus() == final[0][k2]) {
                break;
            }
            prod1 = prod1->getNext();
        }
        output<<prod1->getValue().getNumeProdus()<<"----";
        prod1 = listaProduse.front();

        while ( prod2->getNext() != NULL) {
            if( prod2->getValue().getIdProdus() == final[1][k2]) {
                break;
            }
            prod2 = prod2->getNext();
        }
        output<<prod2->getValue().getNumeProdus()<<"\n";
        prod2 = listaProduse.front();
    } 
    output.close(); 
}
