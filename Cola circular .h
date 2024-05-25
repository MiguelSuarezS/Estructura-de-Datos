#include <iostream>
using namespace std;

class ColaCircular {
private:
    int *arr;
    int frente;
    int final;
    int tamano;
    int capacidad;

public:
    // Constructor
    ColaCircular(int capacidad);

    // Destructor
    ~ColaCircular();

    // Inserta un elemento al final
    void encolar(int dato);

    // Elimina un elemento del frente
    int desencolar();

    // Muestra el elemento del frente
    int obtenerFrente();

    // Muestra el elemento del final
    int obtenerFinal();

    // Muestra el tamaño de la cola
    int obtenerTamano();

    // Verifica si la cola está vacía
    bool estaVacia();

    // Verifica si la cola está llena
    bool estaLlena();
};
