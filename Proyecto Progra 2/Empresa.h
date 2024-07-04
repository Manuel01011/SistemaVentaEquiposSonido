/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef EMPRESA_H
#define EMPRESA_H

#include"ClienteLinea.h"

using namespace std;

//Clase Empresa, hereda públicamente de la clase ClienteEnLinea
class Empresa : public ClienteEnLinea {
private://Atributos propios de una empresa
	bool frecuente;
public:
	Empresa(Subject* = nullptr, string = "", string = "", string = "", double = 0, string = "", string = "", bool = 0);//Constructor
	virtual ~Empresa();//Destructor

	void setFrecuente(bool);//Set del atributo propio de la clase empresa
	bool getFrecuente();//Get del atributo propio de la clase empresa

	//Implementacion de los metodos virtuales puros de la clase que hereda
	virtual void actualizar(string);
	virtual string toString(bool);

	friend ostream& operator << (ostream&, Empresa&);//Sobrecarga del operador de inserción
};
#endif 