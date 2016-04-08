#include <iostream>

#include "../headers/ArrayList.h"
#include "../headers/Stack.h"
#include "Hashtable.h"

#define NR_SLOTS 30

using namespace std;

int main (){
	ArrayList<int> slots;
	slots.Init( NR_SLOTS );
	Stack<int> paleti;
	cout<<"este gol "<<paleti.isEmpty()<<endl;
	for( int i = 1; i <= NR_SLOTS; i++ ) {
		cout << slots[i] + i << ' ';
		paleti.push( i );
	}
	cout<<"nu si acum "<<paleti.isEmpty()<<endl;
		cout<<endl<<paleti.peek()<<endl;
//	while(paleti.isEmpty() == 0)
//		cout<<paleti.pop()<<' ';
	for( int i = 1; i <= NR_SLOTS; i++ ) 
		cout<<paleti.pop()<<' ';
	cout<<paleti.isEmpty();
//	cout<<paleti.pop()<<' ';
	return 0 ;
}