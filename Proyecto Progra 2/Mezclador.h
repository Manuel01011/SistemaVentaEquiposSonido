/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef MEZCLADOR_H
#define MEZCLADOR_H

#include"ProcesadorAbst.h"

//Clase Mezclador la cual hereda públicamente de la clase abstracta ProcesadorAbst
class Mezclador : public ProcesadorAbst {
public:
	Mezclador(double = 0, string = "", string = "", string = "");//Constructor
	virtual ~Mezclador();//Destructor

	virtual string toString(bool);
	friend ostream& operator << (ostream&, Mezclador&);//Sobrecarga del operador de inserción 
};
#endif