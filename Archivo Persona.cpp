#include "persona.h"

int persona::get_codigo()
{
    return (codigo);
}

string persona::get_nombre()
{
    return (nombre);
}

string persona::get_apellido()
{
    return (apellido);
}

string persona::get_fechadenac()
{
    return (fechadenac);
}

char persona::get_genero()
{
    return (genero);
}

string persona::get_direccion()
{
    return (direccion);
}
string persona::get_telefono()
{
    return (telefono);
}

char persona::get_estado()
{
    return (estado);
}

void persona::guardar(ofstream& fsalida)
{
    fsalida.write(reinterpret_cast<char*>(&nombre), sizeof(nombre));
    fsalida.write(reinterpret_cast<char*>(&codigo), sizeof(codigo));
    fsalida.write(reinterpret_cast<char*>(&apellido), sizeof(apellido));
    fsalida.write(reinterpret_cast<char*>(&fechadenac), sizeof(fechadenac));
    fsalida.write(reinterpret_cast<char*>(&genero), sizeof(genero));
    fsalida.write(reinterpret_cast<char*>(&direccion), sizeof(direccion));
    fsalida.write(reinterpret_cast<char*>(&telefono), sizeof(telefono));
    fsalida.write(reinterpret_cast<char*>(&estado), sizeof(estado));
}
bool persona::leer(ifstream& fentrada)
{
    bool k = false;

    if (fentrada.is_open() == true) {
        fentrada.read(reinterpret_cast<char*>(&nombre), sizeof(nombre));
        if (fentrada.eof() == false) {
            fentrada.read(reinterpret_cast<char*>(&codigo), sizeof(codigo));
            fentrada.read(reinterpret_cast<char*>(&apellido), sizeof(apellido));
            fentrada.read(reinterpret_cast<char*>(&fechadenac), sizeof(fechadenac));
            fentrada.read(reinterpret_cast<char*>(&genero), sizeof(genero));
            fentrada.read(reinterpret_cast<char*>(&direccion), sizeof(direccion));
            fentrada.read(reinterpret_cast<char*>(&telefono), sizeof(telefono));
            fentrada.read(reinterpret_cast<char*>(&estado), sizeof(estado));
            k = true;
        }
        else {
            //  cout << "no se encontro " << endl;
        }
    }
    else {
        cout << "no existe " << endl;
    }
    return k;
}
bool persona::eliminar(fstream& fes, int nroReg)
{
    bool k = false;
    if (fes.is_open() == true) {
        fes.seekg(get_tam() * (nroReg - 1), ios::beg);
        fes.read(reinterpret_cast<char*>(&nombre), sizeof(nombre));
        if (fes.eof() == false) {
            fes.read(reinterpret_cast<char*>(&codigo), sizeof(codigo));
            fes.read(reinterpret_cast<char*>(&apellido), sizeof(apellido));
            fes.read(reinterpret_cast<char*>(&fechadenac), sizeof(fechadenac));
            fes.read(reinterpret_cast<char*>(&genero), sizeof(genero));
            fes.read(reinterpret_cast<char*>(&direccion), sizeof(direccion));
            fes.read(reinterpret_cast<char*>(&telefono), sizeof(telefono));
            fes.read(reinterpret_cast<char*>(&estado), sizeof(estado));

            estado = 'E';
            fes.seekp(get_tam() * (nroReg - 1), ios::beg);
            fes.write(reinterpret_cast<char*>(&nombre), sizeof(nombre));
            fes.write(reinterpret_cast<char*>(&codigo), sizeof(codigo));
            fes.write(reinterpret_cast<char*>(&apellido), sizeof(apellido));
            fes.write(reinterpret_cast<char*>(&fechadenac), sizeof(fechadenac));
            fes.write(reinterpret_cast<char*>(&genero), sizeof(genero));
            fes.write(reinterpret_cast<char*>(&direccion), sizeof(direccion));
            fes.write(reinterpret_cast<char*>(&telefono), sizeof(telefono));
            fes.write(reinterpret_cast<char*>(&estado), sizeof(estado));
            k = true;
        }
        else {
            cout << "no se encontro " << endl;
        }
    }
    else {
        cout << "no existe " << endl;
    }
    return k;
}

bool persona::modificar(fstream& fes, int nroReg)
{
bool k = false;
    if (fes.is_open() == true) {
        string nomAux;
        nomAux = nombre;
        fes.seekg(get_tam() * (nroReg - 1), ios::beg);
        fes.read(reinterpret_cast<char*>(&nombre), sizeof(nombre));
        if (fes.eof() == false) {
            nombre = nomAux;
            estado = 'A';
            fes.seekp(get_tam() * (nroReg - 1), ios::beg);
            fes.write(reinterpret_cast<char*>(&nombre), sizeof(nombre));
            fes.write(reinterpret_cast<char*>(&codigo), sizeof(codigo));
            fes.write(reinterpret_cast<char*>(&apellido), sizeof(apellido));
            fes.write(reinterpret_cast<char*>(&fechadenac), sizeof(fechadenac));
            fes.write(reinterpret_cast<char*>(&genero), sizeof(genero));
            fes.write(reinterpret_cast<char*>(&direccion), sizeof(direccion));
            fes.write(reinterpret_cast<char*>(&telefono), sizeof(telefono));
            fes.write(reinterpret_cast<char*>(&estado), sizeof(estado));
            k = true;
        }
        else {
            cout << "no se encontro " << endl;
        }
  }
    else {
        cout << "no existe " << endl;
    }
    return k;
}

bool persona::buscar(ifstream& fentrada, int nroReg)
{
    bool k = false;
    if (fentrada.is_open() == true) {
        fentrada.seekg(get_tam() * (nroReg - 1), ios::beg);
        fentrada.read(reinterpret_cast<char*>(&nombre), sizeof(nombre));
        fentrada.read(reinterpret_cast<char*>(&codigo), sizeof(codigo));
        fentrada.read(reinterpret_cast<char*>(&apellido), sizeof(apellido));
        fentrada.read(reinterpret_cast<char*>(&fechadenac), sizeof(fechadenac));
        fentrada.read(reinterpret_cast<char*>(&genero), sizeof(genero));
        fentrada.read(reinterpret_cast<char*>(&direccion), sizeof(direccion));
        fentrada.read(reinterpret_cast<char*>(&telefono), sizeof(telefono));
        fentrada.read(reinterpret_cast<char*>(&estado), sizeof(estado));
        if (fentrada.eof() == false) {
            k = true;
        }
        else {
            cout << "no se encontro " << endl;
        }
    return k;
}

int persona::get_tam()
{
    return (sizeof(nombre) + sizeof(codigo) + sizeof(apellido) + sizeof(fechadenac) + sizeof(genero) + sizeof(direccion) + sizeof(telefono) + sizeof(estado));
}   
