

void task3 ( LinkedList<Produs>& listaProduse, LinkedList<Palet>& listaPaleti, LinkedList<Tranzactie>& listaTranzactii, LinkedList<Bon>& listaBonuri, string produs ){
	/* nrProduse = numarul de produse din listaProduse / citite din fisier */
	Node<Produs> *numarare = listaProduse.front();
	int nrProduse = 0;

	while( numarare != NULL ){
		numarare = numarare->getNext();
		nrProduse++;
	}
	
	/* hashmap - hashtable cu nrProduse bucketuri, avand cheia de tip int si valoarea de tip Pereche (simuleaza un vector de frecventa, de fapt)*/
	Hashtable<int,Pereche> hashmap = Hashtable<int,Pereche>( nrProduse );
	Hashtable<int,int> hashCantitati = Hashtable<int,int>( nrProduse );

	/* slots - vector de NR_SLOTS LinkedList-uri */
	//ArrayList<Palet> slots = ArrayList<Palet>( NR_SLOTS );

	/* contorIndex - retine indexul curent al fiecarui Slot */
	int contorIndex [ NR_SLOTS + 1 ] = { 0 };
	
	/* parcurgere - pointer la inceputul listei de paleti */
	Node<Palet> *parcurgere = listaPaleti.front();
	/* pair - structura definita in Hashtable.h */
	Pereche pair;

	/* Se parcurge lista de paleti, atat timp cat exista elemente */
	while( parcurgere != NULL ) {
		/* pair.idSlot - Retine valoarea idSlot-ului elementului curent din lista */
		pair.idSlot = parcurgere->getValue().getIdSlot();
		/* Se insereaza in vectorul slots, la indexul pair.idSlot, elementul din lista curenta */ 
		//slots.push( pair.idSlot, parcurgere->getValue() );
		/* Se incrementeaza indexul curent aferent slotului pe care se lucreaza acum, semn ca s-a mai introdus un palet in slotul curent */
		contorIndex[ pair.idSlot ]++; 
		/* Se retine si in elementul curent, indexul la care a fost inserat */
		pair.indexSlot = contorIndex[ pair.idSlot ];
		/* Se insereaza in hashtable, in bucketul "parcurgere->getValue().getProdType()", elementul "pair" */
		hashmap.Insert( parcurgere->getValue().getProdType(), pair );
		hashCantitati.Insert( parcurgere->getValue().getProdType(), parcurgere->getValue().getNumberOfItems() );
		/* Mutam pointerul asupra elementului urmator din lista */
		parcurgere = parcurgere->getNext();
	}
	
	/* Taskul 3_1 */
	task3_1( listaProduse, hashmap, produs );

	/* Taskul 3_2 */
	task3_2( listaProduse, hashmap, contorIndex, produs );

	/* Taskul 3_3 */
	task3_3( listaTranzactii, listaBonuri, nrProduse, hashCantitati, listaProduse );

}