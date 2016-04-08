#include "../headers/ArrayList.h"

template<typename T>
ArrayList<T>::ArrayList( ) {	
	this->array = 0;
	this->size = 0;
}

template<typename T>
ArrayList<T>::~ArrayList() {
	delete [] array;
}

template<typename T>
void ArrayList<T>::operator= ( const ArrayList<T>& v ) {
	for( int i = 1; i <= size; i++ )
		this->array[ i ] = v.array[ i ];
}

template<typename T>
T ArrayList<T>::operator[]( int index ) {
	return array[ index ];
}

template<typename T>
void ArrayList<T>::Init( int size ) {
	array = new T[ size + 1 ];
}

template<typename T>
void ArrayList<T>::add( T value, int index ) {
	this->array[ index ] = value; 
}

template class ArrayList<int>;
/*template class ArrayList<int>*/




