#include"Sistemas.h"


string Sistemas::toString() {
    stringstream c;
    c << "-------------------------" << endl;
    c << "Caracteristicas: " << caracteristica << endl;
    c << "Precio: " << precio << endl;
    c << "Codigo: " << codigo << endl;
    c << "-------------------------" << endl << endl;
    return c.str();
}

ProcesadorAbst* Sistemas::crearProcesador(int precioB, string caracteristica, string modelo, string nombre)
{

    return new ProcesadorAbst(precioB, caracteristica, modelo, nombre);
   
}

FuenteAbst* Sistemas::crearFuente(int precioB, string caracteristica, string modelo, string nombre)
{
    return new FuenteAbst(precioB, caracteristica, modelo, nombre);
}

ParlanteAbst* Sistemas::crearParlante(int precioB, string caracteristica, string modelo, string nombre)
{
    return new ParlanteAbst(precioB, caracteristica, modelo, nombre);
}
