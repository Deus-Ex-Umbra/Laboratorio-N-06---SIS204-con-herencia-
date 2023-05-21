#pragma once
#include <iostream>
#include <string>
#include "Lista.h"
#include "Lista_Estudiantes.h"
#include "Nodo_Cabeza_Asignatura.h"
#include "Nodo_Asignatura.h"
class Lista_Asignaturas : public Lista
{
private:
	Nodo_Asignatura* nodo_inicial;
	Nodo_Cabeza_Asignatura* nodo_cabeza;
	Lista_Estudiantes lista_estudiantes;
	std::string codigo;
	int posicion;
	virtual Nodo_Asignatura* buscar(int _posicion = 0, std::string _codigo = "", Nodo* nodo_c = nullptr) override {
		Nodo_Asignatura* nodo_actual = static_cast<Nodo_Asignatura*>(nodo_c);
		int indice = 1;
		while (nodo_actual != nullptr && nodo_actual->asignatura.codigo != _codigo && indice != _posicion + 1) { 
			nodo_actual = nodo_actual->siguiente;
			indice++;
		}
		return static_cast<Nodo_Asignatura*>(nodo_c);
	}
	virtual bool encontrar(Nodo* nodo_c = nullptr) override { return (static_cast<Nodo_Asignatura*>(nodo_c) != nullptr); }
public:
	Lista_Asignaturas() : nodo_inicial(new Nodo_Asignatura()), nodo_cabeza(new Nodo_Cabeza_Asignatura()) {} // Constructor es lo mismo que la función «iniciar()»
	virtual void insertar(int _posicion, Nodo* nodo_c = nullptr) override {
		Nodo_Asignatura* nodo_nuevo = new Nodo_Asignatura();
		Nodo_Asignatura* nodo_actual = nodo_inicial;
		std::cout << "Ingrese el Código de la Asignatura: "; std::getline(std::cin, nodo_nuevo->asignatura.codigo);
		std::cout << "Ingrese el Nombre de la Asignatura: "; std::getline(std::cin, nodo_nuevo->asignatura.nombre);
		std::cout << "Ingrese la Descripción de la Asignatura: "; std::getline(std::cin, nodo_nuevo->asignatura.descripcion);
		std::cout << "Ingrese la Cantidad de Horas de la Asignatura: ";
		while (!(std::cin >> nodo_nuevo->asignatura.horas) || nodo_nuevo->asignatura.horas <= 0) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ingrese la cantidad de horas correcta de la Asignatura: ";
		}
		if (vacia() || _posicion == 1) {
			nodo_nuevo->siguiente_e = nullptr;
			nodo_nuevo->siguiente = (!vacia()) ? nodo_actual : nullptr;
			if (nodo_nuevo->siguiente != nullptr) { nodo_actual->anterior = nodo_nuevo; }
			nodo_nuevo->anterior = nullptr;
			nodo_inicial = nodo_nuevo;
			nodo_cabeza->siguiente_a = nodo_nuevo;
		} else {
			nodo_actual = buscar(_posicion, "", nodo_nuevo);
			nodo_nuevo->siguiente_e = nullptr;
			nodo_nuevo->siguiente = nodo_actual->siguiente;
			if (nodo_actual->siguiente != nullptr) { nodo_actual->siguiente->anterior = nodo_nuevo; }
			nodo_nuevo->anterior = nodo_actual;
			nodo_actual->siguiente = nodo_nuevo;
		}
		std::cout << "--------------------------------------------------------------------\n";
		nodo_cabeza->cantidad_asignaturas++;
	}
	virtual void eliminar(std::string _codigo, Nodo* nodo_c = nullptr) override {
		Nodo_Asignatura* nodo_eliminar = nodo_inicial;
		nodo_eliminar = buscar(0, _codigo, nodo_eliminar);
		if (encontrar(nodo_eliminar)) {
			lista_estudiantes.eliminar_todo(nodo_eliminar);
			if (nodo_eliminar->siguiente != nullptr) { nodo_eliminar->siguiente->anterior = nodo_eliminar->anterior; }
			if (nodo_eliminar->anterior != nullptr) { nodo_eliminar->anterior->siguiente = nodo_eliminar->siguiente; }
			if (nodo_eliminar == nodo_inicial) { nodo_inicial = nodo_eliminar->siguiente; nodo_cabeza->siguiente_a = nodo_inicial; }
			delete nodo_eliminar;
			if (vacia()) { nodo_inicial = nullptr; nodo_cabeza->siguiente_a = nullptr; }
			std::cout << "Se eliminó la Asignatura con el código: " << _codigo << " correctamente.\n";
			std::cout << "--------------------------------------------------------------------\n";
			nodo_cabeza->cantidad_asignaturas--;
		}
		else {
			std::cout << "No se encontró la Asignatura con el código: " << _codigo << "\n";
			std::cout << "--------------------------------------------------------------------\n";
			std::system("pause");
		}
	}
	virtual void mostrar(Nodo* nodo_c = nullptr) override {
		Nodo_Asignatura* nodo_actual = nodo_inicial;
		std::cout << "Cantidad de Asignaturas: " << nodo_cabeza->cantidad_asignaturas << "\n";
		std::cout << "--------------------------------------------------------------------\n";
		while (nodo_actual != nullptr) {
			std::cout << "Codigo de la Asignatura: " << nodo_actual->asignatura.codigo << "\n";
			std::cout << "Nombre de la Asignatura: " << nodo_actual->asignatura.nombre << "\n";
			std::cout << "Descripcion de la Asignatura: " << nodo_actual->asignatura.descripcion << "\n";
			std::cout << "Cantidad de Horas de la Asignatura: " << nodo_actual->asignatura.horas << "\n";
			std::cout << "--------------------------------------------------------------------\n";
			nodo_actual = nodo_actual->siguiente;
		}
	}
	virtual bool vacia(Nodo* nodo_c = nullptr) override {
		return (nodo_cabeza->cantidad_asignaturas == 0);
	}
	int cantidad_asignaturas() { return nodo_cabeza->cantidad_asignaturas; }
	void ingresar_lista_estudiantes(int _opciones) {
		std::cout << "Escriba el código de la Asignatura: "; std::getline(std::cin, codigo);
		std::cout << "--------------------------------------------------------------------\n";
		Nodo_Asignatura* nodo_buscar = nodo_inicial;
		nodo_buscar = buscar(0, codigo, nodo_buscar);
		if (encontrar(nodo_buscar))
		{
			if (lista_estudiantes.vacia(nodo_buscar)) { std::cout << "Error: Lista de Estudiantes Vacía.\nSe insertará un nuevo estudiante\n"; _opciones = 5; }
			if (nodo_buscar->siguiente_e == nullptr) {
				Lista_Estudiantes lista_nueva(nodo_buscar);
				lista_estudiantes = lista_nueva;
			}
			switch (_opciones)
			{
			case 5:
				std::cout << "Escriba la posición del Estudiante: ";
				while (!(std::cin >> (posicion)) || (posicion < 1 || posicion > nodo_buscar->cantidad_estudiantes + 1)) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "--------------------------------------------------------------------\n";
					std::cout << "Escriba una posición válida: ";
				}
				std::cin.ignore();
				lista_estudiantes.insertar(posicion, nodo_buscar);
				break;
			case 6:
				std::cout << "Escriba el código del Estudiante: "; std::getline(std::cin, codigo);
				std::cout << "--------------------------------------------------------------------\n";
				lista_estudiantes.eliminar(codigo, nodo_buscar);
				break;
			case 7:
				lista_estudiantes.mostrar(nodo_buscar);
				break;
			case 8:
				std::cout << "La cantidad de Estudiantes es: " << lista_estudiantes.cantidad_estudiantes(nodo_buscar) << "\n";
				std::cout << "--------------------------------------------------------------------\n";
				break;
			case 9:
				lista_estudiantes.mostrar_masculinos(nodo_buscar);
				break;
			case 10:
				lista_estudiantes.mostrar_femeninos(nodo_buscar);
				break;
			}
		} else {
			std::cout << "Error: No se encontró la Asignatura con el código: " << codigo << "\n";
		}
	}
	void mostrar_todo() {
		Nodo_Asignatura* nodo_actual = nodo_inicial;
		while (nodo_actual != nullptr) {
			std::cout << "Codigo de la Asignatura: " << nodo_actual->asignatura.codigo << "\n";
			std::cout << "Nombre de la Asignatura: " << nodo_actual->asignatura.nombre << "\n";
			std::cout << "Descripcion de la Asignatura: " << nodo_actual->asignatura.descripcion << "\n";
			std::cout << "Cantidad de Horas de la Asignatura: " << nodo_actual->asignatura.horas << "\n";
			std::cout << "--------------------------------------------------------------------\n";
			lista_estudiantes.mostrar(nodo_actual);
			nodo_actual = nodo_actual->siguiente;
		}
	}
};

