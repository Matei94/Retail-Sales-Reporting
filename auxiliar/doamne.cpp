#include <iostream>

#include "Hashtable.h"

using namespace std;


int main() {
	Hashtable<string,int> map = Hashtable<string,int>( 10 );
	map.Insert( "ana",30 );
	map.Insert( "fasoleame",3100 );
	map.Insert( "bunica",90 );
	map.Insert( "mama",70 );
	cout<<map.get("ana")<<endl;	
	map.printTable();
	return 1;
}