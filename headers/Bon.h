#ifndef __bon_h__
#define __bon_h__

#include <string.h>

class Bon{

public:

	Bon( std::string idBon, std::int idProdus );

	Bon( const Bon& b );

	void operator= ( const Bon& b );

	~Bon();

	string getIdBon( std::string idBon );

	int getIdProdus( std::int idProdus );

friend:
	
	std::ostream& operator<< ( std::ostream& out, const Bon& b );
	std::istream& operator<< ( std::istream& in, Bon& b );

private:

	std::string idBon;
	std::int idProdus;

};

#endif __bon_h__