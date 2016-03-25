#include "tranzactii.h"

Tranzactii::Tranzactii ( int id_tranzactii , string timestamp , long long id_bon , int id_magazine ) {
	this->id_tranzactii = id_tranzactii;
	this->timestamp = timestamp;
	this->id_bon = id_bon;
	this->id_magazine = id_magazine;
	
}

Tranzactii::Tranzactii( Tranzactii& copy ) {

	id_tranzactii = copy.id_tranzactii;
	timestamp = copy.timestamp;
	id_bon = copy.id_bon;
	id_magazin = copy.id_magazin;
}

void operator=( const Tranzactii& copy ) {
	
	id_tranzactii = copy.id_tranzactii;
	timestamp = copy.timestamp;
	id_bon = copy.id_bon;
	id_magazin = copy.id_magazin;
}

Tranzactii::~Tranzactii() {

	delete id_tranzactii;
	delete timestamp;
	delete id_bon;
	delete id_magazine;
}

Tranzactii::getid_tranzactii(int id_tranzactii) {

	return id_tranzactii;		
}

Tranzactii::gettimestamp(string timestamp) {

	return timestamp;
}

Tranzactii::getid_bon() {

	return id_bon;
}

Tranzactii::getid_magazine(int id_magazine) {

	return id_magazine;
}
