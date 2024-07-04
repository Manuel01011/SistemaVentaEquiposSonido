/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef AUDIFONO_H
#define AUDIFONO_H

#include "ParlanteAbst.h"

//Clase Audifono la cual hereda públicamente de la clase abstracta ParlanteAbst
class Audifono : public ParlanteAbst {
public:
	Audifono(double = 0, string = "", string = "", string = "");//Constructor
	virtual ~Audifono();//Destructor

	virtual string toString(bool);
	friend ostream& operator << (ostream&, Audifono&);//Sobrecarga del operador de inserción 
};
#endif