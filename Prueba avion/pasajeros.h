#pragma once
#include "persona.h"
#include "ConexionBD.h"
#include <iostream>
#include <mysql.h>
#include <string>


using namespace std;

class pasajeros : persona {

private: int codigo = 0;

public :
		pasajeros(){}
		pasajeros(int cod, string nom, string ape, string ha, string hs, string ac, string df) : persona(cod, nom, ape, ha, hs, ac, df) {
			codigo = cod;
		}

		void setCodigo(int cod) { codigo = cod; }
		void setNombres(string nom) { nombres = nom; }
		void setApellidos(string ape) { apellidos = ape; }
		void setHoradeabordaje(string ha) { hora_de_abordaje = ha; }
		void setHoradesalida(string hs) { hora_de_salida = hs; }
		void setAsientocorrespondiente(string ac) { asiento_correspondiente = ac; }
		void setDestinofinal(string df) { destino_final = df; }

		int getCodigo() { return codigo; }
		string getNombres() { return nombres; }
		string getApellidos() { return apellidos; }
		string getHoradeabordaje() { return hora_de_abordaje; }
		string getHoradesalida() { return hora_de_salida; }
		string getAsientocorrespondiente() { return asiento_correspondiente; }
		string getDestinofinal() { return destino_final; }

	void crear() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConector()) {
			string co = to_string(codigo);
			string consulta = "INSERT INTO avion (codigo, nombre, apellidos, hora de abordaje, hora de salida, asiento correspondiente, destino final) VALUES (" + co + ", '" + nombres + "','" + apellidos + "', '" + hora_de_abordaje + "', '" + hora_de_salida + "','" + asiento_correspondiente + "','" + destino_final + "');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConector(), c);
			if (!q_estado) {
				cout << " Ingreso de Datos Exitoso " << endl;
			}
			else {
				cout << "Consulta Fallida" << endl;
			}
		}
		else {
			cout << "Conexion Fallida" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConector()) {
			cout << " Datos de los padajeros " << endl;
			string consulta = "SELECT * FROM prueba.avion;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConector(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConector());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "Codigo: " << fila[0] << "nombres: " << fila[1] << "Apellido: " << fila[2] << "Hora de abordaje:" << fila[3] << " Hora de salida: " << fila[4] << "asiento correspondiente: " << fila[5] << "destino final" << fila[6] << endl;
				}
			}
			else {
				cout << " Consulta Exitosa" << endl;
			}
		}
		else {
			cout << "Conexion Fallida" << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConector()) {
			string co = to_string(codigo);
			string cod = to_string(codigo);
			string consulta = "update avion set codigo = " + co + ", nombres = '" + nombres + "', apellidos ='" + apellidos + "',hora de abordaje = '" + hora_de_abordaje + "', hora de salida = '" + hora_de_salida +"', asiento correspondiente'" + asiento_correspondiente + "', destino final'" + destino_final + "' Where codigo = "+cod+" ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConector(), c);
			if (!q_estado) {
				cout << " Modificaciones Exitosas " << endl;
			}
			else {
				cout << "Modificaciones Fallidas " << endl;
			}

		}
		else {
			cout << " Conexion Fallida " << endl;
		}
	}
	void borrar() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConector()) {
			string co = to_string(codigo);
			string cod = to_string(codigo);
			string consulta = " delete from avion where codigo = " + cod + " ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConector(), c);
			if (!q_estado) {
				cout << " Eliminacion Exitosa" << endl;
			}
			else {
				cout << "Eliminacion Fallida " << endl;
			}
		}
		else {
			cout << "Conexion Fallida" << endl;
		}
	}
};

