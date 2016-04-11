#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


#include "../headers/Produs.h"
#include "../headers/Bon.h"
#include "../headers/LinkedList.h"
#include "../headers/Node.h"
//#include "Hashtable.h"

using namespace std;

/* Functie care initializeaza un vector cu 0 */
void initializareZero(int *v, int n) {
	for (int i = 0; i < n; i++) {
		v[i] = 0;
	}
}

void task1_5(LinkedList<Produs> &listaProduse, LinkedList<Bon> &listaBonuri) {

    // Numarul total de produse din fisier
	int numarProduse = listaProduse.numberOfNodes();      

    // Destul de clar
	int numarLiniiBonuri = listaBonuri.numberOfNodes();                

    // Alocare matrice triunghiulara
	int matrice[numarProduse][numarProduse];                       

    // Vectorul vizitat memoreaza daca am vizitat un nod din listaBonuri 
	int vizitat[numarLiniiBonuri];

    // Bagam niste zero-uri ca asa e frumos 
	initializareZero(vizitat, numarLiniiBonuri);

    // Pentru fiecare bon avem niste id-uri de produse, pe care le bagam in acest vector
    // Dupa ce ne facem mendrele cu id-urile de pe bon, le aruncam la cos
    
	int produseBon[50];

	int id1, id2, id1max, id2max;

	int indiceVizitat, indiceProduseBon, indiceVizitatAvans, i, j, maxim = 0;

	Node<Bon> *auxiliar = listaBonuri.front(), *auxiliar2;

    Node<Produs> *prod1 = listaProduse.front(), *prod2 = listaProduse.front();

    // Aici incepe partea amuzanta :)). Numele variabilelor sunt sugestive, deci o sa fie ca o poveste, putin repetitiva ;) 
    // Indice pentru vectorul vizitat
    indiceVizitat = 0;

    // Parcurgem nodurile din listaBonuri cu auxiliar si auxiliar2.
    //   Aici incepe auxiliar, el se misca mai greu decat auxiliar2 
    while ( auxiliar != NULL) {
         
        auxiliar2 = auxiliar->getNext();

        // Am vizitat nodul corespunzator lui auxiliar
        vizitat[indiceVizitat] = 1;
    
        // Marim indicele de vizitare pentru urmatorul nod
        indiceVizitat++;
    
        // Si pentru auxiliar2 avem nevoie de un indice de vizitare. 
        indiceVizitatAvans = indiceVizitat;
        
        // La inceput nu avem niciun produs pentru un bon
        indiceProduseBon = 0;
    
        // Memoram id-ul produsului corespunzator lui auxiliar
        produseBon[indiceProduseBon] = auxiliar->getValue().getIdProdus();
        
        // Va creste numarul de produse(indice)
        indiceProduseBon++;

        // Pentru fiecare auxiliar, un auxiliar2 va parcurge toata lista de bonuri
        while ( auxiliar2 != NULL) {
            
            // Avem nevoie de cazurile in care avem acelasi bon si nu l-am mai vizitat 
            if ( auxiliar->getValue().getIdBon() == auxiliar2->getValue().getIdBon() && vizitat[indiceVizitatAvans] == 0) {

                // Daca am gasit ceva, se pune ca l-am vizitat
                vizitat[indiceVizitatAvans] = 1;

                // Adaugam id-ul produsului in vectorul de produse
                produseBon[indiceProduseBon] = auxiliar2->getValue().getIdProdus();

                indiceProduseBon++;

                auxiliar2 = auxiliar2->getNext();
            } else {
                // Daca nu am gasit alte produse pentru acelasi bon, doar mergem mai departe 
                auxiliar2 = auxiliar2->getNext();
            }
        } 

        // Pentru un vector de produse de pe acelasi bon, facem combinari de numarProduse luate cate 2 
        for (i = 0; i < indiceProduseBon; i++) {
                id1 = produseBon[i];

            for (j = i + 1;j < indiceProduseBon; j++) {

                id2 = produseBon[j];

                // In matrice cautam in acelasi timp maximul de aparitii pentru o pereche.
                // Se stie ca numarul coloanei va fi < numarul liniei  
                if (id1 > id2) {
                    
                    // Id-urile produselor sunt intregi de la 1 la numarProduse.
                    // Deci crestem pe pozitia corespunzatoare in matrice cu 1 
                    matrice[id1][id2]++;

                    if( matrice[id1][id2] > maxim) {
                        maxim = matrice[id1][id2];
                        id1max = id1;
                        id2max = id2;
                    }
                }
                else {
                    // Aici se procedeaza la fel
                    matrice[id2][id1]++;

                    if( matrice[id2][id1] > maxim) {
                        maxim = matrice[id2][id1];
                        id1max = id1;
                        id2max = id2;
                    }
                }
            }
        }
        // Dupa ce nu mai avem nevoie de produsele de pe un bon, le stergem 
        initializareZero(produseBon, indiceProduseBon);

        // auxiliar trece mai departe
        
    //    cout<<auxiliar->getValue().getIdBon();
    	auxiliar = auxiliar->getNext();
       
	}

    // Pentru perechea de id-uri vom cauta in lista de produse numele acestora si le afisam
    while ( prod1 != NULL) {
        if( prod1->getValue().getIdProdus() == id1max) {
            break;
        }
        prod1 = prod1->getNext();
    }


    while ( prod2 != NULL) {
        if( prod2->getValue().getIdProdus() == id2max) {
            break;
        }
        prod2 = prod2->getNext();
    }
  	
	cout<<"Cea mai vanduta pereche este ( "<< prod1->getValue().getNumeProdus() <<" , "<< prod2->getValue().getNumeProdus()<<')' << endl;

   
} 
