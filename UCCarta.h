//---------------------------------------------------------------------------

#ifndef UCCartaH
#define UCCartaH

#include "dir.h"

#include <vcl.h>
#include <fstream>
#include <Vcl.Grids.hpp>
#include <new>



using namespace std;
//---------------------------------------------------------------------------
#endif

struct nodo{
	string note;
	int price;
	string description;
	nodo *sig;
};

class letter{

	private:

		ifstream	i_food_file,
					i_drink_file;


		ofstream    o_food_file,
					o_drink_file;


		TStringGrid *Grid;

		nodo *ptrNote;


	public:

		letter();

		void learn_food();
		void learn_drink();
		void learn_StringGrid(TStringGrid*&);



		// CREATE FOLDER AND FILES
		void create_folder();
		void create_food_file();
		void create_drink_file();

		// EDIT

		void save_food(string, int, string);
        void save_drink(string, int);

		// MOODS
		void modify_food(string, string, int);
        string validate_str(string);

		void table_food_note();
        void table_drink_note();



		//  Methods
		int count_foods();
		int count_drinks();
		int m_count_ptr();

		void load_food_char(string);

		void load_food();
        void load_drink();









};