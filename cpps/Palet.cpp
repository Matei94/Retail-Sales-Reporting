#include <string>

#include "../headers/Palet.h"

using namespace std;

Palet::Palet( ) {
	this->idPalet = "";
	this->prodType = 0;
	this->numberOfItems = 0;
	this->idSlot = 0;	
	this->indexSlot = 0;
}

Palet::Palet( string idPalet, int prodType, int numberOfItems, int idSlot, int indexSlot ) {
	this->idPalet = idPalet;
	this->prodType = prodType;
	this->numberOfItems = numberOfItems;
	this->idSlot = idSlot;
	this->indexSlot = indexSlot;
}

Palet::~Palet( ) {
	/* Do nothing */
}

Palet::Palet( const Palet& obiectulPalet ) {
	this->idPalet = obiectulPalet.idPalet;
	this->prodType = obiectulPalet.prodType;
	this->numberOfItems = obiectulPalet.numberOfItems;
	this->idSlot = obiectulPalet.idSlot;
	this->indexSlot = obiectulPalet.indexSlot;
}

void Palet::operator=( const Palet& obiectulPalet ) {
	this->idPalet = obiectulPalet.idPalet;
	this->prodType = obiectulPalet.prodType;
	this->numberOfItems = obiectulPalet.numberOfItems;
	this->idSlot = obiectulPalet.idSlot;
	this->indexSlot = obiectulPalet.indexSlot;
}

string Palet::getIdPalet( ) {
	return idPalet;
}

int Palet::getProdType( ) {
	return prodType;
}

int Palet::getNumberOfItems( ) {
	return numberOfItems;
}

int Palet::getIdSlot( ) {
	return idSlot;
}

Palet::Palet( string linieFisier ){
	int firstComma = linieFisier.find_first_of( ',' );
	this->idPalet = linieFisier.substr( 0, firstComma );
	string sirulDeProcesat = linieFisier.substr( firstComma + 1, linieFisier.length( ) - firstComma - 1 );
	firstComma = sirulDeProcesat.find_first_of( ',' );
	this->prodType = stoi( sirulDeProcesat.substr( 0, firstComma ) );
	sirulDeProcesat = sirulDeProcesat.substr( firstComma + 1, sirulDeProcesat.length( ) - firstComma - 1 );
	firstComma = sirulDeProcesat.find_first_of( ',' );
	this->numberOfItems = stoi( sirulDeProcesat.substr( 0, firstComma ) );
	this->idSlot = stoi( sirulDeProcesat.substr( firstComma + 1, sirulDeProcesat.length( ) - firstComma - 1 ) );
}

int Palet::getIndexSlot( ) {
	return indexSlot;
}
