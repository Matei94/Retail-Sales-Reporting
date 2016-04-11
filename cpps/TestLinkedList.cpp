#include "../headers/LinkedList.h"
using namespace std;

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

  cout<< l.numberOfNodes();

  l.removeFirst();

  cout<< l.numberOfNodes();
  
}
