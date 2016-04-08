#ifndef __PALET_H_
#define __PALET_H_

class Palet {
  private:
	string idPalet;
	int prodType, numberOfItems, idSlot;
	/* indexSlot -> retine indexul paletului curent in slot. Astfel, putem calcula in O(1)
	numarul de mutari necesare extragerii unui palet dintr-un slot. E posibil sa nu fie 
	necesara variabila asta. De analizat ulterior!! */
	int indexSlot;

  public:
	/* Constructor */
	Palet( string idPalet, int prodType, int numberOfItems, int idSlot, int indexSlot );

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

	/* Extragere indexSlot */
	int getIndexSlot( );

	/* Constructor pentru citirea din fisier */
	Palet( string linieFisier );

};

#endif //__PALET_H_
