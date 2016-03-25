#ifndef __magazine_H_
#define __magazine_H_

class Magazine {
	int id_magazin;
	string locatie_magazin;
		public:
			int get_id_magazin ();
			string get_locatie_magazin ();
			~Magazine (); //Destructor
			Magazine (int id_magazin, string locatie_magazin); //Constructor
			Magazine (const Magazine& magazin); //Copy-constructor
		};
#endif;
