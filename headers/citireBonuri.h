#include<fstream>
#include<<sstream>

using namespace std;

void citireBonuri( LinkedList<Bon>& listaBonuri ){
	
	ifstream bonuri ( "bonuri.csv" );
	
	string linieFisier;
    
    getline( bonuri, linieFisier );
    
    while ( getline( bonuri, linieFisier ) ){
    	
    	listaBonuri.addLast ( Bon ( linieFisier ) );
    }
    
    bonuri.close();
	
}