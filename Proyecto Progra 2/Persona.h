/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef PERSONA_H
#define PERSONA_H

#include"ClienteLinea.h"

//Clase Persona, hereda públicamente de la clase ClienteEnLinea
class Persona : public ClienteEnLinea {
private://Atributos propios de una persona
	string nacionalidad;
public:
	Persona(Subject* = nullptr, string = "", string = "", string = "", double = 0, string = "", string = "", string = "");//Constructor
	virtual ~Persona();//Destructor

	void setNacionalidad(string);//Set del atributo propio de la clase persona
	string getNacionalidad();//Get del atributo propio de la clase persona

	//Implementacion de los metodos virtuales puros de la clase que hereda
	virtual void actualizar(string);
	virtual string toString(bool);

	friend ostream& operator << (ostream&, Persona&);//Sobrecarga del operador de inserción
};
#endif 