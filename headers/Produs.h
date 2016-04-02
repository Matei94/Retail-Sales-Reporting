#ifndef __PRODUS_H_
#define __PRODUS_H_

class Produs {
  private: 
	int idProdus, idCategorie, price;
	string numeProdus;

  public:
	/* Constructor */
	Produs( int idProdus, int idCategorie, int price, string numeProdus );

	/* Destructor */
	~Produs( );

	/* Copy-Constructor */
	Produs( const Produs& obiectProdus );

	/* Suprascrierea operatorului de atribuire */
	void operator= ( const Produs& obiectProdus );

	/* Extragere idProdus */
	int getIdProdus( );

	/* Extragere idCategorie */
	int getIdCategorie( );

	/* Extragere price */
	int getPrice( );

	/* Extragere numeProdus */
	string getNumeProdus( );

};

#endif // __PRODUS_H_
