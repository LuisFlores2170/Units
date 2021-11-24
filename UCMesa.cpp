//---------------------------------------------------------------------------

#pragma hdrstop

#include "UCMesa.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

table::table(int n_number, bool n_state){
	account = 0;
	state = n_state;
    number = n_number;

    learn_file();
	create_folder();

}

//---------------------------------------------------------------------------

void table::learn_file(){
	if (!i_consume.is_open()) {
		i_consume.open(get_route_file(), ios::in);
	}

}

//---------------------------------------------------------------------------

void table::create_folder(){
	string f = get_date();
	char c_f[100];
	strcpy(c_f,f.c_str());

	mkdir(c_f);
	create_file();
}

//---------------------------------------------------------------------------

void table::create_file(){
	if ( i_consume.fail()) {
		o_consume.open(get_route_file(), ios::out);
		o_consume.close();
		i_consume.close();
	}

}

//---------------------------------------------------------------------------

string table::get_date(){
	string  day 	= 	UniToStr( IntToStr( time->tm_mday) ),
			mon 	= 	UniToStr( IntToStr( time->tm_mon + 1) ) ,
			year 	= 	UniToStr( IntToStr( 1900+ time->tm_year) );

	return day+"-"+mon+"-"+year;
}

//---------------------------------------------------------------------------

string table::get_route_file(){
	return get_date()+"/m-"+UniToStr(IntToStr(number))+".txt";
}

//---------------------------------------------------------------------------

void table::set_number(int n_number){
	number = n_number;
}

//---------------------------------------------------------------------------

int table::get_number(){
	return number;
}

//---------------------------------------------------------------------------

void table::set_state(bool n_state){
	state = n_state;
}

//---------------------------------------------------------------------------

bool table::get_state(){
	return state;
}

