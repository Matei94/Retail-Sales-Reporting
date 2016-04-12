
#define NR_SLOTS 30

int getIdProdusAfterName( LinkedList<Produs>& listaProduse, string produs ){
	Node<Produs> *cautare = listaProduse.front();

		while( cautare != NULL ){
		if( produs == cautare->getValue().getNumeProdus() ) {
			return cautare->getValue().getIdProdus();
		}
		cautare = cautare->getNext();
	}	
}

void task3_1( LinkedList<Produs>& listaProduse, Hashtable<int,Pereche>& hashmap, string produs ) {

	int idProdus = getIdProdusAfterName( listaProduse, produs );

	Pereche pair;
	LinkedList<int> idSlot;
	LinkedList<int> indexSlot;

	int aparitiislots [ NR_SLOTS + 1 ] = { 0 };

	while(hashmap.get( idProdus, pair )){
		
		idSlot.addLast( pair.idSlot );
		indexSlot.addLast( pair.indexSlot );

		aparitiislots[ pair.idSlot ]++;

		hashmap.remove( idProdus );
	}

	cout << " Produsul " << produs << " apare in urmatoarele slot-uri: " << endl;
	for( int i = 1; i <= NR_SLOTS; i++ )
		if( aparitiislots[ i ] > 0 )
			cout << i << " ";

	cout<<endl;
	
	Node<int> *primulid = idSlot.front(); 
	Node<int> *primulindex = indexSlot.front();

	while( ( primulid != NULL ) && ( primulindex != NULL ) ){
		pair.idSlot = primulid->getValue();
		pair.indexSlot = primulindex->getValue();
		hashmap.Insert( idProdus, pair );
		primulid = primulid->getNext();
		primulindex = primulindex->getNext();
	}
}