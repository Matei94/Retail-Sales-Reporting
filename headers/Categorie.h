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
	void setId(int id);
	void setNume(string nume);
	Categorie (const Categorie& c);
	void operator=(const Categorie& c);
	Categorie(string line);
};
#endif /*__Categorie_H_*/
	
