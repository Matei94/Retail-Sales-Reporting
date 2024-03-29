#include <string>

#include "Categorie.h"

using namespace std;

Categorie::Categorie( ) {
  this->idCategorie = 0;
  this->numeCategorie = "";
}

Categorie::Categorie ( int idCategorie, string numeCategorie ) {
    this->idCategorie = idCategorie;
    this->numeCategorie = numeCategorie;
}

Categorie::~Categorie( ) {
  /* Do nothing */
}

Categorie::Categorie ( const Categorie& obiectulCategorie ) {
  this->idCategorie = obiectulCategorie.idCategorie;
  this->numeCategorie = obiectulCategorie.numeCategorie;  
}

void Categorie::operator= ( const Categorie& obiectulCategorie ) {
  this->idCategorie = obiectulCategorie.idCategorie;
  this->numeCategorie = obiectulCategorie.numeCategorie;
}

int Categorie::getIdCategorie( ) {
  return idCategorie;
}

string Categorie::getNumeCategorie( ) {
  return numeCategorie;
}

Categorie::Categorie( string linieFisier ){
  int firstComma = linieFisier.find_first_of( ',' );
  this->idCategorie = stoi( linieFisier.substr( 0, firstComma ) );
  this->numeCategorie = linieFisier.substr( firstComma + 1, linieFisier.length( ) - firstComma - 1 );
}
