#include "ProcesadorAbst.h"

ProcesadorAbst::ProcesadorAbst(double prec, string nom, string mod, string carac) : caracteristicas(carac), modelo(mod), nombre(nom), precioBase(prec) {}

ProcesadorAbst::~ProcesadorAbst() {}

string ProcesadorAbst::getNombre() { return nombre; }
string ProcesadorAbst::getCaracteristicas() { return caracteristicas; }
string ProcesadorAbst::getModelo() { return modelo; }
double ProcesadorAbst::getPrecio() { return precioBase; }
