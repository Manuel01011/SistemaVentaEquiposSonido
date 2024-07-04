#include "Catalogo.h"

Catalogo::Catalogo(){
	catalogo = new ListarGenerica<Sistema>();
	suscriptores = new ListarGenerica<Observer>();
	descripcion = "Indefinido";
}

void Catalogo::notificar(){//Se encarga de notificar a todos los clientes suscritos acerca cambios(agregar o eliminar) que se hayan realizado a los objetos de tipo sistema
	if (suscriptores->getK() > 0){
		cout << "----> Enviando notificaciones a los Clientes <----" << endl << endl;
		for (int i = 1; i <= suscriptores->getK(); i++){
			suscriptores->retonarObjetoLugar(i)->actualizar(descripcion);
			cout << "-----------------------------------" << endl << endl;
		}
	}
}

void Catalogo::crearMensaje(Sistema* sis, bool key) {//Mensaje que se le envia a los clientes cuando se realizan cambios(agregar o eliminar) con los objetos de tipo sistema para notificarles
	if (key) descripcion = "Agregamos el siguiente sistema:\n\n" + sis->toString();
	else descripcion = "Eliminamos el siguiente sistema:\n\n" + sis->toString();
}

void Catalogo::agregarSub(Observer* obj) {suscriptores->insertarInicio(*obj);}

void Catalogo::eliminarSub(int pos) {suscriptores->eliminarLugar(pos);}

string Catalogo::mostrarSubs(){//Muestra a todos los suscriptores de la tienda
	stringstream s;
	for (int i = 1; i <= suscriptores->getK(); i++){
		s << i << "- " << suscriptores->retonarObjetoLugar(i)->toString(true);
		s << "-------------------------------------" << endl << endl;
	}
	return s.str();
}

ClienteEnLinea* Catalogo::retornarSubPos(int pos){//Devuelve el suscriptor en la posicion recibida por parametro
	ClienteEnLinea* aux = dynamic_cast<ClienteEnLinea*>(suscriptores->retonarObjetoLugar(pos));
	return aux;
}

bool Catalogo::ExisteCedula(string ced, bool per) {//Recibe por parametro un string y un bool los cuales utiliza primero el bool para saber el tipo de cedula que se esta digitando(Juridica o personal) y luego utiliza la cedula(string) para ver si encuentra alguna coincidencia en la lista generica de clientes en caso de haberla retorna true en caso contrario retorna false.
	ClienteEnLinea* aux = nullptr;
	if (per) {
		for (int i = 1; i <= suscriptores->getK(); i++) {
			aux = dynamic_cast<Persona*>(suscriptores->retonarObjetoLugar(i));
			if (aux) {
				if (aux->getCedula() == ced) {
					return true;
				}
			}
		}
	}
	else {
		for (int i = 1; i <= suscriptores->getK(); i++) {
			aux = dynamic_cast<Empresa*>(suscriptores->retonarObjetoLugar(i));
			if (aux) {
				if (aux->getCedula() == ced) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Catalogo::ExisteCorreo(string cor){//Recibe por parametro un string el cual utiliza para ver si encuentra alguna coincidencia(correo) en la lista generica de clientes en caso de haberla retorna true en caso contrario retorna false.
	ClienteEnLinea* aux = nullptr;
	for (int i = 1; i <= suscriptores->getK(); i++){
		aux = dynamic_cast<ClienteEnLinea*>(suscriptores->retonarObjetoLugar(i));
		if (aux->getCorreo() == cor){
			return true;
		}
	}
	return false;
}

bool Catalogo::ExisteCodigo(string cod){//Recibe por parametro un string el cual utiliza para ver si encuentra alguna coincidencia(correo) en la lista generica de clientes en caso de haberla retorna true en caso contrario retorna false.
	for (int i = 1; i <= catalogo->getK(); i++){
		if (catalogo->retonarObjetoLugar(i)->getCodigo() == cod){
			return true;
		}
	}
	return false;
}

void Catalogo::ingresaSistema(Sistema* sis) {//Recibe por parametro un puntero a un objeto de tipo Sistema para ingresarlo al principio del catalogo.Posteriormente crea un mensaje para notificar a los suscriptores de este cambio
	catalogo->insertarInicio(*sis);
	crearMensaje(sis, true);
	notificar();
}

void Catalogo::eliminarSistema(int pos) {//Recibe por parametro un entero(posicion del sistema que se desea eliminar) para luego buscar el sistema en la posicion del entero dado y eliminarlo. Posteriormente crea un mensaje para notificar a los suscriptores de este cambio
	Sistema* sis = catalogo->retonarObjetoLugar(pos);
	crearMensaje(sis, false);
	notificar();
	catalogo->eliminarLugar(pos);
}

string Catalogo::mostrarCatalogo() {//Muestra el catalogo
	stringstream s;
	s << *catalogo;
	return s.str();
}

Sistema* Catalogo::getsistemaPos(int pos) {return catalogo->retonarObjetoLugar(pos);}//Devuelve el sistema en la posicion recibida por parametro

void Catalogo::quitarSistemaePos(int pos){//Recibe por parametro un entero(posicion del sistema que se desea eliminar) para luego buscar el sistema en la posicion del entero dado y eliminarlo. Posteriormente crea un mensaje para notificar a los suscriptores de este cambio
	Sistema* sis = catalogo->retonarObjetoLugar(pos);
	crearMensaje(sis, false);
	notificar();
	catalogo->quitarObjetoLugar(pos);
}

int Catalogo::getCanTotalSistemas() { return catalogo->getK(); }//Devuelve el numero de sistemas que hay en stock en la tienda

int Catalogo::getCanTotalSubs(){return suscriptores->getK();}//Devuelve el numero de suscriptores(Persona y empresa) de la tienda

int Catalogo::getCanTotalDeClientesEmpresa(){//Devuelve el numero de ClientesEnLinea(Empresa) suscritos a la tienda
	ClienteEnLinea* aux = nullptr;
	int cont = 0;
	for (int i = 1; i <= suscriptores->getK(); i++){
		aux = dynamic_cast<Empresa*>(suscriptores->retonarObjetoLugar(i));
		if (aux){
			cont++;
		}
	}
	return cont;
}

int Catalogo::getCanTotalDeClientesFisicos(){//Devuelve el numero de ClientesEnLinea(Persona) suscritos a la tienda
	ClienteEnLinea* aux = nullptr;
	int cont = 0;
	for (int i = 1; i <= suscriptores->getK(); i++) {
		aux = dynamic_cast<ClienteEnLinea*>(suscriptores->retonarObjetoLugar(i));
		if (aux) {
			cont++;
		}
	}
	return cont;
}

string Catalogo::getDescripcion(){return descripcion;}//Get del atributo descripcion
void Catalogo::setDescripcion(string d){descripcion;}//Set del atributo descripcion

ListarGenerica<Sistema>* Catalogo::getCatalogo(){return catalogo;}//Get del atributo catalogo.Devuelve la lista generica de sistemas
ListarGenerica<Observer>* Catalogo::getSuscriptores(){return suscriptores;}//Get del atributo suscriptores.Devuelve la lista generica del observer

void Catalogo::setCatalogo(ListarGenerica<Sistema>* contenedor){catalogo = contenedor;}//Set del atributo catalogo
void Catalogo::setSuscriptores(ListarGenerica<Observer>* contenedor){suscriptores = contenedor;}//Set del atributo suscriptores