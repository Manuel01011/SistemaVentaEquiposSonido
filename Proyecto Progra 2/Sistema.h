/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef SISTEMA_H
#define SISTEMA_H

#include<iostream>
#include<sstream>
#include "FuenteAbst.h"
#include "ProcesadorAbst.h"
#include "ParlanteAbst.h"
#include "UnidadCD.h"
#include "Tornamesa.h"
#include "Radio.h"
#include "Bluetooth.h"
#include "Microfono.h"
#include "Amplificador.h"
#include "Mezclador.h"
#include "Parlante.h"
#include "Audifono.h"


class Sistema {
private://Atributos necesarios de un sistema
    FuenteAbst* fuentePtr;
    ParlanteAbst* parlantePtr;
    ProcesadorAbst* procesadorPtr;

    double precio;
    string tipo;
    string codigo;
    int cantidad;
public:
    Sistema(FuenteAbst*, ParlanteAbst*, ProcesadorAbst*, double, string, string, int);//Constructor
    virtual ~Sistema();//Destructor

    //Gets de los atributos de un sistema
    virtual double getPrecio();
    virtual string getTipo();
    virtual string getCodigo();
    virtual int getCantidad();
    virtual FuenteAbst* getFuente();
    virtual ParlanteAbst* getParlante();
    virtual ProcesadorAbst* getProcesador(); 

    virtual void agregarCantidad(int);//Metodo para cambiar el atributo cantidad de sistema

    virtual string toString();

    string informacionSistemaArc(bool);//Metodo utilizado para los archivos

    friend ostream& operator << (ostream&, const Sistema&);//Sobrecarga del operador de inserción
};
#endif 