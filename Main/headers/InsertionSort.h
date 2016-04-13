#ifndef __InsertionSort_H_
#define __InsertionSort_H_

#include <string>

#include "LinkedList.h"
#include "Tranzactie.h"

using namespace std;

void InsertionSort( LinkedList<Tranzactie>& listaTranzactii ) {
  /* head - pointer la inceputul listei; ramane constant si de referinta */
  Node<Tranzactie> *head = listaTranzactii.front();
  /* aux - pointer auxiliar utilizat la parcurgere */
  Node<Tranzactie> *aux = listaTranzactii.front();
  /* sortedList - lista sortata */
  LinkedList<Tranzactie> sortedList;
  /* currentValue - variabila auxiliara in care vom retine valoarea elementului curent din lista*/
  Tranzactie currentValue;

  /* Se adauga by default primul element din lista de procesat in viitoarea lista sortata*/
  sortedList.addLast( currentValue );
  currentValue = aux->getValue();
  sortedList.addLast( currentValue );
  aux = aux->getNext();

  /* Se parcurge lista, atat timp cat exista elemente */
  while ( aux != NULL ) {
    currentValue = aux->getValue();
    string wantedValue = currentValue.getTimeStamp();
    /* auxSort - pointer de parcurgere a listei sortate */
    Node<Tranzactie> *auxSort = sortedList.front();

    /* Se parcurge lista deja sortata si i se cauta locul de insertie a valorii curente */
    while ( auxSort != NULL ) {
      /* Daca ajunge la ultimul element din lista, e clar ca nu mai avem nimic in dreapta,
      deci inseram direct la coada si iesim */
      if ( auxSort->getNext() == NULL ) {
        sortedList.addLast( currentValue );
        break;
      }

      /* now - valoarea elementului curent */
      string now = auxSort->getValue().getTimeStamp();
      /* next - valoarea elementului urmator */
      string next = auxSort->getNext()->getValue().getTimeStamp();
      
      /* Daca locul valorii este intre cele doua elemente, inseram valoarea acolosa si ne oprim din cautare*/
      if ( now <= wantedValue && wantedValue <= next ) {
        sortedList.insertElement( currentValue, auxSort );
        break;
      }

      /* Daca nu ... mergem la urmatorul nod */
      auxSort = auxSort->getNext();
    }

    aux = aux->getNext();
  }

  sortedList.removeFirst();

  /* Se modifica proprietatile listei curente cu cele ale listei sortate */
  listaTranzactii = sortedList;
}

#endif // __InsertionSort_H_
