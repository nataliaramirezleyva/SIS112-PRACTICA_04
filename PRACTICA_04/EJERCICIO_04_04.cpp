// Materia: Programación I, Paralelo 4

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 20/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 4

// Problema planteado: Escribir el programa para solicitar al usuario N calificaciones comprendidas en el rango
// de 1 a 100, calcular y presentar la sumatoria y promedio de estas N calificaciones. La
// entrada de valores es para las calificaciones, debe hacerlo mediante una función.

#include <iostream>
#include <vector>

// Función para ingresar N calificaciones y almacenarlas en un vector.
void ingresarCalificaciones(std::vector<int>& calificaciones, int N) {
    calificaciones.clear(); // Limpiar el vector por si ya contiene calificaciones previas.

    for (int i = 0; i < N; ++i) {
        int calificacion;
        do {
            std::cout << "Ingrese la calificación " << i + 1 << " (entre 1 y 100): ";
            std::cin >> calificacion;
        } while (calificacion < 1 || calificacion > 100);

        calificaciones.push_back(calificacion); // Agregar la calificación al vector.
    }
}

int main() {
    int N;
    std::vector<int> calificaciones;

    // Solicitar al usuario el número de calificaciones.
    std::cout << "Ingrese el número de calificaciones: ";
    std::cin >> N;

    // Llamar a la función para ingresar las calificaciones.
    ingresarCalificaciones(calificaciones, N);

    // Calcular la sumatoria y el promedio de las calificaciones.
    int sumatoria = 0;
    for (int i = 0; i < N; ++i) {
        sumatoria += calificaciones[i];
    }

    double promedio = static_cast<double>(sumatoria) / N;

    // Mostrar los resultados.
    std::cout << "\nLa sumatoria de las calificaciones es: " << sumatoria << std::endl;
    std::cout << "El promedio de las calificaciones es: " << promedio << std::endl;

    return 0;
}