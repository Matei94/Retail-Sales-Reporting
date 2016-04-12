/*

Intelegerea pe deplin a hashtable-ului a fost facuta la site-ul acesta: 
"https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250#.1c96qyu6p"

Logica Hashtable-ului nostru este in principiu exacta cu cea de la site-ul de sus avand mici modificari.
(nu s-a dat nicio secunda copy-paste, dar cum s-a zis, implementarea noastra a fost masiv influentata de ideea site-ului de mai sus)

*/

#ifndef __Hashtable_H_
#define __Hashtable_H_

#include <iostream>
#include <string>

using namespace std;

struct Pereche {
	int idSlot;
	int indexSlot;

	void operator= ( const Pereche &per) {
		this->idSlot = per.idSlot;
		this->indexSlot = per.indexSlot;
	}

	friend ostream& operator<< ( ostream& out, const Pereche& per ) {
	out << "Perechea { idSlot, indexSlot }: { " << per.idSlot << ", " << per.indexSlot << " }"<<endl;
	return out;
}

};

template<typename Tkey, typename Tvalue>
struct Hashnode {
	Tkey key;
	Tvalue value;
	Hashnode *next;
};


template<typename Tkey, typename Tvalue>
class Hashtable {
	private:
		int size;
		Hashnode<Tkey,Tvalue> **Bucket;

	public:
		Hashtable( int length );

		~Hashtable();

		int Hash( Tkey key );

		bool getLast( Tkey key, Tvalue& value );

		void Insert( Tkey key, Tvalue value );

		bool get ( Tkey key, Tvalue& value );

		void remove( Tkey key );

		void printTable( );

		int badHash(string key);

};

#endif /* __Hashtable_H_ */