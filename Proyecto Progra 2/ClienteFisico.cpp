#include "ClienteFisico.h"

ClienteFisico::ClienteFisico(string nom, string ced) : nombre(nom), cedula(ced){}

ClienteFisico::~ClienteFisico() {}

string ClienteFisico::toString(bool arch) {
	stringstream s;
	if (arch) {
		s << "-----> Cliente Fisico <-----" << endl
			<< "Nombre: " << nombre << endl
			<< "Cedula: " << cedula << endl;
	}
	else { s << "ClienteFisico" << '\t' << nombre << '\t' << cedula; }
	return s.str();
}

ostream& operator<<(ostream& out, const ClienteFisico& obj) {
	out << "-----> Cliente Fisico <-----" << endl
		<< "Nombre: " << obj.nombre << endl
		<< "Cedula: " << obj.cedula << endl;
	return out;
}