#ifndef __BON_H__
#define __BON_H__

#include <string.h>

class Bon{

public:

	Bon( std::string idBon, int idProdus );

	Bon( const Bon& b );

	void operator= ( const Bon& b );

	~Bon();

	string getIdBon( std::string idBon );

	int getIdProdus( int idProdus );

friend:
	
	std::ostream& operator<< ( std::ostream& out, const Bon& b );
	std::istream& operator>> ( std::istream& in, Bon& b );

private:

	std::string idBon;
	int idProdus;

};

<<<<<<< HEAD
#endif __BON_H__
=======
#endif __bon_h__
>>>>>>> 30bf737a3307d4121843e0a190adc67ca019dcbb
