#ifndef __BON__
#define __BON__

class Bon {
  private:
	long long idBon;
	int idProdus;
	
  public:
	// Constructor
	Bon( long long idBon, int idProdus );

	// Destructor
	~Bon( );

	// Copy-Constructor
	Bon( Bon& obiectulBon );

	// Suprascrierea operatorului de atribuire
	void operator= ( const Bon& obiectulBon );

	// Extragere idBon
	long long getIdBon( );

	// Extragerea idProdus
	int getIdProdus( );

};

#endif //__BON_H__
