#ifndef __BON_H_
#define __BON_H_
using namespace std;

class Bon {
  private:
	string idBon;
	int idProdus;
	
  public:
  	/* Constructor default */
  	Bon( );

	/* Constructor */
	Bon( string idBon, int idProdus );

	/* Destructor */
	~Bon( );

	/* Copy-Constructor */
	Bon( const Bon& obiectulBon );

	/* Suprascrierea operatorului de atribuire */
	void operator= ( const Bon& obiectulBon );

	/* Extragere idBon */
	string getIdBon( );

	/* Extragerea idProdus */
	int getIdProdus( );

	/* Constructor pentru citirea din fisier */
	Bon( string linieFisier );

};

#endif //__BON_H_

