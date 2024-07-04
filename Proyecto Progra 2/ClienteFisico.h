/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef CLIENTEFISICO_H
#define CLIENTEFISICO_H

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

//Clase ClienteFisico, se encarga de la informacion de los clientes que vienen de manera presencial a la tienda
class ClienteFisico{
private://Atributos de un Cliente Fisico
	string nombre;
	string cedula;
public:
	ClienteFisico(string = "", string = "");//Constructor
	virtual ~ClienteFisico();//Destructor

	virtual string toString(bool);

	friend ostream& operator << (ostream&, const ClienteFisico&);//Sobrecarga del operador de inserción 
};
#endif 