#include <string>

#include "Magazin.h"

using namespace std;

Magazin::Magazin( ) {
	this->idMagazin = 0;
	this->locatieMagazin = "";
}

Magazin::Magazin( int idMagazin, string locatieMagazin ) {
	this->idMagazin = idMagazin;
	this->locatieMagazin = locatieMagazin;
}

Magazin::~Magazin( ) {
	/* Do nothing */
}

Magazin::Magazin( const Magazin& obiectulMagazin ) {
	this->idMagazin = obiectulMagazin.idMagazin;
	this->locatieMagazin = obiectulMagazin.locatieMagazin;
}

void Magazin::operator=( const Magazin& obiectulMagazin ) {
	this->idMagazin = obiectulMagazin.idMagazin;
	this->locatieMagazin = obiectulMagazin.locatieMagazin;
}

int Magazin::getIdMagazin( ) {
	return idMagazin;
}

string Magazin::getLocatieMagazin( ) {
	return locatieMagazin;
}

Magazin::Magazin( string linieFisier ){
	int firstComma = linieFisier.find_first_of( ',' );
	this->idMagazin	= stoi( linieFisier.substr( 0, firstComma ) );
	this->locatieMagazin = stoi( linieFisier.substr( firstComma + 1, linieFisier.length( ) - firstComma - 1 ) );
}

