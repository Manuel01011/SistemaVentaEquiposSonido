/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include "Empresa.h"
#include "Persona.h"
#include "Catalogo.h"
#include "Sistema.h"
#include "VentaDirecta.h"
#include "VentaLinea.h"

using namespace std;

//Clase encargada de manejar el almacenamiento y recuperacion de informacion.
class Archivos {
private://Atributos necesarios para los archivos
	fstream archivo;
public://Los metodos excepto el constructor y el destructor se encuentran explicados en el .cpp
	Archivos();//Constructor
	virtual ~Archivos();//Destructor

	//Abrir y cerrar los archivos
	virtual void abrirFlujoModoEscritura();
	virtual void abrirFlujoModoLectura();
	virtual void cerrarFlujo();

	//Conversiones
	static int obtenerInt(string);
	static double obtenerDouble(string);
	static bool obtenerBool(string);

	//Guardar y recuperar difentes tipos de variables
	virtual void guardarBool(bool, char);
	virtual void guardarInt(int, char);
	virtual void guardarDouble(double, char);
	virtual void guardarString(string, char);

	virtual bool recuperarBool(char);
	virtual int recuperarInt(char);
	virtual double recuperarDouble(char);
	virtual string recuperarString(char);

	//Guardado y recuperacion del Singleton
	virtual void guardarDatosSingleton();
	virtual void recuperarDatosSingleton();

	//Guardar y Recuperar objetos
	virtual void guardarClienteLinea(Observer*);
	virtual void guardarSistema(Sistema*);
	virtual void guardarVenta(Venta*);


	virtual ClienteFisico* recuperarClienteFisico(char);
	virtual Observer* recuperarClienteLinea(char);
	virtual Sistema* recuperarSistema(char);
	virtual FuenteAbst* recuperarFuente(char);
	virtual ProcesadorAbst* recuperarProcesador(char);
	virtual ParlanteAbst* recuperarParlante(char);
	virtual Venta* recuperarVenta();

	//Guardar y Recuperar Listas 
	virtual void guardarClientesEnLinea(ListarGenerica<Observer>*);
	virtual void guardarSistemas(ListarGenerica<Sistema>*);
	virtual void guardarVentas(ListarGenerica<Venta>*);

	virtual ListarGenerica<Observer>* recuperarClientesLinea();
	virtual ListarGenerica<Sistema>* recuperarSistemas();
	virtual ListarGenerica<Venta>* recuperarVentas();
};

#endif 

