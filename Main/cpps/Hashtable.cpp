/*

Intelegerea pe deplin a hashtable-ului a fost facuta la site-ul acesta: 
"https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250#.1c96qyu6p"

Logica Hashtable-ului nostru este in principiu exacta cu cea de la site-ul de sus avand mici modificari.
(nu s-a dat nicio secunda copy-paste, dar cum s-a zis, implementarea noastra a fost masiv influentata de ideea site-ului de mai sus)

*/

#include "../headers/Hashtable.h"

using namespace std;


/* Hashtable() */
template<typename Tkey, typename Tvalue>
Hashtable<Tkey,Tvalue>::Hashtable( int length){
	/* size = length = numarul de bucketuri pe care il va avea hashtableul */
	size = length;

	/* Se aloca un hashtable nou, ce admite o cheie de tipul Tkey, o valoare de tipul Tvalue, cu size+1 bucketuri */
	Bucket = new Hashnode<Tkey,Tvalue> *[ size + 1 ];

	/* Se parcurge fiecare bucket declarat anterior si se initializeaza cu un element default  */
	for (int i = 0; i <= size; ++i)
	{
		Bucket[ i ] = new Hashnode<Tkey,Tvalue>;
		Bucket[ i ] = NULL;
	}
}


/* ~Hashtable() */
template<typename Tkey, typename Tvalue>
Hashtable<Tkey,Tvalue>::~Hashtable ( ) {
	/* Se parcurg bucketurile hashtable-ulului */
	for( int i = 0; i < size; i++ ){

		/* first - pointer la inceputul bucketului curent */
		Hashnode<Tkey,Tvalue> *first = Bucket[ i ];

		/* Se parcurg elementele din bucketul curent */
		while( first != NULL ) {

			/* prev - copie a lui first */
			Hashnode<Tkey,Tvalue> *prev = first;
			
			/* first - devine pointer la elementul urmator din bucketul curent */
			first = first->next;
			
			/* Se elibereaza zona de memorie alocata elementului curent din bucket */
			delete prev;
		}

		/* Cum bucketul a fost golit de elemente, pointerul de inceput devine NULL */
		Bucket[ i ] = NULL;
	}

	/* Se elibereaza si zona de memorie alocata bucketurilor */
	delete [] Bucket;
}


/* Hash() */
template<typename Tkey, typename Tvalue>
int Hashtable<Tkey,Tvalue>::Hash( Tkey key ) {
	/* Smecheria este ca functia noastra de hash este functia identitate, astfel, hashtable-ul nostru se comporta intocmai ca un vector de frecventa */
	return key;
}


/* getLast() */
template<typename Tkey, typename Tvalue>
bool Hashtable<Tkey,Tvalue>::getLast( Tkey key, Tvalue& value ) {
	/* index - indicele bucketului in care a fost distribuita valoarea corespunzatoare cheii key, dupa aplicarea functiei de hash */
	unsigned int index = Hash( key );

	/* prev - poiner la nodul anterior */
	Hashnode<Tkey,Tvalue> *prev = NULL;

	/* first - pointer la inceputul bucketului cu indicele index */
	Hashnode<Tkey,Tvalue> *first = Bucket[ index ];

	/* Daca bucketul indicat este gol, functia returneaza false, semnn ca nu exista un last element ce poate fi returnat, iar value se intoarce cu valoarea cu care a intrat in functie */
	if( first == NULL )
		return false;

	/* Daca bucketul indicat contine un singur element */
	if( first->next == NULL ){

		/* Value preia valoarea acelui element */
		value = first->value;

		/* Pointerul de la inceputul listei devine NULL, semn ca bucketul se goleste */
		Bucket[ index ] = NULL;

		/* Functia returneaza true, semna ca a avut ce sa returneze */
		return true;
	}

	/* Cat timp mai exista cel putin inca un nod in afara de cel curent in bucket */
	while( ( first->next != NULL ) ) {

		/* Mutam pointerul de la elementul anterior la elementul curent din bucket */
		prev = first;

		/* si de la elementul curent la urmatorul element din bucket */
		first = first->next;
	}
	/* La iesirea din while, first va pointa tocmai catre ultimul element din bucketul respectiv */

	/* Value ia tocmai valoarea dorita, si anume valoarea aferenta ultimului element din bucket */
	value = first->value;
	
	/* Se elibereaza zona de memorie alocata ultimului element */
	delete first;
	
	/* Elementul precedent devine acum ultimul element din lista */
	prev->next = NULL;

	/* Functia returneaza true, semn ca a avut ce anume sa returneze */
	return true;
}


/* Insert() */
template<typename Tkey, typename Tvalue>
void Hashtable<Tkey,Tvalue>::Insert( Tkey key, Tvalue value ){
	
	/* index - indicele indicele bucketului in care a fost distribuita valoarea corespunzatoare cheii key, dupa aplicarea functiei de hash */
	unsigned int index = Hash( key );
	
	/* prev - pointer la elementul anterior din bucket */
	Hashnode<Tkey,Tvalue> *prev = NULL;

	/* first - pointer la inceputul bucketului aferent indicelui index */
	Hashnode<Tkey,Tvalue> *first = Bucket[ index ];

	/* Se parcurge bucketul curent pana la final */
	while( ( first != NULL ) ) {
		prev = first;
		first = first->next;
	}

	/* Cand se ajunge la finalul bucketului */
	if( first == NULL )	{

		/* Se insereaza/construieste un element default in bucketul curent */
		first = new Hashnode<Tkey,Tvalue>;
		
		/* I se atribuie cheia si valoarea date ca parametru functiei */
		first->key = key;
		first->value = value;

		/* Va pointa la NULL, fiind ultimul element din bucket */
		first->next = NULL;

		/* Daca este totodata si primul element din bucket */
		if( prev == NULL ){
			//este primul nod din bucket
			/* Pointerul de la inceputul bucketului va coincide cu pointerul la elementul curent */
			Bucket[ index ] = first;
		}else
			/* Daca nu este primul element din bucketul curent */
			//se pune in continuarea listei
			prev->next = first;
	} else 
		//in situatia aceasta inseamna ca facem update
		//first->value = value;
		//am modificat ca sa nu dea refresh ci ca sa puna in contiunuare -> "CONTIUNUARE"- Codi, aprilie 2016
		prev->next = first;
	
}


/* get() */
template<typename Tkey, typename Tvalue>
bool Hashtable<Tkey,Tvalue>::get( Tkey key, Tvalue& value ) {
	
	/* index - indicele indicele bucketului in care a fost distribuita valoarea corespunzatoare cheii key, dupa aplicarea functiei de hash */	
	unsigned int index = Hash( key );

	/* first - pointer la inceputul bucketului aferent indicelui index */	
	Hashnode<Tkey,Tvalue> *first = Bucket [ index ];

	/* Se parcurge bucketul curent pana la final */
	while( first != NULL ) {

		/* Daca cheia elementului curent este cheia cautata */
		if( first->key == key ) {

			/* Se extrage valoarea elementului curent */
			value = first->value; 

			/* Se returneaza true, semn ca a fost gasit in bucket elementul cu cheia key */
			return true;
		}

		/* Mutam pointerul asupra urmatorului element din bucket */
		first = first->next;
	}

	/* Se returneaza false, semn ca nu a fost gasit in bucket elementul cu cheia key */
	return false;
}


/* remove() */
template<typename Tkey, typename Tvalue>
void Hashtable<Tkey,Tvalue>::remove( Tkey key ) {
	
	/* index - indicele indicele bucketului in care a fost distribuita valoarea corespunzatoare cheii key, dupa aplicarea functiei de hash */
	unsigned int index = Hash( key );

	/* prev - pointer la elementul anterior din bucket */	
	Hashnode<Tkey,Tvalue> *prev = NULL;

	/* first - pointer la inceputul bucketului aferent indicelui index */	
	Hashnode<Tkey,Tvalue> *first = Bucket[ index ];

	/* Se parcurge bucketul pana la elementul care are cheia key */
	while( ( first != NULL ) && ( first->key != key ) ) {

		/* Pointerul de la elementul anterior devine pointer la elementul curent */
		prev = first;

		/* Pointerul de la elementul curent devine pointer la elementul urmator */
		first = first->next;
	}

	//nu s-a gasit cheia -> Nu mai comentez eu aici, ca zice bine si Codi
	/* Daca nu s-a gasit cheia, programul se incheie aici */
	if( first == NULL )
		return;

	/* Daca a fost gasita cheia */
	else {

		/* Daca primul element era cel cautat */
		if( prev == NULL )
			/* Se modifica pointerul de la inceputul bucketului curent */
			Bucket[ index ] = first->next;
		else {
			/* In caz contrar, elementul precedent va pointa direct la urmatorul de dupa elementul gasit, legaturile dintre elementul cautat si vecini fiind taiate */
			prev->next = first->next;
		}

		/* Se elibereaza zona de memorie aferenta nodului respectiv */
		delete first;
	}
}


/* printTable */
template<typename Tkey, typename Tvalue>
void Hashtable<Tkey,Tvalue>::printTable( ) {
	
	cout<<"Hashtable :"<<endl;
	
	/* Se parcurg bucketurile hashtable-ulului */
	for( int i = 1; i <= size; i++ ) {

		/* prev - pointer la elementul precedent din bucketul curent */
		Hashnode<Tkey,Tvalue> *prev = NULL;

		/* first - pointer la inceputul bucketului curent */
		Hashnode<Tkey,Tvalue> *first = Bucket[ i ];
		
		/* Se parcurge bucketul curent si se afiseaza fiecare valoare a elementelor */
		while( first != NULL ) 
			cout<<"Bucket "<< i <<": "<<first->value<<endl;

		/* Pointerii se deplaseaza la urmatorul element */
		prev = first;
		first = first->next;
	}
}


template class Hashtable<int,int>;
template class Hashtable<int,Pereche>;
//template class Hashtable<string,int>;