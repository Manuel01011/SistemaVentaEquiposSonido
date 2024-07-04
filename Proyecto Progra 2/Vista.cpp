#include "Vista.h"

int Vista::menu(){
	int op = 0;
	cout << "--------->Steren<---------" << endl << endl;
	cout << "----> Menu Principal <----" << endl;
	cout << "[1] Venta Directa" << endl;
	cout << "[2] Venta en linea" << endl;
	cout << "[3] Mantenimiento" << endl;
	cout << "[4] Salir" << endl << endl;
	cout << "->";
	cin >> op;
	system("cls");
	return op;
}

int Vista::menuVentaDirecta(){
	int op1 = 0;
	cout << "-------->Steren<---------" << endl << endl;
	cout << "----> Venta Directa <----" << endl;
	cout << "[1] Realizar venta" << endl;
	cout << "[2] Volver" << endl << endl;
	cout << "->";
	cin >> op1;
	system("cls");
	return op1;
}

int Vista::menuInicioVentaEnLinea(){
	int op2 = 0;
	cout << "---------->Steren<----------" << endl << endl;
	cout << "-----> Venta en Linea <-----" << endl << endl;
	cout << "----> Ya esta suscrito <----" << endl << endl;

	cout << "[1] Cliente Persona " << endl;
	cout << "[2] Cliente Empresa " << endl << endl;

	cout << "----> No esta suscrito <----" << endl << endl;

	cout << "[3] Suscribirse" << endl;
	cout << "[4] Volver" << endl << endl;
	cout << "->";
	cin >> op2;
	system("cls");

	return op2;
}

int Vista::menuCompraVentaEnLinea(){
	int op = 0;
	cout << "--------->Steren<---------" << endl << endl;
	cout << "----> Venta en Linea <----" << endl << endl;
	cout << "[1] Comprar Sistema Preconfigurado del catalogo" << endl;
	cout << "[2] Volver" << endl << endl;
	cout << "->";
	cin >> op;
	system("cls");
	return op;
}

int Vista::menuPartesDeSistema(){
	int op = 0;
	cout << "----> Partes de Sistema <----" << endl << endl;
	cout << "[1] Fuente de Audio" << endl;
	cout << "[2] Procesador de Senal" << endl;
	cout << "[3] Parlante" << endl << endl;
	cout << "->";
	cin >> op;
	cout << endl;
	return op;
}

int Vista::menuTiposDeFuentes(){
	int op = 0;
	cout << "----> Tipos de Fuentes <----" << endl << endl;
	cout << "[1] Unidad CD" << endl;
	cout << "[2] Tornamesa" << endl;
	cout << "[3] Radio" << endl << endl;
	cout << "[4] Unidad Bluetooth" << endl;
	cout << "[5] Microfono" << endl << endl;
	cout << "[6] Volver" << endl << endl;
	cout << "->";
	cin >> op;
	cout << endl;
	return op;
}

int Vista::menuTiposDeProcesadores(){
	int op = 0;
	cout << "----> Tipos de Procesadores <----" << endl << endl;
	cout << "[1] Amplificador" << endl;
	cout << "[2] Mezclador" << endl;
	cout << "[3] Volver" << endl << endl;
	cout << "->";
	cin >> op;
	cout << endl;
	return op;
}

int Vista::menuTiposDeParlante(){
	int op = 0;
	cout << "----> Tipos de Parlante <----" << endl << endl;
	cout << "[1] Parlante" << endl;
	cout << "[2] Audifono" << endl;
	cout << "[3] Volver" << endl << endl;
	cout << "->";
	cin >> op;
	cout << endl;
	return op;
}

int Vista::menuMantenimiento(){
	int op4 = 0;
	cout << "--------->Steren<---------" << endl << endl;
	cout << "----> Mantenimiento <----" << endl;
	cout << "[1] Sistema" << endl;
	cout << "[2] Suscriptores" << endl;
	cout << "[3] Ventas" << endl;
	cout << "[4] Volver" << endl << endl;
	cout << "->";
	cin >> op4;
	system("cls");
	return op4;
}

int Vista::menuSistema(){
	int op;
	cout << "--------->Steren<---------" << endl << endl;
	cout << "--------->Sistema<-------" << endl;
	cout << "[1] Ingresar Sistema" << endl;
	cout << "[2] Eliminar Sistema" << endl;
	cout << "[3] Ver Catalogo" << endl;
	cout << "[4] Volver" << endl << endl;
	cout << "->";
	cin >> op;
	system("cls");
	return op;
}

int Vista::menuAsociados(){
	int op = 0;
	cout << "--------->Steren<---------" << endl << endl;
	cout << "------> Suscriptores <----" << endl;
	cout << "[1] Eliminar Suscriptor" << endl;
	cout << "[2] Ver lista de clientes Persona" << endl;
	cout << "[3] Ver lista de clientes Empresa" << endl;
	cout << "[4] Volver" << endl << endl;
	cout << "->";
	cin >> op;
	system("cls");
	return op;
}

int Vista::menuVentas(){
	int op = 0;
	cout << "--------->Steren<---------" << endl << endl;
	cout << "--------> Ventas <--------" << endl;
	cout << "[1] Ver historial de ventas" << endl;
	cout << "[2] Ventas totales" << endl;
	cout << "[3] Codigo del Sistema mas vendido" << endl;
	cout << "[4] Volver" << endl << endl;
	cout << "->";
	cin >> op;
	system("cls");
	return op;
}

ClienteFisico* Vista::datosClienteFisico(){
	string id, nom;
	cout << "----> Datos del comprador <----" << endl << endl;
	cout << "Ingrese la cedula del cliente: ";
	cin >> id;
	cin.ignore();
	cout << "Ingrese el nombre del cliente: ";
	getline(cin, nom);
	cout << endl;
	return new ClienteFisico(nom, id);
}

int Vista::canSistemaAComprar(){
	int cant = 0;
	cout << "----------> Sistema Comprados <-----------" << endl << endl;
	cout << "Ingrese la cantidad de Sistema comprados: ";
	cin >> cant;
	cout << endl;
	return cant;
}

string Vista::ingresarNombrePersona(){
	string nombre = "";
	cout << "-----> Ingrese sus datos <-----" << endl << endl;
	cin.ignore();
	cout << "Ingrese su nombre: ";
	getline(cin, nombre);
	return nombre;
}

string Vista::ingresarIDPersona(){
	string id = "";
	cout << "Ingrese su cedula: ";
	cin >> id;
	return id;
}

string Vista::ingresarCedulaPersona(){
	string id = "";
	cout << "Ingrese la cedula: ";
	cin >> id;
	cout << endl;
	return id;
}

string Vista::ingresarCorreoPersona(){
	string correo = "";
	cout << "Ingrese su E-Mail: ";
	cin >> correo;
	return correo;
}

string Vista::ingresarNacionalidad(){
	string nacionalidad = "";
	cin.ignore();
	cout << "Ingrese su nacionalidad: ";
	getline(cin, nacionalidad);
	cout << endl;
	return nacionalidad;
}

string Vista::ingresarCedulaJuridica(){
	string id = "";
	cout << "Ingrese la cedula judirica: ";
	cin >> id;
	cout << endl;
	return id;
}

string Vista::confirmarCodigoTraslado(){
	string cod = "";
	cout << Venta::listaCodigos();
	cout << "Confirme el codigo de Traslado: ";
	cin >> cod;
	cout << endl;
	return cod;
}

string Vista::ingresarCodigoTrasladoEmpresa(){
	string cod = "";
	cout << Venta::listaCodigos();
	cout << "Ingrese el codigo que mas se adapte a la localidad de la empresa: ";
	cin >> cod;
	cout << endl;
	return cod;
}

string Vista::ingresarCodSistema(){
	string cod = "";
	cout << "Ingrese el codigo del Sistema: ";
	cin >> cod;
	cout << endl;
	return cod;
}

int Vista::ingresarCantidadDeSistemas(){
	int aux = 0;
	cout << "Ingrese la cantidad de Sistema: ";
	cin >> aux;
	cout << endl;
	return aux;
}

int Vista::seleccioneElTipoDeCliente(){
	int op = 0;
	cout << "-----> Seleccione el tipo de cliente <-----" << endl << endl;
	cout << "[1] Persona " << endl;
	cout << "[2] Empresa " << endl << endl;
	cout << "->";
	cin >> op;
	system("cls");
	return op;
}

int Vista::EliminarPorPosSistema(){
	int auxInt;
	cout << "Ingrese la posicion del Sistema a eliminar: ";
	cin >> auxInt;
	return auxInt;
}

int Vista::EliminarPorPosSuscri(){
	int auxInt = 0;
	cout << "Ingresar la posicion del cliente a eliminar: ";
	cin >> auxInt;
	cout << endl;
	return auxInt;
}

void Vista::tituloIniciarSeccion(){
	cout << "--------->Steren<---------" << endl << endl;
	cout << "----> Iniciar Seccion <----" << endl << endl;
}

void Vista::tituloSistemaAmedida(){cout << "----> Sistema a Medida <----" << endl << endl;}

void Vista::tituloEliminarSistema(){cout << "----> Eliminando Sistema <----" << endl << endl;}

void Vista::tituloEliminarSuscri(){cout << "----> Eliminando Suscriptor <----" << endl << endl;}

void Vista::tituloIngresoSistema(){cout << "----> Ingresando Sistema <----" << endl << endl;}

void Vista::ingresaProcesador(){
	cout << "Digite el tipo de procesador que desea " << endl;
	cout << "[1] Procesador tipo Amplificador " << endl;
	cout << "[2] Procesador tipo Mezclador " << endl;
}

void Vista::ingresaFuente(){
	cout << "Digite el tipo de fuente que desea " << endl;
	cout << "[3] Fuente tipo Unidad CD " << endl;
	cout << "[4] Fuente tipo Tornamesa" << endl;
	cout << "[5] Fuente tipo Radio" << endl;
	cout << "[6] Fuente tipo Bluetooth" << endl;
	cout << "[7] Fuente tipo Microfono" << endl;
}

void Vista::ingresaParlante(){
	cout << "Digite el tipo de Parlante que desea " << endl;
	cout << "[8] Parlante tipo Parlante" << endl;
	cout << "[9] Parlante tipo Audifono" << endl;
}

string Vista::ingresarCodigoTrasladoPersona(){
	string cod = "";
	cout << Venta::listaCodigos();
	cout << "Ingrese el codigo que mas se adapte a su localidad: ";
	cin >> cod;
	cout << endl;
	return cod;
}

string Vista::ingresarNombreEmpresa(){
	string nombre = "";
	cout << "-----> Ingrese los datos de la empresa <-----" << endl << endl;
	cin.ignore();
	cout << "Ingrese el nombre: ";
	getline(cin, nombre);
	return nombre;
}

string Vista::ingresarIDJuridico(){
	string cedula = "";
	cout << "Ingrese su cedula juridica: ";
	cin >> cedula;
	return cedula;
}

string Vista::ingresarCorreoEmpresa(){
	string correo = "";
	cout << "Ingrese su E-Mail: ";
	cin >> correo;
	cout << endl;
	return correo;
}

int Vista::mensajeIngresarPosSistema(){
	int entero = 0;
	cout << "Ingrese la posicion del Sistema deseado: ";
	cin >> entero;
	cout << endl;
	return entero;
}

int Vista::mensajeIngresarPosicion(){
	int auxInt;
	cout << "Ingrese la posicion del Sistema deseado: ";
	cin >> auxInt;
	cout << endl;
	return auxInt;
}

int Vista::mensajeRealizacionCompraPersona(string nombre, string correo){
	int auxInt;
	cout << "-----> Realizacion del pago <-----" << endl << endl;
	cout << nombre << " confirma que su correo es: " << correo << endl;
	cout << "Y que desea suscribirse al boletin de informacion de nuestro empresa" << endl << endl;
	cout << "-----> Confirmacion <-----" << endl << endl;
	cout << "[1] - Si -" << endl;
	cout << "[2] - No -" << endl << endl;
	cout << "-> ";
	cin >> auxInt;
	return auxInt;
}

void Vista::mensajeRealizacionCompraEmpresa(string nombre, string correo){
	cout << "-----> Realizacion del pago <-----" << endl << endl;
	cout << nombre << " confirma que el correo de la empresa es: " << correo << endl;
	cout << "Y que desea suscribirse al boletin de informacion de nuestro empresa" << endl << endl;
}

void Vista::mensajeAtencionInformacion(){cout << "-----> Tenga en cuenta la siguiente informacion <-----" << endl << endl;}

void Vista::mensajeGraciasPorComprar(){cout << "----> Gracias por la compra <----" << endl << endl;}

void Vista::mensajeCancelacion(){
	cout << "\n!!No hay problema, te esperamos pronto!!" << endl << endl;
	system("pause");
	system("cls");
}

int Vista::mensajeConfirmacion(){
	int auxInt = 0;
	cout << "-----> Confirmacion <-----" << endl << endl;
	cout << "[1] - Si -" << endl;
	cout << "[2] - No -" << endl << endl;
	cout << "-> ";
	cin >> auxInt;
	return auxInt;
}

void Vista::mensajeDefault(){
	cout << "\t!!Codigo invalido!!" << endl << endl;
	system("pause");
}

void Vista::mensajeSistemaMasVendido(){
	cout << "--------->Steren<---------" << endl << endl;
	cout << "----> Sistema mas Vendido <----" << endl << endl;
}

void Vista::mensajeListaSistemas(){
	cout << "--------->Steren<---------" << endl << endl;
	cout << "----> Listado de Sistema <----" << endl << endl;
}

void Vista::mensajeListaVentas(){cout << "----> Listado de Ventas <----" << endl << endl;}

void Vista::mensajeSuscripcion(){cout << "------> Suscripcion al Catalogo <------" << endl << endl;}

void Vista::mensajeVentaEnLinea(){cout << "----> Venta en Linea <----" << endl << endl;}

void Vista::mensajeSuscripcionExitosa(ClienteEnLinea* clEnLinea){
	system("cls");
	cout << clEnLinea->toString(true);
	cout << "----> Se ha realizado la suscripcion con exito <----" << endl << endl;
	system("pause");
}