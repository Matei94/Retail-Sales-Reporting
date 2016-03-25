#ifndef __Tranzactie__
#define __Tranzactie__

class Tranzactie {
  private:
	int idTranzactie, idMagazin;  
	string timeStamp;
	long long idBon;

  public:
	// Constructor
	Tranzactie( int idTranzactie, string timeStamp, long long idBon, int idMagazin );

	// Destructor
	~Tranzactie( );

	// Copy-Constructor
	Tranzactie( Tranzactie& obiectulTranzactie );

	// Suprascrierea operatorului de atribuire
	void operator= ( const Tranzactie& obiectulTranzactie );

	// Extragere idTranzactie
	int getIdTranzactie( );

	// Extragere idMagazin
	int getIdMagazin( );
		
	// Extragere timeStamp
	string getTimeStamp( );

	// Extragere idBon
	long long getIdBon( );

};

#endif //__Tranzactie__
