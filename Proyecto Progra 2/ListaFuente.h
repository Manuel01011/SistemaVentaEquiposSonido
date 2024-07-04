/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#include"Lista.h"
#include"FuenteAbst.h"

#ifndef LISTAFUENTE_H
#define LISTAFUENTE_H

//Lista generica de objetos tipo fuente
class ListaFuente {
private://Atributos necesarios para una lista de fuentes
	ListarGenerica<FuenteAbst>* listaFuente;
public:
	ListaFuente();//Constructor
	virtual ~ListaFuente();//Destructor
	void insertarFuente(FuenteAbst* a);//Se explica en el .cpp
	string tostring();
};
#endif