#include "../headers/magazine.h"

int Magazin::get_id_magazin () {
	return id_magazin;
}

string Magazin::get_locatie_magazin () {
	return locatie_magazin;
}

Magazin::~Magazin () {
};

Magazin::Magazin (int id_magazin, string locatie_magazin) {
	this->id_magazin = id_magain;
	strcpy (this->locatie_magazin, locatie_magazin);
}
Magazin::Magazin (const Magazin& magazin) {
	this->id_magazin = magazin.id_magain;
	strcpy (this->locatie_magazin, magazin.locatie_magazin);
}
