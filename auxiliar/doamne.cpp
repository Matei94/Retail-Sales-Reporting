#include <iostream>

#include "Hashtable.h"

using namespace std;

int main() {
	Pereche per;
	Hashtable<string,Pereche> map = Hashtable<string,Pereche>( 10 );
	map.Insert( "ana",{ 100,200 });
	map.Insert( "fasoleame",{ 200,300 });
	map.Insert( "bunica",{300,400} );
	map.Insert( "mama",{ 400,500 });
	map.Insert( "hana", { 999,999 } );
	map.Insert( "hahaha",{ 123,321 } );
	map.Insert( "hahaha",{ 312,123});
	map.Insert( "hahaua",{ 312,123});
	per = {10,10};
	map.get("hana",per);
	cout<<per.idSlot<<' '<<per.indexSlot<<endl;	
	map.printTable();

/*	int ceva = 0;
	Hashtable<string,int> map = Hashtable<string,int>( 10 );
	map.Insert( "ana",20);
	map.Insert( "fasoleame",10);
	map.Insert( "bunica",40 );
	map.Insert( "mama",100);
	map.get( "ana", ceva );
	cout<<ceva<<endl;
	map.printTable();*/
	return 1;
}