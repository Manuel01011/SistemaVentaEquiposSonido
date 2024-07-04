#include "ListaFuente.h"

ListaFuente::ListaFuente() {listaFuente = new ListarGenerica<FuenteAbst>(); }

ListaFuente::~ListaFuente() {}

void ListaFuente::insertarFuente(FuenteAbst* a) {listaFuente->insertarInicio(*a);}//Ingresa al principio de la lista un puntero a un objeto de tipo FuenteAbst o a una clase derivada de FuenteAbst.

string ListaFuente::tostring() { return listaFuente->toString(true); }