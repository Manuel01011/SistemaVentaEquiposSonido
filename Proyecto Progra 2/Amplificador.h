/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef AMPLIFICADOR_H
#define AMPLIFICADOR_H

#include"ProcesadorAbst.h"

//Clase Amplificador la cual hereda públicamente de la clase abstracta ProcesadorAbst
class Amplificador : public ProcesadorAbst {
public:
	Amplificador(double = 0, string = "", string = "", string = "");//Constructor
	virtual ~Amplificador();//Destructor

	virtual string toString(bool);
	friend ostream& operator << (ostream&, Amplificador&);//Sobrecarga del operador de inserción 
};

#endif 

