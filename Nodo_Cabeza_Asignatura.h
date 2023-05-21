#pragma once
#include "Nodo.h"
class Nodo_Cabeza_Asignatura : public Nodo{
public:
	int cantidad_asignaturas;
	class Nodo_Asignatura* siguiente_a;
	Nodo_Cabeza_Asignatura() : siguiente_a(nullptr), cantidad_asignaturas(0) {}
};


