// Materia: Programación I, Paralelo 4

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 20/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 3

// Problema planteado: Leer los datos de doce personas como son: nombre, edad, estatura, peso, posteriormente
// indicar cuál es el nombre de la persona de menor edad, el promedio de las estaturas y el
// de los pesos. (realizar con estructuras)

#include <iostream>
#include <string>

// Definición de la estructura Persona para almacenar los datos de una persona.
struct Persona {
    std::string nombre;
    int edad;
    double estatura;
    double peso;
};

int main() {
    const int numPersonas = 12;
    Persona personas[numPersonas];

    // Leer los datos de las doce personas.
    for (int i = 0; i < numPersonas; ++i) {
        std::cout << "Ingrese los datos de la persona " << i + 1 << ":\n";
        std::cout << "Nombre: ";
        std::cin >> personas[i].nombre;
        std::cout << "Edad: ";
        std::cin >> personas[i].edad;
        std::cout << "Estatura (en metros): ";
        std::cin >> personas[i].estatura;
        std::cout << "Peso (en kilogramos): ";
        std::cin >> personas[i].peso;
    }

    // Encontrar la persona de menor edad.
    int edadMinima = personas[0].edad;
    std::string nombrePersonaMasJoven = personas[0].nombre;

    for (int i = 1; i < numPersonas; ++i) {
        if (personas[i].edad < edadMinima) {
            edadMinima = personas[i].edad;
            nombrePersonaMasJoven = personas[i].nombre;
        }
    }

    // Calcular el promedio de estaturas y pesos.
    double sumaEstaturas = 0.0;
    double sumaPesos = 0.0;

    for (int i = 0; i < numPersonas; ++i) {
        sumaEstaturas += personas[i].estatura;
        sumaPesos += personas[i].peso;
    }

    double promedioEstaturas = sumaEstaturas / numPersonas;
    double promedioPesos = sumaPesos / numPersonas;

    // Mostrar los resultados.
    std::cout << "\nLa persona de menor edad es: " << nombrePersonaMasJoven << " (" << edadMinima << " años).\n";
    std::cout << "El promedio de estaturas es: " << promedioEstaturas << " metros.\n";
    std::cout << "El promedio de pesos es: " << promedioPesos << " kilogramos.\n";

    return 0;
}