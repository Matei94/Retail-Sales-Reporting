#include <string>
#include <stdio.h>

#include "../headers/Hashtable.h"


using namespace std;

/*  */
#define VMAX 1000

/* Constructorul care aloca memoria pentru hashtable */
template<class Tkey, class Tvalue> 
Hashtable<Tkey, Tvalue>::Hashtable(int hmax, int (*h) (Tkey)) {
  HMAX = hmax;
  hash = h;
  H = new LinkedList<struct elemInfo<Tkey, Tvalue> > [HMAX];
}

/* Destructorul care dezaloca memoria pentru hashtable, parcurgand fiecare bucket in parte
   si eliminand pe rand fiecare element din continutul lui */
template<typename Tkey, typename Tvalue> 
Hashtable<Tkey, Tvalue>::~Hashtable() {
  for (int i = 0; i < HMAX; i++) {
      while ( !H[i].isEmpty() ) /* functie din lista */
        H[i].removeFirst();   /* functie din lista */
  }

  delete[] H;
}


template<typename Tkey, typename Tvalue> 
void Hashtable<Tkey, Tvalue>::put(Tkey key, Tvalue value) {
  //struct Node<struct elemInfo<Tkey, Tvalue> > *p;   //Asa era cu un struct node
  Node<struct elemInfo<Tkey, Tvalue> > *p = new Node<struct elemInfo<Tkey, Tvalue> >(); //cu un class node *******
  struct elemInfo<Tkey, Tvalue> aux;

  
  /* hkey = indexul bucketului din hashtable */
  int hkey = hash(key);
  
  /* p = primul element din bucket */
  p = H[hkey].front(); //functie din lista

  
  /* Se parcurge bucketul si se cauta cheia "key". La gasirea acesteia se abandoneaza cautare. 
    p = pointer la elementul cautat sau NULL daca nu se gaseste elementul cu cheia "key" */
  while (p != NULL) {  // operator == must be meaningful
      if (p->getValue().key == key) 
          break;
      p = p->getNext();
  }

  /* aux este un element auxiliar ce va fi inserat in hashtable */
  aux.key = key;
  aux.value = value;


  /* Daca elemntul cu cheia respectiva exista deja in lista, trebuie actualizat, asa ca ii
    schimbam doar valoarea, fara sa pierdem legatura la urmatorul nod. */
  if (p != NULL) {
     //p->value(de la Node).value(de la elemInfo) = value(valoarea care este);
    p->setValue(aux);
  } else {
    /* Daca nu exista un element cu cheia respectiva in lista, facem un element nou si il punem 
      la sfarsitul listei din bucketul aferent cheii. */
    H[hkey].addLast(aux);  //functie din lista
  }
}


/* Returneaza valoarea cheii data ca parametru */
template<typename Tkey, typename Tvalue> 
Tvalue Hashtable<Tkey, Tvalue>::get(Tkey key) {
  //struct Node<struct elemInfo<Tkey, Tvalue> > *p;
  Node<struct elemInfo<Tkey, Tvalue> > *p = new Node<struct elemInfo<Tkey, Tvalue> >(); //cu un class node *******

  /* hkey = indexul bucketului din hashtable */
  int hkey = hash(key);

  /* p = primul element din bucket */
  p = H[hkey].front(); //functie din lista

  
  /* Se parcurge bucketul si se cauta cheia "key". La gasirea acesteia se abandoneaza cautare. 
    p = pointer la elementul cautat sau NULL daca nu se gaseste elementul cu cheia "key" */
  while (p != NULL) {  // operator == must be meaningful
      if (p->getValue().key == key) 
          break;
      p = p->getNext();
  } 

  /* Daca gaseste in lista elementul cautat, returneaza valoarea */
  if (p != NULL)
      return p->getValue().value; /* Node::getValue */
  /* Daca nu gaseste in lista elementul cautat, printeaza o valoare */
  else {
      fprintf(stderr, "Error 101 - The key does not exist\n");
      /* Returnam ceva de-a-mpulea? Nici noi nu stim... */
      Tvalue x;
      return x;
  }
}


/* Functia de verificare a existentei cheii "key" in hashtable */
template<typename Tkey, typename Tvalue> 
int Hashtable<Tkey, Tvalue>::hasKey(Tkey key) {
  //struct Node<struct elemInfo<Tkey, Tvalue> > *p;
  Node<struct elemInfo<Tkey, Tvalue> > *p = new Node<struct elemInfo<Tkey, Tvalue> >(); //cu un class node *******

  /* hkey = indexul bucketului din hashtable */
  int hkey = hash(key);

  /* p = primul element din bucket */
  p = H[hkey].front(); //functie din lista


  /* Se parcurge bucketul si se cauta cheia "key". La gasirea acesteia se abandoneaza cautare. 
    p = pointer la elementul cautat sau NULL daca nu se gaseste elementul cu cheia "key" */
  while (p != NULL) {  // operator == must be meaningful
      if (p->getValue().key == key) 
          break;
      p = p->getNext();
  }

  /* Daca se gaseste cheia, returnam 1, daca nu returnam 0 */
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

template class Hashtable<string,int>;
template class Hashtable<int,int>;

int Hash_string(string key) {
    int hkey = 0;
    for (int i = 0; i < key.length(); i++)
        hkey = (hkey * 31 + key[i]) % VMAX;
    return hkey;
}

int Hash_long (long key) {
  // Trebuie o functie buna de hash :D
}

// Chestiile alea cu template, exemplu:
