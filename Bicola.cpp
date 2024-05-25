#include "Deque.h"

// Implementación del constructor de Node
Node::Node(int data) : data(data), prev(nullptr), next(nullptr) {}

// Implementación del constructor de Deque
Deque::Deque() : front(nullptr), rear(nullptr), size(0) {}

// Implementación del destructor de Deque
Deque::~Deque() {
    while (front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

// Inserta un elemento al frente
void Deque::insertFront(int data) {
    Node* newNode = new Node(data);
    if (front == nullptr) {
        // Si la bicola está vacía
        front = rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    size++;
}

// Inserta un elemento al final
void Deque::insertLast(int data) {
    Node* newNode = new Node(data);
    if (rear == nullptr) {
        // Si la bicola está vacía
        front = rear = newNode;
    } else {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

// Elimina un elemento del frente
void Deque::deleteFront() {
    if (front == nullptr) {
        cout << "Deque is empty" << endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr; // La bicola está ahora vacía
    } else {
        front->prev = nullptr;
    }
    delete temp;
    size--;
}

// Elimina un elemento del final
void Deque::deleteLast() {
    if (rear == nullptr) {
        cout << "Deque is empty" << endl;
        return;
    }
    Node* temp = rear;
    rear = rear->prev;
    if (rear == nullptr) {
        front = nullptr; // La bicola está ahora vacía
    } else {
        rear->next = nullptr;
    }
    delete temp;
    size--;
}

// Muestra el elemento del frente
int Deque::getFront() {
    if (front == nullptr) {
        cout << "Deque is empty" << endl;
        return -1;
    }
    return front->data;
}

// Muestra el elemento del final
int Deque::getLast() {
    if (rear == nullptr) {
        cout << "Deque is empty" << endl;
        return -1;
    }
    return rear->data;
}

// Muestra el tamaño de la bicola
int Deque::getSize() {
    return size;
}
