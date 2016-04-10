#include<fstream>
#include<iostream>
#include<sstream>
#include<sting>

#include "Task2_2.h"

using namespace std;

void task2_1(LinkedList<Tranzactie> listaTranzactii, LinkedList<Magazin> listaMagazine, LinkedList<Bon> listaBonuri, int nrZile){
	ofstream output ("Task2_1.out");
	Tranzactie* tranzactie = listaTranzactii.front();
	int nrMagazine = 0;
	Magazin* magazin = listaMagazine.front();
	Bon* bon;
	while (magazin != NULL){
		nrMagazine++;
		magazin = magazin->getNext();
	}
	int** produse;
	int i, j, sortat, aux;
	produse = new int*[nrMagazine + 1];

	for (i = 0; i <= nrMagazine; i++){
		produse[i] = new int[367];
	}
	while (tranzactie != NULL){
		bon = listaBonuri.front();
		while (bon != NULL){
			if (bon.getIdBon() == tranzactie.getIdBon()){
				produse[tranzactie.getIdMagazin()][ziuaTranzactiei( tranzactie.getTimeStamp() )]++;
			}
			bon = bon->getNext();
		}
		tranzactie = tranzactie->getNext();
	}

	int** permutare;
	permutare = new int*[nrMagazine + 1];

	for (i = 0; i <= nrMagazine; i++){
		permutare[i] = new int[367];
	}

	for (i = 1; i <= nrMagazine; i++){
		for (j = 1; j <= 366; j++){
			permutare[i][j] = j;
		}
	}

	for (i = 1; i <= nrMagazine; i++){
		sortat = 0;
		while (sortat == 0){
			sortat = 1;
			for (j = 1; j < 366; j++){
				if (produse[i][j] < produse[i][j + 1]){
					aux = produse[i][j];
					produse[i][j] = produse[i][j + 1];
					produse[i][j + 1] = aux;
					aux = permutare[i][j];
					permutare[i][j] = permutare[i][j + 1];
					permutare[i][j + 1] = aux;
					sortat = 0;
				}
			}
		}
	}

	output << "Primele " << nrZile << " ca numar de produse cumparate pentru fiecare magazin in parte sunt:\n\n";
	for (i = 1; i <= nrMagazine; i++){
		output << "Magazinul " << i << ":\n";
		for (j = 1; j <= nrZile; j++){
			output << transformaInString(permutare[i][j]) << ", cu " << produse[i][j] << " produse cumparate\n\n";
		}

		output << "\n";
	}

	output.close();
}
