#include <string>

#include "Tranzactie.h"

Tranzactie::Tranzactie( ) {
	this->idTranzactie = 0;
	this->idMagazin = 0;
	this->timeStamp = "";
	this->idBon = "";
}

Tranzactie::Tranzactie( int idTranzactie, int idMagazin, string timeStamp, string idBon ) {
	this->idTranzactie = idTranzactie;
	this->idMagazin = idMagazin;
	this->timeStamp = timeStamp;
	this->idBon = idBon;
}

Tranzactie::~Tranzactie( ) {
	/* Do nothing */
}

Tranzactie::Tranzactie( const Tranzactie& obiectulTranzactie ) {
	idTranzactie = obiectulTranzactie.idTranzactie;
	idMagazin = obiectulTranzactie.idMagazin;
	timeStamp = obiectulTranzactie.timeStamp;
	idBon = obiectulTranzactie.idBon;
}

void Tranzactie::operator=( const Tranzactie& obiectulTranzactie ) {
	idTranzactie = obiectulTranzactie.idTranzactie;
	idMagazin = obiectulTranzactie.idMagazin;
	timeStamp = obiectulTranzactie.timeStamp;
	idBon = obiectulTranzactie.idBon;
}

int Tranzactie::getIdTranzactie( ) {
	return idTranzactie;
}

int Tranzactie::getIdMagazin( ) {
	return idMagazin;
}

string Tranzactie::getTimeStamp( ) {
	return timeStamp;
}

string Tranzactie::getIdBon( ) {
	return idBon;
}