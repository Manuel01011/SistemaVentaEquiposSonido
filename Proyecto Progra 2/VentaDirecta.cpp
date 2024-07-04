#include "VentaDirecta.h"

VentaDirecta::VentaDirecta(Sistema* sis, ClienteFisico* cl) : Venta(sis), comprador(cl){}

VentaDirecta::~VentaDirecta(){}

void VentaDirecta::realizarVenta(){//Este metodo se encarga de actualizar la cantidad de ventas y el total de ventas de la empresa luego de que algun cliente haya realizado una compra
    VentasEmpresa& v = VentasEmpresa::instanciar();
    double ventas = 0;
    int cantVendido = 1;
    ventas += sis->getPrecio();
    v.setCantVentas(cantVendido);
    v.setTotalVentas(ventas);
}

string VentaDirecta::toString(bool arch) {
    stringstream s;
    if (arch) {
        s << "\tComprador:" << endl
            << comprador->toString(true) << endl << endl;
        s << "\tSistema Vendido:" << endl
            << sis << endl << endl;
    }
    else
    {
        s << "ClienteFisico" << '\t' << comprador->toString(false) << '\t' << sis->informacionSistemaArc(false);
    }

    return s.str();
}

string VentaDirecta::venta(){
    stringstream s;
    s << "------------> Factura <--------------" << endl << endl;
    s << "----> Informacion del comprador <----" << endl << endl
        << comprador->toString(true) << endl;
    s << "----> Informacion del Sistema <----" << endl << endl;
    s << sis->toString();
    return s.str();
}

ostream& operator<<(ostream& out, VentaDirecta& obj){
    out << "\tComprador:" << endl
        << obj.comprador << endl << endl;
    out << "\tSistema Vendido:" << endl
        << obj.sis << endl << endl;
    return out;
}
