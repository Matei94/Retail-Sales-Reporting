#include "../headers/ArrayList.h"
#include "../headers/Stack.h"

template<typename T>
ArrayList<T>::ArrayList( ) {
	array = 0;
}

template<typename T>
ArrayList<T>::ArrayList( int cantitate ) {
	size = cantitate;
	array = new Stack<T> [ size + 1 ];
}

template<typename T>
ArrayList<T>::~ArrayList() {
	for( int i = 0; i <= size; i++ )
		while( ! array[ i ].isEmpty() )
			array[ i ].pop();
	delete [] array;
}

/*
template<typename T>
Stack<T> ArrayList<T>::operator[]( int index ) {
	return array[ index ];
}
*/

template<typename T>
void ArrayList<T>::push( int index, T value ) {
	array[ index ].push( value );
}

template<typename T>
T ArrayList<T>::peek( int index ) {
	return array[ index ].peek();
}

template<typename T>
T ArrayList<T>::pop( int index ) {
	return array[ index ].pop();
}

template<typename T>
bool ArrayList<T>::isEmpty( int index ) {
	return array[ index ].isEmpty();
}

template class ArrayList< int >;
/*template class ArrayList<int>*/




