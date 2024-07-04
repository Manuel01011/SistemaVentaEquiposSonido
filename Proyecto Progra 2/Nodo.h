/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef NODO_H
#define NODO_H

#include<iostream>
#include<sstream>

using namespace std;

template<class T>
class NodoGenerico {
private:
	T* objeto;
	NodoGenerico<T>* siguiente;
public:
	NodoGenerico(T* = nullptr, NodoGenerico<T>* = nullptr);

	virtual ~NodoGenerico();

	void setObj(T*);
	void setSig(NodoGenerico<T>*);
	T* getObj();
	NodoGenerico<T>* getSig();
};

template<class T>
inline NodoGenerico<T>::NodoGenerico(T* o, NodoGenerico<T>* s) : objeto(o), siguiente(s) {

}

template<class T>
inline NodoGenerico<T>::~NodoGenerico() {
	if (objeto != nullptr) {

		delete objeto;
	}
}

template<class T>
inline void NodoGenerico<T>::setObj(T* o) {
	objeto = o;
}

template<class T>
inline void NodoGenerico<T>::setSig(NodoGenerico<T>* s) {
	siguiente = s;
}

template<class T>
inline T* NodoGenerico<T>::getObj()
{
	return objeto;
}

template<class T>
inline NodoGenerico<T>* NodoGenerico<T>::getSig() {
	return siguiente;
}
#endif