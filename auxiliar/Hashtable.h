#include "../headers/LinkedList.h"

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
        Hashtable(int hmax, int (*h) (Tkey)) ;
        
        ~Hashtable() ;
        
        void put(Tkey key, Tvalue value) ;

        Tvalue get(Tkey key) ;

        int hasKey(Tkey key) ;
        
/*        int getCollisions() {
            int collisions = 0;
            for (int i = 0; i < HMAX; i++) {
                int size = H[i].size();
                if (size>1)
                  collisions += size-1;
            }
            return collisions;
        }

        int getMaxCollisions() {
            int maxCollisions = 0;
            for (int i = 0; i < HMAX; i++) {
                int size = H[i].size();
                if ((size-1)>maxCollisions)
                  maxCollisions = size-1;
            }
            return maxCollisions;
        }

*/

};


