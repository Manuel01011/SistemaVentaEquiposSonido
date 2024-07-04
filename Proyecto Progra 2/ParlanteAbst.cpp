#include "ParlanteAbst.h"

ParlanteAbst::ParlanteAbst(double prec, string nom, string mod, string carac) : caracteristicas(carac), modelo(mod), nombre(nom), precioBase(prec) {}

ParlanteAbst::~ParlanteAbst() {}

string ParlanteAbst::getNombre() { return nombre; }
string ParlanteAbst::getCaracteristicas() { return caracteristicas; }
string ParlanteAbst::getModelo() { return modelo; }
double ParlanteAbst::getPrecio() { return precioBase; }
