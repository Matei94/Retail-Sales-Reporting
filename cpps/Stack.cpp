#include <cstddef>

#include "Node.h"

#include "../headers/Stack.h"

using namespace std;

template<typename T>
Stack<T>::Stack() {
	first = NULL;
}

template<typename T>
Stack<T>::~Stack() {
	while (first != NULL) {
		Node<T> *del = first;
		first = first->getNext();
		delete del;
	}
}

template <typename T>
void Stack<T>::push (T value) {
	Node<T> *n = new Node<T>(value);
	if (isEmpty()) {
		this->first = n;
	} else {
		n->setNext(this->first);
		this->first = n;
	}
}

template <typename T>
T Stack<T>::pop (){
	Node<T> *current = first;
	T val = current->getValue();
	first = first->getNext();
	delete current;
	return val;
}

template <typename T>
T Stack<T>::peek () {
	return first->getValue();
}

template <typename T>
bool Stack<T>::isEmpty () {
	return first == NULL;
}

template class Stack<int>;
