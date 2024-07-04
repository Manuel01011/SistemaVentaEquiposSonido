#include "UnidadCD.h"

UnidadCD::UnidadCD(double pre, string nom, string mod, string carac) : FuenteAbst(pre, nom, mod, carac){}

UnidadCD::~UnidadCD() {}

string UnidadCD::toString(bool arch) {
	stringstream s;
	if (arch) {
		s << "-----> UnidadCD <-----" << endl
			<< "Precio: " << precioBase << " dolares" << endl
			<< "Nombre: " << nombre << endl
			<< "Modelo: " << modelo << endl
			<< "Caracteristicas: " << caracteristicas << endl;
	}
	else { s << "UnidadCD" << '\t' << nombre << '\t' << modelo << '\t' << caracteristicas << '\t' << precioBase; }
	return s.str();
}

ostream& operator<<(ostream& out, UnidadCD& obj) {
	out << "-----> UnidadCD <-----" << endl
		<< "Precio: " << obj.precioBase << " dolares" << endl
		<< "Nombre: " << obj.nombre << endl
		<< "Modelo: " << obj.modelo << endl
		<< "Caracteristicas: " << obj.caracteristicas << endl;

	return out;
}