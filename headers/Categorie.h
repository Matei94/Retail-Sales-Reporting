#ifndef __Categorie_H_
#define __Categorie_H_
#include<string>
using namespace std;

class Categorie {
	private:
	int id;
	string nume;

	public:
	Categorie(int id, string nume);
	int getId();
	string getNume();
};
#endif /*__Categorie_H_
	
