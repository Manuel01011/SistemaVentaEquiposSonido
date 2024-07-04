#include "ListaParlante.h"
ListaParlante::ListaParlante() { listaParlante = new ListarGenerica<ParlanteAbst>(); }

ListaParlante::~ListaParlante() {}

void ListaParlante::insertarParlante(ParlanteAbst* a) { listaParlante->insertarInicio(*a);}//Ingresa al principio de la lista un puntero a un objeto de tipo ParlanteAbst o a una clase derivada de ParlanteAbst.

string ListaParlante::tostring() { return listaParlante->toString(true); }