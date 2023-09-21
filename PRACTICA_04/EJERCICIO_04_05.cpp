// Materia: Programación I, Paralelo 4

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 20/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 5

// Problema planteado: Elabore un programa para registro académico de la UCB, que solicite el nombre de una
// materia, el paralelo, el docente y sus correspondientes notas de periodo. Al final, se
// muestra la nota final y si aprobó o reprobo el curso. (realizar con estructuras)

#include <iostream>
#include <string>

struct Materia {
    std::string nombre;
    std::string paralelo;
    std::string docente;
    double nota1;
    double nota2;
    double nota3;
    double notaFinal; // Agregar notaFinal
    bool aprobado;    // Agregar aprobado
};

// Función para calcular la nota final y determinar si el estudiante aprobó o reprobó.
void calcularNotaFinal(Materia& materia) {
    materia.notaFinal = (materia.nota1 + materia.nota2 + materia.nota3) / 3.0;
    if (materia.notaFinal >= 70.0) {
        materia.aprobado = true;
    } else {
        materia.aprobado = false;
    }
}

int main() {
    Materia materia;

    std::cout << "Registro Académico de la UCB" << std::endl;

    std::cout << "Nombre de la materia: ";
    std::cin >> materia.nombre;

    std::cout << "Paralelo: ";
    std::cin >> materia.paralelo;

    std::cout << "Docente: ";
    std::cin >> materia.docente;

    std::cout << "Nota del primer período: ";
    std::cin >> materia.nota1;

    std::cout << "Nota del segundo período: ";
    std::cin >> materia.nota2;

    std::cout << "Nota del tercer período: ";
    std::cin >> materia.nota3;

    calcularNotaFinal(materia);

    std::cout << "\nResumen de la Materia:" << std::endl;
    std::cout << "Nombre: " << materia.nombre << std::endl;
    std::cout << "Paralelo: " << materia.paralelo << std::endl;
    std::cout << "Docente: " << materia.docente << std::endl;
    std::cout << "Nota Final: " << materia.notaFinal << std::endl;
    
    if (materia.aprobado) {
        std::cout << "Estado: Aprobado" << std::endl;
    } else {
        std::cout << "Estado: Reprobado" << std::endl;
    }

    return 0;
}
