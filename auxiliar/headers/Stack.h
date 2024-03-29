#ifndef __STACK_H_
#define __STACK_H_

#include "Node.h"

using namespace std;



template <typename T>
class Stack {
private:
	
	Node<T> *first;

public:
	Stack();
	
	~Stack();

	void push(T value);
	
	T pop();
	
	T peek();
	
	Node<T>* getFirst();

	bool isEmpty();

};

#endif /* __STACK_H_ */
