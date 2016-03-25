#ifndef __PALET__
#define __PALET__

class Palet {
  private:
	string idPalet;
	int prodType, numberOfItems, idSlot;

  public:
	// Constructor
	Palet( string idPalet, int prodType, int numberOfItems, int idSlot );

	// Destructor
	~Palet( );

	// Copy-Constructor
	Palet( Palet& obiectulPalet );

	// Suprascrierea operatorului de atribuire
	void operator= ( const Palet& obiectulPalet );

	// Extragere idPalet
	string getIdPalet( );

	// Extragere prodType
	int getProdType( );

	// Extragere numberOfItems
	int getNumberOfItems( );

	// Extragere idSlot
	int getIdSlot( );

};

#endif //__PALET__
