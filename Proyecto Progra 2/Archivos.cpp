#include "Archivos.h"

Archivos::Archivos(){}

Archivos::~Archivos() {}

void Archivos::abrirFlujoModoEscritura() { archivo.open("../Archivos.txt", ios::out); }//Abre el archivo en modo de escritura

void Archivos::abrirFlujoModoLectura() { archivo.open("../Archivos.txt", ios::in); }//Abre el archivo en modo de lectura

void Archivos::cerrarFlujo() { archivo.close(); }//Cierra el archivo

int Archivos::obtenerInt(std::string s) {//Convierte el string proveniente del archivo en un entero
	int v;
	stringstream r(s);
	r >> v;
	return v;
}

double Archivos::obtenerDouble(std::string s) {//Convierte el string proveniente del archivo en un double
	double v;
	stringstream r(s);
	r >> v;
	return v;
}

bool Archivos::obtenerBool(std::string s) {//Convierte el string proveniente del archivo en un entero
	bool v;
	stringstream r(s);
	r >> v;
	return v;
}

void Archivos::guardarBool(bool b, char delimitador) { archivo << b << delimitador; }//Guarda en el archivo las variables de tipo bool con su respectivo delimitador

void Archivos::guardarInt(int i, char delimitador) { archivo << i << delimitador; }//Guarda en el archivo las variables de tipo int con su respectivo delimitador

void Archivos::guardarDouble(double d, char delimitador) { archivo << d << delimitador; }//Guarda en el archivo las variables de tipo double con su respectivo delimitador

void Archivos::guardarString(string s, char delimitador) { archivo << s << delimitador; }//Guarda en el archivo las variables de tipo string con su respectivo delimitador

bool Archivos::recuperarBool(char delimitador) {//Rcupera del archivo las variables de tipo bool y las envia a obtenerBool para hacer la conversion string a bool
	string r;
	getline(archivo, r, delimitador);
	return obtenerBool(r);
}

int Archivos::recuperarInt(char delimitador) {
	string r;
	getline(archivo, r, delimitador);
	if (r != "") return obtenerInt(r);
	return obtenerInt("0");
}

double Archivos::recuperarDouble(char delimitador) {
	string r;
	getline(archivo, r, delimitador);
	if (r != "") return obtenerDouble(r);
	return obtenerDouble("0");
}

string Archivos::recuperarString(char delimitador) {
	string r;
	getline(archivo, r, delimitador);
	return r;
}

void Archivos::guardarDatosSingleton() {
	VentasEmpresa& v = VentasEmpresa::instanciar();
	guardarString(v.guardarDatos(), '\n');
}

void Archivos::recuperarDatosSingleton() {
	VentasEmpresa& v = VentasEmpresa::instanciar();
	double totalVentas = recuperarDouble('\t');
	int cantVentas = recuperarInt('\n');
	v.setTotalVentas(totalVentas);
	v.setCantVentas(cantVentas);
}

void Archivos::guardarClienteLinea(Observer* obj) { guardarString(obj->toString(false), '\n'); }

void Archivos::guardarSistema(Sistema* obj) { guardarString(obj->informacionSistemaArc(false), '\n'); }

void Archivos::guardarVenta(Venta* obj) { guardarString(obj->toString(false), '\n'); }

ClienteFisico* Archivos::recuperarClienteFisico(char delimitador) {
	string type = "Indefinido", nom = "", ced = "";
	ClienteFisico* CLF;
	type = recuperarString('\t');
	nom = recuperarString('\t');
	ced = recuperarString(delimitador);
	CLF = new ClienteFisico(nom, ced);
	return CLF;
}

Observer* Archivos::recuperarClienteLinea(char delimitador) {
	string type = "Indefinido";

	Observer* obs = nullptr;
	Subject* subj = new Catalogo();
	string nom = "", ced = "", correo = "", ciudad = "", pais = "", nacionalidad = "";
	double pago = 0;
	bool frecuente = 0;

	type = recuperarString('\t');

	if (type == "Persona") {
		nom = recuperarString('\t');
		ced = recuperarString('\t');
		correo = recuperarString('\t');
		pais = recuperarString('\t');
		ciudad = recuperarString('\t');
		pago = recuperarDouble('\t');
		nacionalidad = recuperarString(delimitador);
		obs = new Persona(subj, nom, ced, correo, pago, ciudad, pais, nacionalidad);
	}
	if (type == "Empresa") {
		nom = recuperarString('\t');
		ced = recuperarString('\t');
		correo = recuperarString('\t');
		pago = recuperarDouble('\t');
		ciudad = recuperarString('\t');
		pais = recuperarString('\t');
		frecuente = recuperarBool(delimitador);
		obs = new Empresa(subj, nom, ced, correo, pago, ciudad, pais, frecuente);
	}
	return obs;
}

Sistema* Archivos::recuperarSistema(char delimitador) {
	Sistema* sistema = nullptr;
	FuenteAbst* fuente = nullptr;
	ProcesadorAbst* procesador = nullptr;
	ParlanteAbst* parlante = nullptr;
	string tipo = "Indefinido";
	string codigo = "";
	double precio = 0;
	int cant = 0;

	codigo = recuperarString('\t');
	precio = recuperarDouble('\t');
	fuente = recuperarFuente('\t');
	procesador = recuperarProcesador('\t');
	parlante = recuperarParlante('\t');
	cant = recuperarInt(delimitador);

	sistema = new Sistema(fuente, parlante, procesador, precio, tipo, codigo, cant);

	return sistema;
}

FuenteAbst* Archivos::recuperarFuente(char delimitador) {
	string type = "Indefinido";
	FuenteAbst* fuente = nullptr;
	string nom = "", mod = "", carac = "";
	double precio = 0;

	type = recuperarString('\t');
	nom = recuperarString('\t');
	mod = recuperarString('\t');
	carac = recuperarString('\t');
	precio = recuperarDouble(delimitador);

	if (type == "UnidadCD") fuente = new UnidadCD(precio, nom, mod, carac);
	if (type == "Radio") fuente = new Radio(precio, nom, mod, carac);
	if (type == "Tornamesa") fuente = new Tornamesa(precio, nom, mod, carac);
	if (type == "Bluetooth") fuente = new Bluetooth(precio, nom, mod, carac);
	if (type == "Microfono") fuente = new Microfono(precio, nom, mod, carac);
	return fuente;
}

ProcesadorAbst* Archivos::recuperarProcesador(char delimitador) {
	string type = "Indefinido";
	ProcesadorAbst* procesador = nullptr;
	string nom = "", mod = "", carac = "";
	double precio = 0;

	type = recuperarString('\t');
	nom = recuperarString('\t');
	mod = recuperarString('\t');
	carac = recuperarString('\t');
	precio = recuperarDouble(delimitador);

	if (type == "Amplificador") procesador = new Amplificador(precio, nom, mod, carac);
	if (type == "Mezclador") procesador = new Mezclador(precio, nom, mod, carac);

	return procesador;
}

ParlanteAbst* Archivos::recuperarParlante(char delimitador) {
	string type = "Indefinido";
	ParlanteAbst* parlante = nullptr;
	string nom = "", mod = "", carac = "";
	double precio = 0;

	type = recuperarString('\t');
	nom = recuperarString('\t');
	mod = recuperarString('\t');
	carac = recuperarString('\t');
	precio = recuperarDouble(delimitador);

	if (type == "Parlante") parlante = new Parlante(precio, nom, mod, carac);
	if (type == "Audifono") parlante = new Audifono(precio, nom, mod, carac);

	return parlante;
}

Venta* Archivos::recuperarVenta() {
	Venta* venta = nullptr;
	ClienteFisico* clFisico = nullptr;
	Observer* clLinea = nullptr;
	Sistema* sistema = nullptr;

	string type = "Indefinido";
	string codTras = "";

	type = recuperarString('\t');

	if (type == "ClienteFisico") {
		clFisico = recuperarClienteFisico('\t');
		sistema = recuperarSistema('\n');
		venta = new VentaDirecta(sistema, clFisico);
	}

	else {
		codTras = recuperarString('\t');
		clLinea = recuperarClienteLinea('\t');
		sistema = recuperarSistema('\n');
		venta = new VentaEnLinea(codTras, sistema, clLinea);
	}

	return venta;
}

void Archivos::guardarClientesEnLinea(ListarGenerica<Observer>* lista) {
	lista->incializarPrincio();
	Observer* obs = nullptr;

	int n = lista->getK();
	guardarInt(n, '\n');

	int i = 0;
	while (i < n) {
		obs = &lista->recuperar();
		guardarClienteLinea(obs);
		i++;
	}
}

void Archivos::guardarSistemas(ListarGenerica<Sistema>* lista) {
	lista->incializarPrincio();
	Sistema* sistema = nullptr;

	int n = lista->getK();
	guardarInt(n, '\n');

	int i = 0;
	while (i < n) {
		sistema = &lista->recuperar();
		guardarSistema(sistema);
		i++;
	}
}

void Archivos::guardarVentas(ListarGenerica<Venta>* lista) {
	lista->incializarPrincio();
	Venta* venta = nullptr;

	int n = lista->getK();
	guardarInt(n, '\n');

	int i = 0;
	while (i < n) {
		venta = &lista->recuperar();
		guardarVenta(venta);
		i++;
	}
}

ListarGenerica<Observer>* Archivos::recuperarClientesLinea() {
	int cant = 0;
	ListarGenerica<Observer>* contenedor = new ListarGenerica<Observer>();

	Observer* obs = nullptr;
	cant = recuperarInt('\n');

	int i = 0;
	while (i < cant) {
		obs = recuperarClienteLinea('\n');
		contenedor->insertarInicio(*obs);
		i++;
	}
	return contenedor;
}

ListarGenerica<Sistema>* Archivos::recuperarSistemas() {
	int cant = 0;
	ListarGenerica<Sistema>* contenedor = new ListarGenerica<Sistema>();

	Sistema* sistema = nullptr;
	cant = recuperarInt('\n');

	int i = 0;
	while (i < cant) {
		sistema = recuperarSistema('\n');
		contenedor->insertarInicio(*sistema);
		i++;
	}
	return contenedor;
}

ListarGenerica<Venta>* Archivos::recuperarVentas() {
	int cant = 0;
	ListarGenerica<Venta>* contenedor = new ListarGenerica<Venta>();

	Venta* venta = nullptr;
	cant = recuperarInt('\n');

	int i = 0;
	while (i < cant) {
		venta = recuperarVenta();
		contenedor->insertarInicio(*venta);
		i++;
	}
	return contenedor;
}