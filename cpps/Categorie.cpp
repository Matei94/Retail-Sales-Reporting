#include <string>

#include "Categorie.h"

Categorie::Categorie () {
	this->idCategorie = 0;
	this->numeCategorie = "";
}

Categorie::Categorie ( int idCategorie, string numeCategorie ) {
  	this->idCategorie = idCategorie;
  	this->numeCategorie = numeCategorie;
}

Categorie::~Categorie () {
	/* Do nothing */
}

Categorie::Categorie ( const Categorie& obiectulCategorie ) {
	idCategorie = obiectulCategorie.idCategorie;
	numeCategorie = obiectulCategorie.numeCategorie;	
}

void Categorie::operator= ( const Categorie& obiectulCategorie ) {
	idCategorie = obiectulCategorie.idCategorie;
	numeCategorie = obiectulCategorie.numeCategorie;
}

int Categorie::getIdCategorie () {
  return idCategorie;
}

string Categorie::getNumeCategorie () {
  return numeCategorie;
}
