#pragma once
#include <mysql.h>
#include <iostream>

using namespace std;

class ConexionBD{

private: MYSQL* conector; //controla conexion a base de datos
public :
	void abrir_conexion() {
		conector = mysql_init(0);
		conector = mysql_real_connect(conector, "localhost", "root", "", "libreria", 3306, NULL, 0);
	}

	MYSQL* getConector() {
		return conector;
	}

	void cerrar_conexion() {
		mysql_close(conector);
	}
};

