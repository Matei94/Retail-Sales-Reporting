#include <string>

#include "Produs.h"

using namespace std;
Produs::Produs( ) {
	this->idProdus = 0;
	this->idCategorie = 0;
	this->price = 0;
	this->numeProdus = "";
}

Produs::Produs( int idProdus, int idCategorie, int price, string numeProdus ) {
	this->idProdus = idProdus;
	this->idCategorie = idCategorie;
	this->price = price;
	this->numeProdus = numeProdus;
}

Produs::~Produs( ) {
	/* Do nothing */
}

Produs::Produs( const Produs& obiectulProdus ) {
	this->idProdus = obiectulProdus.idProdus;
	this->idCategorie = obiectulProdus.idCategorie;
	this->price = obiectulProdus.price;
	this->numeProdus = obiectulProdus.numeProdus;
}

void Produs::operator=( const Produs& obiectulProdus ) {
	this->idProdus = obiectulProdus.idProdus;
	this->idCategorie = obiectulProdus.idCategorie;
	this->price = obiectulProdus.price;
	this->numeProdus = obiectulProdus.numeProdus;
}

int Produs::getIdProdus( ) {
	return idProdus;	
}

int Produs::getIdCategorie( ) {
	return idCategorie;
}

int Produs::getPrice( ) {
	return price;
}

string Produs::getNumeProdus( ) {
	return numeProdus;
}

Produs::Produs( string linieFisier ) {
	int firstComma = linieFisier.find_first_of( ',' );
	this->idProdus = stoi( linieFisier.substr( 0, firstComma ) );
	string sirulDeProcesat = linieFisier.substr( firstComma + 1, linieFisier.length( ) - firstComma - 1 );
	firstComma = sirulDeProcesat.find_first_of( ',' );
	this->numeProdus = sirulDeProcesat.substr( 0, firstComma );
	sirulDeProcesat = sirulDeProcesat.substr( firstComma + 1, sirulDeProcesat.length( ) - firstComma - 1 );
	firstComma = sirulDeProcesat.find_first_of( ',' );
	this->idCategorie = stoi( sirulDeProcesat.substr( 0, firstComma ) );
	this->price = stoi( sirulDeProcesat.substr( firstComma + 1, sirulDeProcesat.length( ) - firstComma - 1 ) );
}

