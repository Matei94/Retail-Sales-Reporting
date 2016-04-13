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


/* Pentru unul dintre hashuri avem nevoie de o structura care sa retina atat idSlot, cat si indexSlot */
struct Pereche {
	int idSlot;
	int indexSlot;

	/* Supraincarcarea operatorului de egalitate */
	void operator= ( const Pereche &per) {
		this->idSlot = per.idSlot;
		this->indexSlot = per.indexSlot;
	}

	/* Supraincarcarea operatorului << */
	friend ostream& operator<< ( ostream& out, const Pereche& per ) {
		out << "Perechea { idSlot, indexSlot }: { " << per.idSlot << ", " << per.indexSlot << " }"<<endl;
		return out;
	}

};


/* Hashnode - structura de baza a hashtable-ului; un fel de unitate de masura, care are o cheie, o valoare si o legatura cu urmatorul element */
template<typename Tkey, typename Tvalue>
struct Hashnode {
	Tkey key;
	Tvalue value;
	Hashnode *next;
};


/* Hashtable - Structura de date definita ca o clasa */
template<typename Tkey, typename Tvalue>
class Hashtable {
	/* size = numarul de bucketuri
	**Bucket - pointer la inceputul hashtable-ului */
	private:
		int size;
		Hashnode<Tkey,Tvalue> **Bucket;

	public:
		/* Constructorul ce primeste ca parametru numarul de bucketuri pe care il va avea hashtableul */
		Hashtable( int length );

		/* Destructor */
		~Hashtable();

		/* Functia hash */
		int Hash( Tkey key );

		/* Functia care cauta existenta unui ultim element la cheia key si returneaza true sau false, in functie de rezultatul cautarii, dar returneaza si valoarea pe care o gaseste la 
		sfarsitul bucketului respectiv prin intermediul parametrului trimis ca referinta: "value" */
		bool getLast( Tkey key, Tvalue& value );

		/* Functia de insertie a unui nou element in Hashtable, la cheia key si valoarea value */
		void Insert( Tkey key, Tvalue value );

		/* Functia care cauta existenta unui element la cheia key si returneaza true sau false, in functie de rezultatul cautarii, dar returneaza si valoarea pe care o are acesta,
		 prin intermediul parametrului trimis ca referinta: "value" */
		bool get ( Tkey key, Tvalue& value );

		/* Elimina primul element din bucketul aferent cheii "key" */
		void remove( Tkey key );

		/* Afiseaza hashtable-ul  */
		void printTable( );

		/* Functia proasta de hash */
		int badHash(string key);

};

#endif /* __Hashtable_H_ */