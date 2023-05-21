#pragma once
#include <string>
#include "Nodo.h"
class Nodo_Estudiante : public Nodo
{
public:
	struct Estudiante {
		std::string codigo, nombre, direccion, sexo;
		int edad;
	}estudiante;
	Nodo_Estudiante* siguiente, * anterior;
	Nodo_Estudiante() : siguiente(nullptr), anterior(nullptr) {}
};

