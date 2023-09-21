// Materia: Programación I, Paralelo 4

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 20/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 6

// Problema planteado: Escriba un programa que mediante una función determine el pago por el servicio de
// estacionamiento de coches en un parqueo, teniendo en cuenta que la primera hora de
// estadía se paga 8 Bs., y las restantes 3 Bs. c/hora. Si el uso del servicio es menor a una
// hora se cobra por la hora y de igual manera si excede la hora se cobra por la hora
// siguiente.

#include <iostream>

// Función para calcular el tiempo de estadía en horas y minutos.
void calcularTiempoEstadia(int horaEntrada, int minutoEntrada, int horaSalida, int minutoSalida, int& horas, int& minutos) {
    // Calcular la diferencia de tiempo en minutos.
    int minutosEntrada = horaEntrada * 60 + minutoEntrada;
    int minutosSalida = horaSalida * 60 + minutoSalida;
    int diferenciaMinutos = minutosSalida - minutosEntrada;

    // Calcular las horas y minutos a partir de la diferencia en minutos.
    horas = diferenciaMinutos / 60;
    minutos = diferenciaMinutos % 60;
}

// Función para calcular el costo de estacionamiento.
double calcularPagoEstacionamiento(int horas, int minutos) {
    const double tarifaPrimeraHora = 8.0; // Tarifa para la primera hora.
    const double tarifaSiguientesHoras = 3.0; // Tarifa por hora después de la primera.

    if (horas < 0 || minutos < 0) {
        return 0.0; // Si el tiempo es negativo, el costo es 0.
    } else if (horas == 0 && minutos <= 60) {
        return tarifaPrimeraHora; // Si la estadía es de 1 hora o menos, se cobra la tarifa de la primera hora.
    } else {
        // Si la estadía es mayor a 1 hora, se calcula el costo sumando la tarifa de la primera hora
        // más la tarifa por las siguientes horas.
        double costo = tarifaPrimeraHora;
        if (minutos > 0) {
            horas++; // Redondear hacia arriba si hay minutos adicionales.
        }
        costo += tarifaSiguientesHoras * (horas - 1);
        return costo;
    }
}

int main() {
    int horaEntrada, minutoEntrada, horaSalida, minutoSalida;
    int horasEstadia, minutosEstadia;

    std::cout << "Ingrese la hora de entrada (Ejm: 09): ";
    std::cin >> horaEntrada;

    std::cout << "Ingrese el minuto de entrada (Ejm: 35): ";
    std::cin >> minutoEntrada;

    std::cout << "Ingrese la hora de salida (Ejm: 10): ";
    std::cin >> horaSalida;

    std::cout << "Ingrese el minuto de salida (Ejm: 15): ";
    std::cin >> minutoSalida;

    calcularTiempoEstadia(horaEntrada, minutoEntrada, horaSalida, minutoSalida, horasEstadia, minutosEstadia);

    double costo = calcularPagoEstacionamiento(horasEstadia, minutosEstadia);

    std::cout << "Tiempo de estadía: " << horasEstadia << " horas y " << minutosEstadia << " minutos" << std::endl;
    std::cout << "El costo de estacionamiento es: " << costo << " Bs." << std::endl;

    return 0;
}
