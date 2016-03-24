#include "Bon.h"
#include <string.h>	

Bon::Bon( std::string idBon, int id_prdus ){
	this->idBon = idBon;
	this->idProdus = idProdus;
}

Bon::Bon( const Bon& b ){
	this->b = b;

}

Bon::void operator=( const Bon& b ){
	this->b = b;
}

Bon::~Bon{}

int getIdBon( std::string idBon ){
	return idBon;
}

int getIdProdus( int idProdus ){
	return idProdus;
}

std::ostream& operator<< ( std::ostream& out, const Bon& b ){
	out << b.idBon << ' ' << b.idProdus << std::endl;
	return out;
}

std::istream& operator>> ( std::ostream& is, Bon& b ){
	is >> b.idBon >> b.idProdus;
	return is;
}