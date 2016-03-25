#ifndef __Categorie___
#define __Categorie___

class Categorie {
  private:
	int idCategorie;
	string numeCategorie;

  public:
	// Constructor	
	Categorie( int idCategorie, string numeCategorie );

	// Destructor
	~Categorie( );

	// Copy-Constructor
	Categorie( Categorie& obiectulCategorie );

	// Suprascrierea operatorului de atribuire
	void operator= ( const Categorie& obiectulCategorie );

	// Extrage idCategorie 
	getIdCategorie( );

	// Extrage numeCategorie
	getNumeCategorie( );

};

#endif //__Categorie___
	
