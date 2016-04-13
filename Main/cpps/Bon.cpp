#include <string>

#include "../headers/Bon.h"	

using namespace std;

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
	this->idBon = obiectulBon.idBon;
	this->idProdus = obiectulBon.idProdus;
}

void Bon::operator=( const Bon& obiectulBon ){
	this->idBon = obiectulBon.idBon;
	this->idProdus = obiectulBon.idProdus;	
}

string Bon::getIdBon( ) {
	return idBon;
}

int Bon::getIdProdus( ){
	return idProdus;
}

Bon::Bon( string linieFisier ){
	int firstComma = linieFisier.find_first_of( ',' );
  	this->idBon = linieFisier.substr( 0, firstComma );
  	this->idProdus = stoi( linieFisier.substr( firstComma + 1, linieFisier.length( ) - firstComma - 1 ) );
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


