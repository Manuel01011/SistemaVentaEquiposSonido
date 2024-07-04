#include "Persona.h"

Persona::Persona(Subject* sub, string nom, string ced, string cor, double pag, string ciu, string pai, string nac) : ClienteEnLinea(sub, nom, ced, cor, pag, ciu, pai), nacionalidad(nac){}

Persona::~Persona(){}

void Persona::setNacionalidad(string nac){nacionalidad = nac;}

string Persona::getNacionalidad(){return nacionalidad;}

void Persona::actualizar(string des){
	cout << "Hola estimado " << nombre << " como usted nos importa "
		<< "le informamos de una nueva actualizacion en nuestro catalogo" << endl << endl;
	cout << des;
}

string Persona::toString(bool arch) {
	stringstream s;
	if (arch) {
		s << "-----> Cliente Persona <-----" << endl
			<< "Nombre: " << nombre << endl
			<< "Cedula: " << cedula << endl
			<< "Correo: " << correo << endl
			<< "Pais: " << pais << endl
			<< "Ciudad: " << ciudad << endl
			<< "Pago suscripcion: " << pagoSub << endl
			<< "Nacionalidad: " << nacionalidad << endl << endl;
	}
	else { s << "Persona" << '\t' << nombre << '\t' << cedula << '\t' << correo << '\t' << pais << '\t' << ciudad << '\t' << pagoSub << '\t' << nacionalidad; }
	return s.str();
}

ostream& operator<<(ostream& out, Persona& obj){
	out << "-----> Cliente Persona <-----" << endl
		<< "Nombre: " << obj.nombre << endl
		<< "Cedula: " << obj.cedula << endl
		<< "Correo: " << obj.correo << endl
		<< "Pais: " << obj.pais << endl
		<< "Ciudad: " << obj.ciudad << endl
		<< "Pago suscripcion: " << obj.pagoSub << endl
		<< "Nacionalidad: " << obj.nacionalidad << endl << endl;
	return out;
}
