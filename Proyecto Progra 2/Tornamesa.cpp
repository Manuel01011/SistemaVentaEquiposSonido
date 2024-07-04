#include "Tornamesa.h"

Tornamesa::Tornamesa(double pre, string nom, string mod, string carac) : FuenteAbst(pre, nom, mod, carac){}

Tornamesa::~Tornamesa() {}

string Tornamesa::toString(bool arch) {
	stringstream s;
	if (arch) {
		s << "-----> Tornamesa <-----" << endl
			<< "Precio: " << precioBase << " dolares" << endl
			<< "Nombre: " << nombre << endl
			<< "Modelo: " << modelo << endl
			<< "Caracteristicas: " << caracteristicas << endl;
	}
	else { s << "Tornamesa" << '\t' << nombre << '\t' << modelo << '\t' << caracteristicas << '\t' << precioBase; }
	return s.str();
}

ostream& operator<<(ostream& out, Tornamesa& obj) {
	out << "-----> Tornamesa <-----" << endl
		<< "Precio: " << obj.precioBase << " dolares" << endl
		<< "Nombre: " << obj.nombre << endl
		<< "Modelo: " << obj.modelo << endl
		<< "Caracteristicas: " << obj.caracteristicas << endl;
	return out;
}

