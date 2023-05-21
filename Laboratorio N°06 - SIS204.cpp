#include <iostream>
#include <string>
#include "Lista_Asignaturas.h"
bool main(int argv, char** argc) {
	int opcion, posicion;
	std::string codigo;
	enum Opciones { INSERTAR_ASIGNATURA = 1,
		ELIMINAR_ASIGNATURA = 2,
		MOSTRAR_ASIGNATURAS = 3,
		MOSTRAR_CANTIDAD_ASIGNATURAS = 4,
		INSERTAR_ESTUDIANTE = 5,
		ELIMINAR_ESTUDIANTE = 6,
		MOSTRAR_ESTUDIANTES = 7,
		MOSTRAR_CANTIDAD_ESTUDIANTES = 8,
		MOSTRAR_ESTUDIANTES_MASCULINOS_ASIGNATURA = 9,
		MOSTRAR_ESTUDIANTES_FEMENINOS_ASIGNATURA = 10,
		MOSTRAR_MULTILISTA = 11
	} opciones;
	Lista_Asignaturas lista_asignaturas;
	do {
		std::system("cls");
		std::cout << "--------------------------------------------------------------------\n";
		std::cout << "***Multilista de Asignaturas y Estudiantes***\n";
		std::cout << "--------------------------------------------------------------------\n";
		std::cout << "1. Insertar una Asignatura.\n";
		std::cout << "2. Eliminar una Asignatura.\n";
		std::cout << "3. Mostrar las Asignaturas.\n";
		std::cout << "4. Mostrar la cantidad de Asignaturas.\n";
		std::cout << "5. Insertar un Estudiante.\n";
		std::cout << "6. Eliminar un Estudiante.\n";
		std::cout << "7. Mostrar los Estudiantes.\n";
		std::cout << "8. Mostrar la cantidad de Estudiantes.\n";
		std::cout << "9. Mostrar los Estudiantes de una Asignatura.\n";
		std::cout << "10. Mostrar los Estudiantes Masculinos de una Asignatura.\n";
		std::cout << "11. Mostrar los Estudiantes Femeninos de una Asignatura.\n";
		std::cout << "12. Mostrar toda la Multilista.\n";
		std::cout << "13. Salir.\n";
		std::cout << "--------------------------------------------------------------------\n";
		std::cout << "Seleccione una opcion: "; 
		while (!(std::cin >> opcion) || (opcion < 1 || opcion > 13)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "--------------------------------------------------------------------\n";
			std::cout << "Seleccione una opción válida: ";
		}
		if (opcion > 1 && opcion < 13 && lista_asignaturas.vacia()) {
			std::cout << "--------------------------------------------------------------------\n";
			std::cout << "Error: No hay Asignaturas registradas.\n"; opcion = 1;
		}
		std::cout << "--------------------------------------------------------------------\n";
		std::cin.ignore();
		switch (opciones = static_cast<Opciones>(opcion)) {
		case INSERTAR_ASIGNATURA:
			std::cout << "***Se insertará una Asignatura***\n";
			std::cout << "--------------------------------------------------------------------\n";
			std::cout << "Escriba la posición donde se insertará la Asignatura: ";
			while (!(std::cin >> (posicion)) || (posicion < 1 || posicion > lista_asignaturas.cantidad_asignaturas() + 1)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "--------------------------------------------------------------------\n";
				std::cout << "Escriba una posición válida: ";
			}
			std::cout << "--------------------------------------------------------------------\n";
			std::cin.ignore();
			lista_asignaturas.insertar(posicion);
			break;
		case ELIMINAR_ASIGNATURA:
			std::cout << "***Se eliminará una Asignatura***\n";
			std::cout << "--------------------------------------------------------------------\n";
			std::cout << "Escriba el código de la Asignatura que desea eliminar: "; std::cin >> codigo;
			while (codigo == "") {
				std::cout << "--------------------------------------------------------------------\n";
				std::cout << "Escriba un código válido: "; std::getline(std::cin, codigo);
			}
			std::cout << "--------------------------------------------------------------------\n";
			lista_asignaturas.eliminar(codigo);
			break;
		case MOSTRAR_ASIGNATURAS:
			std::cout << "***Se mostrarán las Asignaturas***\n";
			std::cout << "--------------------------------------------------------------------\n";
			lista_asignaturas.mostrar();
			break;
		case MOSTRAR_CANTIDAD_ASIGNATURAS:
			std::cout << "***Se mostrará la cantidad de Asignaturas***\n";
			std::cout << "--------------------------------------------------------------------\n";
			std::cout << "La cantidad de Asignaturas es: " << lista_asignaturas.cantidad_asignaturas() << "\n";
			break;
		case INSERTAR_ESTUDIANTE:
			std::cout << "***Se insertará un Estudiante a una Asignatura***\n";
			std::cout << "--------------------------------------------------------------------\n";
			lista_asignaturas.ingresar_lista_estudiantes(static_cast<int>(INSERTAR_ESTUDIANTE));
			break;
		case ELIMINAR_ESTUDIANTE:
			std::cout << "***Se eliminará un Estudiante de una Asignatura***\n";
			std::cout << "--------------------------------------------------------------------\n";
			lista_asignaturas.ingresar_lista_estudiantes(static_cast<int>(ELIMINAR_ESTUDIANTE));
			break;
		case MOSTRAR_ESTUDIANTES:
			std::cout << "***Se mostrarán los Estudiantes de una Asignatura***\n";
			std::cout << "--------------------------------------------------------------------\n";
			lista_asignaturas.ingresar_lista_estudiantes(static_cast<int>(MOSTRAR_ESTUDIANTES));
			break;
		case MOSTRAR_CANTIDAD_ESTUDIANTES:
			std::cout << "***Se mostrará la cantidad de Estudiantes de una Asignatura***\n";
			std::cout << "--------------------------------------------------------------------\n";
			lista_asignaturas.ingresar_lista_estudiantes(static_cast<int>(MOSTRAR_CANTIDAD_ESTUDIANTES));
			break;
		case MOSTRAR_ESTUDIANTES_MASCULINOS_ASIGNATURA:
			std::cout << "***Se mostrarán los Estudiantes Masculinos de una Asignatura***\n";
			std::cout << "--------------------------------------------------------------------\n";
			lista_asignaturas.ingresar_lista_estudiantes(static_cast<int>(MOSTRAR_ESTUDIANTES_MASCULINOS_ASIGNATURA));
			break;
		case MOSTRAR_ESTUDIANTES_FEMENINOS_ASIGNATURA:
			std::cout << "***Se mostrarán los Estudiantes Femeninos de una Asignatura***\n";
			std::cout << "--------------------------------------------------------------------\n";
			lista_asignaturas.ingresar_lista_estudiantes(static_cast<int>(MOSTRAR_ESTUDIANTES_FEMENINOS_ASIGNATURA));
			break;
		case MOSTRAR_MULTILISTA:
			std::cout << "***Se mostrará toda la Multilista***\n";
			std::cout << "--------------------------------------------------------------------\n";
			lista_asignaturas.mostrar_todo();
			break;
		default:
			std::cout << "Gracias por usar el programa.\n"; 
			std::cout << "--------------------------------------------------------------------\n";
			return false;
		}
		system("pause");
	} while (true);
	return false;
}