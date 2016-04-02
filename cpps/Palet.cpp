#include <string>

#include "Palet.h"

Palet::Palet( ) {
	this->idPalet = "";
	this->prodType = 0;
	this->numberOfItems = 0;
	this->idSlot = 0;	
}

Palet::Palet( string idPalet, int prodType, int numberOfItems, int idSlot ) {
	this->idPalet = idPalet;
	this->prodType = prodType;
	this->numberOfItems = numberOfItems;
	this->idSlot = idSlot;
}

Palet::~Palet( ) {
	/* Do nothing */
}

Palet::Palet( const Palet& obiectulPalet ) {
	idPalet = obiectulPalet.idPalet;
	prodType = obiectulPalet.prodType;
	numberOfItems = obiectulPalet.numberOfItems;
	idSlot = obiectulPalet.idSlot;
}

void Palet::operator=( const Palet& obiectulPalet ) {
	idPalet = obiectulPalet.idPalet;
	prodType = obiectulPalet.prodType;
	numberOfItems = obiectulPalet.numberOfItems;
	idSlot = obiectulPalet.idSlot;
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
