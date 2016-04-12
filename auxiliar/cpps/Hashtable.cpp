/*

Intelegerea pe deplin a hashtable-ului a fost facuta la site-ul acesta: 
"https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250#.1c96qyu6p"

Logica Hashtable-ului nostru este in principiu exacta cu cea de la site-ul de sus avand mici modificari.
(nu s-a dat nicio secunda copy-paste, dar cum s-a zis, implementarea noastra a fost masiv influentata de ideea site-ului de mai sus)

*/

#include "../headers/Hashtable.h"

using namespace std;

template<typename Tkey, typename Tvalue>
Hashtable<Tkey,Tvalue>::Hashtable( int length){
	size = length;
	Bucket = new Hashnode<Tkey,Tvalue> *[ size + 1 ];
	for (int i = 0; i <= size; ++i)
	{
		Bucket[ i ] = new Hashnode<Tkey,Tvalue>;
		Bucket[ i ] = NULL;
	}
}

template<typename Tkey, typename Tvalue>
Hashtable<Tkey,Tvalue>::~Hashtable ( ) {
	for( int i = 0; i < size; i++ ){
		Hashnode<Tkey,Tvalue> *first = Bucket[ i ];
		while( first != NULL ) {
			Hashnode<Tkey,Tvalue> *prev = first;
			first = first->next;
			delete prev;
		}
		Bucket[ i ] = NULL;
	}
	delete [] Bucket;
}

template<typename Tkey, typename Tvalue>
int Hashtable<Tkey,Tvalue>::Hash( Tkey key ) {
	return key;
}

template<typename Tkey, typename Tvalue>
void Hashtable<Tkey,Tvalue>::Insert( Tkey key, Tvalue value ){
	unsigned int index = Hash( key );
	Hashnode<Tkey,Tvalue> *prev = NULL;
	Hashnode<Tkey,Tvalue> *first = Bucket[ index ];
	while( ( first != NULL ) ) {
		prev = first;
		first = first->next;
	}
	if( first == NULL )	{
		first = new Hashnode<Tkey,Tvalue>;
		first->key = key;
		first->value = value;
		first->next = NULL;
		if( prev == NULL ){
			//este primul nod din bucket
			Bucket[ index ] = first;
		}else
			//se pune in continuarea listei
			prev->next = first;
	} else 
		//in situatia aceasta inseamna ca facem update
		//first->value = value;
		//am modificat ca sa nu dea refresh ci ca sa puna in contiunuare
		prev->next = first;
	
}

template<typename Tkey, typename Tvalue>
Hashnode<Tkey,Tvalue> Hashtable<Tkey,Tvalue>::getList( Tkey key ) {
	unsigned int index = Hash( key );
	return Bucket [ index ];
}

template<typename Tkey, typename Tvalue>
bool Hashtable<Tkey,Tvalue>::get( Tkey key, Tvalue& value ) {
	unsigned int index = Hash( key );
	Hashnode<Tkey,Tvalue> *first = Bucket [ index ];
	while( first != NULL ) {
		if( first->key == key ) {
			value = first->value; 
			return true;
		}
		first = first->next;
	}
	cout<<"Nu s-a gasit ";
	return false;
}

template<typename Tkey, typename Tvalue>
void Hashtable<Tkey,Tvalue>::remove( Tkey key ) {
	unsigned int index = Hash( key );
	Hashnode<Tkey,Tvalue> *prev = NULL;
	Hashnode<Tkey,Tvalue> *first = Bucket[ index ];
	while( ( first != NULL ) && ( first->key != key ) ) {
		prev = first;
		first = first->next;
	}
	//nu s-a gasit cheia
	if( first == NULL )
		return;
	else {
		if( prev == NULL )
			Bucket[ index ] = first->next;
		else {
			prev->next = first->next;
		}
		delete first;
	}
}

template<typename Tkey, typename Tvalue>
void Hashtable<Tkey,Tvalue>::printTable( ) {
	cout<<"Hashtable :"<<endl;
	for( int i = 1; i <= size; i++ ) {
	Hashnode<Tkey,Tvalue> *prev = NULL;
	Hashnode<Tkey,Tvalue> *first = Bucket[ i ];
		while( first != NULL ) {
			cout<<"Bucket "<< i <<": "<<first->value;
		prev = first;
		first = first->next;
		}
	}
}

template class Hashtable<int,Pereche>;
//template class Hashtable<string,int>;