#ifndef __MAGAZIN__
#define __MAGAZIN__

class Magazin {
  private:
	int idMagazin;
	string locatieMagazin;
		
  public: 
	// Constructor
	Magazin( int idMagazin, string locatieMagazin );

	// Destructor
	~Magazin( );

	// Copy-Constructor
	Magazin( Magazin& obiectMagazin );

	// Suprascrierea operatorului de atribuire
	void operator= ( const Magazin& obiectMagazin );

	// Extragere idMagazin
	int getIdMagazin( );

	// Extragere locatieMagazin
	string getLocatieMagazin( );

};

#endif // __MAGAZIN__
