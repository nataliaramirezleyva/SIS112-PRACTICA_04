// Materia: Programación I, Paralelo 4

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 20/09/2023

// Fecha modificación: 21/09/2023

// Número de ejericio: 8

// Problema planteado: Escribir un programa que lea el salario de un empleado y mediante una función
// efectué un incremento salarial en base a la siguiente escala:
// • Si el salario es menor < 1000 Bs. incremente en un 20%
// • Si el salario es mayor o igual a 1000 pero es menor a 3000 Bs. Incremente en
// un 15%
// • Si el salario es mayor o igual a 3000 pero es menor a 6000 Bs. Incremente en
// un 10%
// • Si el salario es mayor o igual a 6000 Bs. Incremente en un 5%
// La función debe obtener el incremento y el nuevo salario

#include <iostream>

// Función para calcular el incremento y el nuevo salario.
void calcularIncrementoSalario(double& salario, double& incremento) {
    if (salario < 1000) {
        incremento = salario * 0.20;
    } else if (salario >= 1000 && salario < 3000) {
        incremento = salario * 0.15;
    } else if (salario >= 3000 && salario < 6000) {
        incremento = salario * 0.10;
    } else {
        incremento = salario * 0.05;
    }

    salario += incremento;
}

int main() {
    double salario;
    double incremento;

    std::cout << "Ingrese el salario del empleado en Bs.: ";
    std::cin >> salario;

    calcularIncrementoSalario(salario, incremento);

    std::cout << "Incremento salarial: " << incremento << " Bs." << std::endl;
    std::cout << "Nuevo salario: " << salario << " Bs." << std::endl;

    return 0;
}
