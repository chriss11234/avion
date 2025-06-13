#pragma once
#include <iostream>
using namespace std;

class persona {
protected: int codigo = 0;
	string nombres, apellidos, hora_de_abordaje, hora_de_salida, asiento_correspondiente, destino_final;

		persona(){}
		persona(int cod,string nom,string ape, string ha, string hs, string ac, string df) {
			codigo = cod;
			nombres = nom;
			apellidos = ape;
			hora_de_abordaje = ha;
			hora_de_salida = hs;
			asiento_correspondiente = ac;
			destino_final = df;
	}	
};

