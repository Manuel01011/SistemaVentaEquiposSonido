/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef SUBJECT_H
#define SUBJECT_H

#include"Lista.h"
#include"Observer.h"
#include"Sistema.h"

class Observer;

//Clase encargada de observar el objeto sistema para poder notificar y actualizar al cliente en linea cuando tenga algun cambio
class Subject {
public:
	Subject() {}//Constructor
	virtual ~Subject() {}//Destructor

	//Metodos virtuales puros(Son desarrolados en la clase catalogo)
	virtual void notificar() = 0;

	virtual void agregarSub(Observer*) = 0;
	virtual void eliminarSub(int) = 0;
	virtual string mostrarSubs() = 0;

	virtual void ingresaSistema(Sistema*) = 0;
	virtual void eliminarSistema(int) = 0;
	virtual string mostrarCatalogo() = 0;
};
#endif 