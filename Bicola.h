#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor para crear un nuevo nodo
    Node(int data);
};

class Deque {
public:
    Node* front;
    Node* rear;
    int size;

    // Constructor
    Deque();

    // Destructor
    ~Deque();

    // Inserta un elemento al frente
    void insertFront(int data);

    // Inserta un elemento al final
    void insertLast(int data);

    // Elimina un elemento del frente
    void deleteFront();

    // Elimina un elemento del final
    void deleteLast();

    // Muestra el elemento del frente
    int getFront();

    // Muestra el elemento del final
    int getLast();

    // Muestra el tamaño de la bicola
    int getSize();
};
