#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include "../headers/LinkedList.h"
#include "../headers/Node.h"

using namespace std;

//Functia care compara compara data a 2 elemente
void compareDate(string timp1,string timp2){
	
	rezultat = strcmp(timp1, timp2);

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

}

void Task3_3(LinkedList<Bon> listaBonuri, ){

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
		int idMagazinMax = tranzactie.getIdMadazin;
		while (tranzactie != NULL){

			int idMagazin  = bon.getIdMagazin();
			if (idMagazin > idMagazinMax){
				idMagazinMax = id.idMagazin;
			}
			
			tranzactie = tranzactie->getNext();
		}

		int vectorProd = new int[idProdMax][idMagazinMax];

		//cate produse erau la inceput
		while (palet != NULL){
			idProd = palet.getProdType;

			// trebuie sa gasesc idMagazin corespunzator produsului aferent. ceva asemanator liniilor 89-96 dar inca nu m-am prins ce sa pun la conditia de if (linia 92)
			
			vectorProd[idProd][idMagazin]= ???
			// la acelasi ProdType exista mai multe valori. nu ar trebui sa fie un numar standard de intrare?
			// adica ma gandeam ca pentru un ProdType, un palet are nrProduseMax items. 
			palet = palet->getNext();
		}

		//cate produse din fiecare tip au ramas in fiecare magazin
		bon = listaBonuri.front();
		while (bon != NULL){

			int idProd = bon.getIdProdus();
			int idBon = bon.getIdBon();

			tranzactie = listaTranzactii.front();
			while(tranzactie != NULL){
				
				if(idBon == tranzactie.getIdBon){
					int idMagazin = tranzactie.getIdMagazin();
				}
				tranzactie = tranzactie->getNext();
			}

			vectorProd[idProd][idMagazin] = vectorProd[idProd][idMagazin] - 1;

			//verificare daca am ajuns la 10% dintr un produs	
			if ( vectorProd[idProd][idMagazin] = 0.1 * nrProduseMax ) // acest nrProduseMax ar fi cel de la liniile 76-78 daca rationamentul meu este corect

					//SOLICITARE palet de la DEPOZIT
					//Poate onora comanda? contoriare, afisare contor cand conditia nu este indeplinita. Contorul reprezinta numarul comenzii ce nu va putea fi onorata
			
			bon = bon->getNext();
		}

		
		
		

		output.close();
	}
}