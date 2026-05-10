#pragma once
#include "ConexionBD.h"
#include <iostream>
#include <iomanip>
#include <mysql.h>
#include <string>
#include <sstream>


using namespace std;

class Libreria{
 
	int id_libro = 0, cantidad = 0;
	double precio = 0;
	string titulo, autor, fecha_publicacion, genero;
	
public :
	Libreria() {};

	Libreria(int id_lbro, string title, string author, string fp, string genre, double price, int cntd) {
		
		id_libro = id_lbro;
		titulo = title;
		autor = author;
		fecha_publicacion = fp;
		genero = genre;
		precio = price;
		cantidad = cntd;
	}

	void setId_libro(int l) { id_libro = l; }
	void setTitulo(string t) { titulo = t; }
	void setAutor(string a) { autor = a; }
	void setFecha_publicacion(string f) { fecha_publicacion = f; }
	void setGenero(string g) { genero = g; }
	void setPrecio(double p) { precio = p; }
	void setCantidad(int c) { cantidad = c; }

	int getId_libro() { return id_libro; }
	string getTitulo() { return titulo; }
	string getAutor() { return autor; }
	string getFecha_publicacion() { return fecha_publicacion; }
	string getGenero() { return genero; }
	double getPrecio() { return precio; }
	int getCantidad() { return cantidad; }


	void Crear() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		
		cn.abrir_conexion();

		if (cn.getConector()) {
		
			string p = to_string(precio);
			string c = to_string(cantidad);
			string insertar = "INSERT INTO libro (titulo, autor, fecha_publicacion, precio, genero, cantidad) VALUES ('"+titulo+"', '"+autor+"', '"+fecha_publicacion+"', '"+p+"', '"+genero+"', '"+c+"');";

			const char* i = insertar.c_str();

			q_estado = mysql_query(cn.getConector(), i);

			if (!q_estado) {
				cout << "\nSe ingreso el libro correctamente..." << endl;
			}
			else {
				cout << "Error al ingresar libro" << endl;
			}

		}
		else {
			cout << "Error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}

	void Buscar() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();

		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();

		if (cn.getConector()) {
			string buscar;

			cout << "Buscar por titulo o autor: ";
			getline(cin, buscar);

			cout << setw(75) << " DATOS DE LOS LIBROS " << endl;
			cout << setw(5) << left << "ID" << setw(50) << "TITULO" << setw(30) << left << "AUTOR" << setw(15) << left << "FECHA PUBLICACION" << setw(10) << right << "GENERO" << setw(15) << right << "PRECIO" << setw(15) << right << "CANTIDAD" << endl;

			cout << setw(145) << setfill('-') << "-" << endl;
			cout << setfill(' ');

			string busqueda = "SELECT * FROM libro WHERE CONCAT(titulo, ' ' , autor) LIKE '%" + buscar + "%'";
			const char* b = busqueda.c_str();
			q_estado = mysql_query(cn.getConector(), b);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConector());
				
				while (fila = mysql_fetch_row(resultado)) {
					
					cout << setw(5) << left << fila[0] << setw(50) << fila[1] << setw(30) << left << fila[2] << setw(15) << left << fila[3] << setw(10) << right << fila[5] << setw(15) << right << fila[4] << setw(15) << right << fila[6] << endl << endl;
				}
			}
			else {
				cout << "Error de busqueda" << endl;
			}
		}
		else {
			cout << "Error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}

	void Editar() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();

		if (cn.getConector()) {

			string id_l = to_string(id_libro);
			string p = to_string(precio);
			string c = to_string(cantidad);
			string insertar = "UPDATE libro SET titulo = '" +titulo+ "', autor = '" +autor+ "', fecha_publicacion = '" +fecha_publicacion+ "', precio = '" +p+ "', genero = '" +genero+ "', cantidad = '" +c+ "' WHERE id_libro = '"+id_l+"' ;";
			const char* i = insertar.c_str();

			q_estado = mysql_query(cn.getConector(), i);

			if (!q_estado) {
				cout << "\nSe edito el libro correctamente..." << endl;
			}
			else {
				cout << "Error al editar libro" << endl;
			}

		}
		else {
			cout << "Error de conexion" << endl;
		}
		cn.cerrar_conexion();


	}
	
	
	void Borrar() {
		
		int q_estado = 0;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();

		if (cn.getConector()) {


			string id_l = to_string(id_libro);
			string p = to_string(precio);
			string insertar = "DELETE FROM libro WHERE id_libro = '" + id_l + "' ;";
			const char* i = insertar.c_str();

			q_estado = mysql_query(cn.getConector(), i);

			if (!q_estado) {
				cout << "\nSe elimino el libro correctamente..." << endl;
			}
			else {
				cout << "Error al eliminar libro" << endl;
			}

		}
		else {
			cout << "Error de conexion" << endl;
		}
		cn.cerrar_conexion();


	}



};

