#include <iostream>

#include "headers/Hashtable.h"

using namespace std;

struct pereche {
	int idSlot;
	int indexSlot;
};

int main() {
	/*
	pereche per = {5,5};
	Hashtable<string,pereche> map = Hashtable<string,pereche>( 10 );
	map.Insert( "ana",per);
	map.Insert( "fasoleame",per);
	map.Insert( "bunica",per );
	map.Insert( "mama",per);
	per = {10,10};
	map.get("ana",per);
	cout<<per.idSlot<<' '<<per.indexSlot<<endl;	
	map.printTable();*/

	int ceva = 0;
	Hashtable<string,int> map = Hashtable<string,int>( 10 );
	map.Insert( "ana",20);
	map.Insert( "fasoleame",10);
	map.Insert( "bunica",40 );
	map.Insert( "mama",100);
	map.get( "ana", ceva );
	cout<<ceva<<endl;
	map.printTable();
	return 1;
}