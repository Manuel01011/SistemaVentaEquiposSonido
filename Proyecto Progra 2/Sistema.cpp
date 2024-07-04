#include "Sistema.h"

Sistema::Sistema(FuenteAbst* fPtr, ParlanteAbst* pPtr, ProcesadorAbst* proPtr, double pre, string tip, string cod, int can) : fuentePtr(fPtr), parlantePtr(pPtr), procesadorPtr(proPtr), precio(pre), tipo(tip), codigo(cod), cantidad(can){}

Sistema::~Sistema(){
    if (fuentePtr != nullptr) {delete fuentePtr;}
    if (parlantePtr != nullptr) {delete parlantePtr;}
    if (procesadorPtr != nullptr) {delete procesadorPtr;}
}

double Sistema::getPrecio(){return precio;}

string Sistema::getTipo() {return tipo;}

string Sistema::getCodigo(){return codigo;}

int Sistema::getCantidad(){return cantidad;}

FuenteAbst* Sistema::getFuente(){return fuentePtr;}

ParlanteAbst* Sistema::getParlante(){return parlantePtr;}

ProcesadorAbst* Sistema::getProcesador(){return procesadorPtr;}

void Sistema::agregarCantidad(int cant){cantidad += cant;}

string Sistema::toString(){
    stringstream s;
    s << "Sistema: " << endl;
    s << "Precio: " << precio << endl;
    s << "Codigo: " << codigo << endl;
    s << "Cantidad: " << cantidad << endl;
    s << procesadorPtr->toString(true) << endl;
    s << fuentePtr->toString(true) << endl;
    s << parlantePtr->toString(true) << endl;
    return s.str();
}

string Sistema::informacionSistemaArc(bool arch){
    stringstream s;
    if (arch) {
        s << "-----> Sistema <-----" << endl;
        s << "Precio: " << precio << " dolares" << endl;
        s << "Codigo: " << codigo << endl;
        s << "Cantidad: " << cantidad << endl;
        s << procesadorPtr->toString(true) << endl;
        s << fuentePtr->toString(true) << endl;
        s << parlantePtr->toString(true) << endl;
    }
    else {s << codigo << '\t' << precio << '\t' << fuentePtr->toString(false) << '\t' << procesadorPtr->toString(false) << '\t' << parlantePtr->toString(false) << '\t' << cantidad;}
    return s.str();
}

ostream& operator<<(ostream& out, const Sistema& obj){
    out << "-----> Sistema <-----" << endl;
    out << "Precio: " << obj.precio << " dolares" << endl;
    out << "Codigo: " << obj.codigo << endl;
    out << "Cantidad: " << obj.cantidad << endl;
    out << obj.procesadorPtr->toString(true) << endl;
    out << obj.fuentePtr->toString(true) << endl;
    out << obj.parlantePtr->toString(true) << endl;
    return out;
}
