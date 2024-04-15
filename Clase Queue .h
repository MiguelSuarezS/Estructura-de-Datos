template <typename T, int MAX_SIZE>
class Queue {
private:
    T data[MAX_SIZE]; // Array para almacenar los elementos de la cola
    int front_index; // Índice del frente de la cola
    int rear_index; // Índice de la parte trasera de la cola
    int count; // Contador para rastrear el número de elementos en la cola

public:
    // Constructor
    Queue();

    // Destructor (no necesario en este caso)

    // Método para insertar un elemento en la cola
    void enqueue(T value);

    // Método para eliminar y devolver el elemento del frente de la cola
    T dequeue();

    // Método para devolver el elemento del frente de la cola sin eliminarlo
    T peek() const;

    // Método para verificar si la cola está vacía
    bool isEmpty() const;

    // Método para verificar si la cola está llena
    bool isFull() const;
};
