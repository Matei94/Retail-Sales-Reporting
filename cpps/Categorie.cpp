#include "../headers/Categorie.h"

Categorie::Categorie(int id, string nume){
  this->id = id;
  this->nume = nume;
}

int Categorie::getId(){
  return id;
}

string Categorie::getNume(){
  return nume;
}

void Categorie::setId(int id){
  this->id = id;
}

void Categorie::setNume(string nume){
  this->nume = nume;
}

Categorie::Categorie(const Categorie& c){
  id = c.id;
  nume = c.nume;
}

void Categorie::operator=(const Categorie& c){
  id = c.id;
  nume = c.nume;
}
