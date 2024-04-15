#include "Queue.h"
#include <iostream>

template <typename T, int MAX_SIZE>
Queue<T, MAX_SIZE>::Queue() : front_index(0), rear_index(-1), count(0) {}

template <typename T, int MAX_SIZE>
void Queue<T, MAX_SIZE>::enqueue(T value) {
    if (isFull()) {
        std::cerr << "Queue overflow: la cola está llena" << std::endl;
        return;
    }
    rear_index = (rear_index + 1) % MAX_SIZE; // Avanzar el índice trasero circularmente
    data[rear_index] = value;
    count++;
}

template <typename T, int MAX_SIZE>
T Queue<T, MAX_SIZE>::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue underflow: la cola está vacía" << std::endl;
        exit(EXIT_FAILURE);
    }
    T value = data[front_index];
    front_index = (front_index + 1) % MAX_SIZE; // Avanzar el índice del frente circularmente
    count--;
    return value;
}

template <typename T, int MAX_SIZE>
T Queue<T, MAX_SIZE>::peek() const {
    if (isEmpty()) {
        std::cerr << "Queue underflow: la cola está vacía" << std::endl;
        exit(EXIT_FAILURE);
    }
    return data[front_index];
}

template <typename T, int MAX_SIZE>
bool Queue<T, MAX_SIZE>::isEmpty() const {
    return count == 0;
}

template <typename T, int MAX_SIZE>
bool Queue<T, MAX_SIZE>::isFull() const {
    return count == MAX_SIZE;
}
