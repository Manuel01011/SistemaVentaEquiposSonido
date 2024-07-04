#include "Audifono.h"

Audifono::Audifono(double pre, string nom, string mod, string carac) : ParlanteAbst(pre, nom, mod, carac){}

Audifono::~Audifono() {}

string Audifono::toString(bool arch) {
	stringstream s;
	if (arch) {
		s << "-----> Audifono <-----" << endl
			<< "Precio: " << precioBase << " dolares" << endl
			<< "Nombre: " << nombre << endl
			<< "Modelo: " << modelo << endl
			<< "Caracteristicas: " << caracteristicas << endl;
	}
	else { s << "Audifono" << '\t' << nombre << '\t' << modelo << '\t' << caracteristicas << '\t' << precioBase; }
	return s.str();
}

ostream& operator<<(ostream& out, Audifono& obj) {
	out << "-----> Audifono <-----" << endl
		<< "Precio: " << obj.precioBase << " dolares" << endl
		<< "Nombre: " << obj.nombre << endl
		<< "Modelo: " << obj.modelo << endl
		<< "Caracteristicas: " << obj.caracteristicas << endl;
	return out;
}