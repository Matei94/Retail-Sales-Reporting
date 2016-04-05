#include<fstream>
#include<sstream>

#include "Palet.h"
#include "LinkedList.h"

using namespace std;

void citirePaleti( LinkedList<Palet>& listaPaleti ){
        ifstream paleti ( "paleti.csv" );
        string linieFisier;
        getline( paleti, linieFisier );
        while ( getline( paleti, linieFisier ) ){
                listaPaleti.addLast ( Palet ( linieFisier ) );
        }
        paleti.close();
}
