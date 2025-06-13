
#include "ConexionBD.h"
#include "persona.h"
#include "pasajeros.h"
#include <iostream>
#include "Prueba avion.h"

using namespace std;
int main()
{
	int opcion;
	do {
		system("cls");
		cout << " BASE DE DATOS ESTUDIANTES" << endl;
		cout << " Qué desea realizar? " << endl;
		cout << " 1. Ingresar " << endl;
		cout << " 2. Actualizar " << endl;
		cout << " 3. Mostrar " << endl;
		cout << " 4. Eliminar " << endl;
		cout << " 0. Salir " << endl;
		cout << " Seleccione una opcion: ";
		cin >> opcion;

		int codigo = 0;
		string nombres, apellidos, hora_de_abordaje, hora_de_salida, asiento_correspondiente, destino_final;
		pasajeros e;

		switch (opcion) {
		case 1:
			cout << "Ingrese codigo: ";
			cin >> codigo;
			cout << "Ingrese nombres: ";
			getline(cin, nombres);
			cout << "Ingrese apellidos: ";
			getline(cin, apellidos);
			cout << "Ingrese hora de abordaje: ";
			getline(cin, hora_de_abordaje);
			cout << "Ingrese hora de salida: ";
			getline(cin, hora_de_salida);
			cout << "Ingrese asiento correspondiente: ";
			getline(cin, asiento_correspondiente);
			cout << "Ingrese Destino final: ";
			getline(cin, destino_final);
			e = pasajeros (nombres, apellidos, hora_de_abordaje, hora_de_salida, asiento_correspondiente, destino_final);
			e.crear();
			break;

		case 2:
			cout << "Ingrese el Codigo A Modificar: ";
			cin >> codigo;
			cout << "Ingrese Nuevo Codigo: ";
			cin >> codigo;
			cin.ignore();
			cout << "Ingrese Nuevos Nombres: ";
			getline(cin, nombres);
			cout << "Ingrese Nuevos Apellidos: ";
			getline(cin, apellidos);
			cout << "Ingrese Nueva hora de abordaje: ";
			getline(cin, hora_de_abordaje);
			cout << "Ingrese Nueva hora de salida: ";
			getline(cin, hora_de_salida);
			cout << "Ingrese Nuevo asiento correspondiente: ";
			getline(cin, asiento_correspondiente);
			cout << "Ingrese Nuevo Destino final: ";
			getline(cin, destino_final);
			e.setCodigo(codigo);
			e.setNombres(nombres);
			e.setApellidos(apellidos);
			e.setHoradeabordaje(hora_de_abordaje);
			e.setHoradesalida(hora_de_salida);
			e.setDestinofinal(destino_final);
			e.actualizar();
			e.leer();
			break;

		case 3:
			e.leer();
			break;

		case 4:
			cout << "Ingrese Codigo De Pasajero A Eliminar: ";
			cin >> codigo;
			e.setCodigo(codigo);
			e.borrar();
			e.leer();
			break;

		case 0:
			cout << "Saliendo del programa..." << endl;
			break;

		default:
			cout << "Opcion invalida. Intente nuevamente." << endl;
		}

		system("pause");

	} while (opcion != 0);

	return 0;
}

