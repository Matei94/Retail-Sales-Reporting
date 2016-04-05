#ifndef __PALET_H_
#define __PALET_H_

class Palet {
  private:
	string idPalet;
	int prodType, numberOfItems, idSlot;

  public:
	/* Constructor */
	Palet( string idPalet, int prodType, int numberOfItems, int idSlot );

	/* Destructor */
	~Palet( );

	/* Copy-Constructor */
	Palet( const Palet& obiectulPalet );

	/* Suprascrierea operatorului de atribuire */
	void operator= ( const Palet& obiectulPalet );

	/* Extragere idPalet */
	string getIdPalet( );

	/* Extragere prodType */
	int getProdType( );

	/* Extragere numberOfItems */
	int getNumberOfItems( );

	/* Extragere idSlot */
	int getIdSlot( );

	/* Constructor pentru citirea din fisier */
	Palet( string linieFisier );

};

#endif //__PALET_H_
