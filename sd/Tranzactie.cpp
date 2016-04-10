#include <string>
#include <iostream>

#include "Tranzactie.h"

using namespace std;

Tranzactie::Tranzactie( ) {
	this->idTranzactie = 0;
	this->idMagazin = 0;
	this->timeStamp = "";
	this->idBon = "";
}

Tranzactie::Tranzactie( int idTranzactie, string timeStamp, string idBon, int idMagazin ) {
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
	/* firstComma = pozitia primei virgule din stringul dat ca parametru */
	int firstComma = linieFisier.find_first_of( ',' );

	/* Se extrage substringul din intervalul [0, firstComma] = idTranzactie*/
	this->idTranzactie = stoi( linieFisier.substr( 0, firstComma ) );

	/* Se elimina substringul anterior si se va lucra pe stringul nou = sirulDeProcesat */
	string sirulDeProcesat = linieFisier.substr( firstComma + 1, linieFisier.length( ) - firstComma - 1 );

	/* Se cauta urmatoarea aparitie a unei virgule */
	firstComma = sirulDeProcesat.find_first_of( ',' );

	/* Se extrage timeStamp-ul din noul sir */
	this->timeStamp = sirulDeProcesat.substr( 0, firstComma );

	/* Se updateaza sirul de procesat, eliminand substringul extras anterior */
	sirulDeProcesat = sirulDeProcesat.substr( firstComma + 1, sirulDeProcesat.length( ) - firstComma - 1 );

	/* Se cauta aparitia urmatoarei virgule */
	firstComma = sirulDeProcesat.find_first_of( ',' );

	/* Se extrage idBon din noul sir */
	this->idBon = sirulDeProcesat.substr( 0, firstComma );

	/* Se extrage idMagazin din ceea ce ramane din string */
	this->idMagazin = stoi( sirulDeProcesat.substr( firstComma + 1, sirulDeProcesat.length( ) - firstComma - 1 ) );
}

