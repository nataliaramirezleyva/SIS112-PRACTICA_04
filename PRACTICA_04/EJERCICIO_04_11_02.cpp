// Materia: Programación I, Paralelo 4

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 21/09/2023

// Fecha modificación: 21/09/2023

// Número de ejericio: 11

// Problema planteado: Construir las funciones para ordenar un vector de N elementos aleatorios y los ordene por.
// • Por incercion

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Función para imprimir un vector
void imprimirVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Función para ordenar un vector por inserción
void ordenarPorInsercion(std::vector<int>& vec) {
    int n = vec.size();
    for (int i = 1; i < n; ++i) {
        int key = vec[i];
        int j = i - 1;
        
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }
}

int main() {
    // Semilla para números aleatorios
    std::srand(std::time(0));

    int N; // Número de elementos en el vector
    std::cout << "Ingrese el tamaño del vector: ";
    std::cin >> N;

    std::vector<int> miVector;

    // Llenar el vector con números aleatorios
    for (int i = 0; i < N; ++i) {
        miVector.push_back(std::rand() % 100); // Rango de números aleatorios de 0 a 99
    }

    std::cout << "Vector original: ";
    imprimirVector(miVector);

    // Ordenar el vector por inserción
    ordenarPorInsercion(miVector);

    std::cout << "Vector ordenado: ";
    imprimirVector(miVector);

    return 0;
}