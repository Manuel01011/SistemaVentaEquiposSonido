#include "Amplificador.h"

Amplificador::Amplificador(double pre, string nom, string mod, string carac): ProcesadorAbst(pre, nom, mod, carac){}

Amplificador::~Amplificador() {}

string Amplificador::toString(bool arch) {
	stringstream s;
	if (arch) {
		s << "-----> Amplificador <-----" << endl
			<< "Precio: " << precioBase << " dolares" << endl
			<< "Nombre: " << nombre << endl
			<< "Modelo: " << modelo << endl
			<< "Caracteristicas: " << caracteristicas << endl;
	}
	else { s << "Amplificador" << '\t' << nombre << '\t' << modelo << '\t' << caracteristicas << '\t' << precioBase; }
	return s.str();
}

ostream& operator<<(ostream& out, Amplificador& obj) {
	out << "-----> Amplificador <-----" << endl
		<< "Precio: " << obj.precioBase << " dolares" << endl
		<< "Nombre: " << obj.nombre << endl
		<< "Modelo: " << obj.modelo << endl
		<< "Caracteristicas: " << obj.caracteristicas << endl;
	return out;
}