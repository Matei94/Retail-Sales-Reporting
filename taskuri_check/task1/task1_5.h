#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


#include "Produs.h"
#include "Bon.h"
#include "LinkedList.h"
#include "Node.h"
#include "Tranzactie.h"


using namespace std;

/* Functie care initializeaza un vector cu 0 */
void initializareZero(int *v, int n) {
	for (int i = 0; i < n; i++) {
		v[i] = 0;
	}
}

void task1_5(LinkedList<Produs> &listaProduse, LinkedList<Bon> &listaBonuri, LinkedList<Tranzactie> &listaTranzactii) {

    // Numarul total de produse din fisier
	int numarProduse = listaProduse.numberOfNodes();      

    // Destul de clar
	int numarLiniiBonuri = listaBonuri.numberOfNodes();                

    // Alocare matrice triunghiulara
	int matrice[numarProduse][numarProduse];                       

	Node<Bon> *pointerBon = listaBonuri.front();

    Node<Produs> *prod1 = listaProduse.front(), *prod2 = listaProduse.front();

    Node<Tranzactie> *pointerTranzactie = listaTranzactii.front();

    int produseBon[50], final[2][10];

    int id1, id2, id1max, id2max, ok;

    int indiceProduseBon, indiceVizitatAvans, i, j, maxim = 0;

    // A vem novoie de o matrice pentru a contoriza prezenta fiecarei perechi de produse de pe fiecare bon
    // Initial avem 0 peste tot
    for ( i = 0; i < numarProduse;i++) {
        for (j = 0; j < numarProduse;j++) {
            matrice[i][j] = 0;
        }
    }
    //  Parcurgem lista de tranzactii si pentru fiecare idBon, parcurgem fisierul de bonuri,
    //pentru a gasi toate produsele de pe fiecare bon in parte
    //  Cat timp nu am ajuns la sfarsitul listei de tranzactii
    while (pointerTranzactie != NULL) {

    	indiceProduseBon = 0;

        pointerBon = listaBonuri.front();
        //  Cat timp nu am ajuns la sfarsitul listei de bonuri
    	while (pointerBon != NULL) {
            // Cand gasim produse de pe acelasi bon, le memoram intr-un vector
    		if (pointerTranzactie->getValue().getIdBon() == pointerBon->getValue().getIdBon()) {
                ok = 1;
                // Este posibil ca pe acelasi bon sa avem produse identice, deci introducem id-ul unui
                //produs numai daca nu exista in vector
                for (int coco = 0; coco <= indiceProduseBon; coco++) {
    			    if ( produseBon[coco] == pointerBon->getValue().getIdProdus()) {
                        ok = 0;
                    }
                }
                if (ok == 1) {  
                    produseBon[indiceProduseBon] = pointerBon->getValue().getIdProdus();
                	indiceProduseBon++;
                }
    		}
            // Mergem mai departe in lista de bonuri
    		pointerBon = pointerBon->getNext();
    	}
        // Pentru un vector de produse de pe acelasi bon, facem combinari de numarProduse luate cate 2 
        for (i = 0; i < indiceProduseBon; i++) {
                id1 = produseBon[i];

            for (j = i + 1;j < indiceProduseBon; j++) {
                id2 = produseBon[j]; 
                // Id-urile produselor sunt intregi de la 1 la numarProduse.
                // Deci crestem pe pozitia corespunzatoare in matrice cu 1 
                matrice[id1-1][id2-1]++;
                matrice[id2-1][id1-1]++;
                // In acelasi timp cautam numarul maxim de aparitii al perechilor de produse
                if( matrice[id2-1][id1-1] > maxim) {
                    maxim = matrice[id2-1][id1-1];    
                }
                
            }
        }
        // Dupa ce nu mai avem nevoie de produsele de pe un bon, le stergem
        initializareZero(produseBon, indiceProduseBon);

        //  Mergem mai departe in lista de tranzactii
    	pointerTranzactie = pointerTranzactie->getNext();

    }
    //  Pentru un numar maxim de aparitii al perechilor de produse, consideram o matrice cu 2 linii pentru
    //a memora id-urile produselor din fiecare pereche care apar de 'maxim' ori.
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
   
    // Afisarea numelor produselor corespunzatoare id-urilor gasite
    cout<<"Cele mai vandute perechi sunt:"<<endl;
    for (int k2 = 0;k2 < k; k2++) {

        // Pentru perechea de id-uri vom cauta in lista de produse numele acestora si le afisam
        while ( prod1->getNext() != NULL) {
            if( prod1->getValue().getIdProdus() == final[0][k2]) {
                break;
            }
            prod1 = prod1->getNext();
        }
        cout<<prod1->getValue().getNumeProdus()<<"----";
        prod1 = listaProduse.front();

        while ( prod2->getNext() != NULL) {
            if( prod2->getValue().getIdProdus() == final[1][k2]) {
                break;
            }
            prod2 = prod2->getNext();
        }
        cout<<prod2->getValue().getNumeProdus()<<endl;
        prod2 = listaProduse.front();
    }  
}
