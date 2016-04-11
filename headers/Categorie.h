#ifndef __Categorie_H_
#define __Categorie_H_

using namespace std;

class Categorie {
  private:
	int idCategorie;
	string numeCategorie;

  public:
  	/* Constructor default */
  	Categorie( );
  	
	/* Constructor */
	Categorie( int idCategorie, string numeCategorie );

	/* Destructor */
	~Categorie( );

	/* Copy-Constructor */
	Categorie( const Categorie& obiectulCategorie );

	/* Suprascrierea operatorului de atribuire */
	void operator= ( const Categorie& obiectulCategorie );

	/* Extrage idCategorie */
	getIdCategorie( );

	/* Extrage numeCategorie */
	getNumeCategorie( );

	/* Constructor pentru citirea din fisier */
	Categorie( string linieFisier );
};

#endif //__Categorie_H_