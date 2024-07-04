#include "SistemaAbst.h"

SistemaAbst::SistemaAbst(FuenteAbst* fPtr, ParlanteAbst* pPtr, ProcesadorAbst* proPtr, int pre, string tip, string cod, int can): fuentePtr(fPtr), parlantePtr(pPtr), procesadorPtr(proPtr), precio(pre), tipo(tip), codigo(cod), cantidad(can)
{
}

SistemaAbst::~SistemaAbst()
{

	if (fuentePtr != nullptr) {
		delete fuentePtr;

	}
	if (parlantePtr != nullptr) {
		delete parlantePtr;
	}
	if (procesadorPtr != nullptr) {
		delete procesadorPtr;
	}
}

int SistemaAbst::getPrecio()
{
	return precio;
}

string SistemaAbst::getTipo()
{
	return tipo;
}



int SistemaAbst::getCantidad()
{
	return cantidad;
}

void SistemaAbst::setCantidad(int cant)
{
	cantidad = cant;

}

FuenteAbst* SistemaAbst::getFuente()
{
	return fuentePtr;
}

ParlanteAbst* SistemaAbst::getParlante()
{
	return parlantePtr;
}

ProcesadorAbst* SistemaAbst::getProcesador()
{
	return procesadorPtr;
}

void SistemaAbst::establecerPrecio()
{
	precio += fuentePtr->getPrecio();
	precio += parlantePtr->getPrecio();
	precio += procesadorPtr->getPrecio();
	precio += precio * 0.80;
}

void SistemaAbst::agregarCantidad(int cant)
{
	cantidad += cant;
}
FuenteAbst* SistemaAbst::crearFuente(int precioBase, string caracteristca, string modelo, string nombre)
{
	return Sistemas::crearFuente(precioBase, caracteristca, modelo, nombre);
}

ParlanteAbst* SistemaAbst::crearParlante(int precioBase, string caracteristca, string modelo, string nombre)
{
	return Sistemas::crearParlante(precioBase, caracteristca, modelo, nombre);
}

ProcesadorAbst* SistemaAbst::crearProcesador(int precioBase, string caracteristca, string modelo, string nombre)
{
	return Sistemas::crearProcesador(precioBase, caracteristca, modelo, nombre);
}

string SistemaAbst::toString()
{
	stringstream s;

	s << "Sistema: " << endl;
	s << "Precio: " << precio << endl;
	s << "Codigo: " << codigo << endl;
	s << " Cantidad: " << cantidad << endl;
	s << procesadorPtr->toString(true) << endl;
	s << fuentePtr->toString(true) << endl;
	s << parlantePtr->toString(true) << endl;

	return s.str();
}

ostream& operator<<(ostream& out, const SistemaAbst& obj)
{

	out << "Sistema: " << endl;
	out << "Precio: " << obj.precio << endl;
	out << "Codigo: " << obj.codigo << endl;
	out << " Cantidad: " << obj.cantidad << endl;
	out << obj.procesadorPtr->toString(true) << endl;
	out << obj.fuentePtr->toString(true) << endl;
	out << obj.parlantePtr->toString(true) << endl;

	return out;

}
