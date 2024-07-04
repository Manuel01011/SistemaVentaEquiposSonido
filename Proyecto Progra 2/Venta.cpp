#include "Venta.h"

Venta::Venta(Sistema* s) : sis(s){}

Venta::~Venta(){}

Sistema* Venta::getSistema(){return sis;}

string Venta::listaCodigos(){
    stringstream s;
    s << "-----> Informacion del Costo de Traslado de los Sistemas <-----" << endl << endl
        << " Codigo: 010 - Pais: Argentina  - Ciudad: Buenos Aires   - Costo: 175.00 dolares" << endl
        << " Codigo: 020 - Pais: Brasil     - Ciudad: Brasilia       - Costo: 150.00 dolares" << endl
        << " Codigo: 030 - Pais: Canada     - Ciudad: Ontario        - Costo: 160.00 dolares" << endl
        << " Codigo: 031 - Pais: EEUU       - Ciudad: California     - Costo: 150.00 dolares" << endl
        << " Codigo: 032 - Pais: EEUU       - Ciudad: New York       - Costo: 100.00 dolares" << endl
        << " Codigo: 040 - Pais: Francia    - Ciudad: Paris          - Costo: 200.00 dolares" << endl
        << " Codigo: 050 - Pais: Inglaterra - Ciudad: Londres        - Costo: 200.00 dolares" << endl
        << " Codigo: 060 - Pais: Italia     - Ciudad: Milan          - Costo: 250.00 dolares" << endl
        << " Codigo: 090 - Pais: Costa Rica - Ciudad: GAM            - Costo:  50.00 dolares" << endl
        << " Codigo: 091 - Pais: Costa Rica - Ciudad: Fuera de la GAM  - Costo:  80.00 dolares" << endl << endl;
    return s.str();
}

ostream& operator<<(ostream& out, Venta& v){
    out << "";
    return out;
}
