#include "ListaProcesador.h"

ListaProcesador::ListaProcesador() { listaProcesador = new ListarGenerica<ProcesadorAbst>(); }

ListaProcesador::~ListaProcesador() {}

void ListaProcesador::insertarProcesador(ProcesadorAbst* a) {listaProcesador->insertarInicio(*a);}//Ingresa al principio de la lista un puntero a un objeto de tipo ProcesadorAbst o a una clase derivada de ProcesadorAbst.

string ListaProcesador::tostring() { return listaProcesador->toString(true); }