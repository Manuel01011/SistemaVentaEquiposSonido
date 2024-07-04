/* --------------------------------------------------------------------
* EIF204 Programación 2
*
* Proyecto de programación #2
*
* 1-1915-0694|Manuel Mora Sandi|Grupo 06
* 1-1851-0810|Felipe Herrera Granados|Grupo 06
* 2-0854-0298|Anthony Li Perera|Grupo 06
* -------------------------------------------------------------------*/

#ifndef LISTA_H
#define LISTA_H

#pragma once
#include"Nodo.h"

template <class T>
class ListarGenerica {
private:
	NodoGenerico<T>* punteroPrimero;
	NodoGenerico<T>* actual;
	int k;
public:
	ListarGenerica();
	virtual ~ListarGenerica();

	bool estaLLena();
	void incializarPrincio();
	T& recuperar();

	void insertarInicio(const T&);
	
	bool eliminarPrimero();
	bool eliminarUltimo();
	bool eliminarLugar(int);

	bool quitarPrimerObjeto();
	bool quitarObjetoLugar(int);

	T* retonarObjetoLugar(int);
	T* retornarObjetoActual();
	



	void setActual(NodoGenerico<T>*);
	NodoGenerico<T>* getActual();
	int getK();
	string toString(bool);
	string toString2();
	bool operator == (const ListarGenerica& c) {
		return (this->punteroPrimero == c.punteroPrimero && this->k == c.k);
	}

	friend ostream& operator << (ostream& sal, const ListarGenerica& c) {
		NodoGenerico<T>* act = c.punteroPrimero;
		int i = 1;
		while (act != nullptr) {
			sal << "Sistema# " << i++ << "\n" << *act->getObj()
				<< "-------------------------------------" << endl << endl;

			act = act->getSig();
		}
		return sal;
	}
};

template<class T>
inline string ListarGenerica<T>::toString(bool arch) {
	stringstream c;

	NodoGenerico<T>* aux = punteroPrimero;

	while (aux) {
		for (int i = 0; i < k; i++){
			c << "----Catalogo----" << endl << endl;
			c << "\tSistema No: " << i+1 << endl;
			c << aux->getObj()->toString(arch);
			aux = aux->getSig();
		}
		
	}
	return c.str();
}
template<class T>
inline string ListarGenerica<T>::toString2() {
	stringstream c;

	NodoGenerico<T>* aux = punteroPrimero;

	while (aux) {
		for (int i = 0; i < k; i++){
			c << "----Catalogo----" << endl << endl;
			c << "\tSistema No: " << i+1 << endl;
			c << aux->getObj()->toString();
			aux = aux->getSig();
		}
		
	}
	return c.str();
}

template<class T>
inline ListarGenerica<T>::ListarGenerica() {
	punteroPrimero = nullptr;
	actual = nullptr;
	k = 0;
}

template<class T>
inline ListarGenerica<T>::~ListarGenerica() {
	NodoGenerico<T>* aux;
	while (punteroPrimero != nullptr) {
		aux = punteroPrimero;
		punteroPrimero = punteroPrimero->getSig();
		delete aux;
	}
}

template<class T>
inline bool ListarGenerica<T>::estaLLena() {
	if (punteroPrimero == nullptr) {
		return true;
	}
	return false;
}

template<class T>
inline void ListarGenerica<T>::incializarPrincio() {
	actual = punteroPrimero;
}

template<class T>
inline T& ListarGenerica<T>::recuperar() {
	T& objeto = *actual->getObj();
	actual = actual->getSig();
	return objeto;
}

template<class T>
inline void ListarGenerica<T>::insertarInicio(const T& o) {
	punteroPrimero = new NodoGenerico<T>((T*)&o, punteroPrimero);
	k++;
}

template<class T>
inline bool ListarGenerica<T>::eliminarPrimero() {
	NodoGenerico<T>* p = punteroPrimero;
	if (punteroPrimero != nullptr) {
		punteroPrimero = punteroPrimero->getSig();
		delete p;
		k--;
		return true;
	}
	else {
		return false;
	}
}

template<class T>
inline bool ListarGenerica<T>::eliminarUltimo() {
	if (punteroPrimero->getSig() == nullptr) {
		return eliminarPrimero();
	}
	else {
		NodoGenerico<T>* p = punteroPrimero;
		while (p->getSig() != nullptr) {
			p = p->getSig();
		}
		delete p;
		k--;
		return true;
	}
}

template<class T>
inline bool ListarGenerica<T>::eliminarLugar(int lug) {
	lug--;
	NodoGenerico<T>* aux = punteroPrimero;
	NodoGenerico<T>* aux2 = nullptr;
	int can = 0;

	if (lug == 0) {
		return eliminarPrimero();
	}
	else {
		while (aux != nullptr) {
			if (can == lug) {
				aux2->setSig(aux->getSig());
				delete aux;
				k--;
				return true;
			}
			can++;
			aux2 = aux;
			aux = aux->getSig();
		}
	}

	return false;
}

template<class T>
inline bool ListarGenerica<T>::quitarPrimerObjeto()
{
	NodoGenerico<T>* p = punteroPrimero;
	if (punteroPrimero != nullptr) {
		punteroPrimero = punteroPrimero->getSig();
		p = nullptr;
		k--;
		return true;
	}
	else {
		return false;
	}
}

template<class T>
inline bool ListarGenerica<T>::quitarObjetoLugar(int lug)
{
	lug--;
	NodoGenerico<T>* aux = punteroPrimero;
	NodoGenerico<T>* aux2 = nullptr;
	int can = 0;

	if (lug == 0) {
		return quitarPrimerObjeto();
	}
	else {
		while (aux != nullptr) {
			if (can == lug) {
				aux2->setSig(aux->getSig());
				aux = nullptr;
				k--;
				return true;
			}
			can++;
			aux2 = aux;
			aux = aux->getSig();
		}
	}

	return false;
}

template<class T>
inline T* ListarGenerica<T>::retonarObjetoLugar(int lug) {
	lug--;
	NodoGenerico<T>* aux = punteroPrimero;
	int can = 0;

	if (lug == 0) {
		return aux->getObj();
	}
	else {
		while (aux != nullptr) {
			if (can == lug) {
				return aux->getObj();
			}
			can++;
			aux = aux->getSig();
		}
	}
	return nullptr;
}

template<class T>
inline T* ListarGenerica<T>::retornarObjetoActual() {
	return actual->getObj();
}

template<class T>
inline void ListarGenerica<T>::setActual(NodoGenerico<T>* a) {
	actual = a;
}

template<class T>
inline NodoGenerico<T>* ListarGenerica<T>::getActual() {
	return actual;
}

template<class T>
inline int ListarGenerica<T>::getK() {
	return k;
}
#endif 