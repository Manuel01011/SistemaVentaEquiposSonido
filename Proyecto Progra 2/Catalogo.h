/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef CATALOGO_H
#define CATALOGO_H

#include"Subject.h"
#include"Persona.h"
#include"Empresa.h"

//Clase Catalogo, hereda públicamente de la clase Subject
class Catalogo : public Subject {
private://Atributos de un Catalogo
	ListarGenerica<Sistema>* catalogo;
	ListarGenerica<Observer>* suscriptores;
	string descripcion;
public://Los metodos excepto el constructor se encuentran explicados en el .cpp
	Catalogo();//Constructor
	virtual void notificar();
	void crearMensaje(Sistema*, bool);

	virtual void agregarSub(Observer*);
	virtual void eliminarSub(int);
	virtual string mostrarSubs();
	ClienteEnLinea* retornarSubPos(int);

	bool ExisteCedula(string, bool);
	bool ExisteCorreo(string);
	bool ExisteCodigo(string);

	virtual void ingresaSistema(Sistema*);
	virtual void eliminarSistema(int);
	virtual string mostrarCatalogo();
	Sistema* getsistemaPos(int);

	void quitarSistemaePos(int);

	int getCanTotalSistemas();
	int getCanTotalSubs();
	int getCanTotalDeClientesEmpresa();
	int getCanTotalDeClientesFisicos();

	string getDescripcion();
	void setDescripcion(string);

	ListarGenerica<Sistema>* getCatalogo();
	ListarGenerica<Observer>* getSuscriptores();

	void setCatalogo(ListarGenerica<Sistema>*);
	void setSuscriptores(ListarGenerica<Observer>*);
};
#endif 