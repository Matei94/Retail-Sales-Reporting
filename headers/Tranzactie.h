#ifndef __Tranzactie_H_
#define __Tranzactie_H_

class Tranzactie {
  private:
	int idTranzactie, idMagazin;  
	string timeStamp, idBon;

  public:
	/* Constructor */
	Tranzactie( int idTranzactie, string timeStamp, string idBon, int idMagazin );

	/* Destructor */
	~Tranzactie( );

	/* Copy-Constructor */
	Tranzactie( const Tranzactie& obiectulTranzactie );

	/* Suprascrierea operatorului de atribuire */
	void operator= ( const Tranzactie& obiectulTranzactie );

	/* Extragere idTranzactie */
	int getIdTranzactie( );

	/* Extragere idMagazin */
	int getIdMagazin( );
		
	/* Extragere timeStamp */
	string getTimeStamp( );

	/* Extragere idBon */
	string getIdBon( );

};

#endif //__Tranzactie_H_