#include<Categorie.h>

Categorie::Categorie (int id, string nume){
  this->id = id;
  this->nume = nume;
}

int Categorie::getId(){
  return id;
}

string Categorie::getNume(){
  return nume;
}
