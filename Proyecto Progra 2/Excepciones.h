/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

#include<iostream>
#include<sstream>

using namespace std;

//Clase Excepciones, hereda públicamente de la clase exception
class Excepciones : public exception {
public://Excepciones varias para tratar diferentes situaciones
	const char* what();
	const char* errorCantInvalida();
	const char* errorNoHaySistemas();
	const char* errorNoHayClientes();
	const char* errorNoNayVentas();
	const char* errorPaisInvalido();
	const char* errorCodigoInvalido();
	const char* errorOpcionInvalida();
	const char* errorPosInvalida();
	const char* errorCedulaRegistrada();
	const char* errorCedulaNoRegistrada();
	const char* errorCorreoRegistrado();
	const char* errorModeloRegistrado();
	const char* errorCantidadInvalida();
};
#endif 