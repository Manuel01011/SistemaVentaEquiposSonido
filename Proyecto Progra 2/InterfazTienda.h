/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef INTERFAZTIENDA_H
#define INTERFAZTIENDA_H

#include"Sistema.h"
#include"VentasEmpresa.h"
#include"Lista.h"
#include"Catalogo.h"
#include"Persona.h"
#include"Empresa.h"
#include"VentaDirecta.h"
#include"VentaLinea.h"
#include "Archivos.h"
#include "ListaFuente.h"
#include "ListaParlante.h"
#include "ListaProcesador.h"

//Clase encargada de centralizar todos los metodos necesarios para luego ser usados en la controladora
class InterfazTienda{
private://Atributos necesarios para la Interfaz
	Archivos* manejo;
	Catalogo* sistemas;
	ListarGenerica<Venta>* ventas;
public://Los metodos excepto el constructor y el destructor se encuentran explicados en el .cpp
	InterfazTienda();//Constructor
	virtual ~InterfazTienda();//Destructor

	void ingresarSistema(Sistema*);
	void ingresarVentas(Venta*);
	void ingresarSuscriptor(ClienteEnLinea*);

	void eliminarSistemaPos(int);
	void eliminarSuscriptorPos(int);

	void quitarSistemaPos(int);

	Sistema* retornarSistemaPorPos(int);
	ClienteEnLinea* retornarClientePorCorreo(string);
	ClienteEnLinea* retornarClientePorCedula(string);

	bool estaCedula(string, bool);
	bool estaCorreo(string);
	bool estaCodigo(string);

	int getCanTotalDeVentas();
	int getCanTotalDeSistema();
	int getCanTotalDeClientes();
	int getCanTotalDeClientesEmpresa();
	int getCanTotalDeClientesFisicos();

	string codigoSistemaMasVendido();
	string ventasConGanancia();

	string listaClientes();
	string listaClientesFisicos();
	string listaClientesEmpresa();
	string mostrarStock();
	string mostrarSuscriptores();
	string mostrarHistorialDeVentas();
	string toString();

	virtual void recuperarDatosAplicacion();
	virtual void guardarDatosAplicacion();
};
#endif 