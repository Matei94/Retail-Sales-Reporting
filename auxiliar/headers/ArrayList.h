#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__

#include "Stack.h"

template <typename T>
class ArrayList {
	private:

		Stack<T> *array;
		int size;

	public:

		/*Cosntructor default*/
		ArrayList( );

		/*Constructor*/
		ArrayList( int size );

		/*Destructor*/
		~ArrayList( ) ;

		/*Assignment operator*/
		void operator=( const ArrayList<T>& v );

		/*Assigment operator for using arrays*/
		Stack<T> operator[]( int index );

		/*Pune in stiva, din vectorul de pe pozitia index, valoarea value*/
		void push( int index, T value );

		/*Arata prima pozitie din stiva, din vectorul de pe pozitia index*/
		T peek( int index );

		/*Scoate din stiva de pe pozitia index a vectorului*/
		T pop( int index );

		/*Verifica daca stiva, din vectorul de pe pozitia index, este goala*/
		bool isEmpty( int index );

};

#endif	/* __ARRAYLIST_H__ */
