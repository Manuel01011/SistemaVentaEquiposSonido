#ifndef SISTEMAS_H
#define SISTEMAS_H
#include<iostream>
#include<sstream>
#include "FuenteAbst.h"
#include "ProcesadorAbst.h"
#include "ParlanteAbst.h"


using namespace std;

class Sistemas {
public:

   
    static string toString();

    static ProcesadorAbst* crearProcesador(int, string, string, string);
    static FuenteAbst* crearFuente(int, string, string, string);
    static ParlanteAbst* crearParlante(int, string, string, string);


private:

    static bool caracteristica;
    static double precio;
    static string codigo;
    static string nombre;

};

#endif


