#ifndef __LINKEDLIST_H_
#define __LINKEDLIST_H_

#include <iostream>
#include <ostream>


using namespace std;

template <typename T>
struct listElem {
	T info;
	listElem<T> *next;
};

template <typename T>
class LinkedList {
private:
  listElem<T> *pFirst, *pLast;

public:
  /* Constructor */
  LinkedList();

  /* Copy Constructor */
  LinkedList(const LinkedList<T>& l);

  /* Assignement operator */
  void operator=(const LinkedList<T>& l);

  /* Destructor */
  ~LinkedList();

  /* Adauga un nod cu valoarea == value la inceputul listei. */
  void addFirst(T value);

  /* Adauga un nod cu valoarea == value la sfarsitul listei. */
  void addLast(T value);

  /* Elimina elementul de la inceputul listei si intoarce valoarea acestuia. */
  T removeFirst();

  /* Elimina elementul de la sfarsitul listei listei si intoarce valoarea acestuia. */
//  T removeLast();

  /* Elimina prima aparitie a elementului care are valoarea == value. */
//  T removeFirstOccurrence(T value);

  /* Elimina ultima aparitie a elementului care are valoarea == value. */
 // T removeLastOccurrence(T value);

  /* Afiseaza elementele listei pe o singura linie, separate printr-un spatiu. */

  /* Intoarce true daca lista este vida, false altfel. */
  bool isEmpty();

  /* Returneaza primul element */
  listElem<T>* front();

  /* Calculeaza numarul de noduri din lista. */
  int numberOfNodes();

  /* Afiseaza elementele listei */
  void printList();

  /* Supraincarcarea operatorului << */
  friend ostream& operator<< ( ostream& out, const LinkedList<T>& obiect );
};

#endif /* __LINKEDLIST_H_ */

