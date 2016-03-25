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

void Categorie::setId(int id){
  this->id = id;
}

void Categorie::setNume(string nume){
  this->nume = nume;
}
