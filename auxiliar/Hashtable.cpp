#include "Hashtable.h"

template<typename Tkey, typename Tvalue >
Hashtable<Tkey,Tvalue>::Hashtable(int hmax, int (*h) (Tkey)) {
    HMAX = hmax;
    hash = h;
    H = new LinkedList<struct elem_info<Tkey, Tvalue> > [HMAX]; 
}

template<typename Tkey, typename Tvalue >
Hashtable<Tkey,Tvalue>::~Hashtable() {
    for (int i = 0; i < HMAX; i++) {
         while (!H[i].isEmpty())
            H[i].removeFirst();
    }

    delete[] H;
}

template<typename Tkey, typename Tvalue >
void Hashtable<Tkey,Tvalue>::put(Tkey key, Tvalue value) {
   struct Node<struct elem_info<Tkey, Tvalue> > *p;
   struct elem_info<Tkey, Tvalue> info;

   int hkey = hash(key);
   p = H[hkey].front();

   while (p != NULL) {  // operator == must be meaningful                    
        if (p->info.key == key) break;
        p = p->next;
   }

   if (p != NULL)
       p->info.value = value;
   else {
       info.key = key;
       info.value = value;
       H[hkey].addLast(info);
   }
}

template<typename Tkey, typename Tvalue >
Tvalue Hashtable<Tkey,Tvalue>::get(Tkey key) {
    struct Node<struct elem_info<Tkey, Tvalue> > *p;

    int hkey = hash(key);
    p = H[hkey].front();

    while (p != NULL) {
        if (p->info.key == key) break;
        p = p->next;
    }

    if (p != NULL)
        return p->info.value;
    else {
        cout<<"Nu exista key";
        Tvalue x;
        return x;
    }
}

template<typename Tkey, typename Tvalue >
int Hashtable<Tkey,Tvalue>::hasKey(Tkey key) {
    struct Node<struct elem_info<Tkey, Tvalue> > *p;

    int hkey = hash(key);
    p = H[hkey].front();

    while (p != NULL) {
        if (p->info.key == key)
            break;
        p = p->next;
    }

    if (p != NULL)
        return 1;
    else
        return 0;
}