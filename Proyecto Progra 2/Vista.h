/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef VISTA_H
#define VISTA_H

#include "InterfazTienda.h"
#include "Excepciones.h"

//Clase encargada del aspecto visual del programa
class Vista{
public:
	static int menu();
	static int menuVentaDirecta();
	static int menuInicioVentaEnLinea();
	static int menuCompraVentaEnLinea();
	static int menuPartesDeSistema();
	static int menuTiposDeFuentes();
	static int menuTiposDeProcesadores();
	static int menuTiposDeParlante();

	static int menuMantenimiento();
	static int menuSistema();
	static int menuAsociados();
	static int menuVentas();

	static ClienteFisico* datosClienteFisico();
	static int canSistemaAComprar();

	static string ingresarCedulaPersona();
	static string ingresarCedulaJuridica();
	static string confirmarCodigoTraslado();
	static string ingresarCodSistema();

	static int ingresarCantidadDeSistemas();
	static int seleccioneElTipoDeCliente();
	static int EliminarPorPosSistema();
	static int EliminarPorPosSuscri();

	static void tituloIniciarSeccion();
	static void tituloSistemaAmedida();
	static void tituloEliminarSistema();
	static void tituloEliminarSuscri();
	static void tituloIngresoSistema();
	static void ingresaProcesador();
	static void ingresaFuente();
	static void ingresaParlante();

	static string ingresarNombrePersona();
	static string ingresarIDPersona();
	static string ingresarCorreoPersona();
	static string ingresarNacionalidad();
	static string ingresarCodigoTrasladoPersona();

	static string ingresarNombreEmpresa();
	static string ingresarIDJuridico();
	static string ingresarCorreoEmpresa();
	static string ingresarCodigoTrasladoEmpresa();

	static int mensajeIngresarPosSistema();
	static int mensajeIngresarPosicion();
	static int mensajeRealizacionCompraPersona(string, string);
	static void mensajeRealizacionCompraEmpresa(string, string);
	static void mensajeAtencionInformacion();
	static void mensajeGraciasPorComprar();
	static void mensajeCancelacion();
	static int mensajeConfirmacion();
	static void mensajeDefault();
	static void mensajeSistemaMasVendido();
	static void mensajeListaSistemas();
	static void mensajeListaVentas();
	static void mensajeSuscripcion();
	static void mensajeVentaEnLinea();
	static void mensajeSuscripcionExitosa(ClienteEnLinea*);
};
#endif



