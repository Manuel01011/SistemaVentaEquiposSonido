/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef CLIENTELINEA_H
#define CLIENTELINEA_H

#include "Observer.h"

//Clase ClienteEnLinea, hereda públicamente de la clase Observer
class ClienteEnLinea : public Observer {
protected://Atributos de un Cliente en Linea
	string nombre;
	string cedula;
	string correo;
	double pagoSub;
	string ciudad;
	string pais;
public:
	ClienteEnLinea(Subject* = nullptr, string = "", string = "", string = "", double = 0, string = "", string = "");//Constructor
	virtual ~ClienteEnLinea();//Destructor

	//Sets de los atributos de un Cliente en Linea
	virtual void setNombre(string);
	virtual void setCedula(string);
	virtual void setCorreo(string);
	virtual void setCiudad(string);
	virtual void setPais(string);
	virtual void setPagoSub(double);

	//Gets de los atributos de un Cliente en Linea
	virtual string getNombre();
	virtual string getCedula();
	virtual string getCorreo();
	virtual string getCiudad();
	virtual string getPais();
	virtual double getPagoSub();

	//Metodos Virtuales Puros(Se heredan a las clases Persona y Empresa)
	virtual void actualizar(string) = 0;
	virtual string toString(bool) = 0;

	friend ostream& operator << (ostream&, const ClienteEnLinea&);//Sobrecarga del operador de inserción 
};
#endif 