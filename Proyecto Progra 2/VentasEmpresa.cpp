#include "VentasEmpresa.h"

VentasEmpresa* VentasEmpresa::instancia = nullptr;

VentasEmpresa::VentasEmpresa(){
    cantVentas = 0;
    totalVentas = 0;
}

VentasEmpresa::~VentasEmpresa(){}

VentasEmpresa& VentasEmpresa::instanciar(){
    if (!instancia){
        instancia = new VentasEmpresa();
        atexit(destruir);
    }
    return *instancia;
}

void VentasEmpresa::destruir(){
    if (instancia != nullptr){delete instancia;}
}

void VentasEmpresa::setCantVentas(int cv){cantVentas += cv;}

void VentasEmpresa::setTotalVentas(double tv){totalVentas += tv;}

int VentasEmpresa::getCantVentas(){return cantVentas;}

double VentasEmpresa::getTotalVentas(){return totalVentas;}

string VentasEmpresa::cantVentasGanancia(){
    stringstream s;
    s << "Total de ventas realizadas : " << cantVentas << endl;
    s << "Ganancia de las ventas totales: " << totalVentas << " dolares" << endl;
    return s.str();
}

string VentasEmpresa::guardarDatos(){
    stringstream s;
    s << totalVentas << '\t' << cantVentas;
    return s.str();
}

string VentasEmpresa::toString(){
    stringstream s;
    s << "Cantidad de unidades vendidas: " << cantVentas << endl
        << "Total de ventas: " << totalVentas << endl << endl;
    return s.str();
}
