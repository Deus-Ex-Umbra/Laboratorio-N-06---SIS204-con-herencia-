#pragma once
#include <string>
#include "Nodo.h"
class Nodo_Asignatura : public Nodo
{
public:
	struct Asignatura {
		std::string codigo, nombre, descripcion;
		int horas;
	}asignatura;
	int cantidad_estudiantes;
	Nodo_Asignatura* siguiente, * anterior;
	class Nodo_Estudiante* siguiente_e;
	Nodo_Asignatura() : siguiente(nullptr), anterior(nullptr), cantidad_estudiantes(0) {}
};

