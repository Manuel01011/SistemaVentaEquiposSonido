#include "VentaLinea.h"

VentaEnLinea::VentaEnLinea(string ct, Sistema* sis, Observer* cl) : Venta(sis), comprador(cl), codigoTraslado(ct){}

VentaEnLinea::~VentaEnLinea(){}

void VentaEnLinea::setCodigoTraslado(string ct){codigoTraslado = ct;}

string VentaEnLinea::getCodigoTraslado(){return codigoTraslado;}

void VentaEnLinea::realizarVenta(){//Este metodo se encarga de actualizar la cantidad de ventas y el total de ventas de la empresa luego de que algun cliente haya realizado una compra
    VentasEmpresa& v = VentasEmpresa::instanciar();
    double ventas = 0;
    ventas += sis->getPrecio();
    ventas += ListaTraslados::costo(codigoTraslado);
    v.setCantVentas(1);
    v.setTotalVentas(ventas);
}

string VentaEnLinea::toString(bool arch) {
    stringstream s;
    if (arch) {
        s << "\tComprador:" << endl
            << comprador->toString(true) << endl;
        s << "\tSistma Vendido:" << endl
            << sis->toString() << endl << endl;
        s << "\tInformacion de Traslado:" << endl
            << "Pais: " << ListaTraslados::pais(codigoTraslado) << endl
            << "Ciudad: " << ListaTraslados::ciudad(codigoTraslado) << endl
            << "Costo del Traslado: " << ListaTraslados::costo(codigoTraslado) << " dolares" << endl << endl;
    }
    else{s << "ClienteEnLinea" << '\t' << codigoTraslado << '\t' << comprador->toString(false) << '\t' << sis->informacionSistemaArc(false);}
    return s.str();
}

string VentaEnLinea::venta(){
    stringstream s;
    s << "------------> Factura <--------------" << endl << endl;
    s << "----> Informacion del comprador <----" << endl << endl
        << comprador->toString(true);
    s << "----> Informacion del Sistema <----" << endl << endl;
    s << sis->toString();
    return s.str();
}

ostream& operator<<(ostream& out, VentaEnLinea& obj){
    out << "\tComprador:" << endl
        << obj.comprador << endl << endl;
    out << "\tSistema Vendido:" << endl
        << obj.sis->toString() << endl << endl;
    out << "\tInformacion de Traslado:" << endl
        << "Pais: " << ListaTraslados::pais(obj.codigoTraslado) << endl
        << "Ciudad: " << ListaTraslados::ciudad(obj.codigoTraslado) << endl
        << "Costo del Traslado: " << ListaTraslados::costo(obj.codigoTraslado) << " dolares" << endl << endl;
    return out;
}