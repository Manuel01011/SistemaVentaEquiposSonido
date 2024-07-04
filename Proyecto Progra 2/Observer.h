/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef OBSERVER_H
#define OBSERVER_H

#include<iostream>
#include<sstream>

using namespace std;

#include "Subject.h"

class Subject;

//Clase encargada de notificar y actualizar a los objetos pertenecientes a las clases empresa y persona cuando los objetos observados por el subject cambian
class Observer {
protected:
	Subject* model;
public:
	Observer(Subject* = nullptr);//Constructor
	virtual ~Observer();//Destructor

	virtual Subject* getSubject();//Get del atributo de la clase

	//Metodos Virtuales Puros desarrollados en las clases Empresa y Persona
	virtual void actualizar(string) = 0;
	virtual string toString(bool) = 0;

	friend ostream& operator << (ostream&, Observer&);//Sobrecarga del operador de inserción 
};
#endif