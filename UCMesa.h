//---------------------------------------------------------------------------

#ifndef UCMesaH
#define UCMesaH
#include <fstream>
#include <ctime>
#include <sstream>
#include "dir.h"

//---------------------------------------------------------------------------
#endif
using namespace std;

class table{
	private:
        bool state;
		int number, account;
		ofstream o_consume;
		ifstream i_consume;

        time_t n = std::time(0);
		tm *time = localtime(&n);



	public :

		table(int, bool);

		void learn_file();

		void create_folder();
		void create_file();

		// getter ans setter
		void set_number(int);
		int get_number();

		void set_state(bool);
		bool get_state();

		string get_date();
		string get_route_file();







		string UniToStr(UnicodeString Uni){

			UnicodeString str = Uni;
			AnsiString astr = str;
			stringstream stream;
			stream<<astr.c_str();
			return stream.str();

		}

};