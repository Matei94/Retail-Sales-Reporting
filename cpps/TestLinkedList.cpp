#include "../headers/LinkedList.h"

int main (int argc, char *argv[]) {
  LinkedList<int> l;
  l.addFirst(1);
  l.printList();

  l.addFirst(2);
  l.printList();

  l.addFirst(3);
  l.printList();

  l.addLast(4);
  l.printList();

  l.addFirst(3);
  l.printList();
}
