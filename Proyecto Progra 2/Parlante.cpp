#include "Parlante.h"

Parlante::Parlante(double pre, string nom, string mod, string carac) : ParlanteAbst(pre, nom, mod, carac){}

Parlante::~Parlante() {}

string Parlante::toString(bool arch) {
	stringstream s;
	if (arch) {
		s << "-----> Parlante <-----" << endl
			<< "Precio: " << precioBase << " dolares" << endl
			<< "Nombre: " << nombre << endl
			<< "Modelo: " << modelo << endl
			<< "Caracteristicas: " << caracteristicas << endl;
	}
	else { s << "Parlante" << '\t' << nombre << '\t' << modelo << '\t' << caracteristicas << '\t' << precioBase; }
	return s.str();
}

ostream& operator<<(ostream& out, Parlante& obj) {
	out << "-----> Parlante <-----" << endl
		<< "Precio: " << obj.precioBase << " dolares" << endl
		<< "Nombre: " << obj.nombre << endl
		<< "Modelo: " << obj.modelo << endl
		<< "Caracteristicas: " << obj.caracteristicas << endl;

	return out;
}
