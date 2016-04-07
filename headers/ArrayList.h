#ifndef __ARRAYLIST_H_
#define __ARRAYLIST_H_

template <typename T>
class ArrayList {
	private:
		T *array;
		int size;

	public:
		/*Constructor*/	
		ArrayList( ) ;

		/*Destrucot*/
		~ArrayList( ) ;

		/*Assignment operator*/
		void operator=( const ArrayList<T>& v );

		/*Assigment operator for using arrays*/
		T operator[]( int index );

		/*Initializare vector*/
		void Init( int size ) ;


		/*Adauga un nod la indexeul cerut*/
		void add( T value, int index );
};

#endif	__ARRAYLIST__