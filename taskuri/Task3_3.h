#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include "../headers/LinkedList.h"
#include "../headers/Node.h"

using namespace std;

//Functia care compara compara data a 2 elemente
void compareDate(string timp1,string timp2){
	
	result = strcmp(timp1, timp2);

	if( result > 0 ){
		return 1;
	}// timp1 e mai mare
   	else{	
   			if( result < 0 ){
   				return -1;
   			} // timp2 e mai mare
   			
   			else{
   				return 0;
   			}// sunt egale
   		}
}

// Functia sortareBonuri ordoneaza lista de bonuri dupa data preluata din lista de Tranzactii
void sortareBonuri(){
		//Momentan consideram lista sortata
}


int cererePalet(int idMagazin,Palet* palet){
		//cate produse erau la inceput
		while (palet != NULL){
			
			// idProd = palet.getProdType;  // Va fi apelat separat inainte de aceasta functie
			int numarProdusePalet= palet.getNumberOfItems();
			palet = palet->getNext();
			return numarProdusePalet;
		}
}

void Task3_3(LinkedList<Bon> listaBonuri, LinkedList<Tranzactie> listaTranzactii, LinkedList<Produs> listaProduse, LinkedList<Palet> listaPaleti){

		ofstream output ("Task3_3.out");

		Tranzactie* tranzactie = listaTranzactii.front();
		Bon* bon = listaBonuri.front();
		Produs* produs = listaProduse.front();
		Palet* palet = listaPaleti.front();

		// aflare cate tipuri de produse avem
		int idProdMax = bon.getIdProdus;
		while (bon != NULL){

			int idProd = bon.getIdProdus();
			if (id.Prod > idProdMax){
				idProdMax = id.Prod;
			}
			
			bon = bon->getNext();
		}

		// aflare cate magazine avem
		int idMagazinMax = tranzactie.getIdMagazin;
		while (tranzactie != NULL){

			int idMagazin  = bon.getIdMagazin();
			if (idMagazin > idMagazinMax){
				idMagazinMax = id.idMagazin;
			}
			
			tranzactie = tranzactie->getNext();
		}

		
		


		int vectorProd = new int[idProdMax][idMagazinMax];

		int contor = new int[idProdMax][idMagazinMax];
			for (int i = 1; i <= idProdMax; i++){
				for(int j = 1; j<= idMagazinMax; j++){

					contor[i][j] = 0; // magazinul j nu a fost aprovizionat cu produsul i
				}
			}

		//cate produse avem la magazin la inceput 
		//prima aprovizionare
		for (int i=1; i <= idMagazinMax; i++){

			idProd = palet.getProdType;
			if( contor[idProd][i] == 0  ){ // daca este neaprovizionat
			
				vectorProd[idProd][i] = cererePalet(idMagazin, palet);
			}
		}






		//cate produse din fiecare tip au ramas in fiecare magazin
		bon = listaBonuri.front();
		while (bon != NULL){

			int idProd = bon.getIdProdus();
			int idBon = bon.getIdBon();

			tranzactie = listaTranzactii.front();
			while(tranzactie != NULL){
				
				if(idBon == tranzactie.getIdBon()){
					int idMagazin = tranzactie.getIdMagazin();
				}
				tranzactie = tranzactie->getNext();
			}

			vectorProd[idProd][idMagazin] = vectorProd[idProd][idMagazin] - 1;

			//verificare daca am ajuns la 10% dintr un produs	
			if ( vectorProd[idProd][idMagazin] = 0.1 * nrProduseMax ) //trebuie lucrat la nrProduseMax

					//daca comanda nu poate fi onorata se afiseaza contorul , adaugat inca o conditie, inca nu m-am prins cum anume
					vectorProd[idProd][idMagazin] = vectorProd[idProd][idMagazin] + cererePalet(idMagazin, palet); // la ceea ce mai ramasese in magazin se adauga noul palet
					
			
			bon = bon->getNext();
		}

		
		
		

		output.close();
	}
}