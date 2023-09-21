// Materia: Programación I, Paralelo 4

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 21/09/2023

// Fecha modificación: 21/09/2023

// Número de ejericio: 9

// Problema planteado: A un trabajador se le paga según las horas que trabaja en la semana, una tarifa de
// pago por hora. Si la cantidad de horas trabajadas es mayor a 40, la tarifa se incrementa
// en un 50%. Calcular el salario total del trabajador, además considere que si existe un
// anticipo se debe restar este valor al salario total. Al total debe descontar un 10% para
// el pago de impuestos. Se debe obtener:
// - Total ganado
// - Total descuentos
// - Pago neto

#include <iostream>

int main() {
    double tarifaPorHora;
    double horasTrabajadas;
    double salarioTotal;
    double anticipo;
    double impuestos;
    double totalGanado;
    double totalDescuentos;
    double pagoNeto;

    // Solicitar la tarifa por hora y las horas trabajadas.
    std::cout << "Ingrese la tarifa por hora en Bs.: ";
    std::cin >> tarifaPorHora;

    std::cout << "Ingrese las horas trabajadas en la semana: ";
    std::cin >> horasTrabajadas;

    // Calcular el salario total antes de impuestos y descuentos.
    if (horasTrabajadas > 40) {
        salarioTotal = 40 * tarifaPorHora + (horasTrabajadas - 40) * tarifaPorHora * 1.5;
    } else {
        salarioTotal = horasTrabajadas * tarifaPorHora;
    }

    // Solicitar el anticipo, si existe.
    std::cout << "Ingrese el anticipo (si no hay anticipo, ingrese 0): ";
    std::cin >> anticipo;

    // Calcular los impuestos (10% del salario total).
    impuestos = salarioTotal * 0.10;

    // Calcular el total ganado, total de descuentos y pago neto.
    totalGanado = salarioTotal;
    totalDescuentos = anticipo + impuestos;
    pagoNeto = totalGanado - totalDescuentos;

    // Mostrar los resultados.
    std::cout << "Total ganado: " << totalGanado << " Bs." << std::endl;
    std::cout << "Total descuentos: " << totalDescuentos << " Bs." << std::endl;
    std::cout << "Pago neto: " << pagoNeto << " Bs." << std::endl;

    return 0;
}
