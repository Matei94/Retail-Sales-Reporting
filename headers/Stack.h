#ifndef __STACK_H_
#define __STACK_H_

#include "../headers/Node.h"

using namespace std;

template <typename T>
class Stack {
private:
	Node<T> *first;

public:
	void push(T value);
	T pop();
	T peek();
	bool isEmpty();
};

#endif /* __STACK_H_ */
