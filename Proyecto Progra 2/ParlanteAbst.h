/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef PARLANTEABST_H
#define PARLANTEABST_H

#include<iostream>
#include<sstream>

using namespace std;

//Clase ParlanteAbst,hereda publicamente a clases como Audifono o Parlante
class ParlanteAbst {
protected://Atributos propios de un parlante
	double precioBase;
	string caracteristicas;
	string modelo;
	string nombre;
public:
	ParlanteAbst(double = 0, string = "", string = "", string = "");//Constructor
	virtual ~ParlanteAbst();//Destructor

	//Gets de los atributos de una parlante
	virtual string getNombre();
	virtual string getCaracteristicas();
	virtual string getModelo();
	virtual double getPrecio();

	virtual string toString(bool)=0;//Metodo Virtual Puro
};
#endif 