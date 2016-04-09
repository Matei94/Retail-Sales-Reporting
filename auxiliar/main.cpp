#include <iostream>

#include "../headers/ArrayList.h"
#include "../headers/Stack.h"

#define NR_SLOTS 30

using namespace std;

int main (){
	Stack<int> ceva;
	ArrayList<int> slots = ArrayList<int>(NR_SLOTS);
	
	for (int i = 1; i <= NR_SLOTS; ++i)
	{
		for (int j = 0; j <= 10; j++)
		{
			slots.push(i,j);
		}
	}
	for (int i = 1; i <= NR_SLOTS; ++i)
	{
		for (int j = 0; j <= 10; j++)
			cout<<slots.pop(i)<<' ';
		cout<<endl;
	}
	return 0 ;
}