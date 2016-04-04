#ifndef __HASHTABLE_H_
#define __HASHTABLE_H_

#include "LinkedList.h"     //Verificare nume cu headerul listei + Guard
#include "Node.h"


/* elemInfo -> perechea( cheie, valoare ) din hashtable */
template<typename Tkey, typename Tvalue> 
struct elemInfo {
    Tkey key;
    Tvalue value; 
};

template<typename Tkey, typename Tvalue> 
class Hashtable {
    private:
        /* H este lista in care se retine hashtable-ul propriu-zis */
        LinkedList<struct elemInfo<Tkey, Tvalue> > *H;
        
        /* HMAX = numarul de bucketuri ocupate din hashtable/ dimensiunea lui H / sizeof(H) */
        int HMAX;

        /* functia de hash */
        int (*hash) (Tkey);

    public:
        /* Constructor */
        Hashtable(int hmax, int (*h) (Tkey));

        /* Destructor */
        ~Hashtable();

        /* Functia de insertie in hashtable */
        void put(Tkey key, Tvalue value);

        /* Functia de extragere a valorii de la o anumita cheie */
        Tvalue get(Tkey key);

        /* Functia de verificare a existentei cheii "hey" in hashtable */
        int hasKey(Tkey key);

//      int getCollisions();

//      int getMaxCollisions();

};

#endif /* __HASHTABLE_H_ */