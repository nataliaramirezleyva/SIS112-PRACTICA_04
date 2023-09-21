// Materia: Programación I, Paralelo 4

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 21/09/2023

// Fecha modificación: 21/09/2023

// Número de ejericio: 11

// Problema planteado: Construir las funciones para ordenar un vector de N elementos aleatorios y los ordene por.
// • Por burbuja

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

// Función para ordenar un vector por burbuja
void ordenarPorBurbuja(std::vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main() {
    // Semilla para números aleatorios
    std::srand(static_cast<unsigned>(std::time(nullptr)));

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

    // Ordenar el vector por burbuja
    ordenarPorBurbuja(miVector);

    std::cout << "Vector ordenado: ";
    imprimirVector(miVector);

    return 0;
}