#ifndef __STACK_H_
#define __STACK_H_

#include "Node.h"
#include "LinkedList.h"
using namespace std;



template <typename T>
class Stack {
private:
	LinkedList<T> *list;
	Node<T> *first;

public:
	Stack();
	~Stack();
	void push(T value);
	T pop();
	T peek();
	bool isEmpty();

};

#endif /* __STACK_H_ */
