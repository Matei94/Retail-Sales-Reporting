#ifndef __Categorie_H_
#define __Categorie_H_

class Categorie {
  private:
	int idCategorie;
	string numeCategorie;

  public:
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

};

#endif //__Categorie_H_
	
