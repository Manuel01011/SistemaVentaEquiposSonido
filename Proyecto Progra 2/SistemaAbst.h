#ifndef SISTEMAABST_H
#define SISTEMAABST_H
#include "Sistemas.h"
#include "FuenteAbst.h"
#include "ProcesadorAbst.h"
#include "ParlanteAbst.h"

class SistemaAbst{

protected:
	FuenteAbst* fuentePtr;
	ParlanteAbst* parlantePtr;
	ProcesadorAbst* procesadorPtr;


	int precio;
	string tipo;
	string codigo;
	int cantidad;

public:
	
	SistemaAbst(FuenteAbst*, ParlanteAbst* , ProcesadorAbst* , int, string , string , int );
	virtual ~SistemaAbst();

	virtual int getPrecio();
	virtual string getTipo();
	
	virtual int getCantidad();
	virtual void setCantidad(int);
	virtual FuenteAbst* getFuente();
	virtual ParlanteAbst* getParlante();
	virtual ProcesadorAbst* getProcesador();
	virtual void establecerPrecio();
	virtual void agregarCantidad(int);
	virtual FuenteAbst* crearFuente(int, string, string, string) = 0;
	virtual ParlanteAbst* crearParlante(int, string, string, string);
	virtual ProcesadorAbst* crearProcesador(int, string, string, string);
	virtual string toString();
	friend ostream& operator << (ostream&, const SistemaAbst&);

};

#endif // !SISTEMAABST_H