#include<fstream>
#include<iostream>
#include<sstream>
#include<string>

#include "LinkedList.h"
#include "Magazin.h"
#include "Bon.h"
#include "Tranzactie.h"
using namespace std;

//Functia ziuaTranzactiei1 returneaza in a cata zi din an s-a efectuat tranzactie cu timeStamp-ul dat ca parametru
int ziuaTranzactiei1( string timeStamp ){
	//zile[i] reprezinta numarul de zile de la inceputul anului pana la sfarsitul lunii i;
	int zile[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
	return zile[stoi( timeStamp.substr( 5, 2 ) ) - 1] + stoi( timeStamp.substr( 8, 2 ) );
}

//Functia transformaInString1 returneaza un string de tipul 2016-luna-ziua, corespunzator zilei din an primite ca parametru
string transformaInString1 (int ziuaAnului){
	//zile[i] reprezinta numarul de zile de la inceputul anului pana la sfarsitul lunii i
	int zile[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
	int luna = 1, i, ziua;
	for (i = 0; i < 12; i++){
		if (zile[i] < ziuaAnului && ziuaAnului <= zile[i + 1]){
			luna = i + 1;
			ziua = ziuaAnului - zile[i];
			break;
		}
	}

	string lunaString = to_string(luna);
	string ziuaString = to_string(ziua);
	string s;

	//Daca luna sau ziua au doar o cifra, pun un 0 pe prima pozitie a stringului
	if (luna < 10){
		lunaString = "0" + lunaString;
	}
	if (ziua < 10){
		ziuaString = "0" + ziuaString;
	}

	s = "2016-" + lunaString + "-" + ziuaString;
	return s;
}

void task2_1(LinkedList<Tranzactie> listaTranzactii, LinkedList<Magazin> listaMagazine, LinkedList<Bon> listaBonuri, int nrZile){
	ofstream output ("Task2_1.out");
	Node<Tranzactie>* tranzactie = listaTranzactii.front();
	int nrMagazine = 0;
	Node<Magazin>* magazin = listaMagazine.front();
	Node<Bon>* bon;
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

	for (i = 0; i <= nrMagazine; i++){
		for (j = 0; j <=366; j++){
			produse[i][j] = 0;
		}
	}

	while (tranzactie != NULL){
		bon = listaBonuri.front();
		while (bon != NULL){
			if (bon->getValue().getIdBon() == tranzactie->getValue().getIdBon()){
				produse[tranzactie->getValue().getIdMagazin()][ziuaTranzactiei1( tranzactie->getValue().getTimeStamp() )]++;
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

	output << "id_magazin,data,numar_produse\n";
	for (i = 1; i <= nrMagazine; i++){
		for (j = 1; j <= nrZile; j++){
			output << i << "," << transformaInString1(permutare[i][j]) << "," << produse[i][j] << "\n";
		}

	}

	output.close();
}
