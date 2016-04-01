#include <string>
#include <stdio.h>

#include "../headers/Hashtable.h"


#define VMAX 1000

template<class Tkey, class Tvalue> 
Hashtable<Tkey, Tvalue>::Hashtable(int hmax, int (*h) (Tkey)) {
  HMAX = hmax;
  hash = h;
  H = new LinkedList<struct elem_info<Tkey, Tvalue> > [HMAX];
}

template<typename Tkey, typename Tvalue> 
Hashtable<Tkey, Tvalue>::~Hashtable() {
  for (int i = 0; i < HMAX; i++) {
      while (!H[i].isEmpty()) //functie din lista
        H[i].removeFirst();   //functie din lista
  }

  delete[] H;
}

template<typename Tkey, typename Tvalue> 
void Hashtable<Tkey, Tvalue>::put(Tkey key, Tvalue value) {
  struct Node<struct elem_info<Tkey, Tvalue> > *p;   //Asa era cu un struct node
  //Node<struct elem_info<Tkey, Tvalue> > *p = new Node<struct elem_info<Tkey, Tvalue> >(value); //cu un class node *******
  struct elem_info<Tkey, Tvalue> aux;

  int hkey = hash(key);
  p = H[hkey].front(); //functie din lista

  while (p != NULL) {  // operator == must be meaningful
      if (p->getValue().key == key) break;
      p = p->getNext();
  }
  aux.key = key;
  aux.value = value;
  if (p != NULL) {
     //p->info.value = value;
    p->Node(aux);   
  }
  else {
    H[hkey].addLast(aux);  //functie din lista
  }
}
template<typename Tkey, typename Tvalue> 
Tvalue Hashtable<Tkey, Tvalue>::get(Tkey key) {
  struct Node<struct elem_info<Tkey, Tvalue> > *p;

  int hkey = hash(key);
  p = H[hkey].front(); //functie din lista

  while (p != NULL) {
      if (p->getValue().key == key) break;
      p = p->getNext();
  } 

  if (p != NULL)
      return p->getValue().value;
  else {
      fprintf(stderr, "Error 101 - The key does not exist\n");
      Tvalue x;
      return x;
  }
}

template<typename Tkey, typename Tvalue> 
int Hashtable<Tkey, Tvalue>::hasKey(Tkey key) {
  struct Node<struct elem_info<Tkey, Tvalue> > *p;

  int hkey = hash(key);
  p = H[hkey].front(); //functie din lista

  while (p != NULL) {
      if (p->getValue().key == key) break;
      p = p->getNext();
  }

  if (p != NULL)
      return 1;
  else
      return 0;
}
/*
template<typename Tkey, typename Tvalue> 
int Hashtable<Tkey, Tvalue>::getCollisions() {
  int collisions = 0;
  for (int i = 0; i < HMAX; i++) {
      int size = H[i].size();
      if (size>1)
        collisions += size-1;
  }
  return collisions;
}

template<typename Tkey, typename Tvalue> 
int Hashtable<Tkey, Tvalue>::getMaxCollisions() {
  int maxCollisions = 0;
  for (int i = 0; i < HMAX; i++) {
      int size = H[i].size();
      if ((size-1)>maxCollisions)
        maxCollisions = size-1;
  }
  return maxCollisions;
}
*/
template class Hashtable<std::string,int>;

int Hash(std::string key) {
    int hkey = 0;
    for (int i = 0; i < key.length(); i++)
        hkey = (hkey * 31 + key[i]) % VMAX;
    return hkey;
}

int main(){

}

// Chestiile alea cu template, exemplu:
