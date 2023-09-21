// Materia: Programación I, Paralelo 4

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 20/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 2

// Problema planteado: Lee por teclado la fecha actual y la fecha de nacimiento de una persona y calcula su edad.

#include <iostream>
#include <ctime>

struct Fecha {
    int dia;
    int mes;
    int anio;
};

int calcularEdad(const Fecha& fechaNacimiento, const Fecha& fechaActual) {
    int edad = fechaActual.anio - fechaNacimiento.anio;
    
    if (fechaActual.mes < fechaNacimiento.mes || 
        (fechaActual.mes == fechaNacimiento.mes && fechaActual.dia < fechaNacimiento.dia)) {
        edad--;
    }
    
    return edad;
}

int main() {
    Fecha fechaNacimiento, fechaActual;
    
    std::cout << "Ingrese la fecha de nacimiento (dd mm aaaa): ";
    std::cin >> fechaNacimiento.dia >> fechaNacimiento.mes >> fechaNacimiento.anio;
    
    time_t tiempoActual = time(nullptr);
    tm* fecha = localtime(&tiempoActual);
    
    fechaActual.dia = fecha->tm_mday;
    fechaActual.mes = fecha->tm_mon + 1;
    fechaActual.anio = fecha->tm_year + 1900;
    
    int edad = calcularEdad(fechaNacimiento, fechaActual);
    
    std::cout << "La edad es: " << edad << " años" << std::endl;
    
    return 0;
}