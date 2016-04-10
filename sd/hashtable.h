#include "LinkedList.h"

#define Vmax 1000
 
 #include<string>
using namespace std;


template<typename Tkey, typename Tvalue> 
struct elemInfo {
    Tkey key;
    Tvalue value; 
};

template<typename Tkey, typename Tvalue> 
class Hashtable {
    private:
        LinkedList<struct elemInfo<Tkey, Tvalue> > *H;
        int HMAX;
        int (*hash) (Tkey);

    public:

        /*
        class Proxy {
          private:
            HashTable* myOwner;
            Tkey myKey;
          public:
            Proxy( HashTable* owner, Tkey const& key ) : myOwner( owner ) , myKey( key ) {
            }

            operator Tvalue const&() const {
                Tvalue const* result = myOwner->get( myKey );
                if ( result == NULL ) {
                    //  Desired error behavior here...
                }
                return *result;
            }

            Proxy const& operator==( Tvalue const& value ) const {
                myOwner->put( myKey, value );
                return *this;
            }
        };

        Tvalue* get( Tkey const& key ) const;
        void put( Tkey const& key, Tvalue const& value );

        Proxy operator[]( Tkey const& key ) {
            return Proxy( this, key );
        }
        */

        Hashtable(int hmax, int (*h) (Tkey)) {
            HMAX = hmax;
            hash = h;
            H = new LinkedList<struct elemInfo<Tkey, Tvalue> > [HMAX]; 
        }

        ~Hashtable() {
            for (int i = 0; i < HMAX; i++) {
                 while ( !H[i].isEmpty() )
                    H[i].removeFirst();
            }

            delete[] H;
        }

        void put(Tkey key, Tvalue value) {
           struct listElem<struct elemInfo<Tkey, Tvalue> > *p;
           struct elemInfo<Tkey, Tvalue> info;

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

        Tvalue get(Tkey key) {
            struct listElem<struct elemInfo<Tkey, Tvalue> > *p;

            int hkey = hash(key);
            p = H[hkey].front();

            while (p != NULL) {
                if (p->info.key == key) break;
                p = p->next;
            }

            if (p != NULL)
                return p->info.value;
            else {
                fprintf(stderr, "Error 101 - The key does not exist\n");
                Tvalue x;
                return x;
            }
        }

        int hasKey(Tkey key) {
            struct listElem<struct elemInfo<Tkey, Tvalue> > *p;

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

        int getCollisions() {
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
        //mapped_type& operator[] (const key_type& k) {
            
        //}

        Tvalue operator[]( const Tkey& key ) {
            int hashKey = hash(key);
            return H[hashKey].front()->info.value;
        }

  /*      void operator=( const elemInfo< Tkey, Tvalue>& ceva ) {
            this[ceva.key].front()->info.key = ceva.key;
            this[ceva.key].front()->value = ceva.value;
        }
*/
        //void

        /* Functia de Hash */
int customHash(string key) {
    int hkey = 0;
    for (int i = 0; i < key.length(); i++)
        hkey = (hkey * 31 + key[i]) % Vmax;
    return hkey;
}

        void operator+=( const elemInfo<Tkey, Tvalue>& ceva ) {
            this->put( ceva.key, this->get( ceva.key ) + value );
        }
        
};



