// Materia: Programación I, Paralelo 4

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 20/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 1

// Problema planteado: Lee por teclado un año y calcula y muestra si es bisiesto

#include <iostream>

bool esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int main() {
    int anio;
    
    std::cout << "Ingrese un año: ";
    std::cin >> anio;
    
    if (esBisiesto(anio)) {
        std::cout << anio << " es un año bisiesto." << std::endl;
    } else {
        std::cout << anio << " no es un año bisiesto." << std::endl;
    }
    
    return 0;
}