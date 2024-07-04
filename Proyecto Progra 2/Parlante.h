/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef PARLANTE_H
#define PARLANTE_H

#include"ParlanteAbst.h"

//Clase Parlante la cual hereda públicamente de la clase abstracta ParlanteAbst
class Parlante : public ParlanteAbst {
public:
	Parlante(double = 0, string = "", string = "", string = "");//Constructor
	virtual ~Parlante();//Destructor

	virtual string toString(bool);
	friend ostream& operator << (ostream&, Parlante&);//Sobrecarga del operador de inserción 
};
#endif