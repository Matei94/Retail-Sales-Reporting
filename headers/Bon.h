#ifndef __BON_H_
#define __BON_H_

class Bon {
  private:
	string idBon;
	int idProdus;
	
  public:
	/* Constructor */
	Bon( string idBon, int idProdus );

	/* Destructor */
	~Bon( );

	/* Copy-Constructor */
	Bon( const Bon& obiectulBon );

	/* Suprascrierea operatorului de atribuire */
	void operator= ( const Bon& obiectulBon );

	/* Extragere idBon */
	long long getIdBon( );

	/* Extragerea idProdus */
	int getIdProdus( );

};

#endif //__BON_H_
