/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef VENTASEMPRESA_H
#define VENTASEMPRESA_H

#include<iostream>
#include<sstream>

using namespace std;

//La clase VentasEmpresa  se encargar de registrar y gestionar las ventas de la tienda.
class VentasEmpresa {
private://Atributos de la clase
	VentasEmpresa();//Constructor privado para evitar que la clase sea instanciada directamente.
	static VentasEmpresa* instancia;
	int cantVentas;
	double totalVentas;
public:
	virtual ~VentasEmpresa();//Destructor

	static VentasEmpresa& instanciar(); //Metodo estatico que devuelve una referencia a la única instancia de la clase.Se utiliza el patron Singleton para evitar mas de un instancia de la clase
	static void destruir();// Metodo estatico que destruye la instancia única de la clase.

	//Sets de los atributos de las ventas de una empresa
	void setCantVentas(int);
	void setTotalVentas(double);

	//Gets de los atributos de las ventas de una empresa
	int getCantVentas();
	double getTotalVentas();

	string cantVentasGanancia();//To String que muestra la cantidad de ventas realizadas y el monto ganado por la tienda

	string guardarDatos();//Metodo utilizado para guardar los datos de las ventas(Cantidad de ventas y total de ventas) de una forma comoda para su recuperacion.
	string toString();
};
#endif