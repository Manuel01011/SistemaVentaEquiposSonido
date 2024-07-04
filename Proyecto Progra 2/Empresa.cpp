#include "Empresa.h"

Empresa::Empresa(Subject* sub, string nom, string ced, string cor, double pag, string ciu, string pai, bool fre) : ClienteEnLinea(sub, nom, ced, cor, pag, ciu, pai), frecuente(fre){}

Empresa::~Empresa(){}

void Empresa::setFrecuente(bool fre){frecuente = fre;}

bool Empresa::getFrecuente(){return frecuente;}

void Empresa::actualizar(string des){
    cout << "Hola " << nombre << ", como agradecemos su colaboracion con nosotros"
        << " les compartimos una nueva actualizacion de nuestro catalogo" << endl << endl;
    cout << des;
}

string Empresa::toString(bool arch) {
    stringstream s;
    if (arch) {
        s << "-----> Cliente Empresa <-----" << endl
            << "Nombre: " << nombre << endl
            << "Cedula: " << cedula << endl
            << "Pais: " << pais << endl
            << "Ciudad: " << ciudad << endl
            << "Pago suscripcion: " << pagoSub << endl
            << "Cliete frecuente: ";
        if (frecuente) { s << "si" << endl << endl; }
        else { s << "no" << endl << endl; }
    }
    else { s << "Empresa" << '\t' << nombre << '\t' << cedula << '\t' << correo << '\t' << pagoSub << '\t' << ciudad << '\t' << pais << '\t' << frecuente; }
    return s.str();
}

ostream& operator<<(ostream& out, Empresa& obj){
    out << "-----> Cliente Empresa <-----" << endl
        << "Nombre: " << obj.nombre << endl
        << "Cedula: " << obj.cedula << endl
        << "Pais: " << obj.pais << endl
        << "Ciudad: " << obj.ciudad << endl
        << "Pago suscripcion: " << obj.pagoSub << endl
        << "Cliete frecuente: ";
    if (obj.frecuente){out << "si" << endl << endl;}
    else { out << "no" << endl << endl; }
    return out;
}
