#include <string>

#include "Magazin.h"

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
	idMagazin = obiectulMagazin.idMagazin;
	locatieMagazin = obiectulMagazin.locatieMagazin;
}

void Magazin::operator=( const Magazin& obiectulMagazin ) {
	idMagazin = obiectulMagazin.idMagazin;
	locatieMagazin = obiectulMagazin.locatieMagazin;
}

int Magazin::getIdMagazin( ) {
	return idMagazin;
}

string Magazin::getLocatieMagazin( ) {
	return locatieMagazin;
}

