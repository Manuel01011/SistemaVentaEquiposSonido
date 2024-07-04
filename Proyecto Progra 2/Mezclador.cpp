#include "Mezclador.h"

Mezclador::Mezclador(double pre, string nom, string mod, string carac) : ProcesadorAbst(pre, nom, mod, carac){}

Mezclador::~Mezclador() {}

string Mezclador::toString(bool arch) {
	stringstream s;
	if (arch) {
		s << "-----> Mezclador <-----" << endl
			<< "Precio: " << precioBase << " dolares" << endl
			<< "Nombre: " << nombre << endl
			<< "Modelo: " << modelo << endl
			<< "Caracteristicas: " << caracteristicas << endl;
	}
	else { s << "Mezclador" << '\t' << nombre << '\t' << modelo << '\t' << caracteristicas << '\t' << precioBase; }
	return s.str();
}

ostream& operator<<(ostream& out, Mezclador& obj) {
	out << "-----> Mezclador <-----" << endl
		<< "Precio: " << obj.precioBase << " dolares" << endl
		<< "Nombre: " << obj.nombre << endl
		<< "Modelo: " << obj.modelo << endl
		<< "Caracteristicas: " << obj.caracteristicas << endl;
	return out;
}