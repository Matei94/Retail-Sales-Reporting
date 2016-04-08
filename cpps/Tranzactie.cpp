#include <string>

#include "../headers/Tranzactie.h"

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
	this->idTranzactie = obiectulTranzactie.idTranzactie;
	this->idMagazin = obiectulTranzactie.idMagazin;
	this->timeStamp = obiectulTranzactie.timeStamp;
	this->idBon = obiectulTranzactie.idBon;
}

void Tranzactie::operator=( const Tranzactie& obiectulTranzactie ) {
	this->idTranzactie = obiectulTranzactie.idTranzactie;
	this->idMagazin = obiectulTranzactie.idMagazin;
	this->timeStamp = obiectulTranzactie.timeStamp;
	this->idBon = obiectulTranzactie.idBon;
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

Tranzactie::Tranzactie( string linieFisier ){
	int firstComma = linieFisier.find_first_of( ',' );
	this->idTranzactie = stoi( linieFisier.substr( 0, firstComma ) );
	string sirulDeProcesat = linieFisier.substr( firstComma + 1, linieFisier.length( ) - firstComma - 1 );
	firstComma = sirulDeProcesat.find_first_of( ',' );
	this->timeStamp = sirulDeProcesat.substr( 0, firstComma );
	sirulDeProcesat = sirulDeProcesat.substr( firstComma + 1, sirulDeProcesat.length( ) - firstComma - 1 );
	firstComma = sirulDeProcesat.find_first_of( ',' );
	this->idBon = sirulDeProcesat.substr( 0, firstComma );
	this->idMagazin = stoi( sirulDeProcesat.substr( firstComma + 1, sirulDeProcesat.length( ) - firstComma - 1 ) );
}
