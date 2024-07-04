/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#include "Lista.h"
#include "ProcesadorAbst.h"

#ifndef LISTAPROCESADOR_H
#define LISTAPROCESADOR_H

//Lista generica de objetos tipo procesador
class ListaProcesador {
private://Atributos necesarios para una lista de procesadores
	ListarGenerica<ProcesadorAbst>* listaProcesador;
public:
	ListaProcesador();//Constructor
	virtual ~ListaProcesador();//Destructor
	void insertarProcesador(ProcesadorAbst* a);//Se explica en el .cpp
	string tostring();
	
};
#endif