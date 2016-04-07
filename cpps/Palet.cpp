#include <string>

#include "Palet.h"

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
	idPalet = obiectulPalet.idPalet;
	prodType = obiectulPalet.prodType;
	numberOfItems = obiectulPalet.numberOfItems;
	idSlot = obiectulPalet.idSlot;
	indexSlot = obiectulPalet.indexSlot;
}

void Palet::operator=( const Palet& obiectulPalet ) {
	idPalet = obiectulPalet.idPalet;
	prodType = obiectulPalet.prodType;
	numberOfItems = obiectulPalet.numberOfItems;
	idSlot = obiectulPalet.idSlot;
	indexSlot = obiectulPalet.indexSlot;
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

int Palet::getIndexSlot( ) {
	return indexSlot;
}