/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef LISTATRASLADOS_H
#define LISTATRASLADOS_H

#include<iostream>
#include<sstream>

using namespace std;

class ListaTraslados {
public:
	static string pais(string);
	static string ciudad(string);
	static double costo(string);
};
#endif