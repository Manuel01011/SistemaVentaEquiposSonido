/* --------------------------------------------------------------------
* EIF204 Programaci�n 2
*
* Proyecto de programaci�n #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef VENTADIRECTA_H
#define VENTADIRECTA_H

#include"Venta.h"

//Clase VentaDirecta la cual hereda p�blicamente de la clase Venta
class VentaDirecta : public Venta {
private://Atributos propios de un venta directa
	ClienteFisico* comprador;
public:
	VentaDirecta(Sistema* = nullptr, ClienteFisico* = nullptr);//Constructor
	virtual ~VentaDirecta();//Destructor

	virtual void realizarVenta();//Se explica en el .cpp
	virtual string toString(bool);

	virtual string venta();//Metodo encargado de devolver la factura con el nombre del cliente y el sistema comprado

	friend ostream& operator << (ostream&, VentaDirecta&);//Sobrecarga del operador de inserci�n 
};
#endif