/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef TORNAMESA_H
#define TORNAMESA_H

#include"FuenteAbst.h"

//Clase TornaMesa la cual hereda públicamente de la clase abstracta FuenteAbst
class Tornamesa : public FuenteAbst {
public:
	Tornamesa(double = 0, string = "", string = "", string = "");//Constructor
	virtual ~Tornamesa();//Destructor

	virtual string toString(bool);
	friend ostream& operator << (ostream&, Tornamesa&);//Sobrecarga del operador de inserción
};
#endif