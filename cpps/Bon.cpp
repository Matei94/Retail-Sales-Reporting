#include <string>

#include "Bon.h"	

//using namespace std;

Bon::Bon( ) {
	this->idBon = "";
	this->idProdus = 0;
}

Bon::Bon( string idBon, int idProdus ) {
	this->idBon = idBon;
	this->idProdus = idProdus;
}

Bon::~Bon( ) {
	/* Do nothing */
}

Bon::Bon( const Bon& obiectulBon ){
	idBon = obiectulBon.idBon;
	idProdus = obiectulBon.isProdus;
}

void Bon::operator=( const Bon& obiectulBon ){
	idBon = obiectulBon.idBon;
	idProdus = obiectulBon.isProdus;	
}

int getIdBon( ) {
	return idBon;
}

int getIdProdus( ){
	return idProdus;
}

/*
ostream& operator<< ( std::ostream& out, const Bon& b ){
	out << b.idBon << ' ' << b.idProdus << std::endl;
	return out;
}

istream& operator>> ( std::ostream& is, Bon& b ){
	is >> b.idBon >> b.idProdus;
	return is;
*/
}