#include <string>

#include "Produs.h"

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
	idProdus = obiectulProdus.idProdus;
	idCategorie = obiectulProdus.idCategorie;
	price = obiectulProdus.price;
	numeProdus = obiectulProdus.numeProdus;
}

void Produs::operator=( const Produs& obiectulProdus ) {
	idProdus = obiectulProdus.idProdus;
	idCategorie = obiectulProdus.idCategorie;
	price = obiectulProdus.price;
	numeProdus = obiectulProdus.numeProdus;
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
