#ifndef __MAGAZIN_H_
#define __MAGAZIN_H_

using namespace std;

class Magazin {
  private:
	int idMagazin;
	string locatieMagazin;
		
  public: 
  	/* Constructor default */
  	Magazin( );
  	
	/* Constructor */
	Magazin( int idMagazin, string locatieMagazin );

	/* Destructor */
	~Magazin( );

	/* Copy-Constructor */
	Magazin( const Magazin& obiectMagazin );

	/* Suprascrierea operatorului de atribuire */
	void operator= ( const Magazin& obiectMagazin );

	/* Extragere idMagazin */
	int getIdMagazin( );

	/* Extragere locatieMagazin */
	string getLocatieMagazin( );

	/* Constructor pentru citire din fisier */
	Magazin( string linieFisier );

};

#endif // __MAGAZIN_H_
