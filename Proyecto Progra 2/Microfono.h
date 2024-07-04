/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef MICROFONO_H
#define MICROFONO_H

#include"FuenteAbst.h"

//Clase Microfono la cual hereda públicamente de la clase abstracta FuenteAbst
class Microfono : public FuenteAbst {
public:
	Microfono(double = 0, string = "", string = "", string = "");//Constructor
	virtual ~Microfono();//Destructor

	virtual string toString(bool);
	friend ostream& operator << (ostream&, Microfono&);//Sobrecarga del operador de inserción 
};
#endif