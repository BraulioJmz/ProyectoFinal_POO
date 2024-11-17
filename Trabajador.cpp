#include "Trabajador.h"

//Constructor
Trabajador::Trabajador(string, float, int) {
    this -> nombre = nombre;
    this -> salario = salario;
    this -> idTrabajador = idTrabajador;
}

//Metodos get y set
string Trabajador::getNombre() {
    return nombre;
}

float Trabajador::getSalario() {
    return salario;
}

int Trabajador::getIdTrabajador() {
    return idTrabajador;
}

void Trabajador::setNombre(string nombre) {
    this -> nombre = nombre;
}

void Trabajador::setSalario(float salario) {
    this -> salario = salario;
}

void Trabajador::setIdTrabajador(int idTrabajador) {
    this -> idTrabajador = idTrabajador;
}



