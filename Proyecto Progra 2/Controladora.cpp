#include "Controladora.h"

Controladora::Controladora() {
	tienda = new InterfazTienda();
	subj = new Catalogo();
	venta = nullptr;
	sis = nullptr;
	clFisico = nullptr;
	clEnLinea = nullptr;
	auxCant = 0;
	auxInt = 0;
	tipo = "";
	id = "";
	cod = "";
	caract = "";
	nombre = "";
	cedula = "";
	correo = "";
	pais = "";
	ciudad = "";
	nacionalidad = "";
	pagoSub = 0;
	cant = 0;
	preciobase1 = 0;
	preciobase2 = 0;
	preciobase3 = 0;
}

Controladora::~Controladora() { if (tienda) { delete tienda; } }

void Controladora::MenuPrincipal() {
int op = 0;
inicio:
	do {
		op = Vista::menu();
		try { if ((tienda->getCanTotalDeSistema() < 1) && (op == 1)) { throw Excepciones(); } }
		catch (Excepciones& e) {
			cout << e.errorNoHaySistemas() << endl << endl;
			system("pause");
			system("cls");
			goto inicio;
		}
		switch (op){
		case 1:
			VentaDirectaOpc();
			break;
		case 2:
			VentaEnLineaOpc();
			break;
		case 3:
			Mantenimiento();
			break;
		case 4:
			break;
		default:
			Vista::mensajeDefault();
			break;
		}
		system("cls");
	} while (op != 4);
}

void Controladora::VentaDirectaOpc() {
int op1 = 0;
ventaDirecta:
	do {
		op1 = Vista::menuVentaDirecta();
		try { if ((tienda->getCanTotalDeSistema() < 1) && op1 == 1) { throw Excepciones(); } }
		catch (Excepciones& e) {
			cout << e.errorNoHaySistemas() << endl << endl;
			system("pause");
			system("cls");
			goto ventaDirecta;
		}
		switch (op1) {
		case 1:
			InfoDeClientes();
			break;
		case 2:
			break;
		default:
			Vista::mensajeDefault();
			break;
		}
		system("cls");
	} while (op1 != 2);
}

void Controladora::InfoDeClientes() {
realizarVenta:
clFisico = Vista::datosClienteFisico();
system("cls");
Vista::mensajeListaSistemas();
cout << tienda->mostrarStock();
	try {
		auxInt = Vista::mensajeIngresarPosSistema();
		if (auxInt < 0 || (auxInt > tienda->getCanTotalDeSistema())) {throw Excepciones();}
	}
	catch (Excepciones& e) {
		cout << e.errorPosInvalida() << endl << endl;
		system("pause");
		system("cls");
		goto realizarVenta;
	}
	sis = tienda->retornarSistemaPorPos(auxInt);
	venta = new VentaDirecta(sis, clFisico);
	system("cls");
	cout << venta->venta();
	Vista::mensajeGraciasPorComprar();
	system("pause");
	system("cls");
	sis->agregarCantidad(-1);
	if (sis->getCantidad() < 1) { tienda->quitarSistemaPos(auxInt); }
	tienda->ingresarVentas(venta);
	venta->realizarVenta();
	system("pause");
}

void Controladora::VentaEnLineaOpc() {
int op2 = 0;
inicioVentaEnLinea:
	do {
		op2 = Vista::menuInicioVentaEnLinea();
		try { if (((tienda->getCanTotalDeClientesFisicos() < 1) && (op2 == 1)) || ((tienda->getCanTotalDeClientesEmpresa() < 1) && (op2 == 2))) { throw Excepciones(); } }
		catch (Excepciones& e) {
			cout << e.errorNoHayClientes() << endl << endl;
			system("pause");
			system("cls");
			goto inicioVentaEnLinea;
		}
		if (op2 == 2) {
			op2 = 1;
			tipo = "Empresa";
		}
		else { tipo = "Fisico"; }
		switch (op2) {
		case 1:
			OpcVentaPerOEmp();
			break;
		case 3:
			Suscribirse();
			break;
		case 4:
			break;
		default:
			Vista::mensajeDefault();
			break;
		}
		system("cls");
	} while (op2 != 4);
}

void Controladora::OpcVentaPerOEmp() {
int op = 0;
IniciarSeccion:
	try {
		Vista::tituloIniciarSeccion();
		if (tipo == "Fisico") {
			id = Vista::ingresarCedulaPersona();
			if (!tienda->estaCedula(id, true)) { throw Excepciones(); }
		}
		else {
			id = Vista::ingresarCedulaJuridica();
			if (!tienda->estaCedula(id, false)) { throw Excepciones(); }
		}
	}
	catch (Excepciones& e) {
		cout << e.errorCedulaNoRegistrada() << endl << endl;
		system("pause");
		system("cls");
		goto IniciarSeccion;
	}
	clEnLinea = tienda->retornarClientePorCedula(id);
	system("cls");
	do {
	ventaEnLinea:
		op = Vista::menuCompraVentaEnLinea();
		try { if ((tienda->getCanTotalDeSistema() < 1) && op == 1) { throw Excepciones(); } }
		catch (Excepciones& e) {
			cout << e.errorNoHaySistemas() << endl << endl;
			system("pause");
			system("cls");
			goto ventaEnLinea;
		}
		switch (op) {
		case 1:
			SistemaPreconfiguradoOpc();
			break;
		case 2:
			break;
		default:
			Vista::mensajeDefault();
			break;
		}
		system("cls");
	} while (op != 2);
}

void Controladora::SistemaPreconfiguradoOpc() {
codigoTraslado:
	Vista::mensajeVentaEnLinea();
	try {
		cod = Vista::confirmarCodigoTraslado();
		if (cod != "010" && cod != "020" && cod != "030" && cod != "031" && cod != "032" && cod != "040" && cod != "050" && cod != "060" && cod != "090" && cod != "091"){throw Excepciones();}
	}
	catch (Excepciones& e) {
		cout << e.errorCodigoInvalido() << endl << endl;
		system("pause");
		system("cls");
		goto codigoTraslado;
	}
possistemas:
	system("cls");
	Vista::mensajeListaSistemas();
	cout << tienda->mostrarStock();
	try {
		auxInt = Vista::mensajeIngresarPosicion();
		if (auxInt < 0 || (auxInt > tienda->getCanTotalDeSistema())){throw Excepciones();}
	}
	catch (Excepciones& e) {
		cout << e.errorPosInvalida() << endl << endl;
		system("pause");
		system("cls");
		goto possistemas;
	}
	sis = tienda->retornarSistemaPorPos(auxInt);
	venta = new VentaEnLinea(cod, sis, clEnLinea);
	system("cls");
	cout << venta->venta();
	Vista::mensajeGraciasPorComprar();
	system("pause");
	system("cls");
	sis->agregarCantidad(-1);
	if (sis->getCantidad() < 1) { tienda->quitarSistemaPos(auxInt); }
	tienda->ingresarVentas(venta);
	venta->realizarVenta();
	system("pause");
}

void Controladora::Suscribirse() {
int auxOp = 0;
inicioSuscripcion:
	try {
		Vista::mensajeSuscripcion();
		auxOp = Vista::seleccioneElTipoDeCliente();
		if (auxOp != 1 && auxOp != 2) { throw Excepciones(); }
	}
	catch (Excepciones& e) {
		cout << e.errorOpcionInvalida() << endl << endl;
		system("pause");
		system("cls");
		goto inicioSuscripcion;
	}
	switch (auxOp) {
	case 1:
		ClientePersonaOpc();
		break;
	case 2:
		ClienteEmpresaOpc();
		break;
	default:
		Vista::mensajeDefault();
		break;
	}
	system("cls");
}

void Controladora::ClientePersonaOpc(){
suscripcion:
	nombre = Vista::ingresarNombrePersona();

	try {cedula = Vista::ingresarIDPersona();
	if (tienda->estaCedula(cedula, true)){throw Excepciones();}}
	catch (Excepciones& e){
		cout << "\n" << e.errorCedulaRegistrada() << endl << endl;
		system("pause");
		system("cls");
		goto suscripcion;
	}
	try {correo = Vista::ingresarCorreoPersona();
	if (tienda->estaCorreo(correo)){throw Excepciones();}
	}
	catch (Excepciones& e){
		cout << "\n" << e.errorCorreoRegistrado() << endl << endl;
		system("pause");
		system("cls");
		goto suscripcion;
	}

	nacionalidad = Vista::ingresarNacionalidad();

	Vista::mensajeAtencionInformacion();

	try {
		cod = Vista::ingresarCodigoTrasladoPersona();
		if (cod != "010" && cod != "020" && cod != "030" && cod != "031" && cod != "032" && cod != "040" && cod != "050" && cod != "060" && cod != "090" && cod != "091"){throw Excepciones();}
	}
	catch (Excepciones& e) {
		cout << e.errorCodigoInvalido() << endl << endl;
		system("pause");
		system("cls");
		goto suscripcion;
	}

	pais = ListaTraslados::pais(cod);
	ciudad = ListaTraslados::ciudad(cod);
	auxInt = Vista::mensajeRealizacionCompraPersona(nombre, correo);

	if (auxInt == 1) {
		pagoSub = 200;
		clEnLinea = new Persona(subj, nombre, cedula, correo, pagoSub, ciudad, pais, nacionalidad);
		tienda->ingresarSuscriptor(clEnLinea);
		Vista::mensajeSuscripcionExitosa(clEnLinea);
	}
	else { Vista::mensajeCancelacion(); }
}

void Controladora::ClienteEmpresaOpc() {
suscipcion2:
nombre = Vista::ingresarNombreEmpresa();

	try {cedula = Vista::ingresarIDJuridico();
	if (tienda->estaCedula(cedula, false)){throw Excepciones();}
	}
	catch (Excepciones& e){
		cout << "\n" << e.errorCedulaRegistrada() << endl << endl;
		system("pause");
		system("cls");
		goto suscipcion2;
	}
	try {
		correo = Vista::ingresarCorreoEmpresa();
		if (tienda->estaCorreo(correo)){throw Excepciones();}
	}
	catch (Excepciones& e){
		cout << e.errorCorreoRegistrado() << endl << endl;
		system("pause");
		system("cls");
		goto suscipcion2;
	}
	Vista::mensajeAtencionInformacion();
	try {
		cod = Vista::ingresarCodigoTrasladoEmpresa();
		if (cod != "010" && cod != "020" && cod != "030" && cod != "031" && cod != "032" && cod != "040" && cod != "050" && cod != "060" && cod != "090" && cod != "091"){throw Excepciones();}
	}
	catch (Excepciones& e){
		cout << e.errorCodigoInvalido() << endl << endl;
		system("pause");
		system("cls");
		goto suscipcion2;
	}

	pais = ListaTraslados::pais(cod);
	ciudad = ListaTraslados::ciudad(cod);

	Vista::mensajeRealizacionCompraEmpresa(nombre, correo);

	try {
		auxInt = Vista::mensajeConfirmacion();
		if (auxInt != 1 && auxInt != 2){throw Excepciones();}
	}
	catch (Excepciones& e){
		cout << e.errorOpcionInvalida() << endl << endl;
		system("pause");
		system("cls");
		goto suscipcion2;
	}
	if (auxInt == 1){
		pagoSub = 400;
		clEnLinea = new Empresa(subj, nombre, cedula, correo, pagoSub, ciudad, pais);
		tienda->ingresarSuscriptor(clEnLinea);
		Vista::mensajeSuscripcionExitosa(clEnLinea);
	}
	else{Vista::mensajeCancelacion();}
}

void Controladora::Mantenimiento(){
int op4 = 0;
mantenimiento:
	do {
		op4 = Vista::menuMantenimiento();
		try{if ((tienda->getCanTotalDeClientes() < 1) && op4 == 2){throw Excepciones();}}
		catch (Excepciones& e){
			cout << e.errorNoHayClientes() << endl << endl;
			system("pause");
			system("cls");
			goto mantenimiento;
		}
		try{if ((tienda->getCanTotalDeVentas() < 1) && op4 == 3){throw Excepciones();}}
		catch (Excepciones& e){
			cout << e.errorNoNayVentas() << endl << endl;
			system("pause");
			system("cls");
			goto mantenimiento;
		}
		switch (op4){
		case 1:
			CreaciondeSistemaOpc();
			break;
		case 2:
			MenuDeSuscriptores();
			break;
		case 3:
			MenuDeVentas();
			break;
		case 4:
			break;
		default:
			Vista::mensajeDefault();
			break;
		}
		system("cls");
	} while (op4 != 4);
}

void Controladora::CreaciondeSistemaOpc(){
int op5 = 0;
sistemas:
	do {
		op5 = Vista::menuSistema();
		try{if ((tienda->getCanTotalDeSistema() < 1) && (op5 == 2 || op5 == 3)){throw Excepciones();}}
		catch (Excepciones& e){
			cout << e.errorNoHaySistemas() << endl << endl;
			system("pause");
			system("cls");
			goto sistemas;
		}
		switch (op5){
		case 1:
			TiposdeSistemas();
			break;
		case 2:
			EliminarUnSistema();
			break;
		case 3:
			VerCatalogo();
			break;
		case 4:
			break;
		default:
			Vista::mensajeDefault();
			break;
		}
		system("cls");
	} while (op5 != 4);
}

void Controladora::TiposdeSistemas() {
double precioBase = 0.0, precioSistema = 0.0;
int cantidad = 0, numero = 0;
string modelo, nombre, caracteristica, tipo, codigo;
tipo:
ListaFuente* listaFuente = new ListaFuente();
ListaParlante* listaParlante = new ListaParlante();
ListaProcesador* listaProcesador = new ListaProcesador();
ProcesadorAbst* procesador = nullptr;
FuenteAbst* fuente = nullptr;
ParlanteAbst* parlantePtr = nullptr;

	Vista::ingresaProcesador();
	cin >> numero;
	try {if (numero != 1 && numero != 2) { throw Excepciones(); }}
	catch (Excepciones& e) {
		cout << e.errorOpcionInvalida() << endl << endl;
		system("pause");
		system("cls");
		goto tipo;
	}
	cout << "Ingrese el precio base del Procesador en colones: " << endl;
	cin >> precioBase;
	preciobase1 = precioBase;
	cout << "Ingrese el nombre del Procesador: " << endl;
	cin >> nombre;
	cout << "Ingrese el modelo del Procesador: " << endl;
	cin >> modelo;
	cout << "Ingrese las caracteristicas del Procesador: " << endl;
	cin >> caracteristica;
	system("pause");
	system("cls");
	if (numero == 1) {
		ProcesadorAbst* amplificador = new Amplificador(precioBase, nombre, modelo, caracteristica);
		listaProcesador->insertarProcesador(amplificador);
		procesador = amplificador;
	}
	if (numero == 2) {
		ProcesadorAbst* mezclador = new Mezclador(precioBase, nombre, modelo, caracteristica);
		listaProcesador->insertarProcesador(mezclador);
		procesador = mezclador;
	}
	Vista::ingresaFuente();
	cin >> numero;
	try { if (numero != 3 && numero != 4 && numero != 5 && numero != 6 && numero != 7) { throw Excepciones(); } }
	catch (Excepciones& e) {
		cout << e.errorOpcionInvalida() << endl << endl;
		system("pause");
		system("cls");
		goto tipo;
	}
	cout << "Ingrese el precio base de la Fuente en colones: " << endl;
	cin >> precioBase;
	preciobase2 = precioBase;
	cout << "Ingrese el nombre de la Fuente: " << endl;
	cin >> nombre;
	cout << "Ingrese el modelo de la Fuente: " << endl;
	cin >> modelo;
	cout << "Ingrese las caracteristicas de la fuente: " << endl;
	cin >> caracteristica;
	system("pause");
	system("cls");
	if (numero == 3) {
		FuenteAbst* unidadCD = new UnidadCD(precioBase, nombre, modelo, caracteristica);
		listaFuente->insertarFuente(unidadCD);
		fuente = unidadCD;
	}
	if (numero == 4) {
		FuenteAbst* tornamesa = new Tornamesa(precioBase, nombre, modelo, caracteristica);
		listaFuente->insertarFuente(tornamesa);
		fuente = tornamesa;
	}
	if (numero == 5) {
		FuenteAbst* radio = new Radio(precioBase, nombre, modelo, caracteristica);
		listaFuente->insertarFuente(radio);
		fuente = radio;
	}
	if (numero == 6) {
		FuenteAbst* bluetooth = new Bluetooth(precioBase, nombre, modelo, caracteristica);
		listaFuente->insertarFuente(bluetooth);
		fuente = bluetooth;
	}
	if (numero == 7) {
		FuenteAbst* microfono = new Microfono(precioBase, nombre, modelo, caracteristica);
		listaFuente->insertarFuente(microfono);
		fuente = microfono;
	}
	Vista::ingresaParlante();
	cin >> numero;
	try {if (numero != 8 && numero != 9) { throw Excepciones(); }}
	catch (Excepciones& e) {
		cout << e.errorOpcionInvalida() << endl << endl;
		system("pause");
		system("cls");
		goto tipo;
	}
	cout << "Ingrese el precio base del Parlante en colones: " << endl;
	cin >> precioBase;
	preciobase3 = precioBase;
	cout << "Ingrese el nombre del Parlante: " << endl;
	cin >> nombre;
	cout << "Ingrese el modelo del Parlante: " << endl;
	cin >> modelo;
	cout << "Ingrese las caracteristicas del Parlante: " << endl;
	cin >> caracteristica;
	system("pause");
	system("cls");
	if (numero == 8) {
		ParlanteAbst* parlante = new Parlante(precioBase, nombre, modelo, caracteristica);
		listaParlante->insertarParlante(parlante);
		parlantePtr = parlante;
	}
	if (numero == 9) {
		ParlanteAbst* audifono = new Audifono(precioBase, nombre, modelo, caracteristica);
		listaParlante->insertarParlante(audifono);
		parlantePtr = audifono;
	}
	cout << "El precio del Sistema es de: " << preciobase1 + preciobase2 + preciobase3 + (preciobase1 + preciobase2 + preciobase3) * 0.35 << " colones" << endl;
    precioSistema += preciobase1 + preciobase2 + preciobase3 + (preciobase1 + preciobase2 + preciobase3) * 0.35;
	cout << "Ingrese el tipo de sistema: " << endl;
	cin >> tipo;
	cout << "Ingrese el codigo del sistema: " << endl;
	cin >> codigo;
	cout << "Ingrese la cantidad de sistemas: " << endl;
	cin >> cantidad;
	Sistema* sistema = new Sistema(fuente, parlantePtr, procesador, precioSistema, tipo, codigo, cantidad);
	tienda->ingresarSistema(sistema);
	cout << "----> Ingresado correctamente <----" << endl << endl;
	system("pause");
}

void Controladora::EliminarUnSistema() {
eliminasistema:
	try {
		Vista::tituloEliminarSistema();
		cout << tienda->mostrarStock();
		auxInt = Vista::EliminarPorPosSistema();
		if (auxInt < 1 || auxInt > tienda->getCanTotalDeSistema()){throw Excepciones();}
	}
	catch (Excepciones& e){
		cout << e.errorPosInvalida() << endl << endl;
		system("pause");
		system("cls");
		goto eliminasistema;
	}
	system("cls");
	tienda->eliminarSistemaPos(auxInt);
	cout << "----> Eliminado correctamente <----" << endl << endl;
	system("pause");
}

void Controladora::VerCatalogo() {
	cout << tienda->mostrarStock();
	system("pause");
}

void Controladora::MenuDeSuscriptores() {
int op5 = 0;
manteAsociados:
	do {
		op5 = Vista::menuAsociados();

		try{if ((tienda->getCanTotalDeClientesFisicos() < 1 && op5 == 2) || (tienda->getCanTotalDeClientesEmpresa() < 1 && op5 == 3) || ((tienda->getCanTotalDeClientesFisicos() < 1 && op5 == 1) && (tienda->getCanTotalDeClientesEmpresa() < 1 && op5 == 1))){throw Excepciones();}}
		catch (Excepciones& e){
			cout << e.errorNoHayClientes() << endl << endl;
			system("pause");
			system("cls");
			goto manteAsociados;
		}
		switch (op5){
		case 1:
			EliminarSuscri();
			break;
		case 2:
			ListaClientesPersona();
			break;
		case 3:
			ListaClientesEmpresa();
			break;
		case 4:
			break;
		default:
			Vista::mensajeDefault();
			break;
		}
		system("cls");
	} while (op5 != 4);
}

void Controladora::EliminarSuscri() {
eliminaAsociado:
	try {
		Vista::tituloEliminarSuscri();
		cout << tienda->listaClientes();
		auxInt = Vista::EliminarPorPosSuscri();
		if (auxInt < 1 || auxInt > tienda->getCanTotalDeClientes()){throw Excepciones();}
	}
	catch (Excepciones& e){
		cout << e.errorPosInvalida() << endl << endl;
		system("pause");
		system("cls");
		goto eliminaAsociado;
	}
	tienda->eliminarSuscriptorPos(auxInt);
	cout << "----> Eliminado correctamente <----" << endl << endl;
	system("pause");
}

void Controladora::ListaClientesPersona() {
	cout << tienda->listaClientesFisicos();
	system("pause");
}

void Controladora::ListaClientesEmpresa() {
	cout << tienda->listaClientesEmpresa();
	system("pause");
}

void Controladora::MenuDeVentas() {
	int op5 = 0;
	do {
		op5 = Vista::menuVentas();
		switch (op5){
		case 1:
			HistoralDeVentas();
			break;
		case 2:
			VentasConGanaciaOpc();
			break;
		case 3:
			SistemaMasVendido();
			break;
		case 4:
			break;
		default:
			Vista::mensajeDefault();
			break;
		}
		system("cls");
	} while (op5 != 4);
}

void Controladora::HistoralDeVentas() {
	Vista::mensajeListaVentas();
	cout << tienda->mostrarHistorialDeVentas();
	system("pause");
}

void Controladora::VentasConGanaciaOpc() {
	Vista::mensajeListaVentas();
	cout << tienda->ventasConGanancia();
	system("pause");
}

void Controladora::SistemaMasVendido() {
	Vista::mensajeSistemaMasVendido();
	cout << "El codigo del sistema mas vendido es: " << tienda->codigoSistemaMasVendido() << endl << endl;
	system("pause");
}

void Controladora::guardarDatos() { tienda->guardarDatosAplicacion(); }

void Controladora::recuperarDatos() { tienda->recuperarDatosAplicacion(); }