#ifndef __BON_H_
#define __BON_H_

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

#endif /* __BON_H_ */

