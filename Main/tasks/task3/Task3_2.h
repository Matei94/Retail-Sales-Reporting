
#define NR_SLOTS 30

void task3_2( LinkedList<Produs>& listaProduse, Hashtable<int,Pereche>& hashmap, int contorIndex[], string produs );

void task3_2( LinkedList<Produs>& listaProduse, Hashtable<int,Pereche>& hashmap, int contorIndex[], string produs ) {

	ofstream output ( "Rezultate.csv", ofstream::app );

	int idProdus = getIdProdusAfterName( listaProduse, produs );

	Pereche pair;
	LinkedList<int> idSlot;
	LinkedList<int> indexSlot;

	while(hashmap.get( idProdus, pair )){
		
		idSlot.addLast( pair.idSlot );
		indexSlot.addLast( pair.indexSlot );

		hashmap.remove( idProdus );
	}

	Node<int> *primulid = idSlot.front(); 
	Node<int> *primulindex = indexSlot.front();

	output << "\n\nTask-ul 3_2:\n\n";

	output << " Numarul de mutari pentru produsul " << produs << " este( pentru fiecare palet ): ";

	while( ( primulid != NULL ) && ( primulindex != NULL ) ){
		pair.idSlot = primulid->getValue();
		pair.indexSlot = primulindex->getValue();

		output << 2 * ( contorIndex[ pair.idSlot ] - pair.indexSlot ) + 1 << ' ';

		hashmap.Insert( idProdus, pair );
		primulid = primulid->getNext();
		primulindex = primulindex->getNext();
	}
	output.close();
}
