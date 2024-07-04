#include "Microfono.h"

Microfono::Microfono(double pre, string nom, string mod, string carac) : FuenteAbst(pre, nom, mod, carac){}

Microfono::~Microfono() {}

string Microfono::toString(bool arch) {
	stringstream s;
	if (arch) {
		s << "-----> Microfono<-----" << endl
			<< "Precio: " << precioBase << " dolares" << endl
			<< "Nombre: " << nombre << endl
			<< "Modelo: " << modelo << endl
			<< "Caracteristicas: " << caracteristicas << endl;
	}
	else { s << "Microfono" << '\t' << nombre << '\t' << modelo << '\t' << caracteristicas << '\t' << precioBase; }
	return s.str();
}

ostream& operator<<(ostream& out, Microfono& obj) {
	out << "-----> Microfono <-----" << endl
		<< "Precio: " << obj.precioBase << " dolares" << endl
		<< "Nombre: " << obj.nombre << endl
		<< "Modelo: " << obj.modelo << endl
		<< "Caracteristicas: " << obj.caracteristicas << endl;
	return out;
}

