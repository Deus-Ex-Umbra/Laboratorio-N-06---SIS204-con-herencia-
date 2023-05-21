#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include "Lista.h"
#include "Nodo_Asignatura.h"
#include "Nodo_Estudiante.h"
class Lista_Estudiantes : public Lista
{
private:
	Nodo_Estudiante* nodo_inicial;
	virtual Nodo_Estudiante* buscar(int _posicion = 0, std::string _codigo = " ", Nodo* nodo_c = nullptr) override {
		int indice = 1;
		while ((static_cast<Nodo_Estudiante*>(nodo_c) != nullptr) && (static_cast<Nodo_Estudiante*>(nodo_c)->estudiante.codigo != _codigo) && (indice != _posicion - 1)) {
			nodo_c = static_cast<Nodo_Estudiante*>(nodo_c)->siguiente;
			indice++;
		}
		return static_cast<Nodo_Estudiante*>(nodo_c);
	}
	virtual bool encontrar(Nodo* nodo_c) override { return (static_cast<Nodo_Estudiante*>(nodo_c) != nullptr); }
public:
	Lista_Estudiantes() : nodo_inicial(nullptr) {}
	Lista_Estudiantes(Nodo_Asignatura* nodo_c) : nodo_inicial(nullptr) { nodo_c->siguiente_e = nodo_inicial; }
	virtual void insertar(int _posicion, Nodo* nodo_c = nullptr) override {
		nodo_inicial = static_cast<Nodo_Asignatura*>(nodo_c)->siguiente_e;
		Nodo_Estudiante* nodo_nuevo = new Nodo_Estudiante();
		Nodo_Estudiante* nodo_actual = nodo_inicial;
		std::cout << "Ingrese el codigo del estudiante: "; std::getline(std::cin, nodo_nuevo->estudiante.codigo);
		std::cout << "Ingrese el nombre del estudiante: "; std::getline(std::cin, nodo_nuevo->estudiante.nombre);
		std::cout << "Ingrese la direccion del estudiante: "; std::getline(std::cin, nodo_nuevo->estudiante.direccion);
		do {
			std::cout << "Ingrese el sexo del estudiante: "; std::getline(std::cin, nodo_nuevo->estudiante.sexo); std::cin.ignore(' ');
			std::transform(nodo_nuevo->estudiante.sexo.begin(), nodo_nuevo->estudiante.sexo.end(), nodo_nuevo->estudiante.sexo.begin(), ::tolower);
		} while (nodo_nuevo->estudiante.sexo != "masculino" || nodo_nuevo->estudiante.sexo != "femenino");
		std::cout << "Ingrese la edad del estudiante: "; 
		while (!(std::cin >> nodo_nuevo->estudiante.edad) || nodo_nuevo->estudiante.edad < 0 || nodo_nuevo->estudiante.edad > 125) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ingrese la edad correcta del estudiante: ";
		}
		if (vacia(nodo_c) || _posicion == 1) {
			static_cast<Nodo_Asignatura*>(nodo_c)->siguiente_e = nodo_inicial;
			nodo_nuevo->siguiente = (!vacia(nodo_c)) ? nodo_actual : nullptr;
			if (nodo_nuevo->siguiente != nullptr) { nodo_actual->anterior = nodo_nuevo; }
			nodo_nuevo->anterior = nullptr;
			nodo_inicial = nodo_nuevo;
			static_cast<Nodo_Asignatura*>(nodo_c)->siguiente_e = nodo_nuevo;
		} else {
			nodo_actual = buscar(_posicion, "", nodo_c);
			nodo_nuevo->siguiente = nodo_actual->siguiente;
			if (nodo_actual->siguiente != nullptr) { nodo_actual->siguiente->anterior = nodo_nuevo; }
			nodo_nuevo->anterior = nodo_actual;
			nodo_actual->siguiente = nodo_nuevo;
		}
		std::cout << "--------------------------------------------------------------------\n";
		static_cast<Nodo_Asignatura*>(nodo_c)->cantidad_estudiantes++;
	}
	virtual void eliminar(std::string _codigo, Nodo* nodo_c) override {
		nodo_inicial = static_cast<Nodo_Asignatura*>(nodo_c)->siguiente_e;
		Nodo_Estudiante* nodo_eliminar = nodo_inicial;
		nodo_eliminar = buscar(0, _codigo, nodo_eliminar);
		if (encontrar(nodo_eliminar)) {
			if (nodo_eliminar->anterior != nullptr) { nodo_eliminar->anterior->siguiente = nodo_eliminar->siguiente; }
			if (nodo_eliminar->siguiente != nullptr) { nodo_eliminar->siguiente->anterior = nodo_eliminar->anterior; }
			if (nodo_eliminar == nodo_inicial) { nodo_inicial = nodo_eliminar->siguiente; static_cast<Nodo_Asignatura*>(nodo_c)->siguiente_e = nodo_inicial; }
			delete nodo_eliminar;
			if (vacia(nodo_c)) { static_cast<Nodo_Asignatura*>(nodo_c)->siguiente_e = nullptr; nodo_inicial = nullptr; }
			std::cout << "Se ha eliminado correctamente la asignatura.\n";
			std::cout << "--------------------------------------------------------------------\n";
			static_cast<Nodo_Asignatura*>(nodo_c)->cantidad_estudiantes--;
		} else {
			std::cout << "No se encontró el Estudiante con el código " << _codigo << "\n";
		}
	}
	virtual void mostrar(Nodo* nodo_c) override {
		Nodo_Estudiante* nodo_actual = nodo_inicial;
		int indice = 0;
		std::cout << "Cantidad de estudiantes: " << cantidad_estudiantes(nodo_c) << "\n";
		std::cout << "--------------------------------------------------------------------\n";
		while (nodo_actual != nullptr) {
			std::cout << "Estudiante N°" << indice++ << "\n";
			std::cout << "--------------------------------------------------------------------\n";
			std::cout << "Codigo: " << nodo_actual->estudiante.codigo << "\n";
			std::cout << "Nombre: " << nodo_actual->estudiante.nombre << "\n";
			std::cout << "Direccion: " << nodo_actual->estudiante.direccion << "\n";
			std::cout << "Sexo: " << nodo_actual->estudiante.sexo << "\n";
			std::cout << "Edad: " << nodo_actual->estudiante.edad << "\n";
			std::cout << "--------------------------------------------------------------------\n";
			std::cout << "--------------------------------------------------------------------\n";
			nodo_actual = nodo_actual->siguiente;
		}
	}
	virtual bool vacia(Nodo* nodo_c) override { return (static_cast<Nodo_Asignatura*>(nodo_c)->cantidad_estudiantes == 0); }
	void mostrar_masculinos(Nodo* nodo_c) {
		Nodo_Estudiante* nodo_actual = nodo_inicial;
		std::cout << "Cantidad de estudiantes: " << cantidad_estudiantes(nodo_c) << "\n";
		std::cout << "--------------------------------------------------------------------\n";
		while (nodo_actual != nullptr) {
			if (nodo_actual->estudiante.sexo == "masculino") {
				std::cout << "Codigo: " << nodo_actual->estudiante.codigo << "\n";
				std::cout << "Nombre: " << nodo_actual->estudiante.nombre << "\n";
				std::cout << "Direccion: " << nodo_actual->estudiante.direccion << "\n";
				std::cout << "Sexo: " << nodo_actual->estudiante.sexo << "\n";
				std::cout << "Edad: " << nodo_actual->estudiante.edad << "\n";
				std::cout << "--------------------------------------------------------------------\n";
				std::cout << "--------------------------------------------------------------------\n";
			}
			nodo_actual = nodo_actual->siguiente;
		}	
	}
	void mostrar_femeninos(Nodo* nodo_c) {
		Nodo_Estudiante* nodo_actual = nodo_inicial;
		std::cout << "Cantidad de estudiantes: " << cantidad_estudiantes(nodo_c) << "\n";
		std::cout << "--------------------------------------------------------------------\n";
		while (nodo_actual != nullptr) {
			if (nodo_actual->estudiante.sexo == "femenino") {
				std::cout << "Codigo: " << nodo_actual->estudiante.codigo << "\n";
				std::cout << "Nombre: " << nodo_actual->estudiante.nombre << "\n";
				std::cout << "Direccion: " << nodo_actual->estudiante.direccion << "\n";
				std::cout << "Sexo: " << nodo_actual->estudiante.sexo << "\n";
				std::cout << "Edad: " << nodo_actual->estudiante.edad << "\n";
				std::cout << "--------------------------------------------------------------------\n";
				std::cout << "--------------------------------------------------------------------\n";
			}
			nodo_actual = nodo_actual->siguiente;
		}
	}
	int cantidad_estudiantes(Nodo* nodo_c) { return (static_cast<Nodo_Asignatura*>(nodo_c)->cantidad_estudiantes); }
	void eliminar_todo(Nodo* nodo_c) {
		Nodo_Estudiante* nodo_eliminar = nodo_inicial;
		while (nodo_eliminar != nullptr) {
			nodo_inicial = nodo_eliminar->siguiente;
			delete nodo_eliminar;
			nodo_eliminar = nodo_inicial;
		}
		static_cast<Nodo_Asignatura*>(nodo_c)->cantidad_estudiantes = 0;
	}
};

