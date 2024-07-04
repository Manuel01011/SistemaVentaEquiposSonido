/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef VENTALINEA_H
#define VENTALINEA_H

#include"Venta.h"

//Clase VentaEnLinea la cual hereda públicamente de la clase Venta
class VentaEnLinea : public Venta {
private://Atributos propios de un venta en linea
	Observer* comprador;
	string codigoTraslado;
public:
	VentaEnLinea(string = "", Sistema* = NULL, Observer* = nullptr);//Constructor
	virtual ~VentaEnLinea();//Destructor

	virtual void setCodigoTraslado(string);//Set del atributo propio de una venta en linea
	virtual string getCodigoTraslado();//Get del atributo propio de una venta en linea

	virtual void realizarVenta();//Se explica en el .cpp
	virtual string toString(bool);

	virtual string venta();//Metodo encargado de devolver la factura con el nombre del cliente y el sistema comprado

	friend ostream& operator << (ostream&, VentaEnLinea&);//Sobrecarga del operador de inserción 
};
#endif