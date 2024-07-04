/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef VENTA_H
#define VENTA_H

#include"VentasEmpresa.h"
#include"ListaTraslados.h"
#include"Lista.h"
#include"ClienteLinea.h"
#include"ClienteFisico.h"
#include"Sistema.h"

//Clase Venta,hereda publicamente a clases como VentaDirecta o VentaEnLinea
class Venta {
protected://Atributos necesarios para una venta
	Sistema* sis;
public:
	Venta(Sistema* = nullptr);//Constructor
	virtual ~Venta();//Destructor

	virtual Sistema* getSistema();//Get del atributo sistema*

	static string listaCodigos();//Lista de codigos de traslado

	//Metodos virtuales puros heredados por la clase venta a las clases VentaDirecta y VentaEnLinea
	virtual void realizarVenta() = 0;
	virtual string toString(bool) = 0;
	virtual string venta() = 0;

	friend ostream& operator << (ostream&, Venta&);//Sobrecarga del operador de inserción
};
#endif 