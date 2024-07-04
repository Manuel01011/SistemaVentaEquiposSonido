/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef UNIDADCD_H
#define UNIDADCD_H

#include"FuenteAbst.h"

//Clase UnidadCD la cual hereda públicamente de la clase abstracta FuenteAbst
class UnidadCD : public FuenteAbst {
public:
	UnidadCD(double = 0, string = "", string = "", string = "");//Constructor
	virtual ~UnidadCD();//Destructor

	virtual string toString(bool);
	friend ostream& operator << (ostream&, UnidadCD&);//Sobrecarga del operador de inserción
};
#endif