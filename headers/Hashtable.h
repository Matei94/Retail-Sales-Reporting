#ifndef __HASHTABLE_H_
#define __HASHTABLE_H_

#include "LinkedList.h"     //Verificare nume cu headerul listei + Guard
#include "Node.h"

template<typename Tkey, typename Tvalue> 
struct elem_info {
    Tkey key;
    Tvalue value; };

template<typename Tkey, typename Tvalue> 
class Hashtable {
    private:
        LinkedList<struct elem_info<Tkey, Tvalue> > *H;
        int HMAX;
        int (*hash) (Tkey);

    public:
        Hashtable(int hmax, int (*h) (Tkey));

        ~Hashtable();

        void put(Tkey key, Tvalue value);

        Tvalue get(Tkey key);

        int hasKey(Tkey key);

        int getCollisions();

        int getMaxCollisions();

};

#endif /* __HASHTABLE_H_ */