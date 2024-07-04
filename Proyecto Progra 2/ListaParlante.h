/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#include"ParlanteAbst.h"
#include "Lista.h"

#ifndef LISTAPARLANTE_H
#define LISTAPARLANTE_H

//Lista generica de objetos tipo parlante
class ListaParlante {
private://Atributos necesarios para una lista de parlantes
	ListarGenerica<ParlanteAbst>* listaParlante;
public:
	ListaParlante();//Constructor
	virtual ~ListaParlante();//Destructor
	void insertarParlante(ParlanteAbst* a);//Se explica en el .cpp
	string tostring();
};
#endif