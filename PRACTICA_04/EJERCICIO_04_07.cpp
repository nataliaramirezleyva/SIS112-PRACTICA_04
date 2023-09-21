// Materia: Programación I, Paralelo 4

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 20/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 7

// Problema planteado: Una empresa efectúa el control de asistencia de sus empleados mediante un lector
// biométrico, el horario en la entrada es a las 8:00 a.m y la salida es a las 16:00 p.m. El empleado
// tiene una tolerancia de 10 minutos en la entrada, si llega más allá de los 10 minutos de tolerancia
// se penaliza todos los minutos de atraso (es decir si llega a las 8:12 se penalizan los 12 minutos).
// De igual forma no puede salir antes del horario establecido en la salida, (si lo hace se penaliza
// los minutos faltantes), pero si el empleado entra antes o sale después de sus horarios el sistema
// solo toma en cuenta las 8 horas laborales de trabajo.
// El problema consiste en determinar los minutos de penalización para el empleado en cualquier
// día laboral.

#include <iostream>
#include <string>
#include <vector>

struct RegistroEmpleado {
    std::string codigo;
    std::string fecha;
    std::string horaEntrada;
    std::string horaSalida;
};

int calcularMinutosPenalizacion(const std::string& horaEntrada, const std::string& horaSalida) {
    // Convertir las horas y minutos de entrada y salida en enteros.
    int horaEntradaH = std::stoi(horaEntrada.substr(0, 2));
    int minutoEntradaM = std::stoi(horaEntrada.substr(3, 2));
    int horaSalidaH = std::stoi(horaSalida.substr(0, 2));
    int minutoSalidaM = std::stoi(horaSalida.substr(3, 2));

    // Calcular el tiempo de entrada en minutos desde las 8:00 a.m. (horaEntradaEsperada).
    const int horaEntradaEsperadaH = 8;
    const int minutoEntradaEsperadaM = 0;
    int minutosEntrada = (horaEntradaH - horaEntradaEsperadaH) * 60 + (minutoEntradaM - minutoEntradaEsperadaM);

    // Calcular el tiempo de salida en minutos hasta las 16:00 p.m. (horaSalidaEsperada).
    const int horaSalidaEsperadaH = 16;
    const int minutoSalidaEsperadaM = 0;
    int minutosSalida = (horaSalidaEsperadaH - horaSalidaH) * 60 + (minutoSalidaEsperadaM - minutoSalidaM);

    // Calcular la penalización total en minutos (sumar penalización de entrada y salida).
    int penalizacionTotal = 0;

    if (minutosEntrada > 10) {
        penalizacionTotal += minutosEntrada; // Penalizar los minutos de atraso en la entrada.
    }

    if (minutosSalida > 0) {
        penalizacionTotal += minutosSalida; // Penalizar los minutos faltantes en la salida.
    }

    return penalizacionTotal;
}

int main() {
    std::vector<RegistroEmpleado> registros;
    char continuar;

    do {
        RegistroEmpleado registro;

        std::cout << "Ingrese el código de empleado: ";
        std::cin >> registro.codigo;

        std::cout << "Ingrese la fecha (dd/mm/yyyy): ";
        std::cin >> registro.fecha;

        std::cout << "Ingrese la hora de entrada (en formato 24 horas, por ejemplo, 15:15): ";
        std::cin >> registro.horaEntrada;

        std::cout << "Ingrese la hora de salida (en formato 24 horas, por ejemplo, 16:30): ";
        std::cin >> registro.horaSalida;

        registros.push_back(registro);

        std::cout << "¿Desea ingresar otro registro? (s/n): ";
        std::cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    for (const RegistroEmpleado& registro : registros) {
        int minutosPenalizacion = calcularMinutosPenalizacion(registro.horaEntrada, registro.horaSalida);

        std::cout << "Código de empleado: " << registro.codigo << std::endl;
        std::cout << "Fecha: " << registro.fecha << std::endl;
        std::cout << "Minutos de penalización: " << minutosPenalizacion << " minutos" << std::endl;
        std::cout << std::endl;
    }

    return 0;
}