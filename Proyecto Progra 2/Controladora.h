/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef CONTROLADORA_H
#define CONTROLADORA_H

#include"Vista.h"

//Clase encargada de gestionar y coordinar el flujo de datos y la interacción entre diferentes partes del programa. 
class Controladora {
private://Atributos utilizados por la Controladora
	InterfazTienda* tienda;
	Venta* venta;
	Sistema* sis;
	Subject* subj;
	Catalogo* cat;
	ClienteFisico* clFisico;
	ClienteEnLinea* clEnLinea;

	int auxCant;
	int auxInt;
	string tipo;
	string id;
	string cod;
	string caract;
	string nombre;
	string cedula;
	string correo;
	string pais;
	string ciudad;
	string nacionalidad;
	double pagoSub;
	double preciobase1, preciobase2, preciobase3;
	int cant;
public:
	Controladora();//Constructor
	virtual ~Controladora();//Destructor

	//Menu Principal
	void MenuPrincipal();

	//Opciones Menu Principal
	void VentaDirectaOpc();
	void VentaEnLineaOpc();
	void Mantenimiento();

	//Opcion de Venta Directa
	void InfoDeClientes();

	//Opciones de Venta en Linea
	void OpcVentaPerOEmp();
	void Suscribirse();
	void SistemaPreconfiguradoOpc();

	//Opciones Suscribirse	
	void ClientePersonaOpc();
	void ClienteEmpresaOpc();


	//Opciones Menu de Mantenimiento
	void CreaciondeSistemaOpc();
	void TiposdeSistemas();
	void EliminarUnSistema();
	void VerCatalogo();

	//Opciones Menu de Suscriptores
	void MenuDeSuscriptores();
	void EliminarSuscri();
	void ListaClientesPersona();
	void ListaClientesEmpresa();

	//Opciones Menu de Ventas
	void MenuDeVentas();
	void HistoralDeVentas();
	void VentasConGanaciaOpc();
	void SistemaMasVendido();

	//Archivos
	void guardarDatos();
	void recuperarDatos();
};

#endif