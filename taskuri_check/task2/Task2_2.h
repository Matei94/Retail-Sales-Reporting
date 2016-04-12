#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include "LinkedList.h"
#include "Tranzactie.h"
#include "Magazin.h"

using namespace std;

//Functia ziuaTranzactiei returneaza in a cata zi din an s-a efectuat tranzactie cu timeStamp-ul dat ca parametru
int ziuaTranzactiei( string timeStamp ){
	//zile[i] reprezinta numarul de zile de la inceputul anului pana la sfarsitul lunii i;
	int zile[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
	return zile[stoi( timeStamp.substr( 5, 2 ) ) - 1] + stoi( timeStamp.substr( 8, 2 ) );
}

//Functia transformaInString returneaza un string de tipul 2016-luna-ziua, corespunzator zilei din an primite ca parametru
string transformaInString (int ziuaAnului){
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

//Parametrul nrZile este citit de la tastatura in momentul rularii programului si arata primele cate zile vor fi afisate
void task2_2(LinkedList<Tranzactie>& listaTranzactii, LinkedList<Magazin>& listaMagazine, int nrZile){
	ofstream output ("Task2_2.out");
	Node<Tranzactie>* tranzactie = listaTranzactii.front();
	int nrMagazine = 0;
	Node<Magazin>* magazin = listaMagazine.front();
	while (magazin != NULL){
		nrMagazine++;
		magazin = magazin->getNext();
	}
	int** cumparatori;
	int i, j, sortat, aux;
	cumparatori = new int*[nrMagazine + 1];

	for (i = 0; i <= nrMagazine; i++){
		cumparatori[i] = new int[367];
	}

	for (i = 0; i <= nrMagazine; i++){
		for (j = 0; j <=366; j++){
			cumparatori[i][j] = 0;
		}
	}

	while (tranzactie != NULL){
		cumparatori[tranzactie->getValue().getIdMagazin()][ziuaTranzactiei( tranzactie->getValue().getTimeStamp() )]++;
		tranzactie = tranzactie->getNext();
	}

	//In continuare, trebuie sa sortez fiecare linie din matricea cumparatori, insa trebuie sa tin minte ce elemente am interschimbat.
	/*Pentru aceasta, folosesc o matrice de permutare, pentru a putea afla la final carei zile ii apartine numarul cel mai mare de
	cumparatori.*/

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

	/*In acest moment, pe fiecare linie din matricea de permutare, pe pozitia j se afla numarul j. Cand fac sortarea descrescatoare a
	liniilor matricei cumparatori si interschimb doua elemente, voi interschimba si matricea de permutare. In final, in permutare[i][1]
	voi avea un numar ce reprezinta a cata zi din an a avut cei mai multi cumparatori in magazinul i*/
	for (i = 1; i <= nrMagazine; i++){
		sortat = 0;
		while (sortat == 0){
			sortat = 1;
			for (j = 1; j < 366; j++){
				if (cumparatori[i][j] < cumparatori[i][j + 1]){
					aux = cumparatori[i][j];
					cumparatori[i][j] = cumparatori[i][j + 1];
					cumparatori[i][j + 1] = aux;
					aux = permutare[i][j];
					permutare[i][j] = permutare[i][j + 1];
					permutare[i][j + 1] = aux;
					sortat = 0;
				}
			}
		}
	}

	output << "id_magazin,data,numar_cumparatori\n";
	for (i = 1; i <= nrMagazine; i++){
		for (j = 1; j <= nrZile; j++){
			output << i << "," << transformaInString(permutare[i][j]) << "," << cumparatori[i][j] << "\n";
		}
	}

//Dezalocare
	for (int i = 0; i <= nrMagazine; i++) {
  		delete[] cumparatori[i];
	}
	delete[] cumparatori;

	for (int i = 0; i <= nrMagazine; i++) {
  		delete[] permutare[i];
	}
	delete[] permutare;

	output.close();
}
