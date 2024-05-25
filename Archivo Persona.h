#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class persona
{
private:
	int codigo;
	string nombre;
	string apellido;
	string fechadenac;
	char genero;
	string direccion;
	string telefono;
	char estado;
public:
	persona() {
		codigo = 0;
		nombre = "";
		apellido = "";
		fechadenac = "";
		genero = ' ';
		direccion = "";
		telefono = "";
		estado = ' ';
	}
persona(int cod, string nom, string ape, string fec, char gen, string dir, string tel) {
		codigo = cod;
		nombre = nom;
		apellido = ape;
		fechadenac = fec;
		genero = gen;
		direccion = dir;
		telefono = tel;
		estado = 'A';
	}

	void set_persona(int cod, string nom, string ape, string fec, char gen, string dir, string tel) {
		codigo = cod;
		nombre = nom;
		apellido = ape;
		fechadenac = fec;
		genero = gen;
		direccion = dir;
		telefono = tel;
		estado = 'A';
	}
int get_codigo();
	string get_nombre();
	string get_apellido();
	string get_fechadenac();
	char get_genero();
	string get_direccion();
	string get_telefono();
	char get_estado();

	void guardar(ofstream& fsalida);
	bool leer(ifstream& fentrada);
	bool eliminar(fstream& fes, int nroReg);
	bool modificar(fstream& fes, int nroReg);
	bool buscar(ifstream& fentrada, int nroReg);
	int get_tam();

