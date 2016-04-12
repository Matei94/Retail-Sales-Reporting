
#define NR_SLOTS 30

void task3_2( LinkedList<Produs>& listaProduse, Hashtable<int,Pereche>& hashmap, int contorIndex[], string produs );

void task3_2( LinkedList<Produs>& listaProduse, Hashtable<int,Pereche>& hashmap, int contorIndex[], string produs ) {

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

	cout << " Numarul de mutari care trebuiesc facute pentru produsul " << produs << " este( pentru fiecare palet ): ";

	while( ( primulid != NULL ) && ( primulindex != NULL ) ){
		pair.idSlot = primulid->getValue();
		pair.indexSlot = primulindex->getValue();

		cout << 2 * ( contorIndex[ pair.idSlot ] - pair.indexSlot ) + 1 << ' ';

		hashmap.Insert( idProdus, pair );
		primulid = primulid->getNext();
		primulindex = primulindex->getNext();
	}

}