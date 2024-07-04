#include "ClienteLinea.h"

ClienteEnLinea::ClienteEnLinea(Subject* sub, string nom, string ced, string cor, double pag, string ciu, string pai) : Observer(sub), nombre(nom), cedula(ced), correo(cor), pagoSub(pag), ciudad(ciu), pais(pai) {}

ClienteEnLinea::~ClienteEnLinea() {}

void ClienteEnLinea::setNombre(string n) {nombre = n;}

void ClienteEnLinea::setCedula(string c) {cedula = c;}

void ClienteEnLinea::setCorreo(string cor) {correo = cor;}

void ClienteEnLinea::setCiudad(string ciu) {ciudad = ciu;}

void ClienteEnLinea::setPais(string pai) {pais = pai;}

void ClienteEnLinea::setPagoSub(double pagS) {pagoSub = pagS;}

string ClienteEnLinea::getNombre() {return nombre;}

string ClienteEnLinea::getCedula() {return cedula;}

string ClienteEnLinea::getCorreo() {return correo;}

string ClienteEnLinea::getCiudad() {return ciudad;}

string ClienteEnLinea::getPais() {return pais;}

double ClienteEnLinea::getPagoSub() {return pagoSub;}

ostream& operator<<(ostream& out, const ClienteEnLinea& obj) {
    out << " ";
    return out;
}