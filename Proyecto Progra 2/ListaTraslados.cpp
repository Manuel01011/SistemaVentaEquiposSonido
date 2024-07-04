#include "ListaTraslados.h"

string ListaTraslados::pais(string cod){
    if (cod == "010") { return "Argentina"; }
    if (cod == "020") { return "Brasil"; }
    if (cod == "030") { return "Canadá"; }
    if (cod == "031") { return "EEUU"; }
    if (cod == "032") { return "EEUU"; }
    if (cod == "040") { return "Francia"; }
    if (cod == "050") { return "Inglaterra"; }
    if (cod == "060") { return "Italia"; }
    if (cod == "090") { return "Costa Rica(local)"; }
    if (cod == "091") { return "Costa Rica(local)"; }
    return "";
}

string ListaTraslados::ciudad(string cod){
    if (cod == "010") { return "Buenos Aires"; }
    if (cod == "020") { return "Brasilia"; }
    if (cod == "030") { return "Ontario"; }
    if (cod == "031") { return "California"; }
    if (cod == "032") { return "New York"; }
    if (cod == "040") { return "Paris"; }
    if (cod == "050") { return "Londres"; }
    if (cod == "060") { return "Milan"; }
    if (cod == "090") { return "GAM"; }
    if (cod == "091") { return "Fuera de la GAM"; }
    return "";
}

double ListaTraslados::costo(string cod){
    if (cod == "010") { return 175.00; }
    if (cod == "020") { return 150.00; }
    if (cod == "030") { return 160.00; }
    if (cod == "031") { return 150.00; }
    if (cod == "032") { return 100.00; }
    if (cod == "040") { return 200.00; }
    if (cod == "050") { return 200.00; }
    if (cod == "060") { return 250.00; }
    if (cod == "090") { return 50.00; }
    if (cod == "091") { return 80.00; }
    return 0;
}
