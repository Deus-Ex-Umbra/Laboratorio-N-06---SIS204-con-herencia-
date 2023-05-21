#pragma once
#include <string>
#include "Nodo.h"
class Lista
{
protected:
	Nodo* nodo_inicial;
	virtual Nodo* buscar(int _posicion = 0, std::string _codigo = "", Nodo* nodo_c = nullptr) = 0;
	virtual bool encontrar(Nodo* nodo_c = nullptr) = 0;
public:
	Lista() : nodo_inicial(nullptr) {}
	virtual void insertar(int _posicion, Nodo* nodo_c = nullptr ) = 0;
	virtual void eliminar(std::string _codigo, Nodo* nodo_c = nullptr) = 0;
	virtual void mostrar(Nodo* nodo_c = nullptr) = 0;
	virtual bool vacia(Nodo* nodo_c = nullptr) = 0;
};

