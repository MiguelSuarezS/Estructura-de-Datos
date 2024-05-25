#include "ABMpersona.h"

void ABMpersona::introducion_datos(persona* newReg)
{
	int codigo;
	string nombre, apellido, fechadenac, direccion, telefono;
	char estado, genero;
	cout << endl;
	cout << "ingrese el nombre completo de la persona " << endl;
	cin.ignore();
	getline(cin, nombre);
	cout << "ingrese el codigo de la persona " << endl;
	cin >> codigo;
	cin.ignore();
	cout << "ingrese el apellido completo de la persona " << endl;
	getline(cin, apellido);
	cout << "ingrese la fecha de nacimiento " << endl;
	getline(cin, fechadenac);
	cout << "ingrese la direccion de donde vive actualmente " << endl;
	getline(cin, direccion);
	cout << "ingrese el telefono actual de la persona " << endl;
	getline(cin, telefono);
	cout << "ingrese el genero de la persona M/F " << endl;
	cin >> genero;
	cin.ignore();

	newReg->set_persona(codigo, nombre, apellido, fechadenac, genero, direccion, telefono);
}

void ABMpersona::mostrar_registro(int nroReg)
{
	cout << endl << nroReg << ".- " << person->get_codigo() << " " << person->get_nombre() << " " << person->get_apellido() << " " << person->get_fechadenac() << " " << person->get_genero() << " " << person->get_direccion() << " " << person->get_telefono() << " " << person->get_estado();
}	

void ABMpersona::adicionar_nuevo()
{
	ofstream fsalida(normArchivo, ios::app | ios::binary);
	person = new persona();
	introducion_datos(person);
	person->guardar(fsalida);
	fsalida.close();
}

void ABMpersona::listar()
{
	int cr = 0;
	person = new persona();
	ifstream fentrada(normArchivo, ios::in | ios::binary);
	while (person->leer(fentrada) == true) {
		cr++;
		if (person->get_estado() == 'A'){
			mostrar_registro(cr);
			}
	}
	fentrada.close();
}

int ABMpersona::buscar_reg()
{
	int nroReg; 
	cout << "ingrese el codigo de la persona qu quiere buscar " << endl;
	cin >> nroReg;
	person = new persona();
	ifstream fentrada(normArchivo, ios::in | ios::binary);
	if (person->buscar(fentrada,nroReg) == true) {
		mostrar_registro(nroReg);
	}
	else {
		cout << "el registro no existe " << endl;
		nroReg = -1;
	}
	fentrada.close();

	return nroReg;
}

void ABMpersona::eliminar_reg()
{
	int nroReg; 
	nroReg = buscar_reg();

	if (nroReg > 0) {
		fstream fes(normArchivo, ios::in | ios::out | ios::binary);
		person = new persona();
		if (person->eliminar(fes, nroReg) == true) {
			cout << "eliminado exitosamente " << endl;
		}
		else {
			cout << "no se ha encontrado" << endl;
		}
		fes.close();
	}
}

void ABMpersona::modificar_reg()
{
	int nroReg;
	nroReg = buscar_reg();

	if (nroReg > 0) {
		fstream fes(normArchivo, ios::in | ios::out | ios::binary);
		person = new persona();
		introducion_datos(person);
		if (person->modificar(fes, nroReg) == true) {
			cout << "modificado " << endl;
		}
		else {
			cout << "no existe el archivo" << endl;
		}
		fes.close();
	}
}
