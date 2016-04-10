#include<fstream>
#include<sstream>
#include<string>

#include"Categorie.h"
#include"LinkedList.h"

using namespace std;

void citireCategorii( LinkedList<Categorie>& listaCategorii ){
	ifstream categorii ( "categorii.csv" );
	string linieFisier;
	getline( categorii, linieFisier );
	while ( getline( categorii, linieFisier ) ){
		listaCategorii.addLast ( Categorie( linieFisier ) );
	}
	categorii.close();
}
