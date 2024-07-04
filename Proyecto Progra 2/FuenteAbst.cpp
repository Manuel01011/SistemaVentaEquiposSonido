#include "FuenteAbst.h"

FuenteAbst::FuenteAbst(double prec, string nom, string mod, string carac) : caracteristicas(carac), modelo(mod), nombre(nom), precioBase(prec) {}

FuenteAbst::~FuenteAbst() {}

string FuenteAbst::getNombre() {return nombre;}
string FuenteAbst::getCaracteristicas() {return caracteristicas;}
string FuenteAbst::getModelo() {return modelo;}
double FuenteAbst::getPrecio() {return precioBase;}