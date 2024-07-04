#include "Bluetooth.h"

Bluetooth::Bluetooth(double pre, string nom, string mod, string carac) : FuenteAbst(pre, nom, mod, carac){}

Bluetooth::~Bluetooth() {}

string Bluetooth::toString(bool arch) {
	stringstream s;
	if (arch) {
		s << "-----> Bluetooth <-----" << endl
			<< "Precio: " << precioBase << " dolares" << endl
			<< "Nombre: " << nombre << endl
			<< "Modelo: " << modelo << endl
			<< "Caracteristicas: " << caracteristicas << endl;
	}
	else { s << "Bluetooth" << '\t' << nombre << '\t' << modelo << '\t' << caracteristicas << '\t' << precioBase; }
	return s.str();
}

ostream& operator<<(ostream& out, Bluetooth& obj) {
	out << "-----> Bluetooth <-----" << endl
		<< "Precio: " << obj.precioBase << " dolares" << endl
		<< "Nombre: " << obj.nombre << endl
		<< "Modelo: " << obj.modelo << endl
		<< "Caracteristicas: " << obj.caracteristicas << endl;
	return out;
}