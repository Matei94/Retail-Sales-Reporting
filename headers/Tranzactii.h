#ifndef __TRANZACTII_H_
#define __TRANZACTII_H_

class Tranzactii {
	private:
		int id_tranzactii;
		string timestamp;
		long long id_bon;
		int id_magazine;

	public:
		Tranzactii( int id_tranzactii, string timestamp, long long id_bon, int id_magazine );

		Tranzactii( Tranzactii& copy );

		void operator=( const Tranzactii& copy );

		~Tranzactii();

		//functiile get
		int getid_tranzactii ();
		
		string gettimestamp ();

		long long getid_bon ();
		
		int getid_magazine ();

};

#endif /* __TRANZACTII_H_ */
