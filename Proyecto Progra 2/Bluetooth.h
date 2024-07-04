/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include"FuenteAbst.h"

//Clase Bluetooth la cual hereda públicamente de la clase abstracta FuenteAbst
class Bluetooth : public FuenteAbst {
public:
	Bluetooth(double = 0, string = "", string = "", string = "");//Constructor
	virtual ~Bluetooth();//Destructor

	virtual string toString(bool);
	friend ostream& operator << (ostream&, Bluetooth&);//Sobrecarga del operador de inserción 
};
#endif