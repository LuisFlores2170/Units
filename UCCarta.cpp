//---------------------------------------------------------------------------

#pragma hdrstop

#include "UCCarta.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

letter::letter(){

	learn_food();
	learn_drink();
	create_folder();
}

void letter::learn_StringGrid(TStringGrid *&SGrid){
    Grid = SGrid;
}

//---------------------------------------------------------------------------

void letter::learn_food(){
	if (!i_food_file.is_open()) {
		i_food_file.open("menu_folder/food_menu.txt", ios::in);
	}

}

//---------------------------------------------------------------------------

void letter::learn_drink(){
	if (!i_drink_file.is_open()) {
		i_drink_file.open("menu_folder/drink_menu.txt", ios::in);
	}

}

//---------------------------------------------------------------------------

void letter::create_folder(){

	mkdir("menu_folder");
	create_food_file();
	create_drink_file();

}

//---------------------------------------------------------------------------

void letter::create_food_file(){

	if ( i_food_file.fail()) {
		o_food_file.open("menu_folder/food_menu.txt", ios::out);
		o_food_file.close();
		i_food_file.close();
	}

}

//---------------------------------------------------------------------------

void letter::create_drink_file(){

	if (i_drink_file.fail()) {
		o_drink_file.open("menu_folder/drink_menu.txt", ios::out);
		o_drink_file.close();
		i_drink_file.close();
	}

}

//---------------------------------------------------------------------------

void letter::save_food(string new_n, int price, string description){

	learn_food();
	if (!i_food_file.fail()) {
		o_food_file.open("menu_folder/food_menu.txt", ios::app);
		o_food_file<<validate_str(new_n)<<endl;
		o_food_file<<price<<endl;
		o_food_file<<validate_str(description)<<endl;
		o_food_file<<endl;
		o_food_file.close();
		i_food_file.close();
		ShowMessage("Guardado exitosamente");

	}
	else
		throw new Exception("Error: el archivo no se abrio");

}

//---------------------------------------------------------------------------

void letter::save_drink(string new_n, int price){
	learn_drink();
	if (!i_drink_file.fail()) {
		o_drink_file.open("menu_folder/drink_menu.txt", ios::app);
		o_drink_file<<validate_str(new_n)<<endl;
		o_drink_file<<price<<endl;
		o_drink_file<<endl;
		o_drink_file.close();
		i_drink_file.close();
		ShowMessage("Guardado exitosamente");
	}
	else
		throw new Exception("Error: el archivo no se abrio");

}

//---------------------------------------------------------------------------

void letter::modify_food(string m_note, string n_note, int n_price){
	ofstream aux_food_file;
	aux_food_file.open("menu_folder/aux_food_menu.txt",ios::out);

	string food, price, description;

	learn_food();
	i_food_file>>food;

	while (!i_food_file.eof()){

		i_food_file>>price;
		i_food_file>>description;

		if (food == m_note) {

			  aux_food_file<<n_note<<endl;
			  aux_food_file<<n_price<<endl;
			  aux_food_file<<description<<endl;
              ShowMessage("Modificado exitosamente");
		}

		else {

			  aux_food_file<<food<<endl;
			  aux_food_file<<price<<endl;
			  aux_food_file<<description<<endl;

		}
		aux_food_file<<endl;
		i_food_file>>food;
	}

	aux_food_file.close();
	i_food_file.close();
	remove("menu_folder/food_menu.txt");
	rename("menu_folder/aux_food_menu.txt", "menu_folder/food_menu.txt");


}

//---------------------------------------------------------------------------

void letter::table_food_note(){

	Grid->RowCount = m_count_ptr() +1;
	Grid->ColCount = 3;
	Grid->ColWidths[0] = 120;
	Grid->ColWidths[1] = 70;
	Grid->ColWidths[2] = 300;
	Grid->Width = Grid->ColWidths[0] +
				  Grid->ColWidths[1] +
				  Grid->ColWidths[2] +10;



	Grid->Cells[0][0] =  "---COMIDA---";
	Grid->Cells[1][0] =  "--PRECIO--";
	Grid->Cells[2][0] =  "--DESCRIPCION--";



	int count = 1;
	nodo *n_aux = ptrNote;
	while (n_aux != NULL){

		Grid->Cells[0][count] = n_aux->note.c_str();
		Grid->Cells[1][count] = IntToStr(n_aux->price);
		Grid->Cells[2][count] = n_aux->description.c_str();

		count++;
		n_aux = n_aux->sig;

	}

}

//---------------------------------------------------------------------------

void letter::table_drink_note(){

	Grid->RowCount = m_count_ptr()+1;
	Grid->ColCount = 2;
	Grid->ColWidths[0] = 120;

	Grid->Cells[0][0] =  "---BEBIDA---";
	Grid->Cells[1][0] =  "--PRECIO--";
	Grid->Width = Grid->ColWidths[0] +
				  Grid->ColWidths[1] + 5;


	int count = 1;
	nodo *n_aux = ptrNote;
	while (n_aux != NULL){

		Grid->Cells[0][count] = n_aux->note.c_str();
		Grid->Cells[1][count] = IntToStr(n_aux->price);

		count++;
		n_aux = n_aux->sig;

	}

}

//---------------------------------------------------------------------------

string letter::validate_str(string str){
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			str[i] = '_';
		}
	}
	return str;
}

//---------------------------------------------------------------------------

int letter::m_count_ptr(){
	int count = 0;
	nodo *c = ptrNote;
	while (c!= NULL){
		c = c->sig;
		count++;
	}
	return count;
}

//---------------------------------------------------------------------------

void letter::load_food_char(string str){
	  learn_food();
	  ptrNote = NULL;

	  string nt, price, desc;
	  i_food_file>>nt>>price>>desc;

	  while (!i_food_file.eof()){
			size_t needle = nt.find(str);
			if (needle != string::npos) {
				nodo *x = new nodo;

				x->note = nt;
				x->price = StrToInt(price.c_str());
				x->description = desc;

				x->sig = ptrNote;
				ptrNote = x;
			}

			i_food_file>>nt>>price>>desc;
	  }


	  i_food_file.close();
}

//---------------------------------------------------------------------------

void letter::load_food(){
	  learn_food();
      ptrNote = NULL;

	  string nt, price, desc;
	  i_food_file>>nt>>price>>desc;

	  while (!i_food_file.eof()){
				nodo *x = new nodo;

				x->note = nt;
				x->price = StrToInt(price.c_str());
				x->description = desc;

				x->sig = ptrNote;
				ptrNote = x;

                i_food_file>>nt>>price>>desc;

	  }

	  i_food_file.close();
}

//---------------------------------------------------------------------------

void letter::load_drink(){
	  learn_drink();
	  ptrNote = NULL;

	  string nt, price;
	  i_drink_file>>nt>>price;

	  while (!i_drink_file.eof()){
				nodo *x = new nodo;

				x->note = nt;
				x->price = StrToInt(price.c_str());
				x->description = "";

				x->sig = ptrNote;
				ptrNote = x;

				i_drink_file>>nt>>price;

	  }

	  i_drink_file.close();
}



