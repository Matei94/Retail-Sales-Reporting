#ifndef __PALET_H_
#define __PALET_H_
#include <string.h>
using namespace std;

class Palet {
	string id_palet;
	int prod_type, n_items, slot;
	public:
		string get_id_palet ();
		int get_prod_type ();
		int get_n_items ();
		int get_slot ();
	//	~Palet (); //destructor
	//	Palet (string id_palet, int prod_type, int n_items, int slot);    //constructor
	//	Palet (const Palet& palet); //copy-constructor
};
#endif /* __PALET_H_ */
