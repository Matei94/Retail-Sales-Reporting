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

		int vectorProd = new int[idProdMax];

		//cate produse erau la inceput
		while (palet != NULL){
			idProd = palet.getProdType;
			vectorProd[idProd] = ???
			// la acelasi ProdType exista mai multe valori. nu ar trebui sa fie un numar standard de intrare?
			
			palet = palet->getNext();
		}

		//cate produse din fiecare tip au ramas
		bon = listaBonuri.front();
		while (bon != NULL){

			int idProd = bon.getIdProdus();
			vectorProd[idProd] = vectorProd[idProd] - 1;	
			
			bon = bon->getNext();
		}

		
		
		

		output.close();
	}
}