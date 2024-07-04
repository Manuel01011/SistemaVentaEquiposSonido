/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef FUENTEABST_H
#define FUENTEABST_H

#include<iostream>
#include<sstream>

using namespace std;

//Clase FuenteAbst,hereda publicamente a clases como UnidadCD,Tornamesa,Radio,Bluetooth o Microfono
class FuenteAbst {
protected://Atributos propios de una fuente
	double precioBase;
	string caracteristicas;
	string modelo;
	string nombre;
public:
	FuenteAbst(double = 0, string = "", string = "", string = "");//Constructor
	virtual ~FuenteAbst();//Destructor

	//Gets de los atributos de una fuente
	virtual string getNombre();
	virtual string getCaracteristicas();
	virtual string getModelo();
	virtual double getPrecio();


	virtual string toString(bool)=0;//Metodo Virtual Puro
};
#endif 