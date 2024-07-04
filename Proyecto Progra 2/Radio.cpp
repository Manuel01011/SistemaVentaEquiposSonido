#include "Radio.h"

Radio::Radio(double pre, string nom, string mod, string carac) : FuenteAbst(pre, nom, mod, carac){}

Radio::~Radio() {}

string Radio::toString(bool arch) {
	stringstream s;
	if (arch) {
		s << "-----> Radio <-----" << endl
			<< "Precio: " << precioBase << " dolares" << endl
			<< "Nombre: " << nombre << endl
			<< "Modelo: " << modelo << endl
			<< "Caracteristicas: " << caracteristicas << endl;
	}
	else { s << "Radio" << '\t' << nombre << '\t' << modelo << '\t' << caracteristicas << '\t' << precioBase; }
	return s.str();
}

ostream& operator<<(ostream& out, Radio& obj) {
	out << "-----> Radio <-----" << endl
		<< "Precio: " << obj.precioBase << " dolares" << endl
		<< "Nombre: " << obj.nombre << endl
		<< "Modelo: " << obj.modelo << endl
		<< "Caracteristicas: " << obj.caracteristicas << endl;
	return out;
}
